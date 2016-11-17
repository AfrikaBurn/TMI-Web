<?php
function quicket_update_user() {
  
  $vars = array();
  $vars['type']="ul";
  $vars['title'] = "";
  $vars['attributes']=array("");
  
  GLOBAL $user;
  $user_fields = user_load($user->uid);
  //drupal_set_message('user_fields:<br><pre>'. print_r($user_fields, true) .'</pre><br><br><br>'); 
  if ( empty( $user_fields->field_quicket_code ) ) {
    
    $headers = array(
        'Content-Type' => 'application/json',
        'usertoken' => '9KySOwx7LTxATa4ODyTeYnJ57kDBVErT',
    );
    $user_pass='';
    $data = "{'EventId':21831,
              'TicketTypes':[38682],
              'IsPercentage':false,
              'DiscountAmount':0.0,
              'NumUses':2,'ValidFrom':
              '2016-10-15T00:00:00Z',
              'ValidTo':'2017-04-30T00:00:00Z',
              'IsAccessCode':true,
              'Email':'" . $user->mail . "'}";
    $options = array(
      'method' => 'POST',
      'data' => $data,
      'timeout' => 45,
      'headers' => $headers,
    );
    $result = drupal_http_request('https://api.quicket.co.za/api/codes?api_key=3171510c9eb84a7b70700652bcbd5cae', $options);
    //drupal_set_message('Result:<br><pre>'. print_r($result->data, true) .'</pre><br><br><br>'); 
    
    if ($result->code == 200) {
      //$obj = json_decode($result[body]);
      //$result = $obj->result;
      $obj = json_decode($result->data);
      $result = $obj->result;
      $codevalue = $result->CodeValue;
      $codeid = $result->CodeId;
      $link = "https://www.quicket.co.za/events/21831-afrikaburn-2017-play/#/?dc=" . $codevalue ;
      drupal_set_message('Result:' . $link ); 
      
      //field_bb_minors_details
      
      $user_fields->field_quicket_code['und'][0]['value'] = $codevalue;
      
      //user_save($user_fields);
    }
    
  
  }
  
  $vars['items'][0]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
  return theme_item_list($vars);
}















