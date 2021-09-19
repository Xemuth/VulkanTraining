#include "UVKengine.h"

#define LLOG(x) LOG(x)

namespace Upp{
	
static dword messageSeverityInfoLog = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
static dword messageTypeInfoLog = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;

void ConfigureVulkanDebugMessengerDefault(){
	messageSeverityInfoLog = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
	messageTypeInfoLog = VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
}

Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr){
	Vector<const char*> buffer;
	for(const Upp::String& str : vectorStr)
		buffer.Add(~str);
	return pick(buffer);
}

Vector<const char*> GetTemporaryCharPtr(const Upp::Index<Upp::String>& indexStr){
	Vector<const char*> buffer;
	for(const Upp::String& str : indexStr)
		buffer.Add(~str);
	return pick(buffer);
}

void ConfigureVulkanDebugMessenger(dword severityFilter,
								   dword typeFilter){
	messageSeverityInfoLog = severityFilter;
	messageTypeInfoLog = typeFilter;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData){
	Upp::String severity = "";
	if(messageSeverity & messageSeverityInfoLog && messageType & messageTypeInfoLog){
		if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
			severity += "[ERROR]";
		if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
			severity += "[WARNING]";
		if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT)
			severity += "[INFO]";
		if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT)
			severity += "[VERBOSE]";
		if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT)
			severity += "[PERFORMANCE]";
		if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT)
			severity += "[VALIDATION]";
		if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT)
			severity += "[GENERAL]";
		LLOG(severity + Upp::String(pCallbackData->pMessage));
	}
	return VK_FALSE;
}

VkResult CreateDebugUtilsMessengerEXT(VkInstance app, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator,VkDebugUtilsMessengerEXT* pDebugMessenger){
	PFN_vkCreateDebugUtilsMessengerEXT func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(app, "vkCreateDebugUtilsMessengerEXT");
	if(func != nullptr){
		return func(app, pCreateInfo, pAllocator, pDebugMessenger);
	}else{
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void DestroyDebugUtilsMEssengerEXT(VkInstance app, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator){
	PFN_vkDestroyDebugUtilsMessengerEXT func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(app, "vkDestroyDebugUtilsMessengerEXT");
	if(func != nullptr){
		func(app, debugMessenger, pAllocator);
	}
}

int GetQueuePosition(VkPhysicalDevice& physicalDevice, dword queue){
	unsigned int queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);
	Vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies);
	for(int i = 0; i < queueFamilyCount; i++){
		if (queueFamilies[i].queueFlags & queue){
			return i;
		}
	}
	return -1;
}

SwapChainSupportDetails QuerySwapchainDetails(VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface){
	SwapChainSupportDetails details;
	vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &details.Capabilities);
	
	unsigned int formatCount;
	vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, nullptr);
	if (formatCount != 0) {
	    details.Formats.SetCount(formatCount);
	    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, details.Formats);
	}
	
	unsigned int presentModeCount;
	vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, nullptr);
	if (presentModeCount != 0) {
	    details.PresentModes.SetCount(presentModeCount);
	    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, details.PresentModes);
	}
	
	return details;
}

bool checkValidationlayerExtensionSupport(const Index<String>& layerRequiered){
	unsigned int totalVlCount = 0;
	
	vkEnumerateInstanceLayerProperties(&totalVlCount, nullptr);
	Vector<VkLayerProperties> totalVl(totalVlCount);
	vkEnumerateInstanceLayerProperties(&totalVlCount, totalVl);
	
	Index<String> requiredLayer(clone(layerRequiered));
	
	for (const auto& layer : totalVl) {
        requiredLayer.RemoveKey(layer.layerName);
    }

    return requiredLayer.GetCount() == 0;
}

bool checkInstanceExtensionSupport(const Index<String>& extensionsRequired) {
    unsigned int extensionCount;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    Vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, availableExtensions);

	Index<String> requiredExtensions(clone(extensionsRequired));
	
    for (const auto& extension : availableExtensions) {
        requiredExtensions.RemoveKey(extension.extensionName);
    }

    return requiredExtensions.GetCount() == 0;
}

