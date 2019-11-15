#include "C:\Users\admin\Desktop\C++\Socket-s\WinLego-Network\Work version\WL.Network\Global\Global.h"

namespace WL_NETWORK	
{
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
