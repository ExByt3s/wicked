int init_winsock();
SOCKET create_tcp_socket(char* hostname, char* port);
int send_tcp_data(SOCKET sock, char* data, ...);
