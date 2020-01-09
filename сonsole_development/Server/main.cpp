#include <winsock2.h>
#include <stdio.h>

//#include "C:\\Users\\admin\\Desktop\\C++\\IMPORTANT\\My Libraries\\BC\\BC.h"

/*struct USER{SOCKET compound;};
USER USER_TEMPLATE;
List<USER>    User;*/

SOCKET 	  compound;
char 	 msg[1024];

///////////////////////////////////////////////////////////////////////////////////////	
void ClientHandler(/*__int64 index*/) 												 //						 		  	    
{	
	int execution_result = 0;	
	
	while(true) 
	{	
		execution_result = recv(/*User[index].*/compound, msg, sizeof(msg), 0);
			
		if(execution_result == SOCKET_ERROR &&                            
		   WSAGetLastError() == WSAECONNRESET)
		{
			closesocket(/*User[index].*/compound);
			break;
		}
		
		printf("msg[1024] = %s\n", msg);
			
		Sleep(1);			
	}
}

int main() 
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
	int nSizeOfADDR      =  		 sizeof(addr);		//
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");		//
	addr.sin_port 		 =   		  htons(1234);		//
	addr.sin_family 	 =       		  AF_INET;   	//
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
/*	while(true)                                                             	 			//
	{*/																						//
																				            //
		if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR)) != false) 	//										 //
		{																		 			//	
			/*USER_TEMPLATE.*/compound = new_connection;						 			//
																				 			//
		//	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ClientHandler, 			 			//
		//	/*(LPVOID)(User.size())*/0, 0, 0);												//
																				 			//
			printf("New client her number is \n"/*, User.size()*/);							//
																				 			//
			/*User.push(USER_TEMPLATE);											 			//
			::User.push(USER_TEMPLATE);	*/										 			//			
		}								 										 			//
																				 			// 
		Sleep(1);																 			//
	//}																	   		 			//
																				 			//
	//////////////////////////////////////////////////////////////////////////////////////////

	
	/////////////////////////////////////////
	ClientHandler();					   //
	/////////////////////////////////////////


	system("pause");
}
