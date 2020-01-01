#include "server.h"

//////////////////////
#include <stdio.h>  //
//////////////////////

namespace
{
	List<wl_network::USER> User; 
	
	SOCKET s; 
}

namespace
{	
	///////////////////////////////////////////////////////////////////////////////////////	
	void ClientHandler(__int64 index) 									 		  	     //
	{	
		char msg[MESSAGE_SIZE];			
		strcpy(msg, "");
		
		while(true) 
		{	
			for(int cnt = 0; cnt < ::User.size(); cnt++) 
			{
				send(::User[cnt].compound, "SERVER_MESSAGE_CONNECT", sizeof("SERVER_MESSAGE_CONNECT"), 0); 
			}
		
			Sleep(1000);
			
			/*
			recv(::User[index].compound, msg, sizeof(msg), 0);
			
			for(int cnt = 0; cnt < ::User.size(); cnt++) 
			{
				if(cnt != index) send(::User[cnt].compound, msg, sizeof(msg), 0);
			}*/
		}			
	}	
}



namespace wl_network
{	

	//....................................CONSTRUCTORS..................................//
								
							
																								  
	///////////////////////////////////////////////////////////////////////////////////////				  
	SERVER::SERVER(const char *IP, unsigned __int8 port): IP(IP), port(port){} 			 //				  
	
	
	
	//.................................CONSTRUCTORS-END.................................//	
				
				
	
				
								
	//....................................MAIN METHODS..................................//
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////	
	void SERVER::Set()																	 //
	{
		
		//////////////////////////////////////////////////////
		//													//
		//        Create a socket and set to listen         //
		//													//
		//////////////////////////////////////////////////////
															//
		WSAData wsaData;									//
		WORD DLLVersion = MAKEWORD(2, 1);					//
		WSAStartup(DLLVersion, &wsaData); 					//
															//
		SOCKADDR_IN addr;									//
		int nSizeOfADDR      =  sizeof(addr);				//
		addr.sin_addr.s_addr = inet_addr(IP);				//
		addr.sin_port 		 =   htons(port);				//
		addr.sin_family 	 =       AF_INET;   			//
															//
		SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);	//
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));		//
		listen(sListen, SOMAXCONN);							//
															//		
		//////////////////////////////////////////////////////	
	
		
		///////////////////////////////////////////////////////////////////////////////
		//																	    	 //		
		//     Establishing a socket connection and accepting initial parameters   	 //	
		//						      from the client							     //
		//																	     	 //	
		///////////////////////////////////////////////////////////////////////////////
																			  		 //
		SOCKET new_connection;	                                                	 //
																					 //
		while(true)                                                             	 //
		{																			 //
			new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR);		 //
																					 //
			if(new_connection != false) 											 //
			{		
				
				////////////////////////////////////////////////////////////////////////////////////////
																									  //
				send(new_connection, "SERVER_MESSAGE_CONNECT", sizeof("SERVER_MESSAGE_CONNECT"), 0);  //
																									  //
				s = new_connection;																	  //
																									  //
				////////////////////////////////////////////////////////////////////////////////////////
				
																					 //	
				USER_TEMPLATE.compound = new_connection;							 //
																					 //
				CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ClientHandler, 			 //
				(LPVOID)(User.size()), 0, 0);										 //
																					 //
				printf("New client her number is %d\n", User.size());				 //
																					 //
				User.push(USER_TEMPLATE);											 //
				::User.push(USER_TEMPLATE);											 //			
			}								 										 //
																					 // 
			Sleep(PAUSE);															 //
		}																	   		 //
																					 //
		///////////////////////////////////////////////////////////////////////////////	
			
	}
	
	
	
	//..............................MAIN METHODS - END..................................//
	

}











