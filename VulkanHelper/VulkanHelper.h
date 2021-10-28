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

class SelectorFactory {
	public:
		enum class Operation {
			EQUAL=0,
			HIGHER=1,
			LOWER=2
		};
		
		SelectorFactory();
		
		PhysicalDeviceSelector Build();
		
		SelectorFactory& AddCustomRules(Function<int (VulkanHelper& helper));
		
		//VkPhysicalDeviceProperties selector
		SelectorFactory& SetApiVersion(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false){}
		SelectorFactory& SetDriverVersion(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDeviceID(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetVendorID(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDeviceType(VkPhysicalDeviceType param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDeviceName(char* param, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPipelineCacheUUID(uint8_t* param, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		
		//VkPhysicalDeviceLimits selector
		SelectorFactory& SetMaxImageDimension1D(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false){}
		SelectorFactory& SetMaxImageDimension2D(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxImageDimension3D(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxImageDimensionCube(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxImageArrayLayer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTexelBufferElement(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxUniformBufferRang(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxStorageBufferRang(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPushConstantsSiz(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxMemoryAllocationCoun(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSamplerAllocationCoun(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetBufferImageGranularit(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseAddressSpaceSiz(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxBoundDescriptorSet(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorSampler(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorUniformBuffer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorStorageBuffer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorSampledImage(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorStorageImage(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageDescriptorInputAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxPerStageResource(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetSampler(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetUniformBuffer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetUniformBuffersDynami(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetStorageBuffer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetStorageBuffersDynami(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetSampledImage(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetStorageImage(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDescriptorSetInputAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxVertexInputAttribute(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxVertexInputBinding(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxVertexInputAttributeOffse(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxVertexInputBindingStrid(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxVertexOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationGenerationLeve(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationPatchSiz(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationControlPerVertexInputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationControlPerVertexOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationControlPerPatchOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationControlTotalOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationEvaluationInputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTessellationEvaluationOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxGeometryShaderInvocation(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxGeometryInputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxGeometryOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxGeometryOutputVertice(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxGeometryTotalOutputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFragmentInputComponent(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFragmentOutputAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFragmentDualSrcAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFragmentCombinedOutputResource(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxComputeSharedMemorySiz(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxComputeWorkGroupCount(uint32_t param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxComputeWorkGroupInvocation(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxComputeWorkGroupSize(uint32_t param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSubPixelPrecisionBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSubTexelPrecisionBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMipmapPrecisionBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDrawIndexedIndexValu(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDrawIndirectCoun(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSamplerLodBia(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSamplerAnisotrop(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxViewport(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxViewportDimensions(uint32_t param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetViewportBoundsRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetViewportSubPixelBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinMemoryMapAlignmen(size_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinUniformBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinStorageBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelOffse(int32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTexelOffse(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelGatherOffse(int32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTexelGatherOffse(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinInterpolationOffse(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxInterpolationOffse(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSubPixelInterpolationOffsetBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferWidt(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferHeigh(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferLayer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferColorSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferDepthSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferStencilSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferNoAttachmentsSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxColorAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageColorSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageIntegerSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageDepthSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageStencilSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStorageImageSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSampleMaskWord(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTimestampComputeAndGraphic(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTimestampPerio(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxClipDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxCullDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxCombinedClipAndCullDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDiscreteQueuePrioritie(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPointSizeRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLineWidthRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPointSizeGranularit(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLineWidthGranularit(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStrictLine(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStandardSampleLocation(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetOptimalBufferCopyOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetOptimalBufferCopyRowPitchAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetNonCoherentAtomSiz(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		
		// VkPhysicalDeviceFeatures selector
		SelectorFactory& SetRobustBufferAcces(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFullDrawIndexUint3(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetImageCubeArra(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetIndependentBlen(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetGeometryShade(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTessellationShade(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampleRateShadin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDualSrcBlen(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLogicO(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMultiDrawIndirec(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDrawIndirectFirstInstanc(VkBool32 para, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDepthClam(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDepthBiasClam(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFillModeNonSoli(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDepthBound(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetWideLine(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLargePoint(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetAlphaToOn(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMultiViewpor(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSamplerAnisotrop(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTextureCompressionETC(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTextureCompressionASTC_LD(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTextureCompressionB(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetOcclusionQueryPrecis(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPipelineStatisticsQuer(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetVertexPipelineStoresAndAtomic(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFragmentStoresAndAtomic(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderTessellationAndGeometryPointSiz(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderImageGatherExtende(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageImageExtendedFormat(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageImageMultisampl(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageImageReadWithoutForma(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageImageWriteWithoutForma(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderUniformBufferArrayDynamicIndexin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderSampledImageArrayDynamicIndexin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageBufferArrayDynamicIndexin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderStorageImageArrayDynamicIndexin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderClipDistanc(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderCullDistanc(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderFloat6(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderInt6(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderInt1(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderResourceResidenc(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetShaderResourceMinLo(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseBindin(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidencyBuffe(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidencyImage2(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidencyImage3(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidency2Sample(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidency4Sample(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidency8Sample(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidency16Sample(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSparseResidencyAliase(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetVariableMultisampleRat(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetInheritedQuerie(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxDrawIndirectCoun(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSamplerLodBia(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSamplerAnisotrop(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxViewport(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxViewportDimensions(uint32_t param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetViewportBoundsRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetViewportSubPixelBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinMemoryMapAlignmen(size_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinUniformBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinStorageBufferOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelOffse(int32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTexelOffse(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinTexelGatherOffse(int32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxTexelGatherOffse(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMinInterpolationOffse(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxInterpolationOffse(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSubPixelInterpolationOffsetBit(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferWidt(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferHeigh(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxFramebufferLayer(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferColorSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferDepthSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferStencilSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetFramebufferNoAttachmentsSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxColorAttachment(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageColorSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageIntegerSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageDepthSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetSampledImageStencilSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStorageImageSampleCount(VkSampleCountFlags param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxSampleMaskWord(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTimestampComputeAndGraphic(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetTimestampPerio(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxClipDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxCullDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetMaxCombinedClipAndCullDistance(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetDiscreteQueuePrioritie(uint32_t param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPointSizeRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLineWidthRange(float param*, int size, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetPointSizeGranularit(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetLineWidthGranularit(float param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStrictLine(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetStandardSampleLocation(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetOptimalBufferCopyOffsetAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetOptimalBufferCopyRowPitchAlignmen(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetNonCoherentAtomSiz(VkDeviceSize param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);

		// VkPhysicalDeviceSparseProperties selector
		SelectorFactory& SetResidencyStandard2DBlockShap(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetResidencyStandard2DMultisampleBlockShap(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetResidencyStandard3DBlockShap(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetResidencyAlignedMipSiz(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		SelectorFactory& SetResidencyNonResidentStric(VkBool32 param, SelectorFactory::Operation = SelectorFactory::Operation::HIGHER, int scoreMultiply = 1, int score = 10, bool crucial = false);
		
		class PhysicalDeviceSelector{
			public:
				PhysicalDeviceSelector(Upp::Array<Function<int (VulkanHelper& helper)>& rules = {});
				VkPhysicalDevice operator()(VulkanHelper& helper);
			protected:
				friend SelectorFactory;
				//Return 0 if operation is true, 1 if false
				int CheckForString(SelectorFactory::Operation operation, void* data, int offset, const char* param);
				int CheckForUint64(SelectorFactory::Operation operation, void* data, int offset, uint64_t param)
				int CheckForUint32(SelectorFactory::Operation operation, void* data, int offset, uint32_t param);
				int CheckForFloat(SelectorFactory::Operation operation, void* data, int offset, float param);
				int CheckForBool(SelectorFactory::Operation operation, void* data, int offset, VkBool32 param);
				
				Upp::Array<Function<int (VulkanHelper& helper)> m_checks;
		};
		
	private:
		Upp::Array<Function<int (VulkanHelper& helper)> m_checks;
		
		VkPhysicalDeviceProperties m_devicesProperties;
		VkPhysicalDeviceFeatures m_devicesFeatures;
		VkPhysicalDeviceLimits m_deviceLimits;
		VkPhysicalDeviceSparseProperties m_sparseProperties;
		
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
