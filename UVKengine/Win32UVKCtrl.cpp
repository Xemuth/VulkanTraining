#include "UVKengine.h"

namespace Upp{
	
#ifdef PLATFORM_WIN32

void VKCtrl::VkPane::State(int reason)
{
	DHCtrl::State(reason);
	if(reason == OPEN) {
		ctrl->CreateSurface(ctrl->m_instance, ctrl->m_surface);
		
		//HDC hDC = GetDC(hwnd);
		//if(!SetPixelFormat(hDC, s_pixelFormatID, &s_pfd))
		//	return;
		//ReleaseDC(hwnd, hDC);
	}
}

#endif

}
