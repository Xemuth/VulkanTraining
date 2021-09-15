#include <Core/Core.h>
#include "UVkApp.h"
#include "UVkCustomAllocator.h"
#include "VulkanToString.h"
using namespace Upp;

struct QueueFamily{
	One<unsigned int> graphicsFamily;
	
	bool isComplete(){
		return !graphicsFamily.IsEmpty();
	}
	
};

UVkPhysicalDevice& pickPhysicalDevice(UVkApp& app);
int IsPhysicalDeviceSuitable(UVkPhysicalDevice& physicalDevice);
QueueFamily findQueueFamilies(UVkPhysicalDevice& physicalDevice);

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
	UVkPhysicalDevice& pdToUse = pickPhysicalDevice(app);
/*
	QueueFamily queues = findQueueFamilies(pdToUse);

	VkDeviceCreateInfo deviceInfo{};
	deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	deviceInfo.pNext = nullptr;
	deviceInfo.flags = 0;
	
	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.pNext = nullptr;
	queueCreateInfo.flags = 0;
	queueCreateInfo.queueFamilyIndex = queues.graphicsFamily;
	queueCreateInfo.queueCount = 1;
	float queuesPrio[1] = {1.0f};
	queueCreateInfo.pQueuePriorities = queuesPrio;
	
	deviceInfo.queueCreateInfoCount = 1;
	deviceInfo.pQueueCreateInfos = &queueCreateInfo;
	deviceInfo.enabledLayerCount = 0;
	deviceInfo.ppEnabledLayerNames = nullptr;
	deviceInfo.enabledExtensionCount = 0;
	deviceInfo.ppEnabledExtensionNames = nullptr;
	VkPhysicalDeviceFeatures pdf = pdToUse.GetPhysicalDeviceFeatures();
	deviceInfo.pEnabledFeatures = &pdf;
	
	UVkDevice device = app.CreateDevice(pdToUse, deviceInfo);*/
}


UVkPhysicalDevice& pickPhysicalDevice(UVkApp& app){
	ASSERT_(app.GetPhysicalDevice().GetCount() > 0, "No device compatible with Vulkan");
	int score = 0;
	int buffer = 0;
	UVkPhysicalDevice* ptr = nullptr;
	for(UVkPhysicalDevice& device : app.GetPhysicalDevice()){
		if(buffer = IsPhysicalDeviceSuitable(device) > score){
			score = buffer;
			ptr = &device;
		}
	}
	ASSERT_(ptr,"No device complies with Vulkan requirement");
	return *ptr;
}

int IsPhysicalDeviceSuitable(UVkPhysicalDevice& physicalDevice){
	QueueFamily queue = findQueueFamilies(physicalDevice);
	if(!queue.isComplete())
		return 0;
	
	VkPhysicalDeviceProperties properties = physicalDevice.GetPhysicalDeviceProperties();
	VkPhysicalDeviceFeatures features = physicalDevice.GetPhysicalDeviceFeatures();
	int score = 0;
	if(properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU){
		score += 1000;
	}
	score+= properties.limits.maxImageDimension2D;
	if(!features.geometryShader){
		return 0;
	}

	return score;
}

QueueFamily findQueueFamilies(UVkPhysicalDevice& physicalDevice){
	QueueFamily queues;
	Array<VkQueueFamilyProperties> allQueues = pick(physicalDevice.GetPhysicalDeviceQueueFamilyProperties());
	for(unsigned int i = 0; i < allQueues.GetCount(); i++){
		if(allQueues[i].queueFlags & VK_QUEUE_GRAPHICS_BIT){
			queues.graphicsFamily.operator=(i);
		}
		if(queues.isComplete()) break;
	}
}