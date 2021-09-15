#include "UVkApp.h"


namespace Upp{
	
NTL_MOVEABLE(VkLayerProperties);
	
UVkApp::UVkApp(UVkCustomAllocator* customAllocator) : m_customAllocator(customAllocator){
	
	VkApplicationInfo vkAppInfo{VK_STRUCTURE_TYPE_APPLICATION_INFO,	nullptr, "UVulkanApp", 1, "UltimateVulkan", 1, VK_API_VERSION_1_0};
	VkInstanceCreateInfo vkInstanceCreate{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, nullptr, 0, &vkAppInfo, 0, nullptr, 0, nullptr};
	#ifdef _DEBUG
		Vector<String> vl = QuerryAllValidationsLayers();
		Vector<const char*> buffer;
		for(String& str : vl){
			LOG("Adding " + str);
			buffer.Add(~str);
		}
		if(CheckValidationLayerSupport(vl.GetCount(), buffer)){
			vkInstanceCreate.enabledLayerCount = vl.GetCount();
			vkInstanceCreate.ppEnabledLayerNames = buffer;
		}
	#endif
	CreateInstance(vkInstanceCreate);
}

UVkApp::UVkApp(const VkInstanceCreateInfo& instanceCreateInfo, UVkCustomAllocator* customAllocator) : m_customAllocator(customAllocator){
	CreateInstance(instanceCreateInfo);
}

UVkApp::~UVkApp(){
	if(m_customAllocator){
		VkAllocationCallbacks allocator = m_customAllocator->GetAllocationCallbacks();
		vkDestroyInstance(m_instance, &allocator);
	}else{
		vkDestroyInstance(m_instance, nullptr);
	}
}

Vector<String> UVkApp::QuerryAllValidationsLayers(){
	unsigned int totalVlCount = 0;
	Vector<const char*> vl;
	Vector<String> validationLayers;
	
	vkEnumerateInstanceLayerProperties(&totalVlCount, nullptr);
	Vector<VkLayerProperties> totalVl(totalVlCount);
	vkEnumerateInstanceLayerProperties(&totalVlCount, totalVl);
	
	for(const VkLayerProperties& lp : totalVl){
		validationLayers.Add(lp.layerName);
	}
	validationLayers.Add(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	return validationLayers;
}

bool UVkApp::CheckValidationLayerSupport(int vlCount, const char* const* vl){
	bool layerFound = false;
	unsigned int totalVlCount = 0;
	vkEnumerateInstanceLayerProperties(&totalVlCount, nullptr);
	Vector<VkLayerProperties> totalVl(totalVlCount);
	vkEnumerateInstanceLayerProperties(&totalVlCount, totalVl);
	for(int i = 0; i < vlCount; i++){
		layerFound = false;
		for(const VkLayerProperties& lp : totalVl){
			if(strcmp(vl[i], lp.layerName) == 0){
				layerFound = true;
				break;
			}
		}
		if(layerFound == false){
			LOG("[UVkApp][CheckValidationLayerSupport] Validation Layer '" + String(vl[i]) +" can't be found in available layer list");
			return false;
		}
	}
	return layerFound;
}

void UVkApp::CreateInstance(const VkInstanceCreateInfo& instanceCreateInfo){
	VkResult vkResult;
	if(m_customAllocator){
		VkAllocationCallbacks allocator = m_customAllocator->GetAllocationCallbacks();
		vkResult= vkCreateInstance(&instanceCreateInfo, &allocator, &m_instance);
	}else{
		vkResult = vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance);
	}
	ASSERT_(vkResult == VK_SUCCESS, "Impossible to initialize Vulkan");
}
Array<UVkPhysicalDevice>& UVkApp::GetPhysicalDevice(bool forceRetrieve){
	if(forceRetrieve || m_phDevices.GetCount() == 0){
		m_phDevices.Clear();
		unsigned int devicesCount = 0;
		VkResult vkResult = vkEnumeratePhysicalDevices(m_instance,&devicesCount, nullptr);
		ASSERT_(vkResult == VK_SUCCESS, "Can't retrieve physical devices count");
		VkPhysicalDevice* physicalsDevices = new VkPhysicalDevice[devicesCount];
		vkResult = vkEnumeratePhysicalDevices(m_instance, &devicesCount, physicalsDevices);
		ASSERT_(vkResult == VK_SUCCESS, "Can't retrieve physical devices");
		for(int e = 0; e < devicesCount; e++){
			m_phDevices.Create(physicalsDevices[e]);
		}
		delete[] physicalsDevices;
	}
	return m_phDevices;
}
VkInstance UVkApp::GetInstance(){return m_instance;}
/*
UVkDevice UVkApp::CreateDevice(const UVkPhysicalDevice& physicalDevice, const VkDeviceCreateInfo& createInfo){
	//custom allocator must be implemented later
	VkDevice dev;
	VkResult vkResult = vkCreateDevice(physicalDevice.GetPhysicalDevice(), &createInfo, nullptr, &dev);
	ASSERT_(vkResult == VK_SUCCESS, "Can't create VkDevice");
	return UVkDevice(dev, physicalDevice);
}
*/


VkDevice UVkApp::CreateDevice(const UVkPhysicalDevice& physicalDevice, Array<VkExtensionProperties>& extenssions, Vector<String>& validationLayers, Array<VkDeviceQueueCreateInfo>& allQueues ){
	VkDevice dev;

	VkDeviceCreateInfo deviceInfo{};
	deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	deviceInfo.pNext = nullptr;
	deviceInfo.flags = 0;
	
	//Queue
	Buffer<VkDeviceQueueCreateInfo> queues(sizeof(VkDeviceQueueCreateInfo) * allQueues.GetCount());
	for(int i = 0; i < allQueues.GetCount(); i++)
		queues[i] = allQueues[i];
	deviceInfo.queueCreateInfoCount = allQueues.GetCount();
	deviceInfo.pQueueCreateInfos = queues;
	
	//Layers
	Vector<const char*> layers;
	for(String& str : validationLayers){
		layers.Add(~str);
	}
	deviceInfo.enabledLayerCount = layers.GetCount();
	deviceInfo.ppEnabledLayerNames = layers;
	
	//Extensions
	Vector<const char*> exts;
	for(const VkExtensionProperties& extenssion : extenssions)
		exts.Add(extenssion.extensionName);
	deviceInfo.enabledExtensionCount = exts.GetCount();
	deviceInfo.ppEnabledExtensionNames = exts;
	
	//Features
	VkPhysicalDeviceFeatures pdf = physicalDevice.GetPhysicalDeviceFeatures();
	deviceInfo.pEnabledFeatures = &pdf;
	
	//Creation
	VkResult vkResult = vkCreateDevice(physicalDevice.GetPhysicalDevice(), &deviceInfo, nullptr, &dev);
	ASSERT_(vkResult == VK_SUCCESS, "Can't create VkDevice");
}

}