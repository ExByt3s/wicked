<?php
require 'config.php';

function insert_bot($uid)
{
    global $db;
    
    $stmt = $db->query('INSERT INTO bots VALUES ('. $uid .')');
    return $stmt;
}

?>