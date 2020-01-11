#include <stdio.h>
#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\main_development\\wl.network\\wl.network.h" 

#include <iostream>
using namespace std;

char msg[256];
wl_network::CLIENT Client;


//////////////////////////////////
//////////////////////////////////
//////////////////////////////////


void function()
{
	while(true)
	{
		if(Client.NewMessage > 0)
			printf("Message from server: %s;\n\n", Client.GetLastMessage());
		
		Sleep(1);
	}	
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////


int main() 
{
	
		
	while(Client.JoinServer("127.0.0.1", 1234) == false)
			printf("fail join server!!\n");
	
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)function, 0, 0, 0);
					
	while(true) 
	{
		printf("Writing message: ");
		cin >> msg;
		Client.SendMessage(msg);	
	}

	system("pause");
}
