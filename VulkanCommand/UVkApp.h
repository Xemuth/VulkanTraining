#ifndef _VulkanCommand_VkApp_h_
#define _VulkanCommand_VkApp_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif
#include "UVkPhysicalDevice.h"
#include "UVkCustomAllocator.h"
namespace Upp{

class UVkApp{
	public:
		UVkApp(UVkCustomAllocator* customAllocator= nullptr);
		UVkApp(const VkInstanceCreateInfo& instanceCreateInfo, UVkCustomAllocator* customAllocator = nullptr);
		
		Array<UVkPhysicalDevice>& GetPhysicalDevice(bool forceRetrieve = false);
		
		VkInstance GetInstance();
		inline operator VkInstance(){return m_instance;}
	private:
		void CreateInstance(const VkInstanceCreateInfo& instanceCreateInfo);
		UVkCustomAllocator* m_customAllocator = nullptr;
		VkInstance m_instance;
		Array<UVkPhysicalDevice> m_phDevices;
};

}
#endif
