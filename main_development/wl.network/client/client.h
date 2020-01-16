#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\main_development\\wl.network\\global\\global.h"
using namespace global;

namespace wl_network
{
	class CLIENT
	{
	private:
		
		SOCKET compound;
		
	public:

		bool join_server(const char *IP, unsigned __int16 port);	
		
		void send_message(const char *message);
		char* get_last_message();
		
		unsigned int unread();	
	};
} 
