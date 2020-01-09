#include "server.h"

///////////////////////
#include <stdio.h>   //
#include <iostream>  //
using namespace std; //
///////////////////////

namespace
{
	List<wl_network::USER> User; 
	char msg[1024/*MESSAGE_SIZE*/];	
}

namespace
{	
	///////////////////////////////////////////////////////////////////////////////////////	
	void ClientHandler(__int64 index) 									 		  	     //
	{	
		while(true) 
		{	
			recv(::User[index].compound, msg, sizeof(msg), 0);
			cout << "msg[1024] = " << msg << endl;
			
			/*for(int cnt = 0; cnt < ::User.size(); cnt++) 
			{
				//if(cnt != index) 
				send(::User[cnt].compound, msg, sizeof(msg), 0);
			}*/
			
			Sleep(PAUSE);
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
			{																		 //	
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











