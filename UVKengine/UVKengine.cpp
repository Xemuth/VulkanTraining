#include "UVKengine.h"

#define LLOG(x) LOG(x)

namespace Upp{
	
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData){
	Upp::String severity = "";
	if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT){
		severity += "[ERROR]";
	}
	if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT){
		severity += "[WARNING]";
	}
	if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT){
		severity += "[INFO]";
	}
	if((messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT){
		severity += "[VERBOSE]";
	}
	
	if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT){
		severity += "[PERFORMANCE]";
	}
	if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT){
		severity += "[VALIDATION]";
	}
	if((messageType & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) == VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT){
		severity += "[GENERAL]";
	}
	LOG(severity + Upp::String(pCallbackData->pMessage));
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


NTL_MOVEABLE(VkLayerProperties);
NTL_MOVEABLE(VkExtensionProperties);
	UVKapp::UVKapp() : m_windowName("UVKApp"){}
	UVKapp::UVKapp(const Upp::String& windowName) : m_windowName(windowName){}
	UVKapp::~UVKapp(){
		if(m_created){
			if(m_debugMessenger){
				ClearDebugMessenger(m_instance, m_debugMessenger);
			}
			ClearInstance(m_instance);
		}
	}
	bool UVKapp::Create(bool trace){
		if(!m_created){
			Upp::Vector<Upp::String> extensions = PickAllExtensions(m_extensionName, trace);
			Upp::Vector<Upp::String> layers = PickAllValidationLayers(m_validationLayers);
			VkResult result = CreateInstance(m_instance, layers, extensions);
			if(result == VK_SUCCESS){
				if(trace){
					result = CreateMessenger(m_instance, m_debugMessenger);
					if(result != VK_SUCCESS){
						m_debugMessenger = 0;
						LLOG("UVKApp::Create][WARNING] Messenger creation have failled");
					}
				}
				result = PickPhysicalDevice(m_instance, m_physicalDevice);
				if(result == VK_SUCCESS){
					result = CreateDevice(m_instance, m_physicalDevice, m_device);
					if(result == VK_SUCCESS){
						m_created = true;
						return m_created;
					}else{
						m_device = 0;
						LLOG("[UVKapp::Create][ERROR] Error during VkDevice creation");
					}
				}else{
					m_physicalDevice = 0;
					LLOG("[UVKapp::Create][ERROR] No compatible physical device found");
				}
				ClearInstance(m_instance);
			}else{
				LLOG("[UVKapp::Create][ERROR] Vulkan instance creation failled");
			}
		}else{
			LLOG("[UVKapp::Create][ERROR] Vulkan instance is already created");
		}
		return false;
	}
	
	void UVKapp::ClearInstance(VkInstance& instance){
		ASSERT_(instance != 0, "Clear instance handler is null (equal to 0)");
		vkDestroyInstance(instance,nullptr);
		LLOG("[UVKapp::ClearInstance][INFO] Vulkan instance has been cleared (handler=" + AsString((int*)instance) + ")");
	}
	void UVKapp::ClearDebugMessenger(VkInstance& instance, VkDebugUtilsMessengerEXT& debugMessenger){
		ASSERT_(instance != 0, "Instance handler is null (equal to 0)");
		ASSERT_(debugMessenger != 0, "Debug Utils Messenger handler is null (equal to 0)");
		DestroyDebugUtilsMEssengerEXT(instance, debugMessenger, nullptr);
		LLOG("[UVKapp::ClearDebugMessenger][INFO] Debug Utils Messenger have been cleared (handler=" + AsString((int*)m_debugMessenger) +")");
	}
	
	VkResult UVKapp::CreateInstance(VkInstance& instance, const Upp::Vector<Upp::String>& layers, const Upp::Vector<Upp::String>& extensions){
		//	VkInstanceCreateInfo struct
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pNext = nullptr;
		//	VkApplicationInfo struct
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = ~m_windowName;
		appInfo.applicationVersion = UVK_ENGINE_VERSION_0_1;
		appInfo.pEngineName = UVK_ENGINE_NAME;
		appInfo.engineVersion = UVK_ENGINE_VERSION_0_1;
		appInfo.apiVersion = UVK_ENGINE_VERSION_0_1;
		createInfo.pApplicationInfo = &appInfo;
		//	Code to fill layers here
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = nullptr;
		Vector<const char*> layersPtr;
		if(m_enableValidationLayers){
			layersPtr = GetTemporaryCharPtr(layers);
			createInfo.enabledLayerCount = layers.GetCount();
			createInfo.ppEnabledLayerNames = layersPtr;
		}
		//	Code to fill extensions here
		Vector<const char*> extensionsPtr = GetTemporaryCharPtr(extensions);
		createInfo.enabledExtensionCount = extensions.GetCount();
		createInfo.ppEnabledExtensionNames = extensionsPtr;
		
		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
		LLOG("[UVKapp::CreateInstance][INFO] Vulkan instance have been created (handler=" + AsString((int*)instance) + ")");
		return result;
	}
	
	VkResult UVKapp::CreateMessenger(VkInstance& instance, VkDebugUtilsMessengerEXT& debugMessenger ){
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
	    LLOG("[UVKapp::CreateMessenger][INFO] Debug Utils Messenger have been created (handler=" + AsString((int*)debugMessenger) + ")");
	    return result;
	}
	
	VkResult UVKapp::PickPhysicalDevice(VkInstance& instance, VkPhysicalDevice& physicalDevice){
		return VK_SUCCESS; //TEMPORARY RETURN VALUE
	}
	VkResult UVKapp::CreateDevice(VkInstance& instance, VkPhysicalDevice& physicalDevice, VkDevice& device){
		return VK_SUCCESS; //TEMPORARY RETURN VALUE
	}
	
	
	UVKapp& UVKapp::EnableValidationLayers(bool b){
		m_enableValidationLayers = b;
		return *this;
	}
	bool UVKapp::IsValidationLayersEnabled()const{
		return m_enableValidationLayers;
	}
	Upp::Vector<Upp::String> UVKapp::PickAllValidationLayers(const Upp::Vector<Upp::String>& layers){
		unsigned int totalVlCount = 0;
		Upp::Vector<Upp::String> validationLayers;
		
		vkEnumerateInstanceLayerProperties(&totalVlCount, nullptr);
		Vector<VkLayerProperties> totalVl(totalVlCount);
		vkEnumerateInstanceLayerProperties(&totalVlCount, totalVl);

		for(const VkLayerProperties& lp : totalVl){
			if(layers.GetCount() > 0){
				for(const Upp::String& layer : layers){
					if(layer.IsEqual(lp.layerName)){
						validationLayers.Add(lp.layerName);
						break;
					}
				}
			}else{
				validationLayers.Add(lp.layerName);
			}
		}
		return pick(validationLayers);
	}
	Upp::Vector<Upp::String> UVKapp::PickAllExtensions(const Upp::Vector<Upp::String>& extensions, bool trace){
		//we query only vulkan extensions here
		unsigned int totalECount = 0;
		bool addedDebugUtils = false;
		Vector<Upp::String> retExtensions;
		
		vkEnumerateInstanceExtensionProperties(nullptr, &totalECount, nullptr);
		Vector<VkExtensionProperties> totalE(totalECount);
		vkEnumerateInstanceExtensionProperties(nullptr, &totalECount, totalE);
		for(const VkExtensionProperties e : totalE){
			if(extensions.GetCount() > 0){
				for(const Upp::String& str :extensions){
					if(str.IsEqual(e.extensionName)){
						if(str.IsEqual(VK_EXT_DEBUG_UTILS_EXTENSION_NAME)) addedDebugUtils = true;
						retExtensions.Add(e.extensionName);
						break;
					}
				}
			}else{
				retExtensions.Add(e.extensionName);
			}
		}
		if(trace && !addedDebugUtils){
			retExtensions.Add(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}
		
		return retExtensions;
	}
	

	UVKapp& UVKapp::SetExtensions(const Upp::Vector<Upp::String>& extensionName){
		m_extensionName = clone(extensionName);
		return *this;
	}
	UVKapp& UVKapp::SetValidationLayers(const Upp::Vector<Upp::String>& layers){
		m_validationLayers = clone(layers);
		return *this;
	}
	
	Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr){
		Vector<const char*> buffer;
		for(const Upp::String& str : vectorStr)
			buffer.Add(~str);
		return pick(buffer);
	}
};