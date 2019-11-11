#include <stdio.h>
#include <winsock2.h>

char szMessage[256];

int main() 
{														
	WSAData wsaData;								
	WORD DLLVersion = MAKEWORD(2, 1);			
	WSAStartup(DLLVersion, &wsaData); 				
														
	SOCKADDR_IN addr;								
	int nSizeOfADDR      =  sizeof(addr);				
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");				
	addr.sin_port 		 = 	 htons(1);			
	addr.sin_family 	 =       AF_INET;		
														
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, 0);
	
	while(connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) 
		printf("Error: connect to server !\n");	
	
	send(Connection, "Name", 6, 0);
	
	if(recv(Connection, szMessage, sizeof(szMessage), 0))
	{
		printf("Server message: %s", szMessage);
	}	
	
}
