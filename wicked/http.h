typedef struct _http_data_s
{
	SOCKET sock;
	BOOL   report;
} http_data_s;

DWORD WINAPI http_thread(LPVOID param);