#include "WL.Network.h"
#include <stdio.h>

namespace
{
	char szEmpty[1024];
	
	const char *MESSAGE_CSP           = "CONNECTIONS_SUCCESSFULLY_PERFORMED";
	const char *MESSAGE_SC            = 			"SUCCESSFULLY_COMPLETED";
	const char *MESSAGE_DS            =    "SERVER_WAS_SUCCESSFULLY_REMOVED";	
	const char *MESSAGE_ERROR_NAME    = 	"NAME ERROR: NAME IS NOT UNIQUE";
	const char *MESSAGE_ERROR_SETDATA = "DATA SETUP ERROR: YOU DID NOT INSTALL DATA TO INSTALL DATA FOR THE SERVER USE THE FUNCTION 'SetData'";
}


namespace _SERVER
{	
	
	//////////////////////////////////////////////////////////////////////////////////
	void MessageHandler(__int64 IndexCompounds)						 		  	    //
	{
		
	}	
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	SERVER::SERVER()														   	 //
	{
		quantity_compound =     0;
		SERVER_DATA.Using = false;
		proceed           =  true;
		
		strcpy(szMsg, szEmpty);	
	}
	
	

	//////////////////////////////////////////////////////////////////////////////////
	SERVER::SERVER(const char *Name, const char* IP, unsigned __int8 Port)    	    //
	{
		quantity_compound =     0;
		SERVER_DATA.Using = false;
		proceed           =  true;
		
		SERVER_DATA.Name  =  Name;
		SERVER_DATA.IP    =    IP;
		SERVER_DATA.Port  =  Port;
		SERVER_DATA.Using =  true;
		
		strcpy(szMsg, szEmpty);	
	}
	
	
	
	//////////////////////////////////////////////////////////////////////////////////
	void SERVER::SetData(const char *Name, const char* IP, unsigned __int8 Port)    //
	{
		SERVER_DATA.Name  = Name;
		SERVER_DATA.IP    =   IP;
		SERVER_DATA.Port  = Port;
		SERVER_DATA.Using = true;
	}
	
	
	
	//////////////////////////////////////////////////////////////////////////////////
	const char* SERVER::Set()													    //
	{
		if(SERVER_DATA.Using == true)
			Set(SERVER_DATA.Name, SERVER_DATA.IP, SERVER_DATA.Port);	
		else 
			return MESSAGE_ERROR_SETDATA;
	}
	
	
	
	//////////////////////////////////////////////////////////////////////////////////
	const char* SERVER::Set(const char *Name, const char* IP, unsigned __int8 Port) //
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
		
		
		
		//////////////////////////////////////////////////////////////////////////
		//																	    //		
		//  Establishing a socket connection and accepting initial parameters   //	
		//						    from the client							    //
		//																	    //	
		//////////////////////////////////////////////////////////////////////////
																			  
		SOCKET new_connection;	                                                
		
		while(proceed)                                                             
		{	
			L_IgnoringConnect:
				
			if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR)))  
			{																	   
				if(recv(new_connection, szMsg, sizeof(szMsg), 0))
				{
					for(__int64 cnt = 0; cnt < quantity_compound; cnt++)
						if(strcmp(User[cnt].Name, szMsg) == 0)
						{	
							send(new_connection, MESSAGE_ERROR_NAME, 
							strlen(MESSAGE_ERROR_NAME), 0);	
							strcpy(szMsg, szEmpty);
							
							goto L_IgnoringConnect;
						}
									
					USER_TEMPLATE.compound = new_connection;					
					USER_TEMPLATE.Name     =          szMsg;				
					
					send(new_connection, MESSAGE_CSP, 
					strlen(MESSAGE_CSP), 0);
				}
				
				CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 		 
				(LPVOID)(++quantity_compound), 0, 0);	 						  
																				   
																				    
				User.push(USER_TEMPLATE);										   
				strcpy(szMsg, szEmpty);											   
			}																	    
		}																	    
		
		if(proceed == false)
			return MESSAGE_DS;
		
		//////////////////////////////////////////////////////////////////////////	
																   
	}
}
