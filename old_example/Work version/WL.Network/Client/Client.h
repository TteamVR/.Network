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
		
			int SendMessage(const char *Message, const char *Recipient);  
			int GetMessage(char *Message, char *Sender, unsigned __int64 *Time);
			
			void SendMessage(const char *Message);
			char* GetLastMessage(char *Message);
	};	
	
}
