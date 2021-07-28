#ifndef _cube_VulkanToString_h_
#define _cube_VulkanToString_h_

#include <Core/Core.h>
#include <vulkan/vulkan.h>

Upp::String ToStringPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties& vkPDMP, int numTab = 0);
Upp::String ToStringMemoryType(VkMemoryType& memoryType, int numTab = 0);
Upp::String ToStringMemoryHeap(VkMemoryHeap& memoryHeap, int numTab = 0);
Upp::String ToStringPhysicalDeviceFeatures(VkPhysicalDeviceFeatures& vkPDF, int numTab = 0);
Upp::String ToStringPhysicalDeviceProperties(VkPhysicalDeviceProperties& vkPDP, int numTab = 0);
Upp::String ToStringQueueFamilyProperties(VkQueueFamilyProperties& vkQFP, int numTab = 0);
Upp::String ToStringExtent3D (VkExtent3D& vkE3D, int numTab = 0);



#endif
