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

QueueFamilyIndices GetQueuePosition(VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface){
	QueueFamilyIndices indices;
	unsigned int queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);
	Vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilies);
	
	for(int i = 0; i < queueFamilyCount; i++){
		if(queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }
        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &presentSupport);
        if(presentSupport) {
            indices.presentFamily = i;
        }
        if(indices.isComplete()) {
            break;
        }
	}
	return indices;
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
	QueueFamilyIndices indices = GetQueuePosition(physicalDevice, surface);
	if(!indices.isComplete()){
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

VkSurfaceFormatKHR ChooseSwapSurfaceFormat(Upp::Vector<VkSurfaceFormatKHR>& availableFormats){
	for (const VkSurfaceFormatKHR& availableFormat : availableFormats) {
	    if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
	        return availableFormat;
	    }
	}
	ASSERT_(availableFormats.GetCount() > 0, "Available formats for swap chain is empty");
	return availableFormats[0];
}

VkPresentModeKHR ChooseSwapPresentMode(const Upp::Vector<VkPresentModeKHR>& availablePresentModes) {
	
	//	VK_PRESENT_MODE_IMMEDIATE_KHR: Images submitted by your application are transferred to the screen right away, which may result in tearing.
	//	VK_PRESENT_MODE_FIFO_KHR: The swap chain is a queue where the display takes an image from the front of the queue when the display is
	//							  refreshed and the program inserts rendered images at the back of the queue. If the queue is full then the
	//							  program has to wait. This is most similar to vertical sync as found in modern games. The moment that the display
	//							  is refreshed is known as "vertical blank".
	//	VK_PRESENT_MODE_FIFO_RELAXED_KHR: This mode only differs from the previous one if the application is late and the queue was empty at the
	//									  last vertical blank. Instead of waiting for the next vertical blank, the image is transferred right away
	//									  when it finally arrives. This may result in visible tearing.
	//	VK_PRESENT_MODE_MAILBOX_KHR: This is another variation of the second mode. Instead of blocking the application when the queue is full, the
	//								 images that are already queued are simply replaced with the newer ones. This mode can be used to render frames
	//								 as fast as possible while still avoiding tearing, resulting in fewer latency issues than standard vertical sync.
	//								 This is commonly known as "triple buffering", although the existence of three buffers alone does not necessarily
	//								 mean that the framerate is unlocked.

	for (const VkPresentModeKHR& availablePresentMode : availablePresentModes) {
        if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
            return availablePresentMode;
        }
    }
    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities){
    if (capabilities.currentExtent.width != UINT32_MAX) {
        return capabilities.currentExtent;
    } else {
        //Querry U++ Window max framebuffer size here
        /*
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        VkExtent2D actualExtent = {
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height)
        };

        actualExtent.width = std::clamp(actualExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
        actualExtent.height = std::clamp(actualExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);
		
        return actualExtent;*/
        return capabilities.currentExtent;
    }
}

