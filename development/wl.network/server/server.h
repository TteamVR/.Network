#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\development\\wl.network\\global\\global.h"
using namespace global;

namespace wl_network
{
	struct USER{SOCKET compound;};
	
	class SERVER
	{	
	private:
		
		List<USER> User;
		USER USER_TEMPLATE; 
		
		const char 		 *IP;
		unsigned __int8 port;
	
	public: 
		
		SERVER(const char *IP, unsigned __int8 port);
		
		void Set(); 
	};
} 
