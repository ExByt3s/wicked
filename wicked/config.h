typedef struct _config_s
{
	char *host;
	char *port;
	char *page;
	int  report_sleep_time;
} config_s;


extern config_s config[];