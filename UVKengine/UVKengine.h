#ifndef _UVKengine_UVKengine_h_
#define _UVKengine_UVKengine_h_
#include <Core/Core.h>
#include <vulkan/vulkan.h>

#define UVK_ENGINE_VERSION_0_1 0x01
#define UVK_ENGINE_NAME "UVKengine"

namespace Upp{
	
	Upp::Vector<const char*> GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr);
	
	class UVKapp{
		public:
			UVKapp(const Upp::String& windowName);
			UVKapp();
			~UVKapp();
		
			bool Create(bool trace);
	
			UVKapp& SetExtensions(const Upp::Vector<Upp::String>& extensionName);
			
			UVKapp& EnableValidationLayers(bool b);
			bool IsValidationLayersEnabled()const;
			UVKapp& SetValidationLayers(const Upp::Vector<Upp::String>& layers);
			
		private:
			Upp::Vector<Upp::String> PickAllValidationLayers(const Upp::Vector<Upp::String>& layers = {});
			Upp::Vector<Upp::String> PickAllExtensions(const Upp::Vector<Upp::String>& extensions = {}, bool trace = false);
			
			
			bool m_created = false;
			Upp::String m_windowName;
			Upp::Vector<Upp::String> m_extensionName;
			
			bool m_enableValidationLayers = false;
			Upp::Vector<Upp::String> m_validationLayers;
			
			//Vulkan
			VkDebugUtilsMessengerEXT m_debugMessenger = 0;
			VkInstance m_instance = 0;
	};
	
}

#endif
