#include "VulkanHelper.h"

#define LLOG(x) LOG(x)

namespace Upp{

VkPhysicalDevice PhysicalDeviceSelector::operator()(VulkanHelper& helper){
	CHECK_HANDLER(helper.GetInstance());
	unsigned int physicalDeviceNumber = 0;
	VkResult result = vkEnumeratePhysicalDevices(helper.GetInstance(), &physicalDeviceNumber, nullptr);
	if(result == VK_SUCCESS){
		if(physicalDeviceNumber > 0){
			Vector<VkPhysicalDevice> physicalDevices(physicalDeviceNumber);
			result = vkEnumeratePhysicalDevices(helper.GetInstance(), &physicalDeviceNumber, physicalDevices);
			int scoreMax = 0;
			int position = -1;
			for(int i = 0; i < physicalDeviceNumber; i++){
				int score = QueryScore(physicalDevices[i], helper);
				if(score > scoreMax){
					scoreMax = score;
					position = i;
				}
			}
			if(position != -1){
				VkPhysicalDeviceProperties deviceProperties;
				vkGetPhysicalDeviceProperties(physicalDevices[position], &deviceProperties);
				LLOG("[PhysicalDeviceSelector::operator()][INFO] Physical device chosen is " + String(deviceProperties.deviceName));
				return physicalDevices[position];
			}else{
				LLOG("[PhysicalDeviceSelector::operator()][ERROR] No vulkan suitable physdical device have been found");
			}
		}else{
			LLOG("[PhysicalDeviceSelector::operator()][ERROR] No vulkan physdical device have been found");
		}
	}else{
		LLOG("[PhysicalDeviceSelector::operator()][ERROR] Impossible to querry physical device");
	}
	return VK_NULL_HANDLE;
}

unsigned int PhysicalDeviceSelector::QueryScore(VkPhysicalDevice physicalDevice, VulkanHelper& helper){
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
	if(!checkDeviceExtensionSupport(physicalDevice, helper.GetSelector().GetDeviceExtensions())){
		return 0;
	}
    return score;
}

bool PhysicalDeviceSelector::checkDeviceExtensionSupport(VkPhysicalDevice& physicalDevice, const Vector<const char*>& extensionsRequired) {
    unsigned int extensionCount;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);
    Vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, availableExtensions);

	Index<String> requiredExtensions;
	for(const char* ptr : extensionsRequired){
		requiredExtensions.Add(ptr);
	}
	
    for (const auto& extension : availableExtensions) {
        requiredExtensions.RemoveKey(extension.extensionName);
    }

    return requiredExtensions.GetCount() == 0;
}
	
}