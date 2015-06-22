#include <Windows.h>
#include <stdio.h>

#include "wicked.h"
#include "socket.h"
#include "http.h"

int entry_point()
{
	init_winsock();

	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)http_thread, NULL, 0, 0);

	getchar();
	return 0;
}