#ifndef _UVKengine_UVKengine_h_
#define _UVKengine_UVKengine_h_
#include <Core/Core.h>
#include <CtrlLib/CtrlLib.h>
#include <vulkan/vulkan.h>

#define UVK_ENGINE_VERSION_0_1 0x01
#define UVK_ENGINE_NAME "UVKengine"


#define UVK_MAKE_API_VERSION(variant, major, minor, patch) \
    ((((uint32_t)(variant)) << 29) | (((uint32_t)(major)) << 22) | (((uint32_t)(minor)) << 12) | ((uint32_t)(patch)))
#define UVK_API_VERSION UVK_MAKE_API_VERSION(0, 1, 0, 0)

namespace Upp{
	
NTL_MOVEABLE(VkLayerProperties);
NTL_MOVEABLE(VkExtensionProperties);
NTL_MOVEABLE(VkQueueFamilyProperties);
NTL_MOVEABLE(VkPresentModeKHR);
NTL_MOVEABLE(VkSurfaceFormatKHR);
NTL_MOVEABLE(VkDeviceQueueCreateInfo);
	
void ConfigureVulkanDebugMessenger(
	dword severityFilter = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT,
	dword typeFilter =  VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
);



		
Upp::Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr);




struct QueueFamilyIndices {
	int graphicsFamily = Null;
    int presentFamily = Null;

    bool isComplete() {
        return !IsNull(graphicsFamily) && !IsNull(presentFamily) ;
    }
};

class VKCtrl : public Ctrl{
	public:
		VKCtrl(const Upp::String& windowName);
		VKCtrl();
		~VKCtrl();
		
		bool Init(bool trace);
		bool IsValidationLayersEnabled()const;
		
		Upp::Vector<Upp::String> PickAllValidationLayers();
		Upp::Vector<Upp::String> PickAllExtensions();
		
		VKCtrl& AddInstanceExtensions(const Upp::String& extensionName);
		VKCtrl& AddDeviceExtensions(const Upp::String& extensionName);
		VKCtrl& AddValidationLayers(const Upp::String& layers);
		VKCtrl& EnableValidationLayers(bool b);
	private:
		bool InitEntireVulkanChain();
	
	private:
		struct SwapChainSupportDetails {
			VkSurfaceCapabilitiesKHR Capabilities;
			Vector<VkSurfaceFormatKHR> Formats;
			Vector<VkPresentModeKHR> PresentModes;
		}m_swapchainSupport;
		
		typedef VKCtrl CLASSNAME;
		
		bool m_created = false;
		Upp::String m_windowName;
		Upp::Index<Upp::String> m_extensionName;
		Upp::Index<Upp::String> m_deviceExtensionName;
		Upp::Index<Upp::String> m_validationLayers;
		//Vulkan handler
		
		
#if defined(WIN32)
		struct VkPane : DHCtrl{
			private:
				friend class VKCtrl;
				VKCtrl *ctrl;
			public:
				VkPane() { NoWantFocus(); }
				virtual void State(int reason);
		};
		VkPane m_pane;
#endif
};

}

#endif
