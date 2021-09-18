#include <Core/Core.h>
#include "UVKengine.h"
using namespace Upp;


GUI_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_TIMESTAMP | LOG_FILE );
	ConfigureVulkanDebugMessenger(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT);
	TopWindow win;
	
	
	VKCtrl app;
#if defined(_DEBUG)
	app.EnableValidationLayers(true);
#endif
	app.Create(true);

	win.Add(app.HSizePos(10, 10).VSizePos(10, 10));
	win.Sizeable().Zoomable();
	win.Open();
	win.Run();
}
		