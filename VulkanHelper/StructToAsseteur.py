from operator import is_

if __name__ == '__main__':
    f = open("C:/Upp/Vulkan/VulkanHelper/headerToGenerate.htg", "r")
    str = f.read()
    pos =  0
    toWrite = "/*\n\tAuto generated header. To be included within SelectorFactory class\n*/\n"
    code = "/*\n\tAuto generated code\n*/\n#include \"VulkanHelper.h\"\n\nnamespace Upp{\n\n"
    while str.find("typedef struct", pos ) != -1:
        pos = str.find("typedef struct", pos)
        firstInc = str.find("{", pos)
        lastInc = str.find("}", firstInc + 1)
        structName = str[pos + len("typedef struct") : firstInc -1].strip()
        TotalDataInStruct = str[firstInc + 1: lastInc -1]
        listOfData = TotalDataInStruct.split("\n")


        toWrite +="//" + structName + " part\n"
        for oneVar  in listOfData:
            oneVar = oneVar.strip()
            if len(oneVar) > 0:
                typeName = oneVar[: oneVar.find(" ")].strip()
                varName = oneVar[oneVar.find(" "):].strip()[:-1]
                isArray = False
                if varName.find("[") != -1:
                    isArray = True
                    arraySize = varName[varName.find("[") + 1: varName.find("]")]
                    varName = varName[:varName.find("[")]
                skip = False

                if typeName == "char":
                    headerLine = "RULES SelectorFactory& " + "Set" + varName[0].upper() + varName[1:] + "(char* param, int score = 10, bool crucial = false);"
                elif not typeName in ("VkPhysicalDeviceLimits", "VkPhysicalDeviceSparseProperties"):
                    headerLine = "RULES SelectorFactory& " + "Set" + varName[0].upper() + varName[1:] + "(" + typeName + ("*" if isArray else "") +" param, Operation operation = Operation::EQUAL_OR_HIGHER, int score = 10, bool crucial = false, bool useValueAsScore = false);"
                else:
                    skip = True

                if not skip:
                    toWrite += headerLine + "\n"

                    #retrieve path to the properties
                    if structName in ("VkPhysicalDeviceProperties", "VkPhysicalDeviceFeatures"):
                        varToUse = "m_" +  structName[10:11].lower() + structName[11:]
                    elif structName == "VkPhysicalDeviceLimits":
                        varToUse = "m_deviceProperties" + ".limits"
                    elif structName ==  "VkPhysicalDeviceSparseProperties":
                        varToUse = "m_deviceProperties" + ".sparseProperties"
                    else:
                        varToUse = "ERROR"

                    funcToCall = "CheckUint32"
                    if isArray:
                        funcToCall = "CheckArrayUint32"
                        # if typeName in ("uint32_t", "VkFlags", "VkSampleCountFlags"):
                        #     funcToCall = "CheckArrayUint32"
                        # elif typeName == "VkBool32":
                        if typeName == "VkBool32":
                            funcToCall = "CheckArrayVkBool32"
                        elif typeName == "float":
                            funcToCall = "CheckArrayFloat"
                        elif typeName in ("VkDeviceSize", "size_t"):
                            funcToCall = "CheckArrayDouble"
                        elif typeName == "char":
                            funcToCall = "CheckStr"
                        elif typeName == "uint8_t":
                            funcToCall = "CheckArrayUint8"
                    else:
                        # if typeName in ("uint32_t", "VkFlags", "VkSampleCountFlags"):
                        #     funcToCall = "CheckUint32"
                        # elif typeName == "VkBool32":
                        if typeName == "VkBool32":
                            funcToCall = "CheckVkBool32"
                        elif typeName == "float":
                            funcToCall = "CheckFloat"
                        elif typeName in ("VkDeviceSize", "size_t"):
                            funcToCall = "CheckDouble"

                    if funcToCall == "CheckStr":
                        code += "RULES SelectorFactory& SelectorFactory::Set" + varName[0].upper() + varName[1:] + "(" + typeName + ("*" if isArray else "") + " param, int score, bool crucial){\n\tm_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{"
                    else:
                        code += "RULES SelectorFactory& SelectorFactory::Set" + varName[0].upper() + varName[1:] + "(" + typeName + ("*" if isArray else "") + " param, Operation operation, int score, bool crucial, bool useValueAsScore){\n\tm_checks.Create() << [=](CurrentPhysicalDeviceData& data) -> int{"


                    if funcToCall == "CheckStr":
                        code += "\n\t\treturn " + funcToCall + "(param, data." + varToUse + "." + varName + ", " + arraySize + " , score, crucial,\"Set" + varName[0].upper() + varName[1:] + "\");"
                    elif isArray:
                        code += "\n\t\treturn " + funcToCall + "(param, data." + varToUse + "." + varName + ", " + arraySize + " ,operation, score, crucial, useValueAsScore, \"Set" +  varName[0].upper() + varName[1:] + "\");"
                    elif len(funcToCall) > 0:
                        code += "\n\t\treturn " + funcToCall +"(param, data." + varToUse + "." + varName + ", operation, score, crucial, useValueAsScore, \"Set" + varName[0].upper() + varName[1:] + "\");"
                    code += "\n\t};\n\treturn *this;\n}\n\r"

        pos += 1

    f = open("C:/Upp/Vulkan/VulkanHelper/VulkanSelectorRules.h", "w")
    f.write(toWrite)
    f.close()

    code += "\n\n}"
    f = open("C:/Upp/Vulkan/VulkanHelper/VulkanSelectorsRules.cpp", "w")
    f.write(code)
    f.close()

