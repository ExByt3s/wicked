#include "wicked.h"
#include "config.h"

config_s config[] =
{
	{
		"localhost", //server
		"80",        //port
		"gate.php",  //gate location
		30000        //http report sleep time
	},
	{ null, null, null }
};