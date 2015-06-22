# wicked
Proof-of-concept on how Windows malware/botnets connect to HTTP command center in C using Winsock.

# How it works
Uses Winsock to create a TCP socket that connects to the host specified in the configuration file.
Once the bot has connected it adds the information received from the GET request into a MySQL database.
Connection is closed and the bot is idle.

The bot will reconnect every X seconds, X defined in the configuration file.

# Todo
Add a simple panel and task management.
