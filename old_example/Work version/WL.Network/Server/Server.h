#include "C:\Users\admin\Desktop\C++\Socket-s\WinLego-Network\Work version\WL.Network\Global\Global.h"

namespace WL_NETWORK
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
			const char *LastMessage;
			bool 		 	  Using;
			
		}SERVER_DATA;
		
		char   szMsg[1024];
		char szStatus[256];

		List<USER> 	  User;
		USER USER_TEMPLATE;
	
	public: 
		
		SERVER();
		SERVER(const char *Name, const char* IP, unsigned __int8 Port);
		
		const char* GetStatus();
		
		void SetData(const char *Name, const char* IP, unsigned __int8 Port);
	
		const char* Set();	
	};
	
}
	
