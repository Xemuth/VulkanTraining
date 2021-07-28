#ifndef _cube_VkMemoryManager_h_
#define _cube_VkMemoryManager_h_
#include <vulkan/vulkan.h>
#include <Core/Core.h>

class VkMemoryManager{
	public:
		VkMemoryManager(int memorySize);
		
		
		inline operator VkAllocationCallbacks()const{
			
			VkAllocationCallbacks result;
			result.pUserData = (void*)this;
			result.pfnAllocation = & Allocation;
			result.pfnReallocation = &Reallocation;
			result.pfnFree = &Free,
			result.pfnInternalAllocation = &InternalAllocation;
			result.pfnInternalFree = &InternalFree;
			return result;
		}
	private:
		static void* VKAPI_CALL Allocation(void* pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
			return static_cast<VkMemoryManager*>(pUserData)->Allocate(size, alignment, allocationScope);
		}
		static void* VKAPI_CALL Reallocation(void* pUserData, void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope){
			return static_cast<VkMemoryManager*>(pUserData)->Reallocate(pOriginal, size ,alignment, allocationScope);
		}
		static void  VKAPI_CALL Free(void* pUserData, void* pMemory){
			static_cast<VkMemoryManager*>(pUserData)->MemFree(pMemory);
		}
		static void VKAPI_CALL InternalAllocation(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
			static_cast<VkMemoryManager*>(pUserData)->InternalAllocate(size, allocationType, allocationScope);
		}
		static void VKAPI_CALL InternalFree(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope){
			static_cast<VkMemoryManager*>(pUserData)->MemInternalFree(size, allocationType, allocationScope);
		}
		
		void* Allocate(size_t size, size_t alignment, VkSystemAllocationScope  allocationScope);
		void* Reallocate(void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope  allocationScope);
		void  MemFree(void* pMemory);
		void  InternalAllocate(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
		void  MemInternalFree(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
	private:
		int size;
		char* begin;
		char* end;

};


#endif
