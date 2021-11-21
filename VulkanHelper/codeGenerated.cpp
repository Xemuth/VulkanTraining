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
RULES SelectorFactory& SelectorFactory::SetDriverVersion(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.driverVersion, operation, score, crucial, useValueAsScore, "SetDriverVersion");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetVendorID(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.vendorID, operation, score, crucial, useValueAsScore, "SetVendorID");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDeviceID(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.deviceID, operation, score, crucial, useValueAsScore, "SetDeviceID");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDeviceType(VkPhysicalDeviceType param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.deviceType, operation, score, crucial, useValueAsScore, "SetDeviceType");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDeviceName(char* param, int score, bool crucial){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckStr(param, data.m_deviceProperties.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE , score, crucial,"SetDeviceName");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetPipelineCacheUUID(uint8_t* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint8(param, data.m_deviceProperties.pipelineCacheUUID, VK_UUID_SIZE ,operation, score, crucial, useValueAsScore, "SetPipelineCacheUUID");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetRobustBufferAccess(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.robustBufferAccess, operation, score, crucial, useValueAsScore, "SetRobustBufferAccess");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFullDrawIndexUint32(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fullDrawIndexUint32, operation, score, crucial, useValueAsScore, "SetFullDrawIndexUint32");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetImageCubeArray(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.imageCubeArray, operation, score, crucial, useValueAsScore, "SetImageCubeArray");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetIndependentBlend(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.independentBlend, operation, score, crucial, useValueAsScore, "SetIndependentBlend");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetGeometryShader(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.geometryShader, operation, score, crucial, useValueAsScore, "SetGeometryShader");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTessellationShader(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.tessellationShader, operation, score, crucial, useValueAsScore, "SetTessellationShader");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSampleRateShading(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sampleRateShading, operation, score, crucial, useValueAsScore, "SetSampleRateShading");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDualSrcBlend(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.dualSrcBlend, operation, score, crucial, useValueAsScore, "SetDualSrcBlend");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetLogicOp(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.logicOp, operation, score, crucial, useValueAsScore, "SetLogicOp");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMultiDrawIndirect(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.multiDrawIndirect, operation, score, crucial, useValueAsScore, "SetMultiDrawIndirect");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDrawIndirectFirstInstance(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.drawIndirectFirstInstance, operation, score, crucial, useValueAsScore, "SetDrawIndirectFirstInstance");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDepthClamp(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthClamp, operation, score, crucial, useValueAsScore, "SetDepthClamp");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDepthBiasClamp(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthBiasClamp, operation, score, crucial, useValueAsScore, "SetDepthBiasClamp");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFillModeNonSolid(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fillModeNonSolid, operation, score, crucial, useValueAsScore, "SetFillModeNonSolid");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDepthBounds(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.depthBounds, operation, score, crucial, useValueAsScore, "SetDepthBounds");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetWideLines(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.wideLines, operation, score, crucial, useValueAsScore, "SetWideLines");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetLargePoints(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.largePoints, operation, score, crucial, useValueAsScore, "SetLargePoints");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetAlphaToOne(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.alphaToOne, operation, score, crucial, useValueAsScore, "SetAlphaToOne");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMultiViewport(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.multiViewport, operation, score, crucial, useValueAsScore, "SetMultiViewport");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSamplerAnisotropy(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.samplerAnisotropy, operation, score, crucial, useValueAsScore, "SetSamplerAnisotropy");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTextureCompressionETC2(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionETC2, operation, score, crucial, useValueAsScore, "SetTextureCompressionETC2");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTextureCompressionASTC_LDR(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionASTC_LDR, operation, score, crucial, useValueAsScore, "SetTextureCompressionASTC_LDR");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTextureCompressionBC(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.textureCompressionBC, operation, score, crucial, useValueAsScore, "SetTextureCompressionBC");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetOcclusionQueryPrecise(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.occlusionQueryPrecise, operation, score, crucial, useValueAsScore, "SetOcclusionQueryPrecise");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetPipelineStatisticsQuery(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.pipelineStatisticsQuery, operation, score, crucial, useValueAsScore, "SetPipelineStatisticsQuery");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetVertexPipelineStoresAndAtomics(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.vertexPipelineStoresAndAtomics, operation, score, crucial, useValueAsScore, "SetVertexPipelineStoresAndAtomics");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFragmentStoresAndAtomics(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.fragmentStoresAndAtomics, operation, score, crucial, useValueAsScore, "SetFragmentStoresAndAtomics");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderTessellationAndGeometryPointSize(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderTessellationAndGeometryPointSize, operation, score, crucial, useValueAsScore, "SetShaderTessellationAndGeometryPointSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderImageGatherExtended(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderImageGatherExtended, operation, score, crucial, useValueAsScore, "SetShaderImageGatherExtended");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageImageExtendedFormats(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageExtendedFormats, operation, score, crucial, useValueAsScore, "SetShaderStorageImageExtendedFormats");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageImageMultisample(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageMultisample, operation, score, crucial, useValueAsScore, "SetShaderStorageImageMultisample");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageImageReadWithoutFormat(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageReadWithoutFormat, operation, score, crucial, useValueAsScore, "SetShaderStorageImageReadWithoutFormat");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageImageWriteWithoutFormat(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageWriteWithoutFormat, operation, score, crucial, useValueAsScore, "SetShaderStorageImageWriteWithoutFormat");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderUniformBufferArrayDynamicIndexing(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderUniformBufferArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderUniformBufferArrayDynamicIndexing");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderSampledImageArrayDynamicIndexing(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderSampledImageArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderSampledImageArrayDynamicIndexing");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageBufferArrayDynamicIndexing(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageBufferArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderStorageBufferArrayDynamicIndexing");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderStorageImageArrayDynamicIndexing(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderStorageImageArrayDynamicIndexing, operation, score, crucial, useValueAsScore, "SetShaderStorageImageArrayDynamicIndexing");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderClipDistance(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderClipDistance, operation, score, crucial, useValueAsScore, "SetShaderClipDistance");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderCullDistance(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderCullDistance, operation, score, crucial, useValueAsScore, "SetShaderCullDistance");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderFloat64(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderFloat64, operation, score, crucial, useValueAsScore, "SetShaderFloat64");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderInt64(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderInt64, operation, score, crucial, useValueAsScore, "SetShaderInt64");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderInt16(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderInt16, operation, score, crucial, useValueAsScore, "SetShaderInt16");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderResourceResidency(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderResourceResidency, operation, score, crucial, useValueAsScore, "SetShaderResourceResidency");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetShaderResourceMinLod(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.shaderResourceMinLod, operation, score, crucial, useValueAsScore, "SetShaderResourceMinLod");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseBinding(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseBinding, operation, score, crucial, useValueAsScore, "SetSparseBinding");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidencyBuffer(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyBuffer, operation, score, crucial, useValueAsScore, "SetSparseResidencyBuffer");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidencyImage2D(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyImage2D, operation, score, crucial, useValueAsScore, "SetSparseResidencyImage2D");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidencyImage3D(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyImage3D, operation, score, crucial, useValueAsScore, "SetSparseResidencyImage3D");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidency2Samples(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency2Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency2Samples");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidency4Samples(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency4Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency4Samples");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidency8Samples(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency8Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency8Samples");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidency16Samples(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidency16Samples, operation, score, crucial, useValueAsScore, "SetSparseResidency16Samples");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseResidencyAliased(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.sparseResidencyAliased, operation, score, crucial, useValueAsScore, "SetSparseResidencyAliased");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetVariableMultisampleRate(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.variableMultisampleRate, operation, score, crucial, useValueAsScore, "SetVariableMultisampleRate");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetInheritedQueries(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceFeatures.inheritedQueries, operation, score, crucial, useValueAsScore, "SetInheritedQueries");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxImageDimension1D(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension1D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension1D");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxImageDimension2D(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension2D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension2D");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxImageDimension3D(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimension3D, operation, score, crucial, useValueAsScore, "SetMaxImageDimension3D");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxImageDimensionCube(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageDimensionCube, operation, score, crucial, useValueAsScore, "SetMaxImageDimensionCube");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxImageArrayLayers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxImageArrayLayers, operation, score, crucial, useValueAsScore, "SetMaxImageArrayLayers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTexelBufferElements(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelBufferElements, operation, score, crucial, useValueAsScore, "SetMaxTexelBufferElements");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxUniformBufferRange(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxUniformBufferRange, operation, score, crucial, useValueAsScore, "SetMaxUniformBufferRange");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxStorageBufferRange(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxStorageBufferRange, operation, score, crucial, useValueAsScore, "SetMaxStorageBufferRange");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPushConstantsSize(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPushConstantsSize, operation, score, crucial, useValueAsScore, "SetMaxPushConstantsSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxMemoryAllocationCount(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxMemoryAllocationCount, operation, score, crucial, useValueAsScore, "SetMaxMemoryAllocationCount");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxSamplerAllocationCount(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxSamplerAllocationCount, operation, score, crucial, useValueAsScore, "SetMaxSamplerAllocationCount");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetBufferImageGranularity(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.bufferImageGranularity, operation, score, crucial, useValueAsScore, "SetBufferImageGranularity");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSparseAddressSpaceSize(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.sparseAddressSpaceSize, operation, score, crucial, useValueAsScore, "SetSparseAddressSpaceSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxBoundDescriptorSets(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxBoundDescriptorSets, operation, score, crucial, useValueAsScore, "SetMaxBoundDescriptorSets");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorSamplers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorSamplers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorSamplers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorUniformBuffers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorUniformBuffers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorUniformBuffers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorStorageBuffers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorStorageBuffers, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorStorageBuffers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorSampledImages(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorSampledImages, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorSampledImages");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorStorageImages(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorStorageImages, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorStorageImages");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageDescriptorInputAttachments(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageDescriptorInputAttachments, operation, score, crucial, useValueAsScore, "SetMaxPerStageDescriptorInputAttachments");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxPerStageResources(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxPerStageResources, operation, score, crucial, useValueAsScore, "SetMaxPerStageResources");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetSamplers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetSamplers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetSamplers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetUniformBuffers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetUniformBuffers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetUniformBuffers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetUniformBuffersDynamic(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetUniformBuffersDynamic, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetUniformBuffersDynamic");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetStorageBuffers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageBuffers, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageBuffers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetStorageBuffersDynamic(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageBuffersDynamic, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageBuffersDynamic");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetSampledImages(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetSampledImages, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetSampledImages");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetStorageImages(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetStorageImages, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetStorageImages");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDescriptorSetInputAttachments(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDescriptorSetInputAttachments, operation, score, crucial, useValueAsScore, "SetMaxDescriptorSetInputAttachments");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxVertexInputAttributes(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputAttributes, operation, score, crucial, useValueAsScore, "SetMaxVertexInputAttributes");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxVertexInputBindings(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputBindings, operation, score, crucial, useValueAsScore, "SetMaxVertexInputBindings");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxVertexInputAttributeOffset(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputAttributeOffset, operation, score, crucial, useValueAsScore, "SetMaxVertexInputAttributeOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxVertexInputBindingStride(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexInputBindingStride, operation, score, crucial, useValueAsScore, "SetMaxVertexInputBindingStride");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxVertexOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxVertexOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxVertexOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationGenerationLevel(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationGenerationLevel, operation, score, crucial, useValueAsScore, "SetMaxTessellationGenerationLevel");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationPatchSize(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationPatchSize, operation, score, crucial, useValueAsScore, "SetMaxTessellationPatchSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationControlPerVertexInputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerVertexInputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerVertexInputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationControlPerVertexOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerVertexOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerVertexOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationControlPerPatchOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlPerPatchOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlPerPatchOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationControlTotalOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationControlTotalOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationControlTotalOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationEvaluationInputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationEvaluationInputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationEvaluationInputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTessellationEvaluationOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTessellationEvaluationOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxTessellationEvaluationOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxGeometryShaderInvocations(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryShaderInvocations, operation, score, crucial, useValueAsScore, "SetMaxGeometryShaderInvocations");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxGeometryInputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryInputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryInputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxGeometryOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxGeometryOutputVertices(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryOutputVertices, operation, score, crucial, useValueAsScore, "SetMaxGeometryOutputVertices");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxGeometryTotalOutputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxGeometryTotalOutputComponents, operation, score, crucial, useValueAsScore, "SetMaxGeometryTotalOutputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFragmentInputComponents(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentInputComponents, operation, score, crucial, useValueAsScore, "SetMaxFragmentInputComponents");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFragmentOutputAttachments(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentOutputAttachments, operation, score, crucial, useValueAsScore, "SetMaxFragmentOutputAttachments");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFragmentDualSrcAttachments(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentDualSrcAttachments, operation, score, crucial, useValueAsScore, "SetMaxFragmentDualSrcAttachments");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFragmentCombinedOutputResources(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFragmentCombinedOutputResources, operation, score, crucial, useValueAsScore, "SetMaxFragmentCombinedOutputResources");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxComputeSharedMemorySize(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxComputeSharedMemorySize, operation, score, crucial, useValueAsScore, "SetMaxComputeSharedMemorySize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxComputeWorkGroupCount(uint32_t* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupCount, 3 ,operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupCount");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxComputeWorkGroupInvocations(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupInvocations, operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupInvocations");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxComputeWorkGroupSize(uint32_t* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxComputeWorkGroupSize, 3 ,operation, score, crucial, useValueAsScore, "SetMaxComputeWorkGroupSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSubPixelPrecisionBits(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subPixelPrecisionBits, operation, score, crucial, useValueAsScore, "SetSubPixelPrecisionBits");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSubTexelPrecisionBits(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subTexelPrecisionBits, operation, score, crucial, useValueAsScore, "SetSubTexelPrecisionBits");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMipmapPrecisionBits(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.mipmapPrecisionBits, operation, score, crucial, useValueAsScore, "SetMipmapPrecisionBits");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDrawIndexedIndexValue(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDrawIndexedIndexValue, operation, score, crucial, useValueAsScore, "SetMaxDrawIndexedIndexValue");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxDrawIndirectCount(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxDrawIndirectCount, operation, score, crucial, useValueAsScore, "SetMaxDrawIndirectCount");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxSamplerLodBias(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxSamplerLodBias, operation, score, crucial, useValueAsScore, "SetMaxSamplerLodBias");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxSamplerAnisotropy(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxSamplerAnisotropy, operation, score, crucial, useValueAsScore, "SetMaxSamplerAnisotropy");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxViewports(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxViewports, operation, score, crucial, useValueAsScore, "SetMaxViewports");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxViewportDimensions(uint32_t* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayUint32(param, data.m_deviceProperties.limits.maxViewportDimensions, 2 ,operation, score, crucial, useValueAsScore, "SetMaxViewportDimensions");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetViewportBoundsRange(float* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.viewportBoundsRange, 2 ,operation, score, crucial, useValueAsScore, "SetViewportBoundsRange");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetViewportSubPixelBits(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.viewportSubPixelBits, operation, score, crucial, useValueAsScore, "SetViewportSubPixelBits");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinMemoryMapAlignment(size_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minMemoryMapAlignment, operation, score, crucial, useValueAsScore, "SetMinMemoryMapAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinTexelBufferOffsetAlignment(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minTexelBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinTexelBufferOffsetAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinUniformBufferOffsetAlignment(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minUniformBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinUniformBufferOffsetAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinStorageBufferOffsetAlignment(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.minStorageBufferOffsetAlignment, operation, score, crucial, useValueAsScore, "SetMinStorageBufferOffsetAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinTexelOffset(int32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.minTexelOffset, operation, score, crucial, useValueAsScore, "SetMinTexelOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTexelOffset(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelOffset, operation, score, crucial, useValueAsScore, "SetMaxTexelOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinTexelGatherOffset(int32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.minTexelGatherOffset, operation, score, crucial, useValueAsScore, "SetMinTexelGatherOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxTexelGatherOffset(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxTexelGatherOffset, operation, score, crucial, useValueAsScore, "SetMaxTexelGatherOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMinInterpolationOffset(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.minInterpolationOffset, operation, score, crucial, useValueAsScore, "SetMinInterpolationOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxInterpolationOffset(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.maxInterpolationOffset, operation, score, crucial, useValueAsScore, "SetMaxInterpolationOffset");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSubPixelInterpolationOffsetBits(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.subPixelInterpolationOffsetBits, operation, score, crucial, useValueAsScore, "SetSubPixelInterpolationOffsetBits");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFramebufferWidth(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferWidth, operation, score, crucial, useValueAsScore, "SetMaxFramebufferWidth");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFramebufferHeight(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferHeight, operation, score, crucial, useValueAsScore, "SetMaxFramebufferHeight");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxFramebufferLayers(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxFramebufferLayers, operation, score, crucial, useValueAsScore, "SetMaxFramebufferLayers");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFramebufferColorSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferColorSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferColorSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFramebufferDepthSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferDepthSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferDepthSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFramebufferStencilSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferStencilSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferStencilSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetFramebufferNoAttachmentsSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.framebufferNoAttachmentsSampleCounts, operation, score, crucial, useValueAsScore, "SetFramebufferNoAttachmentsSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxColorAttachments(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxColorAttachments, operation, score, crucial, useValueAsScore, "SetMaxColorAttachments");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSampledImageColorSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageColorSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageColorSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSampledImageIntegerSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageIntegerSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageIntegerSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSampledImageDepthSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageDepthSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageDepthSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetSampledImageStencilSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.sampledImageStencilSampleCounts, operation, score, crucial, useValueAsScore, "SetSampledImageStencilSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetStorageImageSampleCounts(VkSampleCountFlags param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.storageImageSampleCounts, operation, score, crucial, useValueAsScore, "SetStorageImageSampleCounts");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxSampleMaskWords(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxSampleMaskWords, operation, score, crucial, useValueAsScore, "SetMaxSampleMaskWords");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTimestampComputeAndGraphics(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.timestampComputeAndGraphics, operation, score, crucial, useValueAsScore, "SetTimestampComputeAndGraphics");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetTimestampPeriod(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.timestampPeriod, operation, score, crucial, useValueAsScore, "SetTimestampPeriod");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxClipDistances(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxClipDistances, operation, score, crucial, useValueAsScore, "SetMaxClipDistances");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxCullDistances(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxCullDistances, operation, score, crucial, useValueAsScore, "SetMaxCullDistances");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetMaxCombinedClipAndCullDistances(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.maxCombinedClipAndCullDistances, operation, score, crucial, useValueAsScore, "SetMaxCombinedClipAndCullDistances");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetDiscreteQueuePriorities(uint32_t param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckUint32(param, data.m_deviceProperties.limits.discreteQueuePriorities, operation, score, crucial, useValueAsScore, "SetDiscreteQueuePriorities");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetPointSizeRange(float* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.pointSizeRange, 2 ,operation, score, crucial, useValueAsScore, "SetPointSizeRange");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetLineWidthRange(float* param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckArrayFloat(param, data.m_deviceProperties.limits.lineWidthRange, 2 ,operation, score, crucial, useValueAsScore, "SetLineWidthRange");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetPointSizeGranularity(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.pointSizeGranularity, operation, score, crucial, useValueAsScore, "SetPointSizeGranularity");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetLineWidthGranularity(float param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckFloat(param, data.m_deviceProperties.limits.lineWidthGranularity, operation, score, crucial, useValueAsScore, "SetLineWidthGranularity");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetStrictLines(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.strictLines, operation, score, crucial, useValueAsScore, "SetStrictLines");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetStandardSampleLocations(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.limits.standardSampleLocations, operation, score, crucial, useValueAsScore, "SetStandardSampleLocations");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetOptimalBufferCopyOffsetAlignment(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.optimalBufferCopyOffsetAlignment, operation, score, crucial, useValueAsScore, "SetOptimalBufferCopyOffsetAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetOptimalBufferCopyRowPitchAlignment(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.optimalBufferCopyRowPitchAlignment, operation, score, crucial, useValueAsScore, "SetOptimalBufferCopyRowPitchAlignment");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetNonCoherentAtomSize(VkDeviceSize param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckDouble(param, data.m_deviceProperties.limits.nonCoherentAtomSize, operation, score, crucial, useValueAsScore, "SetNonCoherentAtomSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetResidencyStandard2DBlockShape(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard2DBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard2DBlockShape");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetResidencyStandard2DMultisampleBlockShape(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard2DMultisampleBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard2DMultisampleBlockShape");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetResidencyStandard3DBlockShape(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyStandard3DBlockShape, operation, score, crucial, useValueAsScore, "SetResidencyStandard3DBlockShape");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetResidencyAlignedMipSize(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyAlignedMipSize, operation, score, crucial, useValueAsScore, "SetResidencyAlignedMipSize");
	};
	return *this;
}
RULES SelectorFactory& SelectorFactory::SetResidencyNonResidentStrict(VkBool32 param, Operation operation, int score, bool crucial, bool useValueAsScore){
	m_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{
		return CheckVkBool32(param, data.m_deviceProperties.sparseProperties.residencyNonResidentStrict, operation, score, crucial, useValueAsScore, "SetResidencyNonResidentStrict");
	};
	return *this;
}


}