#include "UVkApp.h"


namespace Upp{
UVkApp::UVkApp(UVkCustomAllocator* customAllocator) : m_customAllocator(customAllocator){
	VkApplicationInfo vkAppInfo{VK_STRUCTURE_TYPE_APPLICATION_INFO,	nullptr, "UVulkanApp", 1, "UltimateVulkan", 1, VK_API_VERSION_1_0};
	VkInstanceCreateInfo vkInstanceCreate{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, nullptr, 0, &vkAppInfo, 0, nullptr, 0, nullptr};
	CreateInstance(vkInstanceCreate);
}
UVkApp::UVkApp(const VkInstanceCreateInfo& instanceCreateInfo, UVkCustomAllocator* customAllocator) : m_customAllocator(customAllocator){
	CreateInstance(instanceCreateInfo);
}

void UVkApp::CreateInstance(const VkInstanceCreateInfo& instanceCreateInfo){
	VkResult vkResult;
	if(m_customAllocator){
		VkAllocationCallbacks allocator = m_customAllocator->GetAllocationCallbacks();
		vkResult= vkCreateInstance(&instanceCreateInfo, &allocator, &m_instance);
	}else{
		vkResult = vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance);
	}
	ASSERT_(vkResult == VK_SUCCESS, "Impossible to initialize Vulkan");
}
Array<UVkPhysicalDevice>& UVkApp::GetPhysicalDevice(bool forceRetrieve){
	if(forceRetrieve || m_phDevices.GetCount() == 0){
		m_phDevices.Clear();
		unsigned int devicesCount = 0;
		VkResult vkResult = vkEnumeratePhysicalDevices(m_instance,&devicesCount, nullptr);
		ASSERT_(vkResult == VK_SUCCESS, "Can't retrieve physical devices count");
		VkPhysicalDevice* physicalsDevices = new VkPhysicalDevice[devicesCount];
		vkResult = vkEnumeratePhysicalDevices(m_instance, &devicesCount, physicalsDevices);
		ASSERT_(vkResult == VK_SUCCESS, "Can't retrieve physical devices");
		for(int e = 0; e < devicesCount; e++){
			m_phDevices.Create(physicalsDevices[e]);
		}
		delete[] physicalsDevices;
	}
	return m_phDevices;
}
VkInstance UVkApp::GetInstance(){return m_instance;}
}