function quicket_loop() {
  if(!function_exists('kid_count')){ 
    function kid_count ($kids) {
      $count = 0;
      $teen = 0;
      foreach ($kids['und'] as $value) {
        if (isset($value['field_first_name']['und'][0]['value']) ) {
          
          
          
          $time = strtotime( substr( $value['field_date_of_birth']['und'][0]['value'], 0, 10 ) );
          $newformat = date('Y-m-d',$time);
          
          if ( strtotime('24 April 2002') < $time ) {
            $count++;
          } elseif ( strtotime('24 April 1999') < $time ) {
            $teen++;
          }
          //drupal_set_message('DoB:<br><pre>' . $value['field_date_of_birth']['und'][0]['value'] . ' ' . $newformat .  ' ' . $teen . ' ' . $count .'</pre><br><br><br>'); 
          
          //drupal_set_message('Node Result:<br><pre>1</pre><br><br><br>'); 
          //drupal_set_message('user_fields:<br>kids<br><br><br><pre>' . print_r($value, 1) . '</pre>');
        } else {
          //drupal_set_message('user_fields:<br>no kids<br><br><br><pre>' . print_r($value, 1) . '</pre>');
        }
      }
      return array ($count, $teen);
    }
  }
  
  $vars = array();
  $vars['type']="ul";
  $vars['title'] = "";
  $vars['attributes']=array("");
  $vars['items']=array();
  
  GLOBAL $user;
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    ->fieldCondition('field_bb_agree', 'value', '0', '!=');
    //->fieldCondition('status', 'value', '1', '=');
    
  
  
  $result = $query->execute();
   
  if (isset($result['user'])) {
    
    $vars['items'][0] = 'Total: ' . count($result['user']);
    //return;
    $count = 1 ;
    
      
    foreach ($result['user'] as $ukey => $uvalue){
      //$vars['items'][$count] .= 'User Result:<pre>'. print_r($uvalue,1) . '</pre> (val:key): ' . $ukey ; 
      $user_fields = user_load($ukey);
      
      $vars['items'][$count] = '';
      
      if ( !isset( $user_fields->field_quicket_code['und'][0]['value'] ) ) {
        
        $vars['items'][$count] .= '<br>not found: ' ;
        
        
          //drupal_set_message('user_fields:' . $user_fields->field_sa_id_or_passport_number['und'][0]['value'] . '<br>');
          //drupal_set_message('user_fields:<pre>' . print_r($user_fields->field_bb_minors_details, 1) . '</pre><br>');
          //drupal_set_message('user_fields:<pre>' . print_r($user_fields, 1) . '</pre><br>');
        list ($no_kids, $teens) = kid_count( $user_fields->field_bb_minors_details );
        
        //$vars['items'][$count] .= '<br>kids: ' . $no_kids . ' ' . $teens . ' <pre>' . print_r($user_fields->field_bb_minors_details, 1) . '</pre> ' ;
        
        $vars['items'][$count] .= '<br>id: ' . $user_fields->field_sa_id_or_passport_number['und'][0]['value'] . ' ' ;
        
        $headers = array(
            'Content-Type' => 'application/json',
            'usertoken' => '9KySOwx7LTxATa4ODyTeYnJ57kDBVErT',
        );
        $user_pass='';
        $data = "{'EventId':21831,
                  'TicketTypes':[".
                                "38682".
                                ( $teens > 0 ? ',39356' : '').
                                ($no_kids  > 0 ? ',38683' : '').
                                "],
                  'IsPercentage':false,
                  'DiscountAmount':0.0,
                  'NumUses':" . ( $no_kids + $teens + 2 ) . ",
                  'ValidFrom':'2016-10-15T00:00:00Z',
                  'ValidTo':'2017-04-30T00:00:00Z',
                  'IsAccessCode':true,
                  'Email':'" .  str_replace(' ', '', $user_fields->field_sa_id_or_passport_number['und'][0]['value']) . "'}";

        $options = array(
          'method' => 'POST',
          'data' => $data,
          'timeout' => 45,
          'headers' => $headers,
        );

        $result = drupal_http_request('https://api.quicket.co.za/api/codes/?api_key=3171510c9eb84a7b70700652bcbd5cae', $options);
        
        watchdog('Quicket call', 'New user:<br><pre>@print_r</pre>', array('@print_r' => print_r( $result, TRUE)));

        if (isset($result->code) and ($result->code == 200) ) {
          
          $obj = json_decode($result->data);
          $result = $obj->result;
          $codevalue = $result->CodeValue;
          $codeid = $result->CodeId;
          $link = "https://www.quicket.co.za/events/21831-afrikaburn-2017-play/#/?dc=" . $codevalue ;
          
          
        
          $user_fields->field_quicket_code['und'][0]['value']=$codevalue;
          $user_fields->field_quicket_id['und'][0]['value']=$codeid;
          $user_fields->field_bb_no_kids_tickets['und'][0]['value']=$no_kids;
          $user_fields->field_bb_no_teens_tickets['und'][0]['value']=$teens;
          unset($user->Login, $user->Role, $user->Unit, $user->expire, $user->pass, $user->field_bb_minors_details, $user->field_previous_envolvement);
          user_save($user_fields);
          
          $vars['items'][$count] .= ' bb created:'. $codevalue  . ' : ' .  ' kids: ' . $no_kids . ' teens: ' . $teens ;
          $count++;
        }
        
        
      } else {
        $vars['items'][$count] .= '<br>bb found:'. $user_fields->field_quicket_code['und'][0]['value'] ;
        
        
      }
      
      
      
      
      if ( $count > 2 ) {
        $vars['items'][$count++] = '<br>Node Result:<pre>'. print_r($user_fields , 1) . '</pre> <br>' ;
        
        //$vars['items'][$count]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
        return theme_item_list($vars);
      }
      
    }
  }
  
  
  $vars['items'][0]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
  return theme_item_list($vars);
  
}








