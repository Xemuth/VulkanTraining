#include "UVkPhysicalDevice.h"

namespace Upp{
UVkPhysicalDevice::UVkPhysicalDevice(const VkPhysicalDevice& device): m_device(device){}

VkPhysicalDeviceMemoryProperties UVkPhysicalDevice::GetPhysicalDeviceMemoryProperties(){
	VkPhysicalDeviceMemoryProperties pdmp;
	vkGetPhysicalDeviceMemoryProperties(m_device, &pdmp);
	return pdmp;
}

VkPhysicalDevice UVkPhysicalDevice::GetPhysicalDevice(){return m_device;}

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

Array<VkSparseImageFormatProperties> UVkPhysicalDevice::GetPhysicalDeviceSparseImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkSampleCountFlagBits& samples, const VkImageUsageFlags& usage, const VkImageTiling& tiling){
	unsigned int propertyCount = 0;
	Array<VkSparseImageFormatProperties> data;
	vkGetPhysicalDeviceSparseImageFormatProperties(m_device, format, type, samples, usage, tiling, &propertyCount, nullptr);
	VkSparseImageFormatProperties* sifp = new VkSparseImageFormatProperties[propertyCount];
	vkGetPhysicalDeviceSparseImageFormatProperties(m_device, format, type, samples, usage, tiling, &propertyCount, sifp);
	for(int e = 0; e < propertyCount; e++){
		data.Create(sifp[e]);
	}
	delete[] sifp;
	return data;
}

VkImageFormatProperties UVkPhysicalDevice::GetPhysicalDeviceImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkImageTiling& tiling, const VkImageUsageFlags& usage, const VkImageCreateFlags& flags){
	VkImageFormatProperties ifp;
	VkResult vkResult = vkGetPhysicalDeviceImageFormatProperties(m_device, format, type, tiling, usage, flags, &ifp);
	ASSERT_(vkResult == VK_SUCCESS, "Can't retrieve VkImageFormatProperties");
	return ifp;
}

}