bool checkDeviceExtensionSupport(VkPhysicalDevice& physicalDevice, const Index<String>& extensionsRequired) {
    unsigned int extensionCount;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);
    Vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, availableExtensions);

	Index<String> requiredExtensions(clone(extensionsRequired));
	
    for (const auto& extension : availableExtensions) {
        requiredExtensions.RemoveKey(extension.extensionName);
    }

    return requiredExtensions.GetCount() == 0;
}

unsigned int QueryScore(VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface, Index<String>& extensionsRequired){
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
    if (GetQueuePosition(physicalDevice, VK_QUEUE_GRAPHICS_BIT) == -1){
        return 0;
	}
	if(!checkDeviceExtensionSupport(physicalDevice, extensionsRequired)){
		return 0;
	}
    SwapChainSupportDetails swapChainSupport = QuerySwapchainDetails(physicalDevice, surface);
    if(swapChainSupport.Formats.GetCount() == 0 && swapChainSupport.PresentModes.GetCount() == 0){
		return 0;
    }
	
    return score;
}

VkResult CreateSwapChain(VkPhysicalDevice& physicalDevice, VkDevice& device, VkSurfaceKHR& surface, VkSwapchainKHR& swapchain){
	//VkSwapchainCreateInfoKHR createInfo ={};
	
	//VkResult result = vkCreateSwapchainKHR(device, &createInfo, nullptr, &swapchain);
	return VK_SUCCESS;
}

void ClearInstance(VkInstance& instance){
	ASSERT_(instance != VK_NULL_HANDLE, "Clear instance handler is null (equal to VK_NULL_HANDLE)");
	vkDestroyInstance(instance,nullptr);
	LLOG("[VKCtrl::ClearInstance][INFO] Vulkan instance successfully deleted (handler=" + AsString((int*)instance) + ")");
}

void ClearDebugMessenger(VkInstance& instance, VkDebugUtilsMessengerEXT& debugMessenger){
	ASSERT_(instance != VK_NULL_HANDLE, "Instance handler is null (equal to VK_NULL_HANDLE)");
	ASSERT_(debugMessenger != VK_NULL_HANDLE, "Debug Utils Messenger handler is null (equal to VK_NULL_HANDLE)");
	DestroyDebugUtilsMEssengerEXT(instance, debugMessenger, nullptr);
	LLOG("[VKCtrl::ClearDebugMessenger][INFO] Debug Utils Messenger successfully deleted (handler=" + AsString((int*)debugMessenger) +")");
}

void ClearDevice(VkDevice& device){
	ASSERT_(device != VK_NULL_HANDLE, "Device handler is null (equal to VK_NULL_HANDLE)");
	vkDestroyDevice(device, nullptr);
	LLOG("[VKCtrl::ClearDevice][INFO] Device successfully deleted (handle=" + AsString(device) + ")");
}

void ClearSurface(VkInstance& instance, VkSurfaceKHR& surface){
	ASSERT_(surface != VK_NULL_HANDLE, "Surface handler is null (equal to VK_NULL_HANDLE)");
	 vkDestroySurfaceKHR(instance, surface, nullptr);
	 LLOG("[VKCtrl::ClearSurface][INFO] Surface successfully deleted (handle=" + AsString(surface) + ")");
}

VkResult CreateInstance(VkInstance& instance, bool enableLayer, const Upp::Index<Upp::String>& layers, const Upp::Index<Upp::String>& extensions, Upp::String& appName){
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
	createInfo.enabledLayerCount = 0;
	createInfo.ppEnabledLayerNames = nullptr;
	Vector<const char*> layersPtr;
	if(enableLayer){
		layersPtr = GetTemporaryCharPtr(layers);
		createInfo.enabledLayerCount = layers.GetCount();
		createInfo.ppEnabledLayerNames = layersPtr;
	}
	//	Code to fill extensions here
	Vector<const char*> extensionsPtr = GetTemporaryCharPtr(extensions);
	createInfo.enabledExtensionCount = extensions.GetCount();
	createInfo.ppEnabledExtensionNames = extensionsPtr;
	
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	LLOG("[VKCtrl::CreateInstance][INFO] Vulkan instance have been created (handler=" + AsString((int*)instance) + ")");
	return result;
}

