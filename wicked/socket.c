#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <stdio.h>

#include "wicked.h"
#include "socket.h"

int init_winsock()
{
	WSADATA wsa;
	return !WSAStartup(MAKEWORD(2, 2), &wsa) ? 1 : 0;
}

SOCKET create_tcp_socket(char* hostname, char* port)
{
	SOCKET			sock;
	struct addrinfo *result = NULL,
					*ptr = NULL,
					hints;
	int				addr;

	RtlSecureZeroMemory(&hints, sizeof(hints));

	/* Fill the socket address structure */
	hints.ai_family   = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	/* Resolve hostname */
	addr = getaddrinfo(hostname, port, &hints, &result);
	if (addr != 0)
	{
#ifdef _DEBUG_
		printf("getaddrinfo failed! (%d)\n", addr);
#endif
		return 0;
	}

	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{
		/* Create socket */
		sock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (sock == INVALID_SOCKET)
		{
#ifdef _DEBUG_
			printf("socket failed! (%d)\n", WSAGetLastError());
#endif
			return 0;
		}

		/* Connect */
		if (connect(sock, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR)
		{
			sock = INVALID_SOCKET;
			continue;
		}

		break;
	}

	freeaddrinfo(result);

	/* Clean up socket if connection failed */
	if (sock == INVALID_SOCKET)
	{
#ifdef _DEBUG_
		printf("failed to connect to the server! (%d)\n", WSAGetLastError());
#endif
		closesocket(sock);
		return 0;
	}

	return sock;
}

int send_tcp_data(SOCKET sock, char* data,...)
{
	va_list va;
	int     len;
	char*   buffer;

	/* Create list to support function argument lists */
	va_start(va, data);
		len	   = _vscprintf(data, va) + 1;
		buffer = malloc(len * sizeof(char));
		vsprintf_s(buffer, len, data, va);
	va_end(va);

	/* Send the completed buffer */
	if (send(sock, buffer, strlen(buffer), 0) == SOCKET_ERROR)
	{
		printf("failed to send TCP socket data! (%d)\n", WSAGetLastError());
		return 0;
	}

	printf("sent socket data: \n%s\n", buffer);

	return 1;
}