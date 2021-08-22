#ifndef _VulkanCommand_UVkCustomAllocator_h_
#define _VulkanCommand_UVkCustomAllocator_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif

namespace Upp{

class UVkCustomAllocator{
	public:
		UVkCustomAllocator(Function<void* (size_t, size_t, VkSystemAllocationScope)> callbackAllocation = Function<void* (size_t, size_t, VkSystemAllocationScope)>{},
						   Function<void* (void*, size_t, size_t, VkSystemAllocationScope)> callbackReallocation = Function<void* (void*, size_t, size_t, VkSystemAllocationScope)>{},
						   Function<void  (void*)> callbackFree = Function<void  (void*)>{},
						   Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> callbackInternalAllocationNotification = Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)>{},
						   Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> callbackInternalFreeNotification = Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)>{});
		
		VkAllocationCallbacks GetAllocationCallbacks()const{
			VkAllocationCallbacks result;
			result.pUserData = (void*)this;
			result.pfnAllocation = &SAllocation;
			result.pfnReallocation = &SReallocation;
			result.pfnFree = &SFree;
			result.pfnInternalAllocation = &SInternalFreeNotification;
			result.pfnInternalFree = &SInternalFreeNotification;
			return result;
		}
		
		inline operator VkAllocationCallbacks()const{
			return GetAllocationCallbacks();
		}
		static Upp::Array<unsigned long long> leakTracker;
	private:
		
		
		static void* VKAPI_CALL SAllocation(void* pUserData, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
		static void* VKAPI_CALL SReallocation(void* pUserData, void* pOriginal, size_t size, size_t alignment, VkSystemAllocationScope allocationScope);
		static void  VKAPI_CALL SFree(void* pUserData, void* pMemory);
		static void  VKAPI_CALL SInternalAllocationNotification(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
		static void  VKAPI_CALL SInternalFreeNotification(void* pUserData, size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
		
		
		static void* DefaultAllocation(size_t size, size_t alignement, VkSystemAllocationScope allocationScope);
		static void* DefaultReallocation(void* pOriginal, size_t size, size_t alignement, VkSystemAllocationScope allocationScope);
		static void  DefaultFree(void* pMemory);
		static void  DefaultInternalAllocationNotification(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
		static void  DefaultInternalFreeNotification(size_t size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);
		
		Function<void* (size_t, size_t, VkSystemAllocationScope)> m_callbackAllocation;
		Function<void* (void*, size_t, size_t, VkSystemAllocationScope)> m_callbackReallocation;
		Function<void  (void*)> m_callbackFree;
		Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> m_callbackInternalAllocationNotification;
		Function<void (size_t, VkInternalAllocationType, VkSystemAllocationScope)> m_callbackInternalFreeNotification;
};

}


#endif
