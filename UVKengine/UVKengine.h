#ifndef _UVKengine_UVKengine_h_
#define _UVKengine_UVKengine_h_
#include <Core/Core.h>
#include <vulkan/vulkan.h>

#define UVK_ENGINE_VERSION_0_1 0x01
#define UVK_ENGINE_NAME "UVKengine"


#define UVK_MAKE_API_VERSION(variant, major, minor, patch) \
    ((((uint32_t)(variant)) << 29) | (((uint32_t)(major)) << 22) | (((uint32_t)(minor)) << 12) | ((uint32_t)(patch)))
#define UVK_API_VERSION UVK_MAKE_API_VERSION(0, 1, 0, 0)

namespace Upp{
	
	void ConfigureVulkanDebugMessenger(
		dword severityFilter = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
		dword typeFilter =  VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
	);

	
	Upp::Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr);
	
	class UVKapp{
		public:
			UVKapp(const Upp::String& windowName);
			UVKapp();
			~UVKapp();
		
			bool Create(bool trace);
	
			UVKapp& SetExtensions(const Upp::Vector<Upp::String>& extensionName);
			
			UVKapp& EnableValidationLayers(bool b);
			bool IsValidationLayersEnabled()const;
			UVKapp& SetValidationLayers(const Upp::Vector<Upp::String>& layers);
			
		private:
			Upp::Vector<Upp::String> PickAllValidationLayers(const Upp::Vector<Upp::String>& layers = {});
			Upp::Vector<Upp::String> PickAllExtensions(const Upp::Vector<Upp::String>& extensions = {}, bool trace = false);
			
			void ClearInstance(VkInstance& instance);
			void ClearDebugMessenger(VkInstance& instance, VkDebugUtilsMessengerEXT& debugMessenger);
			void ClearDevice(VkDevice& device);
			
			VkResult CreateInstance(VkInstance& instance, const Upp::Vector<Upp::String>& layers = {}, const Upp::Vector<Upp::String>& extensions = {});
			VkResult CreateMessenger(VkInstance& instance,VkDebugUtilsMessengerEXT& debugMessenger);
			VkResult PickPhysicalDevice(VkInstance& instance, VkPhysicalDevice& physicalDevice);
			VkResult CreateDevice(VkPhysicalDevice& physicalDevice, VkDevice& device);
			
			bool m_created = false;
			Upp::String m_windowName;
			Upp::Vector<Upp::String> m_extensionName;
			
			bool m_enableValidationLayers = false;
			Upp::Vector<Upp::String> m_validationLayers;
			
			//Vulkan
			VkInstance m_instance = VK_NULL_HANDLE;
			VkDebugUtilsMessengerEXT m_debugMessenger = VK_NULL_HANDLE;
			VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
			VkDevice m_device = VK_NULL_HANDLE;
	};
	
}

#endif
