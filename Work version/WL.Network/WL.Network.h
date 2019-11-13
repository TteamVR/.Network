#include <winsock2.h>

#include "List/List.h"

namespace WL_NETWORK
{
	namespace _SERVER
	{
		struct USER
		{
			SOCKET compound;
			char   	 IP[16];
			char  	  *Name;	
		};		
		
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
	
	
	namespace _CLIENT
	{
		class CLIENT
		{
			private:
				
				SOCKET compound;
				char 	  *Name;
							
			public: 
				
				CLIENT();
				CLIENT(const char *Name);
				
			 	void Rename(const char *Name);
			 	
				const char *ConnectToServer(const char *IP, unsigned __int8 Port);
				
				char* GetMessage();
				void SendMessage();  
		};	
	}

}
