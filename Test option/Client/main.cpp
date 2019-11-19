#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\Work version\\WL.Network\\WL.Network.h"
#include <stdio.h>

char    	Name[256];
char     Message[256];
char   Recipient[256];
char 		  *Answer;

unsigned __int64 Time;
__int8		   choose;

int main() 
{	
	printf("Enter your name:");
	scanf("%s", Name);
	
	WL_NETWORK::CLIENT Client((const char*)Name);
	
	while(true) 
	{
		Answer = (char*)Client.ConnectToServer("127.0.0.1", 1);
		printf("Answer: %s\n", Answer);
		
		if(strcmp(Answer, "CONNECTIONS_SUCCESSFULLY_PERFORMED") == 0)	break;
			
		Sleep(1000);
	}
	
	printf("\nChoose 'true' for write message or 'false' for get message: ");
	scanf("%d", choose);	
	
	if(choose == 1)
	{
		printf("\nEnter message: ");
		scanf("%s", Message);
	
		printf("\nEnter recipient: ");
		scanf("%s", Recipient);
	
		Client.SendMessage(Message, Recipient);
	}
	else
	{
		while(true)
		{
			Client.GetMessage(Message, Recipient, &Time);
			printf("Message: %s;\n Sender: %s;\n Time: %d;", Message, Recipient, Time);
		}	
	}
}