VkResult CreateMessenger(VkInstance& instance, VkDebugUtilsMessengerEXT& debugMessenger ){
	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
						     VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	
    createInfo.pfnUserCallback = debugCallback;
    createInfo.pUserData = nullptr;
    VkResult result = CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr, &debugMessenger);
    LLOG("[VKCtrl::CreateMessenger][INFO] Debug Utils Messenger have been created (handler=" + AsString((int*)debugMessenger) + ")");
    return result;
}

VkResult PickPhysicalDevice(VkInstance& instance, VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface, Index<String>& extensionsRequired){
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(instance, &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(instance, &physicalDeviceNumber, physicalDevices);
			int scoreMax = 0;
			int position = -1;
			for(int i = 0; i < physicalDeviceNumber; i++){
				int score = QueryScore(physicalDevices[i], surface, extensionsRequired);
				if(score > scoreMax){
					scoreMax = score;
					position = i;
				}
			}
			if(position != -1){
				physicalDevice = clone(physicalDevices[position]);
				VkPhysicalDeviceProperties deviceProperties;
				vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);
				LLOG("[VKCtrl::PickPhysicalDevice][INFO] Physical device chosen is " + String(deviceProperties.deviceName));
				return VK_SUCCESS;
			}else{
				LLOG("[VKCtrl::PickPhysicalDevice][ERROR] No vulkan suitable physdical device have been found");
				physicalDevice = VK_NULL_HANDLE;
			}
		}else{
			LLOG("[VKCtrl::PickPhysicalDevice][ERROR] No vulkan physdical device have been found");
		}
	}else{
		LLOG("[VKCtrl::PickPhysicalDevice][ERROR] Impossible to query physical device");
		return result;
	}
	return VK_ERROR_UNKNOWN;
}

VkResult CreateDevice(VkPhysicalDevice& physicalDevice, VkDevice& device){
		int queueIndice = GetQueuePosition(physicalDevice, VK_QUEUE_GRAPHICS_BIT);
		float queuePriority = 1.0f;
		ASSERT_(queueIndice != -1, "VK_QUEUE_GRAPHICS_BIT  not found on the selected physicalDevice");
		
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = queueIndice;
		queueCreateInfo.queueCount = 1;
		queueCreateInfo.pQueuePriorities = &queuePriority;
		
		VkPhysicalDeviceFeatures deviceFeatures{};
		
		VkDeviceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.pEnabledFeatures = &deviceFeatures;
		createInfo.queueCreateInfoCount = 1;
		createInfo.pQueueCreateInfos = &queueCreateInfo;
		
		createInfo.enabledExtensionCount = 0;
		/*if (enableValidationLayers) {
		    createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		    createInfo.ppEnabledLayerNames = validationLayers.data();
		} else {
		    createInfo.enabledLayerCount = 0;
		}*/
		VkResult result = vkCreateDevice(physicalDevice, &createInfo, nullptr, &device);
		if(result == VK_SUCCESS){
			LLOG("[VKCtrl::CreateDevice][INFO] Device successfully created (handle=" + AsString(device) + ")");
			return result;
		}else{
			LLOG("[VKCtrl::CreateDevice][ERROR] Error during creation of device");
			return result;
		}
		return VK_ERROR_UNKNOWN;
}





VKCtrl::VKCtrl() : m_windowName("VKCtrl"){}
VKCtrl::VKCtrl(const Upp::String& windowName) : m_windowName(windowName){}
VKCtrl::~VKCtrl(){
	if(m_created){
		if(m_debugMessenger){
			ClearDebugMessenger(m_instance, m_debugMessenger);
		}
		if(m_surface != VK_NULL_HANDLE){
			ClearSurface(m_instance, m_surface);
		}
		if(m_device != VK_NULL_HANDLE){
			ClearDevice(m_device);
		}
		ClearInstance(m_instance);
	}
}

