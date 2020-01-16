#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\main_development\\wl.network\\global\\global.h"
using namespace global;

namespace wl_network
{
	//struct USER{SOCKET compound;};
	
	class SERVER
	{	
	private:
		
		/*List<USER> 	  User;
		USER USER_TEMPLATE; */
		
		const char 		  *IP;
		unsigned __int16 port;
	
	public: 
		
		SERVER(const char *IP, unsigned __int16 port);
		
		void Set(); 
	};
} 
