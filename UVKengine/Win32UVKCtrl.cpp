#include "UVKengine.h"

#define LLOG(x) LOG(x)


namespace Upp{
	
#ifdef PLATFORM_WIN32

VkResult CreateSurface(VkInstance& instance, VkSurfaceKHR& surface, HWND hwnd){
#if defined(WIN32)
	VkWin32SurfaceCreateInfoKHR  createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	createInfo.hwnd = hwnd;
	createInfo.hinstance = GetModuleHandle(nullptr);
	createInfo.pNext = nullptr;
	VkResult result = vkCreateWin32SurfaceKHR(instance, &createInfo, nullptr, &surface);
#endif

	if(result == VK_SUCCESS){
		LLOG("[VKCtrl::CreateSurface][INFO] VkSurfaceKHR is successfully created (handle=" + AsString(surface) +")");
	}else{
		surface = VK_NULL_HANDLE;
		LLOG("[VKCtrl::CreateSurface][INFO] Error during creation of surface");
	}
	return result;
}


void VKCtrl::VkPane::State(int reason)
{
	DHCtrl::State(reason);
	if(reason == OPEN){
		VkResult result = CreateSurface(ctrl->m_instance, ctrl->m_surface, GetHWND());
		if(result == VK_SUCCESS){
			ctrl->InitEntireVulkanChain();
		}else{
			ctrl->m_surface = VK_NULL_HANDLE;
			LLOG("[VKCtrl::VkPane::State][ERROR] Impossible to create VkSurfaceKHR");
		}
	}
}

#endif

}