bool VKCtrl::Init(bool trace){
	if(!m_created){
		AddDeviceExtensions(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
		AddInstanceExtensions(VK_KHR_SURFACE_EXTENSION_NAME);
		AddInstanceExtensions(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
		if(trace) AddInstanceExtensions(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		if(!checkInstanceExtensionSupport(m_extensionName)){
			LLOG("VKCtrl::Create][WARNING] Invalide extension provided");
			return false;
		}
		if(!checkValidationlayerExtensionSupport(m_validationLayers)){
			LLOG("VKCtrl::Create][WARNING] Invalide validation layer provided");
			return false;
		}
		VkResult result = CreateInstance(m_instance, m_enableValidationLayers, m_validationLayers, m_extensionName, m_windowName);
		if(result == VK_SUCCESS){
			if(trace){
				result = CreateMessenger(m_instance, m_debugMessenger);
				if(result != VK_SUCCESS){
					m_debugMessenger = VK_NULL_HANDLE;
					LLOG("VKCtrl::Create][WARNING] Messenger creation have failled");
				}
			}
			Transparent();
#ifdef PLATFORM_WIN32
			m_pane.ctrl = this;
			Add(m_pane.SizePos());
#endif
			m_created = true;
			return m_created;
		}else{
			LLOG("[VKCtrl::Create][ERROR] Vulkan instance creation failled");
		}
	}else{
		LLOG("[VKCtrl::Create][ERROR] Vulkan instance is already created");
	}
	return false;
}

bool VKCtrl::InitEntireVulkanChain(){
	if(m_created){
		VkResult result = PickPhysicalDevice(m_instance, m_physicalDevice, m_surface, m_deviceExtensionName);
		if(result == VK_SUCCESS){
			result = CreateDevice(m_physicalDevice, m_device);
			if(result == VK_SUCCESS){
				result = CreateSwapChain(m_physicalDevice, m_device, m_surface, m_swapchain);
				if(result == VK_SUCCESS){
					
					
					return true;
				}else{
					m_swapchain = VK_NULL_HANDLE;
					LLOG("[VKCtrl::VkPane::State][ERROR] Impossible to create VkSurfaceKHR");
				}
			}else{
				m_device = VK_NULL_HANDLE;
				LLOG("[VKCtrl::Create][ERROR] Error during VkDevice creation");
			}
		}else{
			m_physicalDevice = VK_NULL_HANDLE;
			LLOG("[VKCtrl::Create][ERROR] No compatible physical device found");
		}
		if(m_debugMessenger != VK_NULL_HANDLE){
			ClearDebugMessenger(m_instance, m_debugMessenger);
		}
		ClearInstance(m_instance);
		return false;
	}
	return false;
}

VKCtrl& VKCtrl::EnableValidationLayers(bool b){
	m_enableValidationLayers = b;
	return *this;
}

bool VKCtrl::IsValidationLayersEnabled()const{
	return m_enableValidationLayers;
}

Upp::Vector<Upp::String> VKCtrl::PickAllValidationLayers(){
	unsigned int totalVlCount = 0;
	Upp::Vector<Upp::String> validationLayers;
	
	vkEnumerateInstanceLayerProperties(&totalVlCount, nullptr);
	Vector<VkLayerProperties> totalVl(totalVlCount);
	vkEnumerateInstanceLayerProperties(&totalVlCount, totalVl);

	for(const VkLayerProperties& lp : totalVl){
		validationLayers.Add(lp.layerName);
	}
	return pick(validationLayers);
}

Upp::Vector<Upp::String> VKCtrl::PickAllExtensions(){
	//we query only vulkan extensions here
	unsigned int totalECount = 0;
	Vector<Upp::String> retExtensions;
	
	vkEnumerateInstanceExtensionProperties(nullptr, &totalECount, nullptr);
	Vector<VkExtensionProperties> totalE(totalECount);
	vkEnumerateInstanceExtensionProperties(nullptr, &totalECount, totalE);
	for(const VkExtensionProperties e : totalE){
		retExtensions.Add(e.extensionName);
	}

	return pick(retExtensions);
}


VKCtrl& VKCtrl::AddInstanceExtensions(const Upp::String& extensionName){
	if(m_extensionName.Find(extensionName) == -1){
		m_extensionName.Add(extensionName);
	}
	return *this;
}
VKCtrl& VKCtrl::AddDeviceExtensions(const Upp::String& extensionName){
	if(m_deviceExtensionName.Find(extensionName) == -1){
		m_deviceExtensionName.Add(extensionName);
	}
	return *this;
}
VKCtrl& VKCtrl::AddValidationLayers(const Upp::String& layers){
	if(m_validationLayers.Find(layers) == -1){
		m_validationLayers.Add(layers);
	}
	return *this;
}


};