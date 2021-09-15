#ifndef _VulkanCommand_VkApp_h_
#define _VulkanCommand_VkApp_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif
#include "UVkPhysicalDevice.h"
#include "UVkCustomAllocator.h"
namespace Upp{

class UVkApp{
	public:
		UVkApp(UVkCustomAllocator* customAllocator= nullptr);
		UVkApp(const VkInstanceCreateInfo& instanceCreateInfo, UVkCustomAllocator* customAllocator = nullptr);
		~UVkApp();
		
		VkDevice CreateDevice(const UVkPhysicalDevice& physicalDevice, Array<VkExtensionProperties>& extenssions, Vector<String>& validationLayers, Array<VkDeviceQueueCreateInfo>& allQueues);
		
	//	UVkDevice CreateDevice(const UVkPhysicalDevice& physicalDevice, const VkDeviceCreateInfo& createInfo);
		
		Array<UVkPhysicalDevice>& GetPhysicalDevice(bool forceRetrieve = false);
		
		Vector<String> GetInstanceValidationLayers(Vector<String>& filter); //Filter allow to only retrieve wanted validation layer
		Array<VkExtensionProperties> GetInstanceExtensionProperties();
		
		bool CheckValidationLayersSupport(Vector<String>& validationLayers);
		bool CheckExtenssionPropertiesSupport(Vector<String>& extenssionName);
		
		VkInstance GetInstance();
		inline operator VkInstance(){return m_instance;}
	private:
		bool CheckValidationLayerSupport(int vlCount, const char* const* vl);
		Vector<String> QuerryAllValidationsLayers();
		void CreateInstance(const VkInstanceCreateInfo& instanceCreateInfo);
		UVkCustomAllocator* m_customAllocator = nullptr;
		VkInstance m_instance;
		Array<UVkPhysicalDevice> m_phDevices;
		#ifdef _DEBUG
			PFN_vkCreateDebugUtilsMessengerEXT debugFunc;
		#endif
};

}
#endif
