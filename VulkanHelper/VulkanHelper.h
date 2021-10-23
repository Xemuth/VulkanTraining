#ifndef _UVKengine_VulkanHelper_h_
#define _UVKengine_VulkanHelper_h_
#include <Core/Core.h>
#include <vulkan/vulkan.h>
/*
	Vulkan helper class allow you to pick/create vulkan instance device etc...
*/
#if defined(flagASSERTHANDLER)
#define CHECK_HANDLER(x) ASSERT_(x != VK_NULL_HANDLE, "$x is null handler");
#define CHECK_NOT_USED_HANDLER(x) ASSERT_(x == VK_NULL_HANDLE, "$x is not null handler ($x=" + AsString((int*)x) +")");
#else
#define CHECK_HANDLER(x) if(x == VK_NULL_HANDLE) throw Exc("$x is null handler");
#define CHECK_NOT_USED_HANDLER(x)  if(x != VK_NULL_HANDLE) throw Exc("$x is not null handler ($x=" + AsString((int*)x) +")");
#endif

#define AllocatorNullPtr nullptr

namespace Upp{
	
NTL_MOVEABLE(VkLayerProperties);
NTL_MOVEABLE(VkExtensionProperties);
NTL_MOVEABLE(VkQueueFamilyProperties);
NTL_MOVEABLE(VkPresentModeKHR);
NTL_MOVEABLE(VkSurfaceFormatKHR);
NTL_MOVEABLE(VkDeviceQueueCreateInfo);

//To do a custom PhysicalDeviceSelector, just inheritate from this class and define Operator()

class PhysicalDeviceSelector;

class VulkanSelector{
	public:
		VulkanSelector(Vector<String> extensions = {}, Vector<String> validationLayers = {}, Vector<String> deviceExtensions = {});
		
		void AddInstanceExtensions(String str);
		void AddValidationLayers(String str);
		void AddDeviceExtensions(String str);
		
		void RemoveInstanceExtensions(String str);
		void RemoveValidationLayers(String str);
		void RemoveDeviceExtensions(String str);
		
		void ClearInstanceExtensions();
		void ClearValidationLayers();
		void ClearDeviceExtensions();
		
		Vector<const char*> GetInstanceExtensions()const;
		Vector<const char*> GetValidationsLayers()const;
		Vector<const char*> GetDeviceExtensions()const;
		
		int GetInstanceExtensionsCount()const;
		int GetValidationsLayersCount()const;
		int GetDeviceExtensionsCount()const;
		
	private:
		int Find(Vector<String>& list, Upp::String& name);
		Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr)const;
		Vector<String> m_devicesExtensions;
		Vector<String> m_validationLayers;
		Vector<String> m_instanceExtensions;
};

class VulkanHelper{
	public:
		VulkanHelper();
		~VulkanHelper();
		
		bool AutoSelectPhysicalDevice();
		bool SelectPhysicalDevice(PhysicalDeviceSelector& selector);
		bool SelectPhysicalDevice(Upp::String& name);
		
		VkInstance GetInstance()const;
		VkDebugUtilsMessengerEXT GetDebugMessenger()const;
		VkDevice GetDevice()const;
		
		VkInstance CreateInstance(Upp::String appname, unsigned long applicationVersion, Upp::String engineName, unsigned long engineVersion, unsigned long apiVersion);
		VkDebugUtilsMessengerEXT CreateDebugMessenger();
		VkDevice CreateDevice();
		
		void ClearInstance();
		void ClearDebugMessenger();
		void ClearDevice();
		
		void SetMessengerCallback(Function<VkBool32(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*, void*)>);

		VulkanSelector& GetSelector();
	private:
		VkPhysicalDevice GetPhysicalDevice(Upp::String& phyiscalDeviceName);

	

		VulkanSelector m_selector;
		Function<VkBool32(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT*, void*)> m_debugCallback;

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

class PhysicalDeviceSelector{
	public:
		virtual VkPhysicalDevice operator()(VulkanHelper& helper);
	private:
		unsigned int QueryScore(VkPhysicalDevice physicalDevice, VulkanHelper& helper);
		bool checkDeviceExtensionSupport(VkPhysicalDevice& physicalDevice, const Vector<const char*>& extensionsRequired);
};

}
#endif
