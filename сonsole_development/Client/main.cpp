#include <winsock2.h>
#include <stdio.h>
	
SOCKET compound; 
char  msg[1024];
char _msg[1024];

void MessageHandler() 
{
	while(true) 
	{							   
		recv(compound, msg, sizeof(msg), 0);	   
		Sleep(1);
	}
}


///////////////////////////////////////////////////////////////////////////////////////	
void SendMessage(const char *Message)												 //
{
	send(compound, Message, sizeof(Message), 0);	
}
	
	

///////////////////////////////////////////////////////////////////////////////////////	
char* GetLastMessage()																 //
{
	return msg;	
}



int main()
{
	////////////////////////////////////////////////////////////////////
	//															 	  //
	//      Creating Sockets and Establishing a Server Connection     //
	//															   	  //
	////////////////////////////////////////////////////////////////////
																 	  //
	WSAData wsaData;											 	  //
	WORD DLLVersion = MAKEWORD(2, 1);							 	  //
	WSAStartup(DLLVersion, &wsaData); 							 	  //
																 	  //
	SOCKADDR_IN addr;											 	  //
	int nSizeOfADDR      =  		 sizeof(addr);				 	  //
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");			  	 	  //
	addr.sin_port 		 = 			 htons(1234);				 	  //
	addr.sin_family 	 =      	  	  AF_INET;	 		     	  //
																  	  //
	compound = socket(AF_INET, SOCK_STREAM, 0);						  //
																 	  //
	if(connect(compound, (SOCKADDR*)&addr, sizeof(addr)) != false) 	  //
		return false;												  //
																	  //														
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 	  	  //	 
	0, 0, 0);													   	  //												 
																	  //
	////////////////////////////////////////////////////////////////////	
	
	
	/////////START/////////
	
	while(true)
	{
		printf("Enter the message: ");
		scanf("%s", _msg);
		
		SendMessage(_msg);
	}
	
	/////////END///////////
	
}
