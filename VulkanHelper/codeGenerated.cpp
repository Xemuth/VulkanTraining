/*
	Auto generated code
*/
#include "VulkanHelper.h"

namespace Upp{

RULES SelectorFactory& SelectorFactory::SetApiVersion(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.apiVersion, operation, score, crucial, useValueAsScore, "SetApiVersion");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.driverVersion, operation, score, crucial, useValueAsScore, "SetDriverVersion");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.vendorID, operation, score, crucial, useValueAsScore, "SetVendorID");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.deviceID, operation, score, crucial, useValueAsScore, "SetDeviceID");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.deviceType, operation, score, crucial, useValueAsScore, "SetDeviceType");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckStr(param, data.m_deviceProperties.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE , score, crucial,"SetDeviceName");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint8(param, data.m_deviceProperties.pipelineCacheUUID, VK_UUID_SIZE ,operation, score, crucial, useValueAsScore, "SetPipelineCacheUUID");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.robustBufferAccess, operation, score, crucial, useValueAsScore, "SetRobustBufferAccess");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fullDrawIndexUint32, operation, score, crucial, useValueAsScore, "SetFullDrawIndexUint32");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.imageCubeArray, operation, score, crucial, useValueAsScore, "SetImageCubeArray");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.independentBlend, operation, score, crucial, useValueAsScore, "SetIndependentBlend");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.geometryShader, operation, score, crucial, useValueAsScore, "SetGeometryShader");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.tessellationShader, operation, score, crucial, useValueAsScore, "SetTessellationShader");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sampleRateShading, operation, score, crucial, useValueAsScore, "SetSampleRateShading");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.dualSrcBlend, operation, score, crucial, useValueAsScore, "SetDualSrcBlend");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.logicOp, operation, score, crucial, useValueAsScore, "SetLogicOp");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.multiDrawIndirect, operation, score, crucial, useValueAsScore, "SetMultiDrawIndirect");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.drawIndirectFirstInstance, operation, score, crucial, useValueAsScore, "SetDrawIndirectFirstInstance");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthClamp, operation, score, crucial, useValueAsScore, "SetDepthClamp");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthBiasClamp, operation, score, crucial, useValueAsScore, "SetDepthBiasClamp");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fillModeNonSolid, operation, score, crucial, useValueAsScore, "SetFillModeNonSolid");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthBounds, operation, score, crucial, useValueAsScore, "SetDepthBounds");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.wideLines, operation, score, crucial, useValueAsScore, "SetWideLines");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.largePoints, operation, score, crucial, useValueAsScore, "SetLargePoints");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.alphaToOne, operation, score, crucial, useValueAsScore, "SetAlphaToOne");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.multiViewport, operation, score, crucial, useValueAsScore, "SetMultiViewport");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.samplerAnisotropy, operation, score, crucial, useValueAsScore, "SetSamplerAnisotropy");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionETC2, operation, score, crucial, useValueAsScore, "SetTextureCompressionETC2");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionASTC_LDR, operation, score, crucial, useValueAsScore, "SetTextureCompressionASTC_LDR");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionBC, operation, score, crucial, useValueAsScore, "SetTextureCompressionBC");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.occlusionQueryPrecise, operation, score, crucial, useValueAsScore, "SetOcclusionQueryPrecise");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.pipelineStatisticsQuery, operation, score, crucial, useValueAsScore, "SetPipelineStatisticsQuery");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.vertexPipelineStoresAndAtomics, operation, score, crucial, useValueAsScore, "SetVertexPipelineStoresAndAtomics");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fragmentStoresAndAtomics, operation, score, crucial, useValueAsScore, "SetFragmentStoresAndAtomics");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderTessellationAndGeometryPointSize, operation, score, crucial, useValueAsScore, "SetShaderTessellationAndGeometryPointSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderImageGatherExtended, operation, score, crucial, useValueAsScore, "SetShaderImageGatherExtended");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageExtendedFormats, operation, score, crucial, useValueAsScore, "SetShaderStorageImageExtendedFormats");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageMultisample, operation, score, crucial, useValueAsScore, "SetShaderStorageImageMultisample");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageReadWithoutFormat, operation, score, crucial, useValueAsScore, "SetShaderStorageImageReadWithoutFormat");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageWriteWithoutFormat, operation, score, crucial, useValueAsScore, "SetShaderStorageImageWriteWithoutFormat");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderUniformBufferArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderUniformBufferArrayDynamicIndexing");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderSampledImageArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderSampledImageArrayDynamicIndexing");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageBufferArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderStorageBufferArrayDynamicIndexing");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderStorageImageArrayDynamicIndexing");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderClipDistance, operation, score, crucial, useValueAsScore, "SetShaderClipDistance");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderCullDistance, operation, score, crucial, useValueAsScore, "SetShaderCullDistance");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderFloat64, operation, score, crucial, useValueAsScore, "SetShaderFloat64");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderInt64, operation, score, crucial, useValueAsScore, "SetShaderInt64");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderInt16, operation, score, crucial, useValueAsScore, "SetShaderInt16");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderResourceResidency, operation, score, crucial, useValueAsScore, "SetShaderResourceResidency");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderResourceMinLod, operation, score, crucial, useValueAsScore, "SetShaderResourceMinLod");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseBinding, operation, score, crucial, useValueAsScore, "SetSparseBinding");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyBuffer, operation, score, crucial, useValueAsScore, "SetSparseResidencyBuffer");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyImage2D, operation, score, crucial, useValueAsScore, "SetSparseResidencyImage2D");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyImage3D, operation, score, crucial, useValueAsScore, "SetSparseResidencyImage3D");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency2Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency2Samples");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency4Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency4Samples");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency8Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency8Samples");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency16Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency16Samples");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyAliased, operation, score, crucial, useValueAsScore, "SetSparseResidencyAliased");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.variableMultisampleRate, operation, score, crucial, useValueAsScore, "SetVariableMultisampleRate");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.inheritedQueries, operation, score, crucial, useValueAsScore, "SetInheritedQueries");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension1D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension1D");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension2D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension2D");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension3D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension3D");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimensionCube, operation, score, crucial, useValueAsScore, "SetMaxImageDimensionCube");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageArrayLayers, operation, score, crucial, useValueAsScore, "SetMaxImageArrayLayers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelBufferElements, operation, score, crucial, useValueAsScore, "SetMaxTexelBufferElements");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxUniformBufferRange, operation, score, crucial, useValueAsScore, "SetMaxUniformBufferRange");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxStorageBufferRange, operation, score, crucial, useValueAsScore, "SetMaxStorageBufferRange");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPushConstantsSize, operation, score, crucial, useValueAsScore, "SetMaxPushConstantsSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxMemoryAllocationCount, operation, score, crucial, useValueAsScore, "SetMaxMemoryAllocationCount");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxSamplerAllocationCount, operation, score, crucial, useValueAsScore, "SetMaxSamplerAllocationCount");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.bufferImageGranularity, operation, score, crucial, useValueAsScore, "SetBufferImageGranularity");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.sparseAddressSpaceSize, operation, score, crucial, useValueAsScore, "SetSparseAddressSpaceSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxBoundDescriptorSets, operation, score, crucial, useValueAsScore, "SetMaxBoundDescriptorSets");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorSamplers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorSamplers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorUniformBuffers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorUniformBuffers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorStorageBuffers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorStorageBuffers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorSampledImages, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorSampledImages");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorStorageImages, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorStorageImages");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorInputAttachments, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorInputAttachments");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageResources, operation, score, crucial, useValueAsScore, "SetMaxPerStageResources");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetSamplers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetSamplers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetUniformBuffers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetUniformBuffers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetUniformBuffersDynamic, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetUniformBuffersDynamic");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageBuffers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageBuffers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageBuffersDynamic, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageBuffersDynamic");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetSampledImages, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetSampledImages");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageImages, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageImages");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetInputAttachments, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetInputAttachments");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputAttributes, operation, score, crucial, useValueAsScore, "SetMaxVertexInputAttributes");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputBindings, operation, score, crucial, useValueAsScore, "SetMaxVertexInputBindings");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputAttributeOffset, operation, score, crucial, useValueAsScore, "SetMaxVertexInputAttributeOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputBindingStride, operation, score, crucial, useValueAsScore, "SetMaxVertexInputBindingStride");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxVertexOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationGenerationLevel, operation, score, crucial, useValueAsScore, "SetMaxTessellationGenerationLevel");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationPatchSize, operation, score, crucial, useValueAsScore, "SetMaxTessellationPatchSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerVertexInputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerVertexInputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerVertexOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerVertexOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerPatchOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerPatchOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlTotalOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlTotalOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationEvaluationInputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationEvaluationInputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationEvaluationOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationEvaluationOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryShaderInvocations, operation, score, crucial, useValueAsScore, "SetMaxGeometryShaderInvocations");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryInputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryInputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryOutputVertices, operation, score, crucial, useValueAsScore, "SetMaxGeometryOutputVertices");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryTotalOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryTotalOutputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentInputComponents, operation, score, crucial, useValueAsScore, "SetMaxFragmentInputComponents");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentOutputAttachments, operation, score, crucial, useValueAsScore, "SetMaxFragmentOutputAttachments");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentDualSrcAttachments, operation, score, crucial, useValueAsScore, "SetMaxFragmentDualSrcAttachments");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentCombinedOutputResources, operation, score, crucial, useValueAsScore, "SetMaxFragmentCombinedOutputResources");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxComputeSharedMemorySize, operation, score, crucial, useValueAsScore, "SetMaxComputeSharedMemorySize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupCount, 3 ,operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupCount");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupInvocations, operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupInvocations");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupSize, 3 ,operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subPixelPrecisionBits, operation, score, crucial, useValueAsScore, "SetSubPixelPrecisionBits");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subTexelPrecisionBits, operation, score, crucial, useValueAsScore, "SetSubTexelPrecisionBits");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.mipmapPrecisionBits, operation, score, crucial, useValueAsScore, "SetMipmapPrecisionBits");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDrawIndexedIndexValue, operation, score, crucial, useValueAsScore, "SetMaxDrawIndexedIndexValue");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDrawIndirectCount, operation, score, crucial, useValueAsScore, "SetMaxDrawIndirectCount");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxSamplerLodBias, operation, score, crucial, useValueAsScore, "SetMaxSamplerLodBias");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxSamplerAnisotropy, operation, score, crucial, useValueAsScore, "SetMaxSamplerAnisotropy");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxViewports, operation, score, crucial, useValueAsScore, "SetMaxViewports");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxViewportDimensions, 2 ,operation, score, crucial, useValueAsScore, "SetMaxViewportDimensions");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.viewportBoundsRange, 2 ,operation, score, crucial, useValueAsScore, "SetViewportBoundsRange");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.viewportSubPixelBits, operation, score, crucial, useValueAsScore, "SetViewportSubPixelBits");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minMemoryMapAlignment, operation, score, crucial, useValueAsScore, "SetMinMemoryMapAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minTexelBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinTexelBufferOffsetAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minUniformBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinUniformBufferOffsetAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minStorageBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinStorageBufferOffsetAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.minTexelOffset, operation, score, crucial, useValueAsScore, "SetMinTexelOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelOffset, operation, score, crucial, useValueAsScore, "SetMaxTexelOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.minTexelGatherOffset, operation, score, crucial, useValueAsScore, "SetMinTexelGatherOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelGatherOffset, operation, score, crucial, useValueAsScore, "SetMaxTexelGatherOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.minInterpolationOffset, operation, score, crucial, useValueAsScore, "SetMinInterpolationOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxInterpolationOffset, operation, score, crucial, useValueAsScore, "SetMaxInterpolationOffset");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subPixelInterpolationOffsetBits, operation, score, crucial, useValueAsScore, "SetSubPixelInterpolationOffsetBits");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferWidth, operation, score, crucial, useValueAsScore, "SetMaxFramebufferWidth");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferHeight, operation, score, crucial, useValueAsScore, "SetMaxFramebufferHeight");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferLayers, operation, score, crucial, useValueAsScore, "SetMaxFramebufferLayers");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferColorSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferColorSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferDepthSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferDepthSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferStencilSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferStencilSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferNoAttachmentsSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferNoAttachmentsSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxColorAttachments, operation, score, crucial, useValueAsScore, "SetMaxColorAttachments");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageColorSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageColorSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageIntegerSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageIntegerSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageDepthSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageDepthSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageStencilSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageStencilSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.storageImageSampleCounts, operation, score, crucial, useValueAsScore, "SetStorageImageSampleCounts");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxSampleMaskWords, operation, score, crucial, useValueAsScore, "SetMaxSampleMaskWords");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.timestampComputeAndGraphics, operation, score, crucial, useValueAsScore, "SetTimestampComputeAndGraphics");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.timestampPeriod, operation, score, crucial, useValueAsScore, "SetTimestampPeriod");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxClipDistances, operation, score, crucial, useValueAsScore, "SetMaxClipDistances");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxCullDistances, operation, score, crucial, useValueAsScore, "SetMaxCullDistances");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxCombinedClipAndCullDistances, operation, score, crucial, useValueAsScore, "SetMaxCombinedClipAndCullDistances");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.discreteQueuePriorities, operation, score, crucial, useValueAsScore, "SetDiscreteQueuePriorities");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.pointSizeRange, 2 ,operation, score, crucial, useValueAsScore, "SetPointSizeRange");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.lineWidthRange, 2 ,operation, score, crucial, useValueAsScore, "SetLineWidthRange");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.pointSizeGranularity, operation, score, crucial, useValueAsScore, "SetPointSizeGranularity");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.lineWidthGranularity, operation, score, crucial, useValueAsScore, "SetLineWidthGranularity");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.strictLines, operation, score, crucial, useValueAsScore, "SetStrictLines");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.standardSampleLocations, operation, score, crucial, useValueAsScore, "SetStandardSampleLocations");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.optimalBufferCopyOffsetAlignment, operation, score, crucial, useValueAsScore, "SetOptimalBufferCopyOffsetAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.optimalBufferCopyRowPitchAlignment, operation, score, crucial, useValueAsScore, "SetOptimalBufferCopyRowPitchAlignment");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.nonCoherentAtomSize, operation, score, crucial, useValueAsScore, "SetNonCoherentAtomSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard2DBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard2DBlockShape");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard2DMultisampleBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard2DMultisampleBlockShape");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard3DBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard3DBlockShape");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyAlignedMipSize, operation, score, crucial, useValueAsScore, "SetResidencyAlignedMipSize");
	};
	return *this;
}

	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyNonResidentStrict, operation, score, crucial, useValueAsScore, "SetResidencyNonResidentStrict");
	};
	return *this;
}


}