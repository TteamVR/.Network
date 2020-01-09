#include "client.h"


namespace
{
	SOCKET compound; 
	char msg[1024/*MESSAGE_SIZE*/];
}

namespace
{
	void MessageHandler() 
	{
		while(true) 
		{							   
			recv(compound, msg, sizeof(msg), 0);	   
			Sleep(1/*PAUSE*/);
		}
	}
}

namespace wl_network
{
	//....................................MAIN METHODS..................................//


	
	///////////////////////////////////////////////////////////////////////////////////////	
	bool CLIENT::JoinServer(const char *IP, unsigned __int8 port)						 //	
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
		int nSizeOfADDR      =  sizeof(addr);						 	  //
		addr.sin_addr.s_addr = inet_addr(IP);					  	 	  //
		addr.sin_port 		 = 	 htons(port);						 	  //
		addr.sin_family 	 =       AF_INET; 			 		     	  //
																	  	  //
		::compound = compound = socket(AF_INET, SOCK_STREAM, 0);		  //
																	 	  //
		if(connect(compound, (SOCKADDR*)&addr, sizeof(addr)) != false) 	  //
			return false;												  //
																		  //														
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 	  	  //	 
		0, 0, 0);													   	  //												 
																		  //
		////////////////////////////////////////////////////////////////////														 	
	
		return true;
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////	
	void CLIENT::SendMessage(const char *Message)										 //
	{
		send(compound, Message, sizeof(Message), 0);	
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////	
	char* CLIENT::GetLastMessage()														 //
	{
		return msg;	
	}
	
	
	
	//..............................MAIN METHODS - END..................................//
	

}


