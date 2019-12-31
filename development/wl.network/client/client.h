#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\development\\wl.network\\global\\global.h"
using namespace global;

namespace wl_network
{
	class CLIENT
	{
	private:
		
		SOCKET compound;
		
	public:

		bool JoinServer(const char *IP, unsigned __int8 port);	
		
		void SendMessage(const char *Message);
		char* GetLastMessage();
	};
} 
