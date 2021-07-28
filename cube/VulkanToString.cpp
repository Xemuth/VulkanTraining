#include "VulkanToString.h"

Upp::String GenTab(int count){
	Upp::String str;
	for(int e = 0; e < count; e++)
		str << "\t";
	return str;
}

Upp::String ToStringMemoryType(VkMemoryType& memoryType, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Memory type -------\n";
	str << "\t" << GenTab(numTab) << "heapIndex: " << memoryType.heapIndex  << "\n";
	str << "\t" << GenTab(numTab) << "propertyFlags: " << Upp::FormatIntHex(memoryType.propertyFlags) << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_HOST_COHERENT_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_HOST_CACHED_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_HOST_CACHED_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_PROTECTED_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_PROTECTED_BIT" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD" << "\n";
	if(memoryType.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD" << "\n";
	return str;
}

Upp::String ToStringMemoryHeap(VkMemoryHeap& memoryHeap, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Memory heap -------\n";
	str << "\t" << GenTab(numTab) << "heapIndex: " << memoryHeap.size  <<" bytes (" << ((memoryHeap.size /1024)/1024) <<" megabytes)\n";
	str << "\t" << GenTab(numTab) << "flags: " << Upp::FormatIntHex(memoryHeap.flags) << "\n";
	if(memoryHeap.flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_HEAP_DEVICE_LOCAL_BIT" << "\n";
	if(memoryHeap.flags & VK_MEMORY_HEAP_MULTI_INSTANCE_BIT) str << "\t\t" << GenTab(numTab) << "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT" << "\n";
	return str;
}

Upp::String ToStringExtent3D (VkExtent3D& vkE3D, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Extent 3D -------\n";
	str << "\t" << GenTab(numTab) << "width: " << Upp::FormatIntHex(vkE3D.width)  << "\n";
	str << "\t" << GenTab(numTab) << "height: " << Upp::FormatIntHex(vkE3D.height)  << "\n";
	str << "\t" << GenTab(numTab) << "depth: " << Upp::FormatIntHex(vkE3D.depth)  << "\n";
	return str;
}

Upp::String ToStringPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties& vkPDMP, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Device memory -------\n";
	str << "\t" << GenTab(numTab) << "memoryTypeCount: " << vkPDMP.memoryTypeCount << "\n";
	for(unsigned int i = 0; i < vkPDMP.memoryTypeCount; i++){
		str << "\t" << ToStringMemoryType(vkPDMP.memoryTypes[i],numTab + 1);
	}
	str << "\t" << GenTab(numTab) << "memoryHeapCount: " << vkPDMP.memoryHeapCount << "\n";
	for(unsigned int i = 0; i < vkPDMP.memoryHeapCount; i++){
		str << "\t" << ToStringMemoryHeap(vkPDMP.memoryHeaps[i],numTab + 1);
	}
	return str;
}

Upp::String ToStringPhysicalDeviceFeatures(VkPhysicalDeviceFeatures& vkPDF, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Features -------\n";
	str << "\t" << GenTab(numTab) << "robustBufferAccess: " << (bool)vkPDF.robustBufferAccess << "\n";
	 str << "\t" << GenTab(numTab) << "fullDrawIndexUint32: " <<	(bool)vkPDF.fullDrawIndexUint32 << "\n";
	 str << "\t" << GenTab(numTab) << "imageCubeArray: " << (bool)vkPDF.imageCubeArray << "\n";
	 str << "\t" << GenTab(numTab) << "independentBlend: " << (bool)vkPDF.independentBlend << "\n";
	 str << "\t" << GenTab(numTab) << "geometryShader: " << (bool)vkPDF.geometryShader << "\n";
	 str << "\t" << GenTab(numTab) << "tessellationShader: " << (bool)vkPDF.tessellationShader << "\n";
	 str << "\t" << GenTab(numTab) << "sampleRateShading: " << (bool)vkPDF.sampleRateShading << "\n";
	 str << "\t" << GenTab(numTab) << "dualSrcBlend: " << (bool)vkPDF.dualSrcBlend << "\n";
	 str << "\t" << GenTab(numTab) << "logicOp: " << (bool)vkPDF.logicOp << "\n";
	 str << "\t" << GenTab(numTab) << "multiDrawIndirect: " << (bool)vkPDF.multiDrawIndirect << "\n";
	 str << "\t" << GenTab(numTab) << "drawIndirectFirstInstance: " << (bool)vkPDF.drawIndirectFirstInstance << "\n";
	 str << "\t" << GenTab(numTab) << "depthClamp: " << (bool)vkPDF.depthClamp << "\n";
	 str << "\t" << GenTab(numTab) << "depthBiasClamp: " << (bool)vkPDF.depthBiasClamp << "\n";
	 str << "\t" << GenTab(numTab) << "fillModeNonSolid: " << (bool)vkPDF.fillModeNonSolid << "\n";
	 str << "\t" << GenTab(numTab) << "depthBounds: " << (bool)vkPDF.depthBounds << "\n";
	 str << "\t" << GenTab(numTab) << "wideLines: " << (bool)vkPDF.wideLines << "\n";
	 str << "\t" << GenTab(numTab) << "largePoints: " << (bool)vkPDF.largePoints << "\n";
	 str << "\t" << GenTab(numTab) << "alphaToOne: " << (bool)vkPDF.alphaToOne << "\n";
	 str << "\t" << GenTab(numTab) << "multiViewport: " << (bool)vkPDF.multiViewport << "\n";
	 str << "\t" << GenTab(numTab) << "samplerAnisotropy: " << (bool)vkPDF.samplerAnisotropy << "\n";
	 str << "\t" << GenTab(numTab) << "textureCompressionETC2: " << (bool)vkPDF.textureCompressionETC2 << "\n";
	 str << "\t" << GenTab(numTab) << "textureCompressionASTC_LDR: " << (bool)vkPDF.textureCompressionASTC_LDR << "\n";
	 str << "\t" << GenTab(numTab) << "textureCompressionBC: " << (bool)vkPDF.textureCompressionBC << "\n";
	 str << "\t" << GenTab(numTab) << "occlusionQueryPrecise: " << (bool)vkPDF.occlusionQueryPrecise << "\n";
	 str << "\t" << GenTab(numTab) << "pipelineStatisticsQuery: " << (bool)vkPDF.pipelineStatisticsQuery << "\n";
	 str << "\t" << GenTab(numTab) << "vertexPipelineStoresAndAtomics: " << (bool)vkPDF.vertexPipelineStoresAndAtomics << "\n";
	 str << "\t" << GenTab(numTab) << "fragmentStoresAndAtomics: " << (bool)vkPDF.fragmentStoresAndAtomics << "\n";
	 str << "\t" << GenTab(numTab) << "shaderTessellationAndGeometryPointSize: " << (bool)vkPDF.shaderTessellationAndGeometryPointSize << "\n";
	 str << "\t" << GenTab(numTab) << "shaderImageGatherExtended: " << (bool)vkPDF.shaderImageGatherExtended << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageImageExtendedFormats: " << (bool)vkPDF.shaderStorageImageExtendedFormats << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageImageMultisample: " << (bool)vkPDF.shaderStorageImageMultisample << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageImageReadWithoutFormat: " << (bool)vkPDF.shaderStorageImageReadWithoutFormat << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageImageWriteWithoutFormat: " << (bool)vkPDF.shaderStorageImageWriteWithoutFormat << "\n";
	 str << "\t" << GenTab(numTab) << "shaderUniformBufferArrayDynamicIndexing: " << (bool)vkPDF.shaderUniformBufferArrayDynamicIndexing << "\n";
	 str << "\t" << GenTab(numTab) << "shaderSampledImageArrayDynamicIndexing: " << (bool)vkPDF.shaderSampledImageArrayDynamicIndexing << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageBufferArrayDynamicIndexing: " << (bool)vkPDF.shaderStorageBufferArrayDynamicIndexing << "\n";
	 str << "\t" << GenTab(numTab) << "shaderStorageImageArrayDynamicIndexing: " << (bool)vkPDF.shaderStorageImageArrayDynamicIndexing << "\n";
	 str << "\t" << GenTab(numTab) << "shaderClipDistance: " << (bool)vkPDF.shaderClipDistance << "\n";
	 str << "\t" << GenTab(numTab) << "shaderCullDistance: " << (bool)vkPDF.shaderCullDistance << "\n";
	 str << "\t" << GenTab(numTab) << "shaderFloat64: " << (bool)vkPDF.shaderFloat64 << "\n";
	 str << "\t" << GenTab(numTab) << "shaderInt64: " << (bool)vkPDF.shaderInt64 << "\n";
	 str << "\t" << GenTab(numTab) << "shaderInt16: " << (bool)vkPDF.shaderInt16 << "\n";
	 str << "\t" << GenTab(numTab) << "shaderResourceResidency: " << (bool)vkPDF.shaderResourceResidency << "\n";
	 str << "\t" << GenTab(numTab) << "shaderResourceMinLod: " << (bool)vkPDF.shaderResourceMinLod << "\n";
	 str << "\t" << GenTab(numTab) << "sparseBinding: " << (bool)vkPDF.sparseBinding << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidencyBuffer: " << (bool)vkPDF.sparseResidencyBuffer << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidencyImage2D: " << (bool)vkPDF.sparseResidencyImage2D << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidencyImage3D: " << (bool)vkPDF.sparseResidencyImage3D << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidency2Samples: " << (bool)vkPDF.sparseResidency2Samples << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidency4Samples: " << (bool)vkPDF.sparseResidency4Samples << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidency8Samples: " << (bool)vkPDF.sparseResidency8Samples << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidency16Samples: " << (bool)vkPDF.sparseResidency16Samples << "\n";
	 str << "\t" << GenTab(numTab) << "sparseResidencyAliased: " << (bool)vkPDF.sparseResidencyAliased << "\n";
	 str << "\t" << GenTab(numTab) << "variableMultisampleRate: " << (bool)vkPDF.variableMultisampleRate << "\n";
	 str << "\t" << GenTab(numTab) << "inheritedQueries: " << (bool)vkPDF.inheritedQueries << "\n";
	return str;
}

Upp::String ToStringPhysicalDeviceProperties(VkPhysicalDeviceProperties& vkPDP, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- " << vkPDP.deviceName << " -------\n";
	str << "\t" << GenTab(numTab) << "apiVersion: " << vkPDP.apiVersion << "\n";
	str << "\t" << GenTab(numTab) << "driverVersion: " << vkPDP.driverVersion << "\n";
	str << "\t" << GenTab(numTab) << "vendorID: " << vkPDP.vendorID << "\n";
	str << "\t" << GenTab(numTab) << "deviceID: " << vkPDP.deviceID << "\n";
	//TODO Pipeline cache UUID & VkPhysicalDeviceType
	//str << "\tdeviceType: " << vkPDP.deviceType << "\n";
	return str;
}

Upp::String ToStringQueueFamilyProperties(VkQueueFamilyProperties& vkQFP, int numTab){
	Upp::String str;
	str << GenTab(numTab) << "------- Queue family properties -------\n";
	str << "\t" << GenTab(numTab) << "queueFlags: " << Upp::FormatIntHex(vkQFP.queueFlags)  << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_GRAPHICS_BIT) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_GRAPHICS_BIT" << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_COMPUTE_BIT) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_COMPUTE_BIT" << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_TRANSFER_BIT) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_TRANSFER_BIT" << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_SPARSE_BINDING_BIT" << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_PROTECTED_BIT) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_PROTECTED_BIT" << "\n";
#ifdef VK_ENABLE_BETA_EXTENSIONS
	if(vkQFP.queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_VIDEO_DECODE_BIT_KHR" << "\n";
	if(vkQFP.queueFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR) str << "\t\t" << GenTab(numTab) << "VK_QUEUE_VIDEO_ENCODE_BIT_KHR" << "\n";
#endif
	str << "\t" << GenTab(numTab) << "queueCount: " << vkQFP.queueCount << "\n";
	str << "\t" << GenTab(numTab) << "timestampValidBits: " << vkQFP.timestampValidBits << "\n";
	str << "\t" << ToStringExtent3D(vkQFP.minImageTransferGranularity, numTab + 1);
	return str;
}

