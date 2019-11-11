#include "WL.Network.h"

namespace _SERVER
{

	///////////////////////////////////////////////////////////////////////////
	void MessageHandler(__int64 IndexCompounds)						 		 //
	{
		
	}	
	
	
	///////////////////////////////////////////////////////////////////////////
	bool SERVER::Set(const char *Name, const char* IP, unsigned __int8 Port) //
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
		addr.sin_port 		 = 	 htons(Port);				//
		addr.sin_family 	 =       AF_INET;				//
															//
		SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);	//
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));		//
		listen(sListen, SOMAXCONN);							//
															//		
		//////////////////////////////////////////////////////
		
		
		
		/////////////////////////////////////////////////////////////////////////
		//																	   //		
		//  Establishing a socket connection and accepting initial parameters  //	
		//						    from the client							   //
		//																	   //	
		/////////////////////////////////////////////////////////////////////////
																			   //
		SOCKET new_connection;	                                               //
		                                                                       //
		if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR))) // 
		{																	   //
			send(new_connection, "Hello", 6, 0);
			
		/*	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 		   //
			(LPVOID)(++quantity_compound), 0, 0);	 						   //
																			   //
			USER_TEMPLATE.compound = new_connection;						   //
																			   //
			User.push(USER_TEMPLATE);	*/									   //
		}																	   //
																			   //
		/////////////////////////////////////////////////////////////////////////	
																   
	}
}
