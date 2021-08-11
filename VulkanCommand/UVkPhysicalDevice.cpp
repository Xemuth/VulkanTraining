#include "UVkPhysicalDevice.h"

namespace Upp{
UVkPhysicalDevice::UVkPhysicalDevice(const VkPhysicalDevice& device): m_device(device){}

VkPhysicalDeviceMemoryProperties UVkPhysicalDevice::GetPhysicalDeviceMemoryProperties(){
	VkPhysicalDeviceMemoryProperties pdmp;
	vkGetPhysicalDeviceMemoryProperties(m_device, &pdmp);
	return pdmp;
}

Array<VkQueueFamilyProperties> UVkPhysicalDevice::GetPhysicalDeviceQueueFamilyProperties(){
	unsigned int queueCount = 0;
	Array<VkQueueFamilyProperties> data;
	vkGetPhysicalDeviceQueueFamilyProperties(m_device, &queueCount, nullptr);
	VkQueueFamilyProperties* pdqfp = new VkQueueFamilyProperties[queueCount];
	vkGetPhysicalDeviceQueueFamilyProperties(m_device, &queueCount, pdqfp);
	for(int e = 0; e < queueCount; e++){
		data.Create(pdqfp[e]);
	}
	delete[] pdqfp;
	return data;
}

VkPhysicalDeviceProperties UVkPhysicalDevice::GetPhysicalDeviceProperties(){
	VkPhysicalDeviceProperties pdp;
	vkGetPhysicalDeviceProperties(m_device, &pdp);
	return pdp;
}

VkPhysicalDeviceFeatures UVkPhysicalDevice::GetPhysicalDeviceFeatures(){
	VkPhysicalDeviceFeatures pdf;
	vkGetPhysicalDeviceFeatures(m_device, &pdf);
	return pdf;
}
}