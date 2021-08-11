#include <Core/Core.h>
#include <vulkan/vulkan.h>
#include "VulkanToString.h"
#include "VkMemoryManager.h"
//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw.h>
/*
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <plugin/glm/vec4.hpp>
#include <plugin/glm/mat4x4.hpp>
*/
using namespace Upp;

CONSOLE_APP_MAIN
{
	VkMemoryManager memory(5);
	
	//Creating instance
	VkApplicationInfo vkAppInfo{
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		nullptr,
		"MyFirstVulkanApp",
		1,
		"UltimateVulkan",
		1,
		VK_API_VERSION_1_0
	};
	VkInstanceCreateInfo vkInstanceCreate{
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		nullptr,
		0,
		&vkAppInfo,
		0,
		nullptr,
		0,
		nullptr
	};
	
	VkInstance instance;
	VkDevice device;
	VkAllocationCallbacks callback = memory;
	VkResult vkResult = vkCreateInstance(&vkInstanceCreate,&callback,&instance);
	if(vkResult != VK_SUCCESS){
		Cout() << "Can't create Vulkan instance" << EOL;
		Exit(-1);
	}
	
//Vulkan Physical Devices
	//Retrieving each devices
	unsigned int deviceCount = 0;
	vkResult = vkEnumeratePhysicalDevices(instance,&deviceCount, nullptr);
	if(vkResult == VK_SUCCESS){
		VkPhysicalDevice* physicalsDevices = new VkPhysicalDevice[deviceCount];
		vkResult = vkEnumeratePhysicalDevices(instance,&deviceCount, physicalsDevices);
		if(vkResult == VK_SUCCESS){
			VkPhysicalDeviceFeatures features;
			for(int i = 0; i < deviceCount; i++){
				//Retrieving properties of this device
				VkPhysicalDeviceProperties properties;
				vkGetPhysicalDeviceProperties(physicalsDevices[i],&properties);
				Cout() << ToStringPhysicalDeviceProperties(properties);
				
				//Retrieving features of this device
				vkGetPhysicalDeviceFeatures(physicalsDevices[i], &features);
				Cout() << ToStringPhysicalDeviceFeatures(features,1);
				
				//Retrieving memory type of device
				VkPhysicalDeviceMemoryProperties memories;
				vkGetPhysicalDeviceMemoryProperties(physicalsDevices[i], &memories);
				Cout() << ToStringPhysicalDeviceMemoryProperties(memories,1);
				
				unsigned int propertyCount = 0;
				vkGetPhysicalDeviceQueueFamilyProperties(physicalsDevices[i], &propertyCount, nullptr);
				VkQueueFamilyProperties* deviceProperties = new VkQueueFamilyProperties[propertyCount];
				vkGetPhysicalDeviceQueueFamilyProperties(physicalsDevices[i], &propertyCount, deviceProperties);
				for(int e = 0; e < propertyCount; e++){
					Cout() << ToStringQueueFamilyProperties(deviceProperties[e],2);
				}
				delete[] deviceProperties;
				
				Cout() << "------------------------------------------\n";
			}
			
			//Creation of logical device
			if(deviceCount > 0){
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
				deviceInfo.pEnabledFeatures = &features;
				
				vkCreateDevice(physicalsDevices[0], &deviceInfo, nullptr, &device);
			}
		}
		delete[] physicalsDevices;
	}

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    Cout() << extensionCount << " extensions supported\n";


	static const VkBufferCreateInfo bufferdef ={VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, nullptr, 0, 1024 * 1024, VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VK_SHARING_MODE_EXCLUSIVE, 0, nullptr};
	VkBuffer buffer = VK_NULL_HANDLE;
	vkCreateBuffer(device, &bufferdef, &callback, &buffer);
	
	VkImage image = VK_NULL_HANDLE;
	VkResult result = VK_SUCCESS;
	static const VkImageCreateInfo imageCreateInfo ={
		VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
		nullptr,
		0,
		VK_IMAGE_TYPE_2D,
		VK_FORMAT_R8G8B8A8_UNORM,	
		{1024, 1024, 1},
		10,
		1,
		VK_SAMPLE_COUNT_1_BIT,
		VK_IMAGE_TILING_OPTIMAL,
		VK_IMAGE_USAGE_SAMPLED_BIT,
		VK_SHARING_MODE_EXCLUSIVE,
		0,
		nullptr,
		VK_IMAGE_LAYOUT_UNDEFINED
	};
	result = vkCreateImage(device, &imageCreateInfo, nullptr, &image);
	
	
	VkMemoryAllocateFlagsInfo allocateInfo;
	
	//vkAllocateMemory(device,  &allocateInfo, )
}

