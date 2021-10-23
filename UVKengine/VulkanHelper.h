#ifndef _UVKengine_VulkanHelper_h_
#define _UVKengine_VulkanHelper_h_

/*
	Vulkan helper class allow you to pick/create vulkan instance device etc...
*/
#if defined(flagASSERTHANDLER)
#define CHECK_HANDLER(x) ASSERT_(x != VK_NULL_HANDLE, "$x is null handler");
#define CHECK_NOT_NULL_HANDLER(x) ASSERT_(x != VK_NULL_HANDLE, "$x is not null handler ($x=" + AsString((int*)x) +")");
#else
#define CHECK_HANDLER(x) if(x == VK_NULL_HANDLE) throw Exc("$x is null handler");
#define CHECK_NOT_NULL_HANDLER(x)  if(x == VK_NULL_HANDLE) throw Exc("$x is not null handler ($x=" + AsString((int*)x) +")");
#endif

#define AllocatorNullPtr nullptr

namespace Upp{

//To do a custom PhysicalDeviceSelector, just inheritate from this class and define Operator()
class PhysicalDeviceSelector{
	public:
		virtual PhysicalDevice operator()(VulkanHelper& helper);
	private:
		unsigned int QueryScore(VkPhysicalDevice device);
		bool checkDeviceExtensionSupport(VkPhysicalDevice& physicalDevice, const Vector<const char*>& extensionsRequired);
};

class VulkanHelper{
	public:
		VulkanHelper();
		
		bool SelectPhysicalDevice(PhysicalDeviceSelector& selector = PhysicalDeviceSelector());
		bool SelectPhysicalDevice(Upp::String& name);
		
		VkInstance GetInstance()const;
		VkDebugUtilsMessengerEXT GetDebugMessenger()const;
		VkDevice GetDevice()const;
		
		VkInstance CreateInstance();
		VkDebugUtilsMessengerEXT CreateDebugMessenger();
		VkDevice CreateDevice(Upp::String& phyiscalDeviceName = "");
		
		void SetMessengerCallback(Function<void ( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)>);

		VulkanSelector& GetSelector();
	private:
		VkPhysicalDevice GetPhysicalDevice(Upp::String& phyiscalDeviceName);

		VulkanSelector m_selector;
		Function<void(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)> m_debugCallback;

		VkInstance m_instance = VK_NULL_HANDLE;
		VkDebugUtilsMessengerEXT m_debugMessenger = VK_NULL_HANDLE;
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkDevice m_device = VK_NULL_HANDLE;
		
		struct QueueFamilyIndices {
		    int graphicsFamily = Null;
			int presentFamily = Null;
		
		    bool isComplete() {
		        return !IsNull(graphicsFamily) && !IsNull(presentFamily);
		    }
		}m_queuesIndices;

		bool m_enableValidationLayers = false;
};

class VulkanSelector{
	public:
		VulkanSelector(Vector<String>& extensions = {}, Vector<String>& validationLayers = {}, Vector<String>& deviceExtensions = {});
		
		void AddInstanceExtensions(String& str);
		void AddValidationLayers(String& str);
		void AddDeviceExtensions(String& str);
		
		const Vector<const char*>& GetInstanceExtensions()const;
		const Vector<const char*>& GetValidationsLayers()const;
		const Vector<const char*>& GetDeviceExtensions()const;
		
		int GetInstanceExtensionsCount()const;
		int GetValidationsLayersCount()const;
		int GetDeviceExtensionsCount()const;
		
	private:
		Vector<String> m_devicesExtensions;
		Vector<String> m_validationLayers;
		Vector<String> m_instanceExtensions;
};

}
#endif
