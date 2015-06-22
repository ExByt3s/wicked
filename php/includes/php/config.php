<?php
$dbHost = "localhost";
$dbName = "wicked";
$dbUser = "root";
$dbPass = "";

/* DO NOT EDIT! */
$db = new PDO('mysql:host='. $dbHost .';dbname='. $dbName .';charset=utf8', $dbUser, $dbPass);
$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$db->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
/* DO NOT EDIT! */

?>