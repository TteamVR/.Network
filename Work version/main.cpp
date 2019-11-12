#include <stdio.h>

#include "WL.Network\\WL.Network.h"
using namespace _SERVER;

int main() 
{	
	_SERVER::SERVER Server("Global-Server", "127.0.0.1", 1);
	 	 
	 //void (*message)(void *) = _SERVER::SERVER::SetInThread;
	//_beginthread(Server.SetInThread, 0, NULL);

	char *Delete = 0;
	scanf("%s", Delete);
	
/*	if(strcmp(Delete, "Delete") == 0) 
		Server.Delete(false, "This server will be deleted !!!");*/
	
	//printf("%s: ", Server.GetStatus());

}
