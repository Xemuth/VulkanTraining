#ifndef _VulkanCommand_UVkDevice_h_
#define _VulkanCommand_UVkDevice_h_
#ifndef CORE_H
#include <Core/Core.h>
#endif
#ifndef _vulkan_vulkan_h_
#include <vulkan/vulkan.h>
#endif

namespace Upp{
class UVkPhysicalDevice;
class UVkDevice{
	public:
		UVkDevice(const VkDevice& device, UVkPhysicalDevice& parent);
		
		VkBuffer CreateBuffer(const VkBufferCreateInfo& bufferCreateInfo);
		void DestroyBuffer(VkBuffer);
		VkBufferView CreateBufferView(const VkBufferViewCreateInfo& bufferViewCreateInfo);
		
		
		
		
		VkDeviceMemory AllocatedMemory(const VkMemoryAllocateInfo& memoryAllocateInfo);
		void FreeMemory(const VkDeviceMemory& deviceMemory);
		const Array<VkDeviceMemory>& GetAllocatedMemory()const;
		
		void** MapMemory(const VkDeviceMemory& deviceMemory, const VkDeviceSize& offset, const VkDeviceSize& size, const VkMemoryMapFlags& flags);
		void UnmapMemory(const VkDeviceMemory& deviceMemory);
		const Array<VkDeviceMemory>& GetMappedMemory()const;
		
		VkDevice GetDevice();
		inline operator VkDevice();
		UVkPhysicalDevice& GetParent();
		inline operator VkPhysicalDevice();
	private:
		Array<VkDeviceMemory> mappedMemory;
		Array<VkDeviceMemory> allocatedMemory;
		
		Array<VkBuffer> createdBuffer;
		
		UVkPhysicalDevice* m_parent;
		VkDevice m_device;
};
}

#endif
