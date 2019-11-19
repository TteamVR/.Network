#include "C:\Users\admin\Desktop\C++\Socket-s\WinLego-Network\Work version\WL.Network\Global\Global.h"

namespace WL_NETWORK	
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
		 	
			const char* ConnectToServer(const char *IP, unsigned __int8 Port);
			
			bool GetMessage(char *Message, char *Sender, __int64 Time);
			bool SendMessage(const char *Message, const char *Recipient);  
	};	
	
}
