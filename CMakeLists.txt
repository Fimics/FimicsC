cmake_minimum_required(VERSION 3.13)
project(FimicsCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)

include_directories(
#        src/mian
#        src/system
#        src/datatype
#        src/array
#        src/function
#        src/string
#        src/pointer
#        src/memory
#        src/datastructure
#        src/complex
#        src/file
#        src/improve
)


set(SOURCE_C_FILES
        #main
        src/main.c
#        #dataType
#        src/datatype/DataType.h
#        src/datatype/DataType.c
#        src/datatype/BinaryConvert.c
#        src/datatype/Char.c
#
#        #function
#        src/function/YFunction.h
#        src/function/YFunction.c
#        src/function/FunctionDemo.c



#        #string
#        src/string/YString.h
#        src/string/YString.c
#        src/string/GetssPuts.c
#        src/string/FgetsFputs.c
#        src/string/PrintfScanf.c
#        src/string/StrlenStrcpy.c
#        src/string/SprintfSscanf.c
#        src/string/Strchr.c
#        src/string/strtokAtoi.c
#
#        #pointer
#        src/pointer/YPointer.h
#        src/pointer/YPointer.c
#        src/pointer/PointerDefine.c
#        src/pointer/WildNullpointer.c
#        src/pointer/ConstDemo.c
#        src/pointer/PointerAndArray.c
#        src/pointer/PointerOperation.c
#        src/pointer/PointerBubbleSort.c
#        src/pointer/PointerStrchr.c
#        src/pointer/PointerMultilevel.c
#        src/pointer/PointerAndParameter.c
#        src/pointer/PointerReturnValue.c
#        src/pointer/PointerString.c
#
#        #array
#        src/array/YArray.h
#        src/array/YArray.c
#        src/array/Array2d.c
#        src/array/ArrayAndPointer.c
#        src/array/Srand.c
#        src/array/vararr2d.c
#        src/array/StringArray.c
#
#        #system
#        src/system/System.h
#        src/system/System.c
#
#        #memory
#        src/memory/YMemory.h
#        src/memory/YMemory.c
#        src/memory/Scope.c
#        src/memory/MemGlobal.c
#        src/memory/MemArea.c
#        src/memory/MemHeap.c
#        src/memory/MemFunction.c

        #complex;
#        src/complex/YComplex.h
#        src/complex/YComplex.c
#        src/complex/StructDefine.c
#        src/complex/StructMemory.c
#        src/complex/structArray.c
#        src/complex/structSort.c
#        src/complex/StructPointer.c
#        src/complex/StructFunction.c
#        src/complex/Structstruct.c
#        src/complex/UnionDemo.c
#        src/complex/EnumDemo.c
#        src/complex/TypeDefDemo.c

        #File
#        src/file/YFile.h
#        src/file/YFile.c
#        src/file/FileOperate.c
#        src/file/FileCat.c
#        src/file/FileFscanf.c
#        src/file/FileBigDataSort.c
#        src/file/FreadFwrite.c
#        src/file/FileCopy.c
#        src/file/FileProperty.c
#        src/file/FileRandomAccess.c
#        src/file/FileMvRmRename.c
#        src/file/FileBuffer.c


        #improve
#        src/improve/YImprove.h
#        src/improve/YImprove.c
#        src/improve/IDataType.c
#        src/improve/YGlobal.c
#        src/improve/IFunction.c
#        src/improve/IPointer.c
#        src/improve/IString.c
#        src/improve/IMemory.c
#        src/improve/IConst.c
#        src/improve/IPointerFunction.c
#        src/improve/IArray.c
#        src/improve/IFile.c
#        src/improve/IBitOperation.c
#        src/improve/IStruct.c
#        src/improve/ISumUp.c
#        src/improve/IFileConfig.h
#        src/improve/IFileConfig.c
#        src/improve/IFunctionPointer.c
#        src/improve/IPreprocessingInstruction.c

        #datastructure
#        src/datastructure/YDataStructure.h
#        src/datastructure/YDataStructure.c
#        src/datastructure/Sort.c
#        src/datastructure/LinkedList.c
#        src/datastructure/LinkedList.h
#        src/datastructure/DynamicArray.c
#        src/datastructure/DynamicArray.h
#        src/datastructure/LinkedList1.h
#        src/datastructure/LinkedList1.c

        )

set(SOURCE_CPP_FILES
        srcplus/main.cpp
        #basic
        srcplus/base/Basic.cpp
        srcplus/base/Basic.h

        #function
        srcplus/function/YFunction.cpp
        srcplus/function/YFunction.h
        srcplus/function/ExternC.c
        srcplus/function/ExternC.h
        srcplus/function/ExternC.cpp
        srcplus/extends/FExtends.h
        srcplus/extends/FExtends.cpp
        srcplus/extends/ExtendsMode.h
        srcplus/extends/ExtendsMode.cpp
        srcplus/function/FunctionPointer.h
        srcplus/function/FunctionPointer.cpp

        #design
        srcplus/design/YDesign.h
        srcplus/design/YDesign.cpp
        srcplus/design/Singleton.h
        srcplus/design/Singleton.cpp


        #objecto
        srcplus/objecto/Circle.cpp
        srcplus/objecto/Circle.h
        srcplus/objecto/YObjectO.cpp
        srcplus/objecto/YObjectO.h
        srcplus/objecto/Packing.h
        srcplus/objecto/Packing.c
        srcplus/objecto/Packing.cpp
        srcplus/objecto/InitObject.cpp
        srcplus/objecto/InitObject.h
        srcplus/objecto/StaticDemo.cpp
        srcplus/objecto/StaticDemo.h
        srcplus/objecto/ObjectModel.h
        srcplus/objecto/ObjectModel.cpp
        srcplus/objecto/FriendClass.h
        srcplus/objecto/FriendClass.cpp

        #Array
        srcplus/array/Array.h
        srcplus/array/Array.cpp

        #string
        srcplus/string/String.h
        srcplus/string/String.cpp

        #operator
        srcplus/operator/YOperator.h
        srcplus/operator/YOperator.cpp
        srcplus/string/StringDemo.h
        srcplus/string/StringDemo.cpp


        #memory
        srcplus/memory/FMemory.h
        srcplus/memory/FMemory.cpp

        #extends
        srcplus/extends/FExtends.h
        srcplus/extends/FExtends.cpp
        srcplus/extends/ExtendsMode.h
        srcplus/extends/ExtendsMode.cpp
        srcplus/function/FunctionPointer.h
        srcplus/function/FunctionPointer.cpp
        srcplus/function/ReferenceVariable.h
        srcplus/function/ReferenceVariavle.cpp

        #extends
        srcplus/extends/Polymorphism.h
        srcplus/extends/Polymorphism.cpp

        #funTemplate
        srcplus/funtemplate/FunTemplate.h
        srcplus/funtemplate/FunTemplate.cpp

        #expection
        srcplus/exception/FException.h
        srcplus/exception/FException.cpp
        srcplus/exception/TypeCast.h
        srcplus/exception/TypeCast.cpp

        #io
        srcplus/io/IO.h
        srcplus/io/IO.cpp

        #stl
        srcplus/stl/YStl.h
        srcplus/stl/YStl.cpp

        #vector
        srcplus/stl/VectorContainer.cpp
        srcplus/stl/VectorContainer.h
        srcplus/stl/VectorContainer1.cpp
        srcplus/stl/VectorContainer1.h

        #string
        srcplus/stl/StringContainer.cpp
        srcplus/stl/StringContainer.h

        #deque
        srcplus/stl/DequeContainer.cpp
        srcplus/stl/DequeContainer.h

        )

add_executable(FimicsCPP ${SOURCE_CPP_FILES})
add_executable(FimicsC ${SOURCE_C_FILES})
