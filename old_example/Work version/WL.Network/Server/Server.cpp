#include "Server.h"

namespace 
{
	List<WL_NETWORK::USER> 		  User; 
	bool 	    			   proceed;
}


namespace WL_NETWORK
{
	
		///////////////////////////////////////////////////////////////////////////////
		SERVER::SERVER()														   	 //
		{
			SERVER_DATA.Using = false;
			proceed           =  true;
			
			strcpy(szMsg,    szEmpty);	
			strcpy(szStatus, szEmpty);	
		}
		
		
	
		//////////////////////////////////////////////////////////////////////////////////
		SERVER::SERVER(const char *Name, const char* IP, unsigned __int8 Port)    	    //
		{
			SERVER_DATA.Using = false;
			proceed           =  true;
			
			SERVER_DATA.Name  =  Name;
			SERVER_DATA.IP    =    IP;
			SERVER_DATA.Port  =  Port;
			SERVER_DATA.Using =  true;
			
			strcpy(szMsg, szEmpty);	
			strcpy(szStatus, szEmpty);
		}
		
		
		
		//////////////////////////////////////////////////////////////////////////////////
		const char* SERVER::GetStatus()												    //
		{
			return szStatus;	
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
		void ClientHandler(int index) 									 		  	    //
		{
			char msg[256];
			while(true) 
			{	
				recv(::User[index].compound, msg, sizeof(msg), 0);
		
				for(int i = 0; i < ::User.size(); i++) 
				{
					if(i != index) send(::User[i].compound, msg, sizeof(msg), 0);
				}
			}		
		}
		
		
		//////////////////////////////////////////////////////////////////////////////////
		const char* SERVER::Set()					             					    //
		{
			if(SERVER_DATA.Using == true)
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
				int nSizeOfADDR      =              sizeof(addr);	//
				addr.sin_addr.s_addr = inet_addr(SERVER_DATA.IP);	//
				addr.sin_port 		 = 	 htons(SERVER_DATA.Port);	//
				addr.sin_family 	 =       			 AF_INET;   //
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
					new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR);

					if(new_connection != 0) 
					{
						char msg[256] = "Hello. It`s my first network program!";
						send(new_connection, msg, sizeof(msg), 0);
			
						USER_TEMPLATE.compound = new_connection;
																	
						CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(User.size()), 0, 0);
						
						User.push(USER_TEMPLATE);
						::User.push(USER_TEMPLATE);
						
					}								 
																							 // 
					Sleep(PAUSE);															 //
				}																	   		 //
																							 //
				///////////////////////////////////////////////////////////////////////////////													   					 //
		
			}																			 
																				 
		}
			
}
