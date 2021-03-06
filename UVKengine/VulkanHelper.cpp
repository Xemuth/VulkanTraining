#include "VulkanHelper.h"

namespace Upp{
	
	
PhysicalDeviceSelector::operator()(VulkanHelper& helper){
	CHECK_HANDLER(helper.GetInstance());
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(helper.GetInstance(), &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(instance, &physicalDeviceNumber, physicalDevices);
			int scoreMax = 0;
			int position = -1;
			for(int i = 0; i < physicalDeviceNumber; i++){
				int score = QueryScore(physicalDevices[i], helper);
				if(score > scoreMax){
					scoreMax = score;
					position = i;
				}
			}
			if(position != -1){
				VkPhysicalDeviceProperties deviceProperties;
				vkGetPhysicalDeviceProperties(physicalDevices[position], &deviceProperties);
				LLOG("[PhysicalDeviceSelector::operator()][INFO] Physical device chosen is " + String(deviceProperties.deviceName));
				return physicalDevices[position];
			}else{
				LLOG("[PhysicalDeviceSelector::operator()][ERROR] No vulkan suitable physdical device have been found");
			}
		}else{
			LLOG("[PhysicalDeviceSelector::operator()][ERROR] No vulkan physdical device have been found");
		}
	}else{
		LLOG("[PhysicalDeviceSelector::operator()][ERROR] Impossible to querry physical device");
	}
	return VK_NULL_HANDLE;
}

PhysicalDeviceSelector::QueryScore(VkPhysicalDevice physicalDevice, VulkanHelper& helper){
	VkPhysicalDeviceProperties deviceProperties;
    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);
    vkGetPhysicalDeviceFeatures(physicalDevice, &deviceFeatures);
	unsigned int score = 0;
    // Discrete GPUs have a significant performance advantage
    if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
        score += 1000;
    }
    // Maximum possible size of textures affects graphics quality
    score += deviceProperties.limits.maxImageDimension2D;
    // Application can't function without geometry shaders
    if (!deviceFeatures.geometryShader) {
        return 0;
    }
	if(!checkDeviceExtensionSupport(physicalDevice, helper.GetSelector().GetDeviceExtensions())){
		return 0;
	}
    return score;
}

bool PhysicalDeviceSelector::checkDeviceExtensionSupport(VkPhysicalDevice& physicalDevice, const Vector<const char*>& extensionsRequired) {
    unsigned int extensionCount;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);
    Vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, availableExtensions);

	Index<String> requiredExtensions;
	for(const char* ptr : extensionsRequired){
		requiredExtensions.Add(ptr);
	}
	
    for (const auto& extension : availableExtensions) {
        requiredExtensions.RemoveKey(extension.extensionName);
    }

    return requiredExtensions.GetCount() == 0;
}



	
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

bool VulkanHelper::SelectPhysicalDevice(PhysicalDeviceSelector& selector){
	m_physicalDevice = selector(*this);
}

bool VulkanHelper::SelectPhysicalDevice(Upp::String& name){
	m_physicalDevice = GetPhysicalDevice(name);
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

VkPhysicalDevice VulkanHelper::GetPhysicalDevice(Upp::String& phyiscalDeviceName = ""){
	CHECK_HANDLER(m_instance);
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(m_instance, &physicalDeviceNumber, physicalDevices);
			for(VkPhysicalDevice& physicalDevice : physicalDevices){
				VkPhysicalDeviceProperties properties;
				result = vkGetPhysicalDeviceProperties(physicalDevice, &properties);
				ASSERT_(result == VK_SUCCESS, "[VulkanHelper::GetPhysicalDevice] Fatal error during vkGetPhysicalDeviceProperties");
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
void VulkanHelper::SetMessengerCallback(Function<void ( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)>){
	
}
VulkanSelector& VulkanHelper::GetSelector(){
	
}
}
