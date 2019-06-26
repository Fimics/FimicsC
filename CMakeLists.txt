cmake_minimum_required(VERSION 3.13)
project(FimicsCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

include_directories(
        src/array
        src/datatype
        src/function
        src/mian
        src/pointer
        src/memory
        src/system
        src/string
        src/datastructure)


set(SOURCE_C_FILES
        #main
        src/main.c

        #dataType
        src/datatype/DataType.h
        src/datatype/DataType.c
        src/datatype/BinaryConvert.c
        src/datatype/Char.c

        #function
        src/function/YFunction.h
        src/function/YFunction.c
        src/function/FunctionDemo.c

        #datastructure
        src/datastructure/YDataStructure.h
        src/datastructure/YDataStructure.c
        src/datastructure/Sort.c


        #string
        src/string/YString.h
        src/string/YString.c
        src/string/GetssPuts.c
        src/string/FgetsFputs.c
        src/string/PrintfScanf.c
        src/string/StrlenStrcpy.c
        src/string/SprintfSscanf.c
        src/string/Strchr.c
        src/string/strtokAtoi.c

        #pointer
        src/pointer/YPointer.h
        src/pointer/YPointer.c
        src/pointer/PointerDefine.c
        src/pointer/WildNullpointer.c
        src/pointer/ConstDemo.c
        src/pointer/PointerAndArray.c
        src/pointer/PointerOperation.c
        src/pointer/PointerBubbleSort.c
        src/pointer/PointerStrchr.c
        src/pointer/PointerMultilevel.c
        src/pointer/PointerAndParameter.c
        src/pointer/PointerReturnValue.c
        src/pointer/PointerString.c

        #array
        src/array/YArray.h
        src/array/YArray.c
        src/array/Array2d.c
        src/array/ArrayAndPointer.c
        src/array/Srand.c
        src/array/vararr2d.c
        src/array/StringArray.c

        #system
        src/system/System.h
        src/system/System.c

        #memory
        src/memory/YMemory.h
        src/memory/YMemory.c
        src/memory/Scope.c)

set(SOURCE_CPP_FILES
        srcplus/main.cpp
)

add_executable(FimicsC ${SOURCE_C_FILES})
add_executable(FimicsCPP ${SOURCE_CPP_FILES})