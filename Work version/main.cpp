#include <stdio.h>

#include "WL.Network\\WL.Network.h"

char Command[256];

int main() 
{	
	WL_NETWORK::SERVER Server("Global-Server", "127.0.0.1", 1);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Server.Set(), 0, 0, 0);
}




