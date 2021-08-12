#ifndef _VulkanCommand_VkPhysicalDevice_h_
#define _VulkanCommand_VkPhysicalDevice_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif

namespace Upp{

class UVkPhysicalDevice{
	public:
		UVkPhysicalDevice(const VkPhysicalDevice& device);
		
		VkPhysicalDevice GetPhysicalDevice();
		inline operator VkPhysicalDevice(){return m_device;}
		
		//TODO
		//UVkDevice CreateDevice();
		
		VkPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties();
		Array<VkQueueFamilyProperties> GetPhysicalDeviceQueueFamilyProperties();
		VkPhysicalDeviceProperties GetPhysicalDeviceProperties();
		VkPhysicalDeviceFeatures GetPhysicalDeviceFeatures();
		Array<VkSparseImageFormatProperties> GetPhysicalDeviceSparseImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkSampleCountFlagBits& samples, const VkImageUsageFlags& usage, const VkImageTiling& tiling);
		VkImageFormatProperties GetPhysicalDeviceImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkImageTiling& tiling, const VkImageUsageFlags& usage, const VkImageCreateFlags& flags);
	
	private:
		VkPhysicalDevice m_device;
};

}
#endif
