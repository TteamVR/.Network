#include "C:\\Users\\admin\\Desktop\\C++\\Socket-s\\WinLego-Network\\main_development\\wl.network\\global\\global.h"
using namespace global;

namespace wl_network
{
	class CLIENT
	{
	public: 
			
		unsigned int NewMessage;
		
	private:
		
		SOCKET compound;
		
	public:

		bool JoinServer(const char *IP, unsigned __int16 port);	
		
		void SendMessage(const char *Message);
		char* GetLastMessage();
	};
} 
