/*
	Auto generated header. To be included within SelectorFactory class
*/
//VkPhysicalDeviceProperties part
RULES SelectorFactory& SetApiVersion(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDriverVersion(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetVendorID(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDeviceID(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDeviceType(VkPhysicalDeviceType param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDeviceName(char* param, int score = 10, bool crucial = false);
RULES SelectorFactory& SetPipelineCacheUUID(uint8_t* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
//VkPhysicalDeviceFeatures part
RULES SelectorFactory& SetRobustBufferAccess(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFullDrawIndexUint32(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetImageCubeArray(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetIndependentBlend(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetGeometryShader(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTessellationShader(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSampleRateShading(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDualSrcBlend(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetLogicOp(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMultiDrawIndirect(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDrawIndirectFirstInstance(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDepthClamp(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDepthBiasClamp(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFillModeNonSolid(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDepthBounds(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetWideLines(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetLargePoints(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetAlphaToOne(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMultiViewport(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSamplerAnisotropy(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTextureCompressionETC2(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTextureCompressionASTC_LDR(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTextureCompressionBC(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetOcclusionQueryPrecise(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetPipelineStatisticsQuery(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetVertexPipelineStoresAndAtomics(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFragmentStoresAndAtomics(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderTessellationAndGeometryPointSize(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderImageGatherExtended(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageImageExtendedFormats(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageImageMultisample(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageImageReadWithoutFormat(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageImageWriteWithoutFormat(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderUniformBufferArrayDynamicIndexing(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderSampledImageArrayDynamicIndexing(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageBufferArrayDynamicIndexing(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderStorageImageArrayDynamicIndexing(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderClipDistance(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderCullDistance(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderFloat64(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderInt64(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderInt16(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderResourceResidency(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetShaderResourceMinLod(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseBinding(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidencyBuffer(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidencyImage2D(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidencyImage3D(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidency2Samples(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidency4Samples(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidency8Samples(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidency16Samples(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseResidencyAliased(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetVariableMultisampleRate(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetInheritedQueries(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
//VkPhysicalDeviceLimits part
RULES SelectorFactory& SetMaxImageDimension1D(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxImageDimension2D(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxImageDimension3D(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxImageDimensionCube(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxImageArrayLayers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTexelBufferElements(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxUniformBufferRange(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxStorageBufferRange(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPushConstantsSize(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxMemoryAllocationCount(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxSamplerAllocationCount(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetBufferImageGranularity(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSparseAddressSpaceSize(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxBoundDescriptorSets(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorSamplers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorUniformBuffers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorStorageBuffers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorSampledImages(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorStorageImages(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageDescriptorInputAttachments(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxPerStageResources(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetSamplers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetUniformBuffers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetUniformBuffersDynamic(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetStorageBuffers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetStorageBuffersDynamic(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetSampledImages(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetStorageImages(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDescriptorSetInputAttachments(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxVertexInputAttributes(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxVertexInputBindings(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxVertexInputAttributeOffset(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxVertexInputBindingStride(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxVertexOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationGenerationLevel(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationPatchSize(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationControlPerVertexInputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationControlPerVertexOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationControlPerPatchOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationControlTotalOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationEvaluationInputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTessellationEvaluationOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxGeometryShaderInvocations(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxGeometryInputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxGeometryOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxGeometryOutputVertices(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxGeometryTotalOutputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFragmentInputComponents(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFragmentOutputAttachments(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFragmentDualSrcAttachments(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFragmentCombinedOutputResources(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxComputeSharedMemorySize(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxComputeWorkGroupCount(uint32_t* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxComputeWorkGroupInvocations(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxComputeWorkGroupSize(uint32_t* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSubPixelPrecisionBits(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSubTexelPrecisionBits(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMipmapPrecisionBits(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDrawIndexedIndexValue(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxDrawIndirectCount(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxSamplerLodBias(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxSamplerAnisotropy(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxViewports(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxViewportDimensions(uint32_t* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetViewportBoundsRange(float* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetViewportSubPixelBits(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinMemoryMapAlignment(size_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinTexelBufferOffsetAlignment(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinUniformBufferOffsetAlignment(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinStorageBufferOffsetAlignment(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinTexelOffset(int32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTexelOffset(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinTexelGatherOffset(int32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxTexelGatherOffset(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMinInterpolationOffset(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxInterpolationOffset(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSubPixelInterpolationOffsetBits(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFramebufferWidth(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFramebufferHeight(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxFramebufferLayers(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFramebufferColorSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFramebufferDepthSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFramebufferStencilSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetFramebufferNoAttachmentsSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxColorAttachments(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSampledImageColorSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSampledImageIntegerSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSampledImageDepthSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetSampledImageStencilSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetStorageImageSampleCounts(VkSampleCountFlags param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxSampleMaskWords(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTimestampComputeAndGraphics(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetTimestampPeriod(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxClipDistances(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxCullDistances(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetMaxCombinedClipAndCullDistances(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetDiscreteQueuePriorities(uint32_t param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetPointSizeRange(float* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetLineWidthRange(float* param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetPointSizeGranularity(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetLineWidthGranularity(float param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetStrictLines(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetStandardSampleLocations(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetOptimalBufferCopyOffsetAlignment(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetOptimalBufferCopyRowPitchAlignment(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetNonCoherentAtomSize(VkDeviceSize param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
//VkPhysicalDeviceSparseProperties part
RULES SelectorFactory& SetResidencyStandard2DBlockShape(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetResidencyStandard2DMultisampleBlockShape(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetResidencyStandard3DBlockShape(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetResidencyAlignedMipSize(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
RULES SelectorFactory& SetResidencyNonResidentStrict(VkBool32 param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);
