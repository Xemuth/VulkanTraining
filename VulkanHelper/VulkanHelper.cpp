#include "VulkanHelper.h"

#define LLOG(x) LOG(x)

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

VulkanHelper::~VulkanHelper(){
	if(m_debugMessenger){
		ClearDebugMessenger();
	}
	if(m_device != VK_NULL_HANDLE){
		ClearDevice();
	}
	if(m_instance != VK_NULL_HANDLE){
		ClearInstance();
	}
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

bool VulkanHelper::AutoSelectPhysicalDevice(){
	
	//PhysicalDeviceSelector selector;
	//m_physicalDevice = selector(*this);
	return (m_physicalDevice != VK_NULL_HANDLE);
}

bool VulkanHelper::SelectPhysicalDevice(PhysicalDeviceSelector& selector){
	CHECK_HANDLER(m_instance);
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, physicalDevices);
			int scoreMax = 0;
			int position = -1;
			CurrentPhysicalDeviceData datas;
			for(int i = 0; i < physicalDeviceNumber; i++){
				datas.m_current = physicalDevices[i];
			    vkGetPhysicalDeviceProperties(datas.m_current, &datas.m_deviceProperties);
			    vkGetPhysicalDeviceFeatures(datas.m_current, &datas.m_deviceFeatures);
				int score = selector(datas);
				if(score == -1){
					LLOG("[VulkanHelper::SelectPhysicalDevice][INFO] Physical device " + String(datas.m_deviceProperties.deviceName) + " don't fit criteria of PhysicalDeviceSelector and have been discarded");
					continue;
				}
				LLOG("[VulkanHelper::SelectPhysicalDevice][INFO] Physical device " + String(datas.m_deviceProperties.deviceName) + " fit criteria with a score of " + AsString(score));
				if(score > scoreMax){
					LLOG("[VulkanHelper::SelectPhysicalDevice][INFO] Physical device " + String(datas.m_deviceProperties.deviceName) + " is now the best device with a score of " + AsString(score));
					scoreMax = score;
					position = i;
				}
			}
			if(position != -1){
				LLOG("[VulkanHelper::operator()][INFO] Physical device chosen is " + String(datas.m_deviceProperties.deviceName));
				m_physicalDevice =  physicalDevices[position];
				CHECK_HANDLER(m_physicalDevice);
				return (m_physicalDevice != VK_NULL_HANDLE);
			}else{
				LLOG("[VulkanHelper::operator()][ERROR] No vulkan suitable physdical device have been found");
			}
		}else{
			LLOG("[VulkanHelper::operator()][ERROR] No vulkan physdical device have been found");
		}
	}else{
		LLOG("[VulkanHelper::operator()][ERROR] Impossible to querry physical device");
	}
	return false;;
}

bool VulkanHelper::SelectPhysicalDevice(Upp::String& name){
	//m_physicalDevice = GetPhysicalDevice(name);
	return (m_physicalDevice != VK_NULL_HANDLE);
}

VkInstance VulkanHelper::CreateInstance(Upp::String appname, unsigned long applicationVersion, Upp::String engineName, unsigned long engineVersion, unsigned long apiVersion){
	if(m_instance == VK_NULL_HANDLE){
		//	VkInstanceCreateInfo struct
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pNext = nullptr;
		
		//	VkApplicationInfo struct
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = ~appname;
		appInfo.applicationVersion = applicationVersion;
		appInfo.pEngineName = ~engineName;
		appInfo.engineVersion = engineVersion;
		appInfo.apiVersion = apiVersion;
		createInfo.pApplicationInfo = &appInfo;
		
		//	Code to fill layers here
		createInfo.enabledLayerCount = m_selector.GetValidationsLayersCount();
		Vector<const char*> validationLayers = m_selector.GetValidationsLayers();
		createInfo.ppEnabledLayerNames = validationLayers;
		
		//	Code to fill extensions here
		createInfo.enabledExtensionCount = m_selector.GetInstanceExtensionsCount();
		Vector<const char*> instanceExtensions = m_selector.GetInstanceExtensions();
		createInfo.ppEnabledExtensionNames = instanceExtensions;
		
		VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);
		if(result == VK_SUCCESS){
			if(m_instance == VK_NULL_HANDLE){
				throw Exc("Vulkan instance is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
			}else{
				LLOG("[VulkanHelper::CreateInstance][INFO] Vulkan instance have been created (handler=" + AsString((int*)m_instance) + ")");
				CHECK_HANDLER(m_instance);
				return m_instance;
			}
		}else{
			throw Exc("Vulkan instance creation failled");
		}
	}
	throw Exc("VulkanHelper instance is already create. You must clear it before recreating it");
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData){
	return (*((Function<VkBool32(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*, void*)>*)pUserData))(messageSeverity, messageType, pCallbackData, pUserData);
}

