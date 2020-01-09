#include <stdio.h>
#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\development\\wl.network\\wl.network.h" 

#include <iostream>
using namespace std;

char msg[256];

int main() 
{
	wl_network::CLIENT Client;
		
	while(Client.JoinServer("127.0.0.1", 1) == false)
			printf("fail join server!!\n");
				
	while(true) 
	{
		printf("Writing message: ");
		cin >> msg;
		Client.SendMessage(msg);	
	}

	system("pause");
}
