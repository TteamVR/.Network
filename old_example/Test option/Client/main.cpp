#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\Work version\\WL.Network\\WL.Network.h"
#include <stdio.h>

#include <iostream>
using namespace std;

char    	Name[256];
char     Message[256];

int main() 
{	
	printf("Enter your name:");
	scanf("%s", Name);
	
	WL_NETWORK::CLIENT Client(Name);
	Client.ConnectToServer("127.0.0.1", 1);

	while(true)
	{
		printf("Enter message: ");
		scanf("%s", Message);	
		
		Client.SendMessage(Message);
		printf("Message: %s", Client.GetLastMessage(Name));
					
		Sleep(100);
		system("cls");
	}	
	
	system("pause");		
	
}
