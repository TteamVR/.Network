#include <windows.h>
#include <winsock2.h>

#include "List\\List.h"


__int64 quantity_compound;
char 		  szMsg[1024];


namespace _USER
{
	struct USER
	{
		SOCKET compound;
		char   	 IP[16];
		char  	  *Name;	
	};

	List<USER> 	  User;
	USER USER_TEMPLATE;
}


void MessageHandler(__int64 IndexCompounds)
{
		
}


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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	
	SOCKET new_connection;
	
	if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR))) 
	{
	//	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UserHandler, (LPVOID)(quantity_compound), 0, 0);		
	}


}










