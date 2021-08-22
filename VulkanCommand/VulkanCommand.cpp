#include <Core/Core.h>
#include "UVkApp.h"
#include "UVkCustomAllocator.h"
#include "VulkanToString.h"
using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_FILE);
//	UVkCustomAllocator allocator;
//	VkAllocationCallbacks allocationCallback = allocator.GetAllocationCallbacks();
	
//	UVkApp app(&allocator);
	UVkApp app;
	//ASSERT_( UVkCustomAllocator::leakTracker.GetCount() == 0, "Many allocation have not been freed");
	
	Array<UVkPhysicalDevice>& devices = app.GetPhysicalDevice();
	LOG("Devices counts : " + AsString( devices.GetCount()));
	UVkPhysicalDevice* pdToUse = nullptr;
	
	
	for(UVkPhysicalDevice& pd : devices){
		if(Upp::String(pd.GetPhysicalDeviceProperties().deviceName).Find("NVIDIA") != -1){
			pdToUse = &pd;
			break;
		}
	}
	if(pdToUse){
		VkDeviceCreateInfo deviceInfo{};
		deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		deviceInfo.pNext = nullptr;
		deviceInfo.flags = 0;
		
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.pNext = nullptr;
		queueCreateInfo.flags = 0;
		queueCreateInfo.queueFamilyIndex = 0;
		queueCreateInfo.queueCount = 2;
		float queuesPrio[2] = {1.0f, 0.5f};
		queueCreateInfo.pQueuePriorities = queuesPrio;
		
		deviceInfo.queueCreateInfoCount = 1;
		deviceInfo.pQueueCreateInfos = &queueCreateInfo;
		deviceInfo.enabledLayerCount = 0;
		deviceInfo.ppEnabledLayerNames = nullptr;
		deviceInfo.enabledExtensionCount = 0;
		deviceInfo.ppEnabledExtensionNames = nullptr;
		VkPhysicalDeviceFeatures pdf = pdToUse->GetPhysicalDeviceFeatures();
		deviceInfo.pEnabledFeatures = &pdf;
		
		UVkDevice device = pdToUse->CreateDevice(deviceInfo);
	}
	
	vkDestroyInstance(app, nullptr);
}
