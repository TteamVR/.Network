#include "client.h"

namespace
{
	char copy[1024];
	char  msg[1024];	
}

namespace
{
	SOCKET 	 	   compound; 
	unsigned int NewMessage;
}

namespace
{
	void MessageHandler() 
	{
		while(true) 
		{							   
			recv(compound, msg, sizeof(msg), 0);	   
			
			if(strlen(msg) != 0)			
				NewMessage++;				
					
			Sleep(1/*PAUSE*/);
		}
	}
}

namespace wl_network
{
	//....................................MAIN METHODS..................................//


	
	///////////////////////////////////////////////////////////////////////////////////////	
	bool CLIENT::join_server(const char *IP, unsigned __int16 port)						 //	
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
	void CLIENT::send_message(const char *message)										 //
	{
		send(compound, message, 1024, 0);
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////	
	char* CLIENT::get_last_message()													 //
	{
		NewMessage--;	
			 
		strcpy(copy, msg);
		strcpy(msg, "");
		return copy;	
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////	
	unsigned int CLIENT::unread()
	{
		return NewMessage;
	}
	
	//..............................MAIN METHODS - END..................................//
	

}


