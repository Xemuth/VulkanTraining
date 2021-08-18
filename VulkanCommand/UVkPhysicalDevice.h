#ifndef _VulkanCommand_VkPhysicalDevice_h_
#define _VulkanCommand_VkPhysicalDevice_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif
#include "UVkDevice.h"

namespace Upp{

class UVkPhysicalDevice{
	public:
		UVkPhysicalDevice(const VkPhysicalDevice& device);
		
		VkPhysicalDevice GetPhysicalDevice();
		inline operator VkPhysicalDevice();
		
		UVkDevice CreateDevice(const VkDeviceCreateInfo& createInfo);
		
		VkPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties()const;
		Array<VkQueueFamilyProperties> GetPhysicalDeviceQueueFamilyProperties()const;
		VkPhysicalDeviceProperties GetPhysicalDeviceProperties()const;
		VkPhysicalDeviceFeatures GetPhysicalDeviceFeatures()const;
		Array<VkSparseImageFormatProperties> GetPhysicalDeviceSparseImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkSampleCountFlagBits& samples, const VkImageUsageFlags& usage, const VkImageTiling& tiling)const;
		VkImageFormatProperties GetPhysicalDeviceImageFormatProperties(const VkFormat& format, const VkImageType& type, const VkImageTiling& tiling, const VkImageUsageFlags& usage, const VkImageCreateFlags& flags)const;
	
	private:
		VkPhysicalDevice m_device;
};

}
#endif
