<?php
$headers = array(
    'Content-Type' => 'application/json',
    'usertoken' => '9KySOwx7LTxATa4ODyTeYnJ57kDBVErT',
);
$user_pass='';
$data = "";

$options = array(
  'method' => 'GET',
  'data' => $data,
  'timeout' => 45,
  'headers' => $headers,
);

$result = drupal_http_request('https://api.quicket.co.za/api/events/26935', $options);
drupal_set_message('Result:<br><pre>'. print_r($result->data, true) .'</pre>'); 
echo 'Result:<br><pre>'. print_r($result->data, true) .'</pre>';

?>

