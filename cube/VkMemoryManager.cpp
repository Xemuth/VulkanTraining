#include "VkMemoryManager.h"

VkMemoryManager::VkMemoryManager(int p_size){
	size = p_size;
}

void* VkMemoryManager::Allocate(size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
	LOG("[VkMemoryManager] Allocate: 0x" + Upp::Format64Hex (size) + "bytes");
	void*  ptr = _aligned_malloc(size, alignment);
	return ptr;
}
void* VkMemoryManager::Reallocate(void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
	LOG("[VkMemoryManager] Reallocate: 0x" + Upp::Format64Hex (size) + "bytes");
	void*  ptr = _aligned_realloc(pOriginal,size, alignment);
	return ptr;
}
void VkMemoryManager::MemFree(void* pMemory){
	LOG("[VkMemoryManager] Free: 0x" + Upp::Format64Hex ((unsigned long long)pMemory));
	_aligned_free(pMemory);
}

void VkMemoryManager::InternalAllocate(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	LOG("[VkMemoryManager] Internal allocation: 0x" + Upp::Format64Hex (size) + "bytes");
}

void VkMemoryManager::MemInternalFree(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	LOG("[VkMemoryManager] Internal free: 0x" + Upp::Format64Hex (size) + "bytes");
}