#include <winsock2.h>
#include <process.h>

#include "List/List.h"

namespace _SERVER
{
	class SERVER
	{
	private: 
		
		struct _SERVER_DATA
		{
			unsigned __int8    Port;
			const char 	   	    *IP;
			const char	   	  *Name;
			bool 		 	  Using;
			const char *LastMessage;
		}SERVER_DATA;
		
		__int64 quantity_compound;
		
		char 		  szMsg[1024];
		char        szStatus[256];
		
		bool 			  proceed;
		
		struct USER
		{
			SOCKET compound;
			char   	 IP[16];
			char  	  *Name;	
		};	
	
		List<USER> 	  User;
		USER USER_TEMPLATE;
	
	public: 
		
		SERVER();
		SERVER(const char *Name, const char* IP, unsigned __int8 Port);
		
		const char* GetStatus();
		
		void SetData(const char *Name, const char* IP, unsigned __int8 Port);
	
		const char* Set();	
		
		unsigned __int64 Delete(bool Auto, const char* LastMessage);
	};
	
	const char* SetServerToStream(SERVER *Server);
}