VkResult CreateSwapChain(VkInstance& instance, VkPhysicalDevice& physicalDevice, VkDevice& device, VkSurfaceKHR& surface, VkSwapchainKHR& swapchain){
	SwapChainSupportDetails swapChainSupport = QuerySwapchainDetails(physicalDevice, surface);

    VkSurfaceFormatKHR surfaceFormat = ChooseSwapSurfaceFormat(swapChainSupport.Formats);
    VkPresentModeKHR presentMode = ChooseSwapPresentMode(swapChainSupport.PresentModes);
    VkExtent2D extent = ChooseSwapExtent(swapChainSupport.Capabilities);
    
    unsigned int imageCount = swapChainSupport.Capabilities.minImageCount + 1;
    if (swapChainSupport.Capabilities.maxImageCount > 0 && imageCount > swapChainSupport.Capabilities.maxImageCount) {
	    imageCount = swapChainSupport.Capabilities.maxImageCount;
	}
	
	VkSwapchainCreateInfoKHR createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	createInfo.surface = surface;
    createInfo.minImageCount = imageCount;
	createInfo.imageFormat = surfaceFormat.format;
	createInfo.imageColorSpace = surfaceFormat.colorSpace;
	createInfo.imageExtent = extent;
	createInfo.imageArrayLayers = 1;
	createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

	QueueFamilyIndices indices = GetQueuePosition(physicalDevice, surface);
	ASSERT_(indices.isComplete(), "QueueFamilyIndices have null queue");
	unsigned int queueFamilyIndices[] = {(unsigned int)indices.graphicsFamily, (unsigned int)indices.presentFamily};
	if (indices.graphicsFamily != indices.presentFamily) {
	    createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
	    createInfo.queueFamilyIndexCount = 2;
	    createInfo.pQueueFamilyIndices = queueFamilyIndices;
	} else {
	    createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	    createInfo.queueFamilyIndexCount = 0; // Optional
	    createInfo.pQueueFamilyIndices = nullptr; // Optional
	}

	createInfo.preTransform = swapChainSupport.Capabilities.currentTransform;
	createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	createInfo.presentMode = presentMode;
	createInfo.clipped = VK_TRUE;
	createInfo.oldSwapchain = VK_NULL_HANDLE;
	
	VkResult result = vkCreateSwapchainKHR(device, &createInfo, nullptr, &swapchain) ;
	if(result == VK_SUCCESS){
		ASSERT_(swapchain != VK_NULL_HANDLE, "Swapchain is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
		LLOG("[VKCtrl::CreateSwapChain][INFO] Swapchain have been created (handler=" + AsString((int*)swapchain) + ")");
		return VK_SUCCESS;
	}else{
		LLOG("[VKCtrl::CreateSwapChain][ERROR] Swapchain creation failled");
		swapchain = VK_NULL_HANDLE;
		return result;
	}
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

void ClearSwapChain(VkDevice& device, VkSwapchainKHR& swapchain){
	ASSERT_(device != VK_NULL_HANDLE, "Device handler is null (equal to VK_NULL_HANDLE)");
	ASSERT_(swapchain != VK_NULL_HANDLE, "Swapchain handler is null (equal to VK_NULL_HANDLE)");
	vkDestroySwapchainKHR(device, swapchain, nullptr);
	LLOG("[VKCtrl::ClearSwapChain][INFO] Swapchain successfully deleted (handle=" + AsString(swapchain) + ")");
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
	if(result == VK_SUCCESS){
		ASSERT_(instance != VK_NULL_HANDLE, "Vulkan instance is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
		LLOG("[VKCtrl::CreateInstance][INFO] Vulkan instance have been created (handler=" + AsString((int*)instance) + ")");
		return VK_SUCCESS;
	}else{
		LLOG("[VKCtrl::CreateInstance][ERROR] Vulkan instance creation failled");
		instance = VK_NULL_HANDLE;
		return result;
	}
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
    if(result == VK_SUCCESS){
		ASSERT_(debugMessenger != VK_NULL_HANDLE, "Debug Utils Messenger is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
		LLOG("[VKCtrl::CreateMessenger][INFO] Debug Utils Messenger have been created (handler=" + AsString((int*)debugMessenger) + ")");
		return VK_SUCCESS;
	}else{
		LLOG("VKCtrl::CreateMessenger][WARNING] Messenger creation have failled");
		debugMessenger = VK_NULL_HANDLE;
		return result;
	}
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
			}
		}else{
			LLOG("[VKCtrl::PickPhysicalDevice][ERROR] No vulkan physdical device have been found");
		}
	}else{
		LLOG("[VKCtrl::PickPhysicalDevice][ERROR] Impossible to query physical device");
		return result;
	}
	physicalDevice = VK_NULL_HANDLE;
	LLOG("[VKCtrl::Create][ERROR] No compatible physical device found");
	return VK_ERROR_UNKNOWN;
}

VkResult CreateDevice(VkPhysicalDevice& physicalDevice, VkDevice& device, VkSurfaceKHR& surface, Upp::Index<Upp::String>& extessionsName ){
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

		/*if (enableValidationLayers) {
		    createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		    createInfo.ppEnabledLayerNames = validationLayers.data();
		} else {
		    createInfo.enabledLayerCount = 0;
		}*/
		VkResult result = vkCreateDevice(physicalDevice, &createInfo, nullptr, &device);
		if(result == VK_SUCCESS){
			ASSERT_(device != VK_NULL_HANDLE, "Device is equal to VK_NULL_HANDLE despite Vulkan return VK_SUCCESS");
			LLOG("[VKCtrl::CreateDevice][INFO] Device successfully created (handle=" + AsString(device) + ")");
			return result;
		}else{
			LLOG("[VKCtrl::CreateDevice][ERROR] Error during creation of device");
			device = VK_NULL_HANDLE;
			return result;
		}
}

VKCtrl::VKCtrl() : m_windowName("VKCtrl"){}
VKCtrl::VKCtrl(const Upp::String& windowName) : m_windowName(windowName){}
VKCtrl::~VKCtrl(){
	if(m_created){
		if(m_debugMessenger){
			ClearDebugMessenger(m_instance, m_debugMessenger);
		}
		if(m_swapchain != VK_NULL_HANDLE){
			ClearSwapChain(m_device, m_swapchain);
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
			LLOG("VKCtrl::Create][ERROR] Invalide extension provided");
			return false;
		}
		if(!checkValidationlayerExtensionSupport(m_validationLayers)){
			LLOG("VKCtrl::Create][ERROR] Invalide validation layer provided");
			return false;
		}
		VkResult result = CreateInstance(m_instance, m_enableValidationLayers, m_validationLayers, m_extensionName, m_windowName);
		if(result == VK_SUCCESS){
			if(trace)
				CreateMessenger(m_instance, m_debugMessenger);
			Transparent();
#ifdef PLATFORM_WIN32
			m_pane.ctrl = this;
			Add(m_pane.SizePos());
#endif
			m_created = true;
			return m_created;
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
			result = CreateDevice(m_physicalDevice, m_device, m_surface, m_deviceExtensionName);
			if(result == VK_SUCCESS){
				result = CreateSwapChain(m_instance ,m_physicalDevice, m_device, m_surface, m_swapchain);
				if(result == VK_SUCCESS){
					
					return true;
				}
			}
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