<html>
<head>
    <title>Login</title>
</head>
<body>
    <form action="index.php">
        Username:<br>
        <input type="text" name="username" />
        <br><br>
        Password:<br>
        <input type="password" name="password" />
        <br><br>
        <input type="submit" value="Login" />
    </form>
</body>
</html>
<?php

@$username = $_POST["username"];
@$password = $_POST["password"];

?>
