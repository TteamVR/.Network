#include "Server.h"

namespace 
{
	List<WL_NETWORK::USER> 		  User; 
	bool 	    			   proceed;
	unsigned __int64 quantity_compound;
}


namespace WL_NETWORK
{
		//////////////////////////////////////////////////////////////////////////////////
		void MessageHandler(__int64 IndexCompounds)						 		  	    //
		{
			char    szMsg[1024];
			char Recipient[256];
			
			while(::proceed)
			{
				if(recv(::User[IndexCompounds].compound, szMsg, sizeof(szMsg), 0))
				{
					for(int cnt = 0; szMsg[cnt] != CONSTANTS::NEXT; cnt++)
					{
						Recipient[cnt] = szMsg[cnt]; 
						szMsg[cnt]	   = 	   ' ';
					}	
					
					for(int cnt = 0; cnt < ::quantity_compound; cnt++)
					{
						if(strcmp(::User[cnt].Name, Recipient) == 0)
						{
							send(::User[cnt].compound, szMsg, strlen(szMsg), 0);	
						}	
						else if(cnt == (::quantity_compound - 1)){} // write message in the file		
					}
				}
				
				Sleep(PAUSE);	
			}
		}	
		
		
		
		///////////////////////////////////////////////////////////////////////////////
		SERVER::SERVER()														   	 //
		{
			quantity_compound =     0;
			SERVER_DATA.Using = false;
			proceed           =  true;
			
			strcpy(szMsg,    szEmpty);	
			strcpy(szStatus, szEmpty);	
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
				while(proceed)                                                             	 //
				{																			 //
					L_IgnoringConnect:														 //
																							 //
					if((new_connection = accept(sListen, (SOCKADDR*)&addr, &nSizeOfADDR)))   //
					{																	   	 //
						if(recv(new_connection, szMsg, sizeof(szMsg), 0))			 		 //
						{																     //
							for(unsigned __int64 cnt = 0; cnt < quantity_compound; cnt++)    //
								if(strcmp(User[cnt].Name, szMsg) == 0)						 //
								{															 //
									send(new_connection, Sysetm_CM::MESSAGE_ERROR_NAME, 	 //
									strlen(Sysetm_CM::MESSAGE_ERROR_NAME), 0);				 //
																							 //
									strcpy(szMsg, szEmpty);									 //
																							 //
									goto L_IgnoringConnect;									 //
								}															 //
																						 	 //   	
							USER_TEMPLATE.compound = new_connection;					  	 //
							USER_TEMPLATE.Name     =          szMsg;						 //	
																							 //	
							CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MessageHandler, 		 //	 
							(LPVOID)(++quantity_compound), 0, 0);	 						 //	  
																							 //
																						     //	
							::quantity_compound = quantity_compound;						 //
																							 //	   													    
							User.push(USER_TEMPLATE);										 //		   
							::User.push(USER_TEMPLATE);										 //
																							 //
							strcpy(szMsg, szEmpty);											 //	
																							 //	
							send(new_connection, Sysetm_CM::MESSAGE_CSP, 					 //
							strlen(Sysetm_CM::MESSAGE_CSP), 0);								 //
																						 	 //	
						}											   					     //
					}																		 //
																							 // 
					Sleep(PAUSE);															 //
				}																	   		 //
																							 //
				if(proceed == false)														 //  
				{																			 //
					for(unsigned __int64 cnt = 0; cnt < quantity_compound; cnt++)			 //	
					{																		 // 		
						send(User[cnt].compound, szMsg, strlen(szMsg), 0);					 //			
						send(User[cnt].compound, Sysetm_CM::COMMAND_UDC, 					 //		
						strlen(Sysetm_CM::COMMAND_UDC), 0);									 //	
					}																		 //   	
																							 //	
					strcpy(szStatus, szEmpty);												 //	
					strcpy(szStatus, Sysetm_CM::MESSAGE_DS);						   		 //
																							 //
					return Sysetm_CM::MESSAGE_DS;											 //
				}																			 //
																							 //
				///////////////////////////////////////////////////////////////////////////////													   					 //
		
			}																			 
			else 																		 
			{																			 
				strcpy(szStatus, szEmpty);											     
				strcpy(szStatus, Sysetm_CM::MESSAGE_ERROR_SETDATA);						 
																						 
				return Sysetm_CM::MESSAGE_ERROR_SETDATA;								 
			}																			 
																						 
		}
		
		
		
		//////////////////////////////////////////////////////////////////////////////////
		unsigned __int64 SERVER::Delete(bool Auto, const char* LastMessage)				//
		{
			SERVER_DATA.LastMessage = LastMessage;
			proceed 				= 		false;
			::proceed               =     proceed;
		}
			
}
