#include "VulkanHelper.h"

#define LLOG(x) LOG(x)

namespace Upp{

VulkanSelector::VulkanSelector(Vector<String> extensions, Vector<String> validationLayers, Vector<String> deviceExtensions){}

void VulkanSelector::AddInstanceExtensions(String str){
	if(Find(m_instanceExtensions, str) == -1)
		m_instanceExtensions.Add(str);
}
void VulkanSelector::AddValidationLayers(String str){
	if(Find(m_validationLayers, str) == -1)
		m_validationLayers.Add(str);
}
void VulkanSelector::AddDeviceExtensions(String str){
	if(Find(m_devicesExtensions, str) == -1)
		m_devicesExtensions.Add(str);
}

void VulkanSelector::RemoveInstanceExtensions(String str){
	if(int pos = Find(m_instanceExtensions, str) != -1)
		m_instanceExtensions.Remove(pos);
}
void VulkanSelector::RemoveValidationLayers(String str){
	if(int pos = Find(m_validationLayers, str) != -1)
		m_validationLayers.Remove(pos);
}
void VulkanSelector::RemoveDeviceExtensions(String str){
	if(int pos = Find(m_devicesExtensions, str) != -1)
		m_devicesExtensions.Remove(pos);
}

void VulkanSelector::ClearInstanceExtensions(){
	m_instanceExtensions.Clear();
}
void VulkanSelector::ClearValidationLayers(){
	m_validationLayers.Clear();
}
void VulkanSelector::ClearDeviceExtensions(){
	m_devicesExtensions.Clear();
}

Vector<const char*> VulkanSelector::GetInstanceExtensions()const{
	return GetTemporaryCharPtr(m_instanceExtensions);
}
Vector<const char*> VulkanSelector::GetValidationsLayers()const{
	return GetTemporaryCharPtr(m_validationLayers);
}
Vector<const char*> VulkanSelector::GetDeviceExtensions()const{
	return GetTemporaryCharPtr(m_devicesExtensions);
}

int VulkanSelector::GetInstanceExtensionsCount()const{
	return m_instanceExtensions.GetCount();
}
int VulkanSelector::GetValidationsLayersCount()const{
	return m_validationLayers.GetCount();
}
int VulkanSelector::GetDeviceExtensionsCount()const{
	return m_devicesExtensions.GetCount();
}

int VulkanSelector::Find(Vector<String>& list, Upp::String& name){
	int indice = 0;
	for(Upp::String& str : list){
		if(str.IsEqual(name))
			return indice;
		indice++;
	}
	return -1;
}
Vector<const char*> VulkanSelector::GetTemporaryCharPtr(const Upp::Vector<Upp::String>& vectorStr)const{
	Vector<const char*> buffer;
	for(const Upp::String& str : vectorStr)
		buffer.Add(~str);
	return buffer;
}

}