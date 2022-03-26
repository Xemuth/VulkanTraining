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

#define RULES
#define AllocatorNullPtr nullptr
#define LLOG(x)  LOG(x)

namespace Upp{
	
NTL_MOVEABLE(VkLayerProperties);
NTL_MOVEABLE(VkExtensionProperties);
NTL_MOVEABLE(VkQueueFamilyProperties);
NTL_MOVEABLE(VkPresentModeKHR);
NTL_MOVEABLE(VkSurfaceFormatKHR);
NTL_MOVEABLE(VkDeviceQueueCreateInfo);


enum class Operation {
	EQUAL=0,
	HIGHER=1,
	LOWER=2,
	EQUAL_OR_HIGHER=3,
	EQUAL_OR_LOWER=4,
	OR=5,
	AND=6
};

struct CurrentPhysicalDeviceData{
	VkPhysicalDevice m_current;
	VkPhysicalDeviceProperties m_deviceProperties;
	VkPhysicalDeviceFeatures m_deviceFeatures;
};

class PhysicalDeviceSelector{
	public:
		PhysicalDeviceSelector(const Upp::Array<Function<int (CurrentPhysicalDeviceData& helper)>>& rules = {});
		PhysicalDeviceSelector(PhysicalDeviceSelector&& pds);
		int operator()(CurrentPhysicalDeviceData& datas);
	protected:
		Upp::Array<Function<int (CurrentPhysicalDeviceData& data)>> m_checks;
};

class SelectorFactory {
	public:
		static SelectorFactory Create();
		PhysicalDeviceSelector Build();
		SelectorFactory(SelectorFactory&& selector);
		//Contain all rules
		#include "VulkanSelectorRules.h"
					
	private:
		template <typename T>
		bool CheckValue(T param, T val, Operation operation);
		template <typename T>
		bool CheckComplex(T param, T val, Operation operation); //Check complexe is hacky thing to prevent compilation error on CheckValue for float and double due to OR and AND operation
		bool CheckValue(double param, double val, Operation operation);
		bool CheckValue(float param, float val, Operation operation);
		const char* GetOperationStr(Operation operation);
		
		int CheckUint32(uint32_t param, uint32_t val, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckDouble(double param, double val, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckVkBool32(VkBool32 param, VkBool32 val, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckFloat(float param, float val, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckStr(char* param, char* val, int size, int score = 10, bool crucial = false, Upp::String functionName="");
		
		int CheckArrayUint32(uint32_t* param, uint32_t* val, int size, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckArrayUint8(uint8_t* param, uint8_t* val, int size, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckArrayDouble(double* param, double* val, int size, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckArrayVkBool32(VkBool32* param, VkBool32* val, int size, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");
		int CheckArrayFloat(float* param, float* val, int size, Operation operation, int score = 10, bool crucial = false, bool useValueAsScore = false, Upp::String functionName="");

		SelectorFactory();
		Upp::Array<Function<int (CurrentPhysicalDeviceData& datas)>> m_checks;
};

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



}
#endif
