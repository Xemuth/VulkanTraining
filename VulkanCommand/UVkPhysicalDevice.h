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
		
		VkPhysicalDevice GetDevice();
		inline operator VkPhysicalDevice(){return m_device;}
		
		VkPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties();
		Array<VkQueueFamilyProperties> GetPhysicalDeviceQueueFamilyProperties();
		VkPhysicalDeviceProperties GetPhysicalDeviceProperties();
		VkPhysicalDeviceFeatures GetPhysicalDeviceFeatures();
	private:
		VkPhysicalDevice m_device;
};

}
#endif
