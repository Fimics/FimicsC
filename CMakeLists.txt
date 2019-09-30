cmake_minimum_required(VERSION 3.10.2)
project(FimicsCPP)
project(FimicsC)
project(FimicsCLINUX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)


set(SOURCE_C_FILES

        #dataType
        src/datatype/DataType.c
        src/datatype/BinaryConvert.c
        src/datatype/Char.c

        #function
        src/function/YFunction.h
        src/function/YFunction.c
        src/function/FunctionDemo.c

        #string
        src/string/GetssPuts.c
        src/string/FgetsFputs.c
        src/string/PrintfScanf.c
        src/string/StrlenStrcpy.c
        src/string/SprintfSscanf.c
        src/string/Strchr.c
        src/string/strtokAtoi.c

        #pointer
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
        src/array/YArray.c
        src/array/Array2d.c
        src/array/ArrayAndPointer.c
        src/array/Srand.c
        src/array/vararr2d.c
        src/array/StringArray.c

        #system
        src/system/System.c

        #memory
        src/memory/Scope.c
        src/memory/MemGlobal.c
        src/memory/MemArea.c
        src/memory/MemHeap.c
        src/memory/MemFunction.c

        #complex;
        src/complex/YComplex.h
        src/complex/StructDefine.c
        src/complex/StructMemory.c
        src/complex/StructArray.c
        src/complex/StructSort.c
        src/complex/StructPointer.c
        src/complex/StructFunction.c
        src/complex/Structstruct.c
        src/complex/UnionDemo.c
        src/complex/EnumDemo.c
        src/complex/TypeDefDemo.c

        #File
        src/file/FileOperate.c
        src/file/FileCat.c
        src/file/FileFscanf.c
        src/file/FileBigDataSort.c
        src/file/FreadFwrite.c
        src/file/FileCopy.c
        src/file/FileProperty.c
        src/file/FileRandomAccess.c
        src/file/FileMvRmRename.c
        src/file/FileBuffer.c


        #improve
        src/improve/IDataType.c
        src/improve/YGlobal.c
        src/improve/IFunction.c
        src/improve/IPointer.c
        src/improve/IString.c
        src/improve/IMemory.c
        src/improve/IConst.c
        src/improve/IPointerFunction.c
        src/improve/IArray.c
        src/improve/IFile.c
        src/improve/IBitOperation.c
        src/improve/IStruct.c
        src/improve/ISumUp.c
        src/improve/IFileConfig.h
        src/improve/IFileConfig.c
        src/improve/IFunctionPointer.c
        src/improve/IPreprocessingInstruction.c

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
        srcplus/stl/container/YStl.h
        srcplus/stl/container/YStl.cpp

        #vector
        srcplus/stl/container/VectorContainer.cpp
        srcplus/stl/container/VectorContainer.h
        srcplus/stl/container/VectorContainer1.cpp
        srcplus/stl/container/VectorContainer1.h

        #string
        srcplus/stl/container/StringContainer.cpp
        srcplus/stl/container/StringContainer.h

        #deque
        srcplus/stl/container/DequeContainer.cpp
        srcplus/stl/container/DequeContainer.h

        #stack
        srcplus/stl/container/StackContainer.cpp
        srcplus/stl/container/StackContainer.h

        #queue
        srcplus/stl/container/QueueContainer.cpp
        srcplus/stl/container/QueueContainer.h

        #list
        srcplus/stl/container/ListContainer.cpp
        srcplus/stl/container/ListContainer.h

        #set
        srcplus/stl/container/SetContainer.cpp
        srcplus/stl/container/SetContainer.h

        #pair
        srcplus/stl/container/PairContainer.cpp
        srcplus/stl/container/PairContainer.h

        #map
        srcplus/stl/container/MapContainer.cpp
        srcplus/stl/container/MapContainer.h

        #multimap
        srcplus/stl/container/MultiMapContainer.cpp
        srcplus/stl/container/MultiMapContainer.h

        #functor
        srcplus/stl/algorithm/Algorithm.cpp
        srcplus/stl/algorithm/Algorithm.h
        srcplus/stl/algorithm/Functor.cpp
        srcplus/stl/algorithm/Functor.h
        srcplus/stl/algorithm/Predicate.cpp
        srcplus/stl/algorithm/Predicate.h
        srcplus/stl/algorithm/BuiltInFunction.cpp
        srcplus/stl/algorithm/BuiltInFunction.h
        srcplus/stl/algorithm/Adapter.cpp
        srcplus/stl/algorithm/Adapter.h
        srcplus/stl/algorithm/Traversal.cpp
        srcplus/stl/algorithm/Traversal.h
        srcplus/stl/algorithm/Find.cpp
        srcplus/stl/algorithm/Find.h
        srcplus/stl/algorithm/Sort.cpp
        srcplus/stl/algorithm/Sort.h
        srcplus/stl/algorithm/CopyAndReplace.cpp
        srcplus/stl/algorithm/CopyAndReplace.h
        srcplus/stl/algorithm/AlgorithmCreater.cpp
        srcplus/stl/algorithm/AlgorithmCreater.h
        srcplus/stl/algorithm/CommonSet.cpp
        srcplus/stl/algorithm/CommonSet.h

        )

set(SOURCE_SYSTEM_FILES
        #file
        system/mian.c
        system/file/File.c
        system/file/MyTouch.c
        system/file/MyCat.c
        system/file/Lseek.c
        system/file/FileStat.c
        system/file/AccessTruncate.c
        system/file/Link.c
        system/file/Chown.c
        system/file/CountFiles.c
        system/file/Errno.c
        system/file/Dup2.c

        #processcntl
        system/processcntl/Fork.c
        system/processcntl/ProcessShared.c
        system/processcntl/Execl.c
        system/processcntl/Wait.c

        #processcomon
        system/processcomon/Pipe.c
        system/processcomon/FifoWrite.c
        system/processcomon/FifoRead.c
        system/processcomon/Mmap.c
        system/processcomon/MmapWriter.c

        #singal
        system/signal/Kill.c
        system/signal/Alarm.c
        system/signal/SetITimer.c
        system/signal/SigSet.c
        system/signal/SigAction.c
        system/signal/SigChild.c

        #thread
        system/thread/DaemonP.c
        system/thread/Thread.c
        system/thread/Mutex.c
        system/thread/TryLock.c
        system/thread/RwLock.c
        system/thread/Producer.c
        system/thread/Sem.c
        system/thread/FileLock.c

        #socket
        system/socket/tcp/client_tcp.c
        system/socket/tcp/warp/client.c
        system/socket/tcp/warp/server.c
        system/socket/tcp/warp/wrap.c
        system/socket/tcp/server_p.c
        )


add_executable(FimicsCPP ${SOURCE_CPP_FILES})
add_executable(FimicsC ${SOURCE_C_FILES})
add_executable(FimicsCLINUX ${SOURCE_SYSTEM_FILES})