function quicket_qc_agree() {
  
  $vars = array();
  $vars['type']="ul";
  $vars['title'] = "";
  $vars['attributes']=array("");
  $vars['items']=array();
  
  GLOBAL $user;
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    ->fieldCondition('field_quicket_code', 'value', '0', '!=');
    
  
  
  $result = $query->execute();
   
  if (isset($result['user'])) {
    
    $vars['items'][0] = 'Total: ' . count($result['user']);
    //return;
    $count = 1 ;
    
      
    foreach ($result['user'] as $ukey => $uvalue){
      //$vars['items'][$count] .= 'User Result:<pre>'. print_r($uvalue,1) . '</pre> (val:key): ' . $ukey ; 
      $user_fields = user_load($ukey);
      
      $vars['items'][$count] = '';
      
      
      if (!isset($user_fields->field_bb_agree['und'][0]['value']) ) {
        $user_fields->field_bb_agree['und'][0]['value']=1;
        //unset($user->Login, $user->Role, $user->Unit, $user->expire, $user->pass, $user->field_bb_minors_details, $user->field_previous_envolvement);
        user_save($user_fields);
      }
      
    }
  }
  
  $vars['items'][0]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
  return theme_item_list($vars);
}
  
/*function quicket_loop() {
  
  $vars = array();
  $vars['type']="ul";
  $vars['title'] = "";
  $vars['attributes']=array("");
  
  GLOBAL $user;
  $user_fields = user_load($user->uid);
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'quicket_code')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('uid', 0);

  $result = $query->execute();
  if (isset($result['node'])) {
    $quicket_nids = array_keys($result['node']);
    $quicket_items = entity_load('node', $quicket_nids);
    
    $count = 0;
    //drupal_set_message('Node Result:<br><pre>'. count($quicket_nids) . ' : ' . print_r($quicket_nids, true) .'</pre><br><br><br>'); 
    foreach ($quicket_nids as $key => $value){
      $vars['items'][$count] = '';
      
      $vars['items'][$count] .= 'Node Result:'. $value . ' (val:key): ' . $key ; 
      
      $node = node_load($value);
      $vars['items'][$count] .= '<br>Node Result:<pre>'. print_r($node , 1) . '</pre> <br>' ; 
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $n_data = $quicket_items[$value];
      
      /*
       * $node = node_load($nid);
          $node_wrapper = entity_metadata_wrapper('node', $node);
          $node_wrapper->field_myfield->set(1);
          $node_wrapper->save();
          *//*
      
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'user')
        ->fieldCondition('field_sa_id_or_passport_number', 'value', $n_data->title, '=');
        
      $vars['items'][$count] .= ' : '. $n_data->title ; 
      
      $result = $query->execute();
      
      //drupal_set_message('User Result:'. count($result) . ' : ' . print_r($result, true) ); 
      if (isset($result['user'])) {
        foreach ($result['user'] as $ukey => $uvalue){
          $vars['items'][$count] .= 'User Result:'.gettype($key); 
          $vars['items'][$count] .= ' : ' . strval($key) .'<br>';
          $vars['items'][$count] .= '<pre>' . print_r( $node_wrapper, 1 ) .'</pre>';
          
          $new_node = new stdClass;
          $new_node->type = 'quicket_code';
          $new_node->title = str_replace(' ', '', $node->title);
          $new_node->{'field_bb_no_kids_tickets'}[LANGUAGE_NONE][0]['value'] = $node->field_bb_no_kids_tickets['und'][0]['value'];
          $new_node->{'field_quicket_code'}[LANGUAGE_NONE][0]['value'] = $node->field_quicket_code[LANGUAGE_NONE][0]['value'];
          $new_node->language = LANGUAGE_NONE;
          $new_node->uid = $uvalue;
          node_object_prepare($new_node);
          node_save($new_node);
        }
        
      }
      
      
      
      
      
      
      $count++;
      if ( $count > 1 ) {
        
        $vars['items'][$count]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
        return theme_item_list($vars);
      }
    }
  }
  
  
  
  
  
  $vars['items'][0]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';
  return theme_item_list($vars);
}*/
