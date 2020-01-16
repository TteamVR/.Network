#include "server.h"

///////////////////////
#include <stdio.h>   //
/*#include <iostream>  //
using namespace std; //
///////////////////////*/


/////////////////////////////////////
namespace 						   //
{								   //
	SOCKET s[10000];			   //
	/*unsigned*/ int cnt;		   //	
}								   //
/////////////////////////////////////


namespace
{
//	List<wl_network::USER> User; 
	char msg[1024/*MESSAGE_SIZE*/];	
}


namespace
{	
	///////////////////////////////////////////////////////////////////////////////////////	
	void ClientHandler(int index) 										 		  	     //
	{	
		int execution_result = 0;	
	
		while(true) 
		{	
			execution_result = recv(/*User[index]*/s[index]/*.compound*/, msg, sizeof(msg), 0);
				
			if(execution_result == SOCKET_ERROR &&                            
			   WSAGetLastError() == WSAECONNRESET)
			{ 
				/////////////////////////////////////////////////////////
				printf("client number %d is disconnected;\n", index);  //
				/////////////////////////////////////////////////////////
				
				/*cnt--;*/
				
				closesocket(/*User[index]*/s[index]/*.compound*/);
				break;
			}
			
			for(/*unsigned*/ int ClientCnt = 1; ClientCnt <= cnt/*User.size()*/; ClientCnt++)
			{
				if(ClientCnt != index)
				{		
					send(/*User[index]*/s[ClientCnt]/*.compound*/, msg, sizeof(msg), 0);
				}
			}		
		
			Sleep(1);			
		}			
	}	
}



namespace wl_network
{	

	//....................................CONSTRUCTORS..................................//
								
							
																								  
	///////////////////////////////////////////////////////////////////////////////////////				  
	SERVER::SERVER(const char *IP, unsigned __int16 port): IP(IP), port(port){} 		 //				  
	
	
	
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

		
		//////////////////////////////////////////////////////////////////////////////////////////
		//																	    	 			//		
		//     		Establishing a socket connection and accepting initial parameters   	 	//	
		//						     		 from the client							     	//
		//																	     	 			//	
		//////////////////////////////////////////////////////////////////////////////////////////
																			  		 			//
		SOCKET new_connection;	                                                	 			//
																					 			//
		while(true)                                                             	 			//
		{																						//
			if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR)) != false) 	//										 //
			{																		 			//	
				//USER_TEMPLATE.compound = new_connection;						 				//
																					 			//
				CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ClientHandler, 			 			//
				(LPVOID)(/*User.size()*/++cnt), 0, 0);											//
																								//
				s[cnt] = new_connection;														//
																					 			//
				printf("New client her number is %d;\n\n", cnt/*User.size()*/);					//
																					 			//
				/*User.push(USER_TEMPLATE);	*/										 			//
				/*::User.push(USER_TEMPLATE);*/										 			//			
			}								 										 			//
																					 			// 
			Sleep(1);																 			//
		}																	   		 			//
																					 			//
		//////////////////////////////////////////////////////////////////////////////////////////
	}
	
	
	
	//..............................MAIN METHODS - END..................................//
}











