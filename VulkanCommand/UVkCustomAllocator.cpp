#include "UVkCustomAllocator.h"
#include <malloc.h>

namespace Upp{

Upp::Array<unsigned long long> UVkCustomAllocator::leakTracker;

UVkCustomAllocator::UVkCustomAllocator(Function<void* (size_t, size_t, VkSystemAllocationScope)> callbackAllocation,
				   Function<void* (void*, size_t, size_t, VkSystemAllocationScope)> callbackReallocation,
				   Function<void  (void*)> callbackFree,
				   Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> callbackInternalAllocationNotification,
				   Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> callbackInternalFreeNotification){
	m_callbackAllocation = DefaultAllocation;
	m_callbackReallocation = DefaultReallocation;
	m_callbackFree = DefaultFree;
	m_callbackInternalAllocationNotification = DefaultInternalAllocationNotification;
	m_callbackInternalFreeNotification = DefaultInternalFreeNotification;
	
	if(callbackAllocation)
		m_callbackAllocation = callbackAllocation;
	if(callbackReallocation)
		m_callbackReallocation = callbackReallocation;
	if(callbackFree)
		m_callbackFree = callbackFree;
	if(callbackInternalAllocationNotification)
		m_callbackInternalAllocationNotification = callbackInternalAllocationNotification;
	if(callbackInternalFreeNotification)
		m_callbackInternalFreeNotification = callbackInternalFreeNotification;
}

void* VKAPI_CALL UVkCustomAllocator::SAllocation(void* pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
	return static_cast<UVkCustomAllocator*>(pUserData)->m_callbackAllocation(size, alignment, allocationScope);
}
void* VKAPI_CALL UVkCustomAllocator::SReallocation(void* pUserData, void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
	return static_cast<UVkCustomAllocator*>(pUserData)->m_callbackReallocation(pOriginal, size, alignment, allocationScope);
}
void  VKAPI_CALL UVkCustomAllocator::SFree(void* pUserData, void* pMemory){
	return static_cast<UVkCustomAllocator*>(pUserData)->m_callbackFree(pMemory);
}
void  VKAPI_CALL UVkCustomAllocator::SInternalAllocationNotification(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	return static_cast<UVkCustomAllocator*>(pUserData)->m_callbackInternalAllocationNotification(size, allocationType, allocationScope);
}
void  VKAPI_CALL UVkCustomAllocator::SInternalFreeNotification(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	return static_cast<UVkCustomAllocator*>(pUserData)->m_callbackInternalFreeNotification(size, allocationType, allocationScope);
}

void* UVkCustomAllocator::DefaultAllocation(size_t size, size_t alignement, VkSystemAllocationScope allocationScope){
	void* ptr;
	if(alignement < size){
		ptr = malloc(size);
		ASSERT_(ptr, "Error during malloc for size of " +  AsString(size));
	}else{
		int rc = posix_memalign(&ptr, alignement, size);
		ASSERT_(rc == 0,"Error code : "+ AsString(rc) +" during posix_memalign for size of " +  AsString(size) + " and alignement of " + AsString(alignement));
	}
	LOG("[UVkCustomAllocator][DefaultAllocation] Allocation of 0x" + Upp::Format64Hex ((unsigned long long)ptr) + " for a size of " + AsString(size) + " bytes and alignment of " + AsString(alignement));
    leakTracker.Add((unsigned long long)ptr);
    return ptr;
}
void* UVkCustomAllocator::DefaultReallocation(void* pOriginal, size_t size, size_t alignement, VkSystemAllocationScope allocationScope){
	void* ptr = DefaultAllocation(size, alignement, allocationScope);
	LOG("[UVkCustomAllocator][DefaultReallocation] Reallocation of 0x" + Upp::Format64Hex ((unsigned long long)pOriginal) + " to 0x" + Upp::Format64Hex ((unsigned long long)ptr) +" for a size of " + AsString(size) + " bytes and alignment of "+ AsString(alignement));
	memcpy(ptr, pOriginal, size);
	LOG("[UVkCustomAllocator][DefaultReallocation] Free memory address 0x" + Upp::Format64Hex ((unsigned long long)pOriginal));
	DefaultFree(pOriginal);
	return ptr;
}
void  UVkCustomAllocator::DefaultFree(void* pMemory){
	if(pMemory){
		LOG("[UVkCustomAllocator][DefaultFree] Free memory address 0x" + Upp::Format64Hex ((unsigned long long)pMemory));
		bool find = false;
		for(int e = 0; e < leakTracker.GetCount(); e++){
			if(leakTracker[e] == (unsigned long long)pMemory){
				leakTracker.Remove(e);
				find = true;
				break;
			}
		}
		ASSERT_(find, "DefaultFree is freeing a never allocated memory address 0x" + Upp::Format64Hex ((unsigned long long)pMemory));
		return free(pMemory);
	}
	LOG("[UVkCustomAllocator][DefaultFree] WARNING: Free memory address 0x" + Upp::Format64Hex ((unsigned long long)pMemory));
}
void  UVkCustomAllocator::DefaultInternalAllocationNotification(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	LOG("[UVkCustomAllocator][DefaultInternalAllocationNotification] Internal allocation 0x" + Upp::Format64Hex (size) + " bytes");
}
void  UVkCustomAllocator::DefaultInternalFreeNotification(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
	LOG("[UVkCustomAllocator][DefaultInternalFreeNotification] Internal allocation 0x" + Upp::Format64Hex (size) + " bytes");
}
	
}