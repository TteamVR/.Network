#include "WL.Network.h"


namespace
{
	char szEmpty[1024];
	
	const char *MESSAGE_CSP        = "CONNECTIONS_SUCCESSFULLY_PERFORMED";	
	const char *MESSAGE_ERROR_NAME = 	 "NAME ERROR: NAME IS NOT UNIQUE";
}


namespace _SERVER
{	
	
	///////////////////////////////////////////////////////////////////////////
	void MessageHandler(__int64 IndexCompounds)						 		 //
	{
		
	}	
	
	
	
	///////////////////////////////////////////////////////////////////////////
	SERVER::SERVER()														 //
	{
		
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////
	SERVER::SERVER(const char *Name, const char* IP, unsigned __int8 Port):  // 	
	SERER_DATA.Name(Name), SERER_DATA.IP(IP), SERER_DATA.Port(Port) 
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
			if(recv(new_connection, szMsg, sizeof(szMsg), 0))
			{
				for(__int64 cnt = 0; cnt < quantity_compound; cnt++)
					if(strcmp(User[cnt].Name, szMsg) == 0)
					{	
						send(new_connection, MESSAGE_ERROR_NAME, 
						strlen(MESSAGE_ERROR_NAME), 0);	
						strcpy(szMsg, szEmpty);
					}
				
				USER_TEMPLATE.compound = new_connection;					
				USER_TEMPLATE.Name     =          szMsg;				
				
				send(new_connection, MESSAGE_CSP, 
				strlen(MESSAGE_CSP), 0);
			}
			
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 		   //
			(LPVOID)(++quantity_compound), 0, 0);	 						   //
																			   //
																			   //
			User.push(USER_TEMPLATE);										   //
			strcpy(szMsg, szEmpty);											   //
		}																	   //
																			   //
		/////////////////////////////////////////////////////////////////////////	
																   
	}
}
