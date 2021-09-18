#include <Core/Core.h>
#include "UVKengine.h"
using namespace Upp;


CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_TIMESTAMP | LOG_FILE );
	ConfigureVulkanDebugMessenger(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT);
	
	UVKapp app;
#if defined(_DEBUG)
	app.EnableValidationLayers(true);
#endif
	app.Create(true);
}
		