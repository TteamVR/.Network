#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\Work version\\WL.Network\\WL.Network.h"
#include <stdio.h>

char    	Name[256];
char     Message[256];
char   Recipient[256];
char 		  *Answer;

unsigned __int64 Time;
int		 	   choose;

int main() 
{	
	printf("Enter your name:");
	scanf("%s", Name);
	
	WL_NETWORK::CLIENT Client(Name);
	
	while(true) 
	{
		Answer = (char*)Client.ConnectToServer("127.0.0.1", 1);
		printf("Answer: %s\n", Answer);
		
		if(strcmp(Answer, "CONNECTIONS_SUCCESSFULLY_PERFORMED") == 0)	break;
			
		Sleep(1000);
	}
	
	system("pause");
/*	
	printf("Enter '1' for write message or enter '2' for get message: ");
	scanf("%d", choose);
	
	switch(choose)
	{
		case 1: 
				
				while(true)
				{
					printf("Enter recipient: ");
					scanf("%s", Recipient);
				
					printf("Enter message: ");
					scanf("%s", Message);
				
					Client.SendMessage(Message, Recipient);				
				}			
				break;
				
		case 2:
				while(true)
				{
					Client.GetMessage(Message, Recipient, &Time);
					printf("Message: %s;\n Sender: %s;\n Time: %d;", Message, Recipient, Time);
					Sleep(10);
				}
				
				break;
	}	*/		
	
}