VkDebugUtilsMessengerEXT VulkanHelper::CreateDebugMessenger(){
	CHECK_HANDLER(m_instance)
	CHECK_NOT_USED_HANDLER(m_debugMessenger);
	
	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	
	createInfo.pfnUserCallback = debugCallback;

    createInfo.pUserData = nullptr;
    PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_instance, "vkCreateDebugUtilsMessengerEXT");
    
	if(func != nullptr){
		VkResult result = VK_ERROR_DEVICE_LOST;
		result = func(m_instance, &createInfo, AllocatorNullPtr, &m_debugMessenger);
		if(result == VK_SUCCESS){
			LLOG("[VulkanHelper::CreateDebugMessenger][INFO] Debug Utils Messenger have been created (handler=" + AsString((int*)m_debugMessenger) + ")");
			CHECK_HANDLER(m_debugMessenger);
			return m_debugMessenger;
		}else{
			throw Exc("Messenger creation have failled");
		}
	}
	throw Exc("Impossible to querry vkCreateDebugUtilsMessengerEXT function");
}

VkPhysicalDevice VulkanHelper::GetPhysicalDevice(Upp::String& phyiscalDeviceName){
	CHECK_HANDLER(m_instance);
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, physicalDevices);
			for(VkPhysicalDevice& physicalDevice : physicalDevices){
				VkPhysicalDeviceProperties properties;
				vkGetPhysicalDeviceProperties(physicalDevice, &properties);
				if(phyiscalDeviceName.IsEqual(properties.deviceName)) return physicalDevice;
			}
		}
		LLOG("[VulkanHelper::GetPhysicalDevice][ERROR] No vulkan physical device have been found");
		return VK_NULL_HANDLE;
	}else{
		LLOG("[VulkanHelper::GetPhysicalDevice][ERROR] Impossible to querry physical device");
		return VK_NULL_HANDLE;
	}
}


VkDevice VulkanHelper::CreateDevice(){
	CHECK_HANDLER(m_instance);
	CHECK_HANDLER(m_physicalDevice);
	//Querry physical device:
	
	
	
	//Querry queues position:
	
	/*
	QueueFamilyIndices indices = GetQueuePosition(physicalDevice, surface);
	ASSERT_(indices.isComplete() == true, "QueueFamilyIndices have null queue");
	
	Upp::Vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    Upp::Vector<unsigned int> uniqueQueueFamilies = {(unsigned int)indices.graphicsFamily};
    if(indices.graphicsFamily != indices.presentFamily) uniqueQueueFamilies.push_back((unsigned int)indices.presentFamily);

    float queuePriority = 1.0f;
    for (unsigned int queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }
		
	VkPhysicalDeviceFeatures deviceFeatures{};
	
	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pEnabledFeatures = &deviceFeatures;
	createInfo.queueCreateInfoCount = queueCreateInfos.GetCount();
	createInfo.pQueueCreateInfos = queueCreateInfos;
	
	
	createInfo.enabledExtensionCount = extessionsName.GetCount();
	Vector<const char*> extenssions = GetTemporaryCharPtr(extessionsName);
	createInfo.ppEnabledExtensionNames = extenssions;

	VkResult result = vkCreateDevice(physicalDevice, &createInfo, nullptr, &device);
	if(result == VK_SUCCESS){
		ASSERT_(device != VK_NULL_HANDLE, "Device is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
		LLOG("[VKCtrl::CreateDevice][INFO] Device successfully created (handle=" + AsString(device) + ")");
		return result;
	}else{
		LLOG("[VKCtrl::CreateDevice][ERROR] Error during creation of device");
		device = VK_NULL_HANDLE;
		return result;
	}*/
}

void VulkanHelper::ClearInstance(){
	CHECK_HANDLER(m_instance);
	vkDestroyInstance(m_instance,nullptr);
	LLOG("[VulkanHelper::ClearInstance][INFO] Vulkan instance successfully deleted (handler=" + AsString((int*)m_instance) + ")");
}

void VulkanHelper::ClearDebugMessenger(){
	CHECK_HANDLER(m_instance);
	CHECK_HANDLER(m_debugMessenger);
	PFN_vkDestroyDebugUtilsMessengerEXT func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_instance, "vkDestroyDebugUtilsMessengerEXT");
	if(func){
		func(m_instance, m_debugMessenger, nullptr);
		LLOG("[VulkanHelper::ClearDebugMessenger][INFO] Debug Utils Messenger successfully deleted (handler=" + AsString((int*)m_debugMessenger) +")");
		return;
	}
	LLOG("[VulkanHelper::ClearDebugMessenger][ERROR] Error, can't retrieve PFN_vkDestroyDebugUtilsMessengerEXT");
}

void VulkanHelper::ClearDevice(){
	CHECK_HANDLER(m_device);
	vkDestroyDevice(m_device, nullptr);
	LLOG("[VulkanHelper::ClearDevice][INFO] Device successfully deleted (handle=" + AsString(m_device) + ")");
}

void VulkanHelper::SetMessengerCallback(Function<VkBool32(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*, void*)>){
	
}
VulkanSelector& VulkanHelper::GetSelector(){
	return m_selector;
}
}
