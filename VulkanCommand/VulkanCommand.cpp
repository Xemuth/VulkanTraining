#include <Core/Core.h>
#include "UVkApp.h"
#include "VulkanToString.h"
using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_FILE);
	UVkApp app;
	Array<UVkPhysicalDevice>& devices = app.GetPhysicalDevice();
	LOG("Devices counts : " + AsString( devices.GetCount()));
	for(UVkPhysicalDevice& pd : devices){
		//LOG(Upp::ToStringPhysicalDeviceMemoryProperties(pd.GetPhysicalDeviceMemoryProperties()));
		LOG(ToStringPhysicalDeviceProperties(pd.GetPhysicalDeviceProperties()));
		LOG("------------------------------");
	}
	
}
