#include "UVkApp.h"
#include "UVkPhysicalDevice.h"
namespace Upp{
UVkDevice::UVkDevice(const VkDevice& device, UVkPhysicalDevice& parent) : m_device(device), m_parent(&parent){}
inline UVkDevice::operator VkDevice(){return m_device;}
VkDevice UVkDevice::GetDevice(){return m_device;}
UVkPhysicalDevice& UVkDevice::GetParent(){ASSERT_(m_parent, "UVkPhysicalDevice is null in UVkDevice"); return *m_parent;}
inline UVkDevice::operator VkPhysicalDevice(){ASSERT_(m_parent, "inline operator VkPhysicalDevice(): UVkPhysicalDevice is null in UVkDevice"); return m_parent->GetPhysicalDevice();}

VkBuffer CreateBuffer(const VkBufferCreateInfo& bufferCreateInfo){
	
}
void DestroyBuffer(VkBuffer){

}
VkDeviceMemory UVkDevice::AllocatedMemory(const VkMemoryAllocateInfo& memoryAllocateInfo){
	
}
void UVkDevice::FreeMemory(const VkDeviceMemory& deviceMemory){
	
}
const Array<VkDeviceMemory>& UVkDevice::GetAllocatedMemory()const{
	
}
void** UVkDevice::MapMemory(const VkDeviceMemory& deviceMemory, const VkDeviceSize& offset, const VkDeviceSize& size, const VkMemoryMapFlags& flags){
	
}
void UVkDevice::UnmapMemory(const VkDeviceMemory& deviceMemory){
	
}
const Array<VkDeviceMemory>& UVkDevice::GetMappedMemory()const{
	
}

}