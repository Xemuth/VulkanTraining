#include "VulkanHelper.h"

namespace Upp{
VulkanHelper::VulkanHelper(){
	m_selector.AddValidationLayers("VK_LAYER_KHRONOS_validation");
	m_selector.AddDeviceExtensions(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
	m_selector.AddInstanceExtensions(VK_KHR_SURFACE_EXTENSION_NAME);
#if defined(WIN32)
	m_selector.AddInstanceExtensions(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#endif
	m_selector.AddInstanceExtensions(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
}
		
VkInstance VulkanHelper::GetInstance()const{
	return m_instance;
}
VkDebugUtilsMessengerEXT VulkanHelper::GetDebugMessenger()const{
	return m_debugMessenger;
}
VkDevice VulkanHelper::GetDevice()const{
	return m_device;
}

VkInstance VulkanHelper::CreateInstance(){
	if(m_instance == VK_NULL_HANDLE){
		//	VkInstanceCreateInfo struct
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pNext = nullptr;
		
		//	VkApplicationInfo struct
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = ~appName;
		appInfo.applicationVersion = UVK_ENGINE_VERSION_0_1;
		appInfo.pEngineName = UVK_ENGINE_NAME;
		appInfo.engineVersion = UVK_ENGINE_VERSION_0_1;
		appInfo.apiVersion = VK_API_VERSION_1_2;
		createInfo.pApplicationInfo = &appInfo;
		
		//	Code to fill layers here
		createInfo.enabledLayerCount = m_selector.GetValidationsLayersCount();
		createInfo.ppEnabledLayerNames = m_selector.GetValidationsLayers();
		
		//	Code to fill extensions here
		createInfo.enabledExtensionCount = m_selector.GetInstanceExtensionsCount();
		createInfo.ppEnabledExtensionNames = m_selector.GetInstanceExtensions();
		
		VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);
		if(result == VK_SUCCESS){
			if(m_instance == VK_NULL_HANDLE){
				throw Exc("Vulkan instance is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
			}else{
				LLOG("[VulkanHelper::CreateInstance][INFO] Vulkan instance have been created (handler=" + AsString((int*)m_instance) + ")");
				CHECK_NOT_NULL_HANDLER(m_instance);
				return m_instance;
			}
		}else{
			throw Exc("Vulkan instance creation failled");
		}
	}
	throw Exc("VulkanHelper instance is already create. You must clear it before recreating it");
}
VkDebugUtilsMessengerEXT VulkanHelper::CreateDebugMessenger(){
	CHECK_HANDLER(m_instance)
	CHECK_NOT_NULL_HANDLER(m_debugMessenger);
	
	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	
    createInfo.pfnUserCallback = m_debugCallback;
    createInfo.pUserData = nullptr;
    PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_instance, "vkCreateDebugUtilsMessengerEXT");
    
	if(func != nullptr){
		VkResult result = VK_ERROR_DEVICE_LOST
		result = func(m_instance, &createInfo, AllocatorNullPtr, m_debugMessenger);
		if(result == VK_SUCCESS)
			LLOG("[VulkanHelper::CreateDebugMessenger][INFO] Debug Utils Messenger have been created (handler=" + AsString((int*)m_debugMessenger) + ")");
			CHECK_NOT_NULL_HANDLER(m_debugMessenger);
			return m_debugMessenger;
		}else{
			throw Exc("Messenger creation have failled");
		}
	}
	throw Exc("Impossible to querry vkCreateDebugUtilsMessengerEXT function");
}

VkDevice VulkanHelper::CreateDevice(Upp::String& phyiscalDeviceName = ""){
	
}
void VulkanHelper::SetMessengerCallback(Function<void ( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)>){
	
}
VulkanSelector& VulkanHelper::GetSelector(){
	
}
}
