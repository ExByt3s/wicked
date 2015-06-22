<?php

function get_client_ip()
{
    $ip;
    
    if (@$_SERVER['HTTP_CLIENT_IP'])
        $ip = $_SERVER['HTTP_CLIENT_IP'];
    else if(@$_SERVER['HTTP_X_FORWARDED_FOR'])
        $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
    else if(@$_SERVER['HTTP_X_FORWARDED'])
        $ip = $_SERVER['HTTP_X_FORWARDED'];
    else if(@$_SERVER['HTTP_FORWARDED_FOR'])
        $ip = $_SERVER['HTTP_FORWARDED_FOR'];
    else if(@$_SERVER['HTTP_FORWARDED'])
        $ip = $_SERVER['HTTP_FORWARDED'];
    else if(@$_SERVER['REMOTE_ADDR'])
        $ip = $_SERVER['REMOTE_ADDR'];
    else
        $ip = 'UNKNOWN';
        
    return $ip;
}

function rand_str()
{
    $str;
    $chars = "abcdefghijklmanopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    $size = strlen($chars);
    
    for($i = 0;$i < $length;$i++)
    {
        $str .= $chars[rand(0,$size-1)];
    
    }
    
    return $str;
}

?>