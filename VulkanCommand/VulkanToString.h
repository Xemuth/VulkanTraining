#ifndef _cube_VulkanToString_h_
#define _cube_VulkanToString_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif
namespace Upp{
Upp::String ToStringPhysicalDeviceMemoryProperties(const VkPhysicalDeviceMemoryProperties& vkPDMP, int numTab = 0);
Upp::String ToStringMemoryType(const VkMemoryType& memoryType, int numTab = 0);
Upp::String ToStringMemoryHeap(const VkMemoryHeap& memoryHeap, int numTab = 0);
Upp::String ToStringPhysicalDeviceFeatures(const VkPhysicalDeviceFeatures& vkPDF, int numTab = 0);
Upp::String ToStringPhysicalDeviceProperties(const VkPhysicalDeviceProperties& vkPDP, int numTab = 0);
Upp::String ToStringQueueFamilyProperties(const VkQueueFamilyProperties& vkQFP, int numTab = 0);
Upp::String ToStringExtent3D (const VkExtent3D& vkE3D, int numTab = 0);
}


#endif
