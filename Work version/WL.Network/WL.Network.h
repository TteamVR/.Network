#include <winsock2.h>

#include "List/List.h"

namespace _SERVER
{
	class SERVER
	{
	private: 
		
		__int64 quantity_compound;
		char 		  szMsg[1024];
	
		struct USER
		{
			SOCKET compound;
			char   	 IP[16];
			char  	  *Name;	
		};	
	
		List<USER> 	  User;
		USER USER_TEMPLATE;
	
	public:
			
		bool Set(const char *Name, const char* IP, unsigned __int8 Port);
		unsigned __int64 Delete(bool Auto, const char* LastMessage);
	};
}

