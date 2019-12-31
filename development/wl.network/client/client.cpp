#include "client.h"

//////////////////////////
#include <stdio.h>	    //
//////////////////////////

namespace{SOCKET compound;}

namespace
{
	void ClientHandler() 
	{
		char msg[1024/*MESSAGE_SIZE*/];
		
		while(true) 
		{
			recv(compound, msg, sizeof(msg), 0);
			printf("\nMessage: %s\n", msg);
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
		compound = socket(AF_INET, SOCK_STREAM, 0);					 	  //
																	 	  //
		if(connect(compound, (SOCKADDR*)&addr, sizeof(addr)) != false) 	  //
			MessageBox(0, "Error: failed connect to server", "Error", 0); //
																		  //
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ClientHandler, 		  //	 
		0, 0, 0);														  //												 
																		  //
		////////////////////////////////////////////////////////////////////														 	
	}
	
	
	//..............................MAIN METHODS - END..................................//
	

}


