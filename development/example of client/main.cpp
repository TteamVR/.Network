#include <stdio.h>
#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\development\\wl.network\\wl.network.h" 

int main() 
{
	wl_network::CLIENT Client;
	
	if(Client.JoinServer("127.0.0.1", 1) == true)	
	{	
		printf("\tYou have joined the server!\n\n");
		
		//Client.SendMessage("1");
		
		while(true)
		{	
			printf("LastMessage: %s\n", Client.GetLastMessage());
			Sleep(1000);
		}
	}
	else printf("\tYou have not joined the server!\n");
	
	system("pause");	
}
