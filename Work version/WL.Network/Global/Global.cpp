#include "Global.h"

namespace WL_NETWORK
{ 
	namespace Sysetm_CM
	{
		const char *COMMAND_UDC 		  = "USER_DISABLE_COMMAND";  
		
		const char *MESSAGE_CSP           = "CONNECTIONS_SUCCESSFULLY_PERFORMED";
		const char *MESSAGE_SC            = "SUCCESSFULLY_COMPLETED";
		const char *MESSAGE_DS            = "SERVER_WAS_SUCCESSFULLY_REMOVED";	
		const char *MESSAGE_ERROR_CTS     = "SERVER CONNECTION ERROR: POSSIBLE AT THIS MOMENT THE SERVER IS DISABLED";	
		const char *MESSAGE_ERROR_NAME    = "NAME ERROR: NAME IS NOT UNIQUE";
		const char *MESSAGE_ERROR_SETDATA = "DATA SETUP ERROR: YOU DID NOT INSTALL DATA TO INSTALL DATA FOR THE SERVER USE THE FUNCTION 'SetData'";
		const char *MESSAGE_ERROR_SETNAME = "SETNAME ERROR: YOU HAVE NOT SPECIFIED YOUR NAME TO SPECIFY IT TO, USE THE FUNCTION 'Rename'";
	}
	
	namespace CONSTANTS 
	{
		namespace ASCII { const char SPACE = 32; }
		
		const char NEXT    				     = '|'; 
		const __int8 NULLPtR 			     =   0;
		const unsigned __int16 MESSAGE_SIZE = 1024;
	}
	
	char  szEmpty[1024];
	const int PAUSE = 1;
}
