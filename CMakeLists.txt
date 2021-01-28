cmake_minimum_required(VERSION 3.8.2)

project(work)

message("------------ Options -------------")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("  CMAKE_BUILD_TYPE: Hello World!")

# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(./googletest)
#头文件
include_directories(${PROJECT_SOURCE_DIR}/src/include ./googletest/include)

#源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/main dir_srcs)
#库文件 : libtest.a 添加到链接路径中
link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/googletest)

#需要添加googletest运行需要的pthread
set(LIBRARIES pthread)

#编译器相关设置
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告


set(WORK

        #dataType
#                src/datatype/DataType.c
#                src/datatype/BinaryConvert.c
#                src/datatype/Char.c

        #function
        #        src/function/YFunction.h
        #        src/function/YFunction.c
        #        src/function/FunctionDemo.c

        #string
        #        src/string/GetssPuts.c
        #        src/string/FgetsFputs.c
        #        src/string/PrintfScanf.c
        #        src/string/StrlenStrcpy.c
        #        src/string/SprintfSscanf.c
        #        src/string/Strchr.c
        #        src/string/strtokAtoi.c

        #pointer
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

        #array
        #        src/array/YArray.c
        #        src/array/Array2d.c
        #        src/array/ArrayAndPointer.c
        #        src/array/Srand.c
        #        src/array/vararr2d.c
        #        src/array/StringArray.c

        #system
        #        src/system/System.c

        #memory
        #        src/memory/Scope.c
        #        src/memory/MemGlobal.c
        #        src/memory/MemArea.c
        #        src/memory/MemHeap.c
        #        src/memory/MemFunction.c

        #complex;
        #        src/complex/YComplex.h
        #        src/complex/StructDefine.c
        #        src/complex/StructMemory.c
        #        src/complex/StructArray.c
        #        src/complex/StructSort.c
        #        src/complex/StructPointer.c
        #        src/complex/StructFunction.c
        #        src/complex/Structstruct.c
        #        src/complex/UnionDemo.c
        #        src/complex/EnumDemo.c
        #        src/complex/TypeDefDemo.c

        #File
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


        # ---------------------------------------c++--------------------------------
        srcplus/App.cpp
        #        #basic
                 srcplus/base/Basic.cpp
        #
        #        #function
        #        srcplus/function/ExternC.c
        #        srcplus/function/ExternC.h
        #        srcplus/function/ExternC.cpp
        #        srcplus/function/FunctionPointer.cpp
        #        srcplus/function/ReferenceVariavle.cpp
        #        srcplus/function/YFunction.cpp
        #
        #        #objecto
        #        srcplus/objecto/Circle.cpp
        #        srcplus/objecto/Packing.c
        #        srcplus/objecto/Packing.cpp
        #        srcplus/objecto/InitObject.cpp
        #        srcplus/objecto/StaticDemo.cpp
        #        srcplus/objecto/ObjectModel.cpp
        #        srcplus/objecto/FriendClass.cpp

        #design
        #        srcplus/design/Singleton.cpp
        #
        #        #Array
        #        srcplus/array/O.h
        #        srcplus/array/Array.cpp
        #
        #        #string
        #        srcplus/string/String.h
        #        srcplus/string/String.cpp
        #        srcplus/string/StringDemo.cpp
        #
        #        #operator
        #        srcplus/operator/YOperator.cpp
        #
        #        #memory
        #        srcplus/memory/FMemory.cpp
        #
        #        #extends
        #        srcplus/extends/ExtendsMode.cpp
        #        srcplus/extends/Polymorphism.cpp
        #
        #        #funTemplate
        #        srcplus/funtemplate/FunTemplate.cpp
        #
        #        #expection
        #        srcplus/exception/FException.cpp
        #        srcplus/exception/TypeCast.cpp
        #
        #        #io
        #        srcplus/io/IO.h
        #        srcplus/io/IO.cpp
        #
        #        #stl
        #
        #        #vector
        #        srcplus/stl/container/Vector.cpp
        #        srcplus/stl/container/Vector1.cpp
        #
        #        #string
        #        srcplus/stl/container/String.cpp
        #
        #        #deque
        #        srcplus/stl/container/Deque.cpp
        #
        #        #stack
        #        srcplus/stl/container/Stack.cpp
        #
        #        #queue
        #        srcplus/stl/container/Queue.cpp
        #
        #        #list
        #        srcplus/stl/container/List.cpp
        #
        #        #set
        #        srcplus/stl/container/Set.cpp
        #
        #        #pair
        #        srcplus/stl/container/Pair.cpp
        #
        #        #map
        #        srcplus/stl/container/Map.cpp
        #
        #        #multimap
        #        srcplus/stl/container/MultiMap.cpp
        #
        #        #functor
        #        srcplus/stl/algorithm/Functor.cpp
        #        srcplus/stl/algorithm/Predicate.cpp
        #        srcplus/stl/algorithm/BuiltInFunction.cpp
        #        srcplus/stl/algorithm/Adapter.cpp
        #        srcplus/stl/algorithm/Traversal.cpp
        #        srcplus/stl/algorithm/Find.cpp
        #        srcplus/stl/algorithm/Sort.cpp
        #        srcplus/stl/algorithm/CopyAndReplace.cpp
        #        srcplus/stl/algorithm/AlgorithmCreater.cpp
        #        srcplus/stl/algorithm/CommonSet.cpp


        #-----------------------------------system----------------------------
        #file
        #        system/mian.c
        #        system/file/File.c
        #        system/file/MyTouch.c
        #        system/file/MyCat.c
        #        system/file/Lseek.c
        #        system/file/FileStat.c
        #        system/file/AccessTruncate.c
        #        system/file/Link.c
        #        system/file/Chown.c
        #        system/file/CountFiles.c
        #        system/file/Errno.c
        #        system/file/Dup2.c

        #processcntl
        #        system/processcntl/Fork.c
        #        system/processcntl/ProcessShared.c
        #        system/processcntl/Execl.c
        #        system/processcntl/Wait.c

        #processcomon
        #        system/processcomon/Pipe.c
        #        system/processcomon/FifoWrite.c
        #        system/processcomon/FifoRead.c
        #        system/processcomon/Mmap.c
        #        system/processcomon/MmapWriter.c

        #singal
        #        system/signal/Kill.c
        #        system/signal/Alarm.c
        #        system/signal/SetITimer.c
        #        system/signal/SigSet.c
        #        system/signal/SigAction.c
        #        system/signal/SigChild.c

        #thread
        #        system/thread/DaemonP.c
        #        system/thread/Thread.c
        #        system/thread/Mutex.c
        #        system/thread/TryLock.c
        #        system/thread/RwLock.c
        #        system/thread/Producer.c
        #        system/thread/Sem.c
        #        system/thread/FileLock.c

        #socket
        #        system/socket/tcp/client_tcp.c
        #        system/socket/tcp/warp/client.c
        #        system/socket/tcp/warp/server.c
        #        system/socket/tcp/warp/wrap.c
        #        system/socket/tcp/server_p.c

        srcplus/App.cpp)

add_custom_target(cmake-build-debug)
add_custom_target(cmake-build-release)
add_executable(${PROJECT_NAME} ${WORK})
target_link_libraries(${PROJECT_NAME} gtest)