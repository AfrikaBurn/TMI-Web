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
      
      user_save($user_fields);
    }
    
  
  }
  
  $vars['items'][0]='Result:<br><pre>'. print_r($result, true) .'</pre><br><br><br>';

  return theme_item_list($vars);
}

