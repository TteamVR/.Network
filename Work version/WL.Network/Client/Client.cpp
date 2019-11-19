#include "Client.h"

namespace
{
	using namespace WL_NETWORK;
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	int ParserMessage(char *sz, char *psz[])                                  	 //
	{
		
		int cnt    = 0,                                                         
		    cnt2   = 0,                                                         
		    cnt3   = 0,                                                         
		    cnt4   = 0,                                                         
		    answer = 0;
	
	L_02:   if(sz[0] == CONSTANTS::ASCII::SPACE)
		    {
		       sz++;
		       goto L_02;
		    }
				    
	L_01:   cnt     ++; 
		    cnt2 = cnt; 	
		    cnt3    ++;
		    
		    while(sz[cnt] != CONSTANTS::NEXT)                                     
		    {
			   		  
		  	   psz[cnt3][cnt - cnt2] = sz[cnt];  
			
			   cnt ++;
			   
			   if(sz[cnt] == 0) 
			   {
				  if(cnt < 3) return 0;	
				  answer ++;
				  psz[cnt3][cnt - cnt2] = 0;
				  return answer;				                                     
			   }
		    } 
		
		    psz[cnt3][cnt - cnt2] = 0;
	        answer ++;   
		    goto L_01;
	}	
}


namespace WL_NETWORK	
{
	
	///////////////////////////////////////////////////////////////////////////////
	CLIENT::CLIENT()															 //
	{
		char Name = CONSTANTS::NULLPtR;	
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	CLIENT::CLIENT(const char *Name)											 //
	{
		this -> Name = (char*)Name;
	}
	
	

	///////////////////////////////////////////////////////////////////////////////
	void CLIENT::Rename(const char *Name)										 //
	{
		this -> Name = (char*)Name;	
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	const char* CLIENT::ConnectToServer(const char *IP, unsigned __int8 Port)	 //
	{
		if(*Name != CONSTANTS::NULLPtR)
		{			
			///////////////////////////////////////////////////////////////
			//															 //
			//   Creating Sockets and Establishing a Server Connection   //
			//															 //
			///////////////////////////////////////////////////////////////
																		 //
			WSAData wsaData;											 //
			WORD DLLVersion = MAKEWORD(2, 1);							 //
			WSAStartup(DLLVersion, &wsaData); 							 //
																		 //
			SOCKADDR_IN addr;											 //
			int nSizeOfADDR      =  sizeof(addr);						 //
			addr.sin_addr.s_addr = inet_addr(IP);					  	 //
			addr.sin_port 		 = 	 htons(Port);						 //
			addr.sin_family 	 =       AF_INET; 			 		     //
																		 //
			compound = socket(AF_INET, SOCK_STREAM, 0);					 //
																		 //
			if(connect(compound, (SOCKADDR*)&addr, sizeof(addr)) != 0) 	 //
				return Sysetm_CM::MESSAGE_ERROR_CTS;    				 //
			else														 //
				send(compound, Name, strlen(Name), 0); 					 //
																		 //
			return Sysetm_CM::MESSAGE_CSP;								 //
			///////////////////////////////////////////////////////////////
		}
		else return Sysetm_CM::MESSAGE_ERROR_SETNAME;
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	bool CLIENT::GetMessage(char *Message, char *Sender, __int64 Time)			 //
	{
			
	}
	
	
	
	///////////////////////////////////////////////////////////////////////////////
	bool CLIENT::SendMessage(const char *Message, const char *Recipient)	     //	
	{
		char *szMsg[1024];
		wsprintf(szMsg, "%s|%s|%s|%s", Recipient, Name, Message, szTime);
	}
}








