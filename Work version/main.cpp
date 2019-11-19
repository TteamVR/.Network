#include <stdio.h>

#include "WL.Network\\WL.Network.h"


int main() 
{	
	WL_NETWORK::SERVER Server("Global-Server", "127.0.0.1", 1);
//	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Server.Set(), 0, 0, 0);


	WL_NETWORK::CLIENT Client("BOT");

}




