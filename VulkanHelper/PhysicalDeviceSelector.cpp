#include "VulkanHelper.h"

#define LLOG(x) LOG(x)

namespace Upp{

PhysicalDeviceSelector::PhysicalDeviceSelector(const Upp::Array<Function<int (CurrentPhysicalDeviceData& helper)>>& rules): m_checks(clone(rules)){}
PhysicalDeviceSelector::PhysicalDeviceSelector(PhysicalDeviceSelector&& pds): m_checks(pick(pds.m_checks)){}
int PhysicalDeviceSelector::operator()(CurrentPhysicalDeviceData& datas){
	int score = 0;
	for(auto& func : m_checks){
		int val = func(datas);
		if(val < 0) return -1;
		else
			score += val;
	}
	return score;
}

SelectorFactory::SelectorFactory(){}
SelectorFactory::SelectorFactory(SelectorFactory&& selector){}
SelectorFactory SelectorFactory::Create(){return SelectorFactory();}

PhysicalDeviceSelector SelectorFactory::Build(){
	return pick(PhysicalDeviceSelector(m_checks));
}
	
int SelectorFactory::CheckUint32(uint32_t param, uint32_t val, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	score = (useValueAsScore)? int(val) : score;
	String operationStr=GetOperationStr(operation);
	
	bool result = CheckValue<VkBool32>(param, val, operation);
	int retValue = 0;
	if(result)
		retValue = score;
	else if(crucial)
		retValue = -1;
	
	if(retValue == -1) LLOG("[PhysicalDeviceSelector::CheckUint32][WARNING] Check FAIL for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	else LLOG("[PhysicalDeviceSelector::CheckUint32][INFO] Check OK for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	return retValue;
}

int SelectorFactory::CheckVkBool32(VkBool32 param, VkBool32 val, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	score = (useValueAsScore)? int(val) : score;
	String operationStr=GetOperationStr(operation);
	
	bool result = CheckValue<VkBool32>(param, val, operation);
	int retValue = 0;
	if(result)
		retValue = score;
	else if(crucial)
		retValue = -1;
	
	if(retValue == -1) LLOG("[PhysicalDeviceSelector::CheckVkBool32][WARNING] Check FAIL for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	else LLOG("[PhysicalDeviceSelector::CheckVkBool32][INFO] Check OK for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	return retValue;
}

int SelectorFactory::CheckFloat(float param, float val, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	score = (useValueAsScore)? int(val) : score;
	String operationStr=GetOperationStr(operation);
	
	bool result = CheckComplex<float>(param, val, operation);
	int retValue = 0;
	if(result)
		retValue = score;
	else if(crucial)
		retValue = -1;
		
	if(retValue == -1) LLOG("[PhysicalDeviceSelector::CheckFloat][WARNING] Check FAIL for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	else LLOG("[PhysicalDeviceSelector::CheckFloat][INFO] Check OK for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	return retValue;
}

int SelectorFactory::CheckDouble(double param, double val, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	score = (useValueAsScore)? int(val) : score;
	String operationStr=GetOperationStr(operation);
	
	bool result = CheckComplex<double>(param, val, operation);
	int retValue = 0;
	if(result)
		retValue = score;
	else if(crucial)
		retValue = -1;
		
	if(retValue == -1) LLOG("[PhysicalDeviceSelector::CheckDouble][WARNING] Check FAIL for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	else LLOG("[PhysicalDeviceSelector::CheckDouble][INFO] Check OK for " + functionName +"(" + AsString(val) + " is " + operationStr + " to " + AsString(param) +")");
	return retValue;
}

int SelectorFactory::CheckStr(char* param, char* val, int size, int score, bool crucial, Upp::String functionName){
	char* ptr1 = param;
	char* ptr2 = val;
	bool equal = true;
	for(int e = 0; e < size; e++, ptr1++, ptr1++){
		if(*ptr1 != *ptr2){
			equal = false;
			break;
		}
	}
	int retValue = 0;
	if(equal)
		retValue = score;
	else if(crucial)
		retValue = -1;
	
	if(retValue == -1) LLOG("[PhysicalDeviceSelector::CheckStr][WARNING] Check FAIL for " + functionName +"(" + Upp::String(val, size) + " is EQUAL to " + Upp::String(param, size) +")");
	else LLOG("[PhysicalDeviceSelector::CheckStr][INFO] Check OK for " + functionName +"(" + Upp::String(val, size) + " is EQUAL to " + Upp::String(param, size) +")");
	return retValue;
}

int SelectorFactory::CheckArrayUint32(uint32_t* param, uint32_t* val, int size, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	int retValue = 0;
	int buffer = 0;
	for(int e = 0; e < size; e++){
		retValue += buffer = CheckUint32(param[e], val[e], operation, score, crucial, useValueAsScore, functionName);
		if(crucial && buffer == -1){
			retValue = -1;
			break;
		}
	}
	return retValue;
}

int SelectorFactory::CheckArrayUint8(uint8_t* param, uint8_t* val, int size, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	int retValue = 0;
	int buffer = 0;
	for(int e = 0; e < size; e++){
		int valcpy1 = param[e];
		int valcpy2 = val[e];
		retValue += buffer = CheckUint32(valcpy1,valcpy2 , operation, score, crucial, useValueAsScore, functionName);
		if(crucial && buffer == -1){
			retValue = -1;
			break;
		}
	}
	return retValue;
}

int SelectorFactory::CheckArrayDouble(double* param, double* val, int size, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	int retValue = 0;
	int buffer = 0;
	for(int e = 0; e < size; e++){
		retValue += buffer = CheckDouble(param[e], val[e], operation, score, crucial, useValueAsScore, functionName);
		if(crucial && buffer == -1){
			retValue = -1;
			break;
		}
	}
	return retValue;
}
int SelectorFactory::CheckArrayVkBool32(VkBool32* param, VkBool32* val, int size, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	int retValue = 0;
	int buffer = 0;
	for(int e = 0; e < size; e++){
		retValue += buffer =CheckVkBool32(param[e], val[e], operation, score, crucial, useValueAsScore, functionName);
		if(crucial && buffer == -1){
			retValue = -1;
			break;
		}
	}
	return retValue;
}
int SelectorFactory::CheckArrayFloat(float* param, float* val, int size, Operation operation, int score, bool crucial, bool useValueAsScore, Upp::String functionName){
	int retValue = 0;
	int buffer = 0;
	for(int e = 0; e < size; e++){
		retValue += buffer = CheckFloat(param[e], val[e], operation, score, crucial, useValueAsScore, functionName);
		if(crucial && buffer == -1){
			retValue = -1;
			break;
		}
	}
	return retValue;
}

template <typename T>
bool SelectorFactory::CheckValue(T param, T val, Operation operation){
	switch(operation){
		case Operation::EQUAL:
			return (val == param);
		case Operation::EQUAL_OR_HIGHER:
			return (val >= param);
		case Operation::EQUAL_OR_LOWER:
			return (val <= param);
		case Operation::LOWER:
			return (val < param);
		case Operation::HIGHER:
			return (val > param);
		case Operation::OR:
			return (val | param);
		case Operation::AND:
			return (val & param);
		default:
			return false;
	}
}

template <typename T>
bool SelectorFactory::CheckComplex(T param, T val, Operation operation){
	switch(operation){
		case Operation::EQUAL:
			return (val == param);
		case Operation::EQUAL_OR_HIGHER:
			return (val >= param);
		case Operation::EQUAL_OR_LOWER:
			return (val <= param);
		case Operation::LOWER:
			return (val < param);
		case Operation::HIGHER:
			return (val > param);
		case Operation::OR:
			LLOG("[SelectorFactory::CheckComplex][WARNING] OR operation is always false for complex object");
			return false;
		case Operation::AND:
			LLOG("[SelectorFactory::CheckComplex][WARNING] AND operation is always false for complex object");
			return false;
		default:
			return false;
	}
}

const char* SelectorFactory::GetOperationStr(Operation operation){
	switch(operation){
		case Operation::EQUAL:
			return "EQUAL";
		case Operation::EQUAL_OR_HIGHER:
			return "EQUAL_OR_HIGHER";
		case Operation::EQUAL_OR_LOWER:
			return "EQUAL_OR_LOWER";
		case Operation::LOWER:
			return "LOWER";
		case Operation::HIGHER:
			return "HIGHER";
		case Operation::OR:
			return "OR";
		case Operation::AND:
			return "AND";
		default:
			return "INVALIDE_OPERATION";
	}
}
}