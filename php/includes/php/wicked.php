<?php
require 'config.php';

function insert_bot($uid, $ip)
{
    global $db;
    
    $stmt = $db->query('INSERT INTO bots VALUES ('. $uid .', '. $ip .') ON DUPLICATE KEY UPDATE ip='. $ip .'');
    return $stmt;
}

?>