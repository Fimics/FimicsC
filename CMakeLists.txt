cmake_minimum_required(VERSION 3.10.2)
project(FimicsCPP)
project(FimicsC)
project(FimicsCLINUX)
project(FimicsCSTRUCTURE)

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
        #basic
        srcplus/base/Basic.cpp

        #function
        srcplus/function/ExternC.c
        srcplus/function/ExternC.h
        srcplus/function/ExternC.cpp
        srcplus/function/FunctionPointer.cpp
        srcplus/function/ReferenceVariavle.cpp
        srcplus/function/YFunction.cpp

        #objecto
        srcplus/objecto/Circle.cpp
        srcplus/objecto/Packing.c
        srcplus/objecto/Packing.cpp
        srcplus/objecto/InitObject.cpp
        srcplus/objecto/StaticDemo.cpp
        srcplus/objecto/ObjectModel.cpp
        srcplus/objecto/FriendClass.cpp

        #design
        srcplus/design/Singleton.cpp

        #Array
        srcplus/array/O.h
        srcplus/array/Array.cpp

        #string
        srcplus/string/String.h
        srcplus/string/String.cpp
        srcplus/string/StringDemo.cpp

        #operator
        srcplus/operator/YOperator.cpp

        #memory
        srcplus/memory/FMemory.cpp

        #extends
        srcplus/extends/ExtendsMode.cpp
        srcplus/extends/Polymorphism.cpp

        #funTemplate
        srcplus/funtemplate/FunTemplate.cpp

        #expection
        srcplus/exception/FException.cpp
        srcplus/exception/TypeCast.cpp

        #io
        srcplus/io/IO.h
        srcplus/io/IO.cpp

        #stl

        #vector
        srcplus/stl/container/Vector.cpp
        srcplus/stl/container/Vector1.cpp

        #string
        srcplus/stl/container/String.cpp

        #deque
        srcplus/stl/container/Deque.cpp

        #stack
        srcplus/stl/container/Stack.cpp

        #queue
        srcplus/stl/container/Queue.cpp

        #list
        srcplus/stl/container/List.cpp

        #set
        srcplus/stl/container/Set.cpp

        #pair
        srcplus/stl/container/Pair.cpp

        #map
        srcplus/stl/container/Map.cpp

        #multimap
        srcplus/stl/container/MultiMap.cpp

        #functor
        srcplus/stl/algorithm/Functor.cpp
        srcplus/stl/algorithm/Predicate.cpp
        srcplus/stl/algorithm/BuiltInFunction.cpp
        srcplus/stl/algorithm/Adapter.cpp
        srcplus/stl/algorithm/Traversal.cpp
        srcplus/stl/algorithm/Find.cpp
        srcplus/stl/algorithm/Sort.cpp
        srcplus/stl/algorithm/CopyAndReplace.cpp
        srcplus/stl/algorithm/AlgorithmCreater.cpp
        srcplus/stl/algorithm/CommonSet.cpp

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

set(Fimics_C_STRUCTURE

        #1nd_review
#        structure/1nd_review/abcConstRef.cpp
#        structure/1nd_review/abcException.cpp
#        structure/1nd_review/abcExceptionChar.cpp
#        structure/1nd_review/abcFloat.cpp
#        structure/1nd_review/abcGeneral.cpp
#        structure/1nd_review/abcInt.cpp
#        structure/1nd_review/abcRef.cpp
#        structure/1nd_review/abcTemplate.cpp
#        structure/1nd_review/currency.cpp
#        structure/1nd_review/currency.h
#        structure/1nd_review/currencyFriend.cpp
#        structure/1nd_review/currencyFriend.h
#        structure/1nd_review/currencyNew.cpp
#        structure/1nd_review/currencyNew.h
#        structure/1nd_review/currencyOverload.cpp
#        structure/1nd_review/currencyOverload.h
#        structure/1nd_review/delete2dArray.cpp
#        structure/1nd_review/delete2dArray.h
#        structure/1nd_review/factorial.cpp
#        structure/1nd_review/indexOfMax.cpp
#        structure/1nd_review/make2dArray.cpp
#        structure/1nd_review/make2dArray.h
#        structure/1nd_review/make2dArrayNoCatch.cpp
#        structure/1nd_review/make2dArrayNoCatch.h
#        structure/1nd_review/myExceptions.h
#        structure/1nd_review/noSwap.cpp
#        structure/1nd_review/permutations.cpp
#        structure/1nd_review/permutationsSTL.cpp
#        structure/1nd_review/productSTL.cpp
#        structure/1nd_review/quadraticRoots.cpp
#        structure/1nd_review/rsum.cpp
#        structure/1nd_review/sum.cpp
#        structure/1nd_review/sumSTL.cpp

        #2nd_performance_analysis
#        structure/2nd_performance_analysis/bubbleSort.cpp
#        structure/2nd_performance_analysis/d.cpp
#        structure/2nd_performance_analysis/earlyBubbleSort.cpp
#        structure/2nd_performance_analysis/earlySelectionSort.cpp
#        structure/2nd_performance_analysis/horner.cpp
#        structure/2nd_performance_analysis/inef.cpp
#        structure/2nd_performance_analysis/insert.cpp
#        structure/2nd_performance_analysis/insertionSort.h
#        structure/2nd_performance_analysis/insertionSort1.cpp
#        structure/2nd_performance_analysis/insertionSort2.cpp
#        structure/2nd_performance_analysis/matrixAdd.cpp
#        structure/2nd_performance_analysis/matrixMultiply1.cpp
#        structure/2nd_performance_analysis/matrixMultiply2.cpp
#        structure/2nd_performance_analysis/matrixMultiply3.cpp
#        structure/2nd_performance_analysis/matrixTerm.h
#        structure/2nd_performance_analysis/matrixTranspose.cpp
#        structure/2nd_performance_analysis/matrixWithTranspose.cpp
#        structure/2nd_performance_analysis/matrixWithTranspose.h
#        structure/2nd_performance_analysis/minmax1.cpp
#        structure/2nd_performance_analysis/minmax2.cpp
#        structure/2nd_performance_analysis/minMax3.cpp
#        structure/2nd_performance_analysis/polyEval.cpp
#        structure/2nd_performance_analysis/quickSort.cpp
#        structure/2nd_performance_analysis/quickSort.h
#        structure/2nd_performance_analysis/rank.cpp
#        structure/2nd_performance_analysis/rankSort1.cpp
#        structure/2nd_performance_analysis/rankSort2.cpp
#        structure/2nd_performance_analysis/rSequentialSearch.cpp
#        structure/2nd_performance_analysis/rSumCount.cpp
#        structure/2nd_performance_analysis/selectionSort.cpp
#        structure/2nd_performance_analysis/sequentialSearch1.cpp
#        structure/2nd_performance_analysis/sequentialSearch2.cpp
#        structure/2nd_performance_analysis/sumCount1.cpp
#        structure/2nd_performance_analysis/sumCount2.cpp


        #3nd_asymptotic_analysis
#        structure/3nd_asymptotic_analysis/binarySearch.cpp

        #4nd_performance_measurement
#        structure/4nd_performance_measurement/timeInsertionSort1.cpp
#        structure/4nd_performance_measurement/timeInsertionSort2.cpp
#        structure/4nd_performance_measurement/timeInsertionSort3.cpp
#        structure/4nd_performance_measurement/timeInsertionSort4.cpp


        #5nd_arraylist
        structure/5nd_arraylist/linearList.h
        structure/5nd_arraylist/arrayList.h
#        structure/5nd_arraylist/arrayList.cpp
        structure/5nd_arraylist/arrayListWithIterator.h
#        structure/5nd_arraylist/arrayListWithIterator.cpp
        structure/5nd_arraylist/vectorList.h
#        structure/5nd_arraylist/vectorList.cpp
        structure/5nd_arraylist/arrayListNoSTL.h
#        structure/5nd_arraylist/arrayListNoSTL.cpp

        #6nd_linkedlist
        structure/6nd_linkedlist/chain.h
        structure/6nd_linkedlist/chainNode.h
#        structure/6nd_linkedlist/chain.cpp
        structure/6nd_linkedlist/chainWithIterator.h
#        structure/6nd_linkedlist/chainWithIterator.cpp
        structure/6nd_linkedlist/extendedChain.h
        structure/6nd_linkedlist/extendedLinearList.h
#        structure/6nd_linkedlist/extendedChain.cpp
#        structure/6nd_linkedlist/circularListWithHeader.cpp
        structure/6nd_linkedlist/circularListWithHeader.h
#        structure/6nd_linkedlist/binsort1.cpp

        #7nd_array_and_matrix
#        structure/7nd_array_and_matrix/irregularArray.cpp
#        structure/7nd_array_and_matrix/matrix.cpp
        structure/7nd_array_and_matrix/matrix.h
        structure/7nd_array_and_matrix/diagonalMatrix.h
#        structure/7nd_array_and_matrix/diagonalMatrix.cpp

        #8nd_stack
        structure/8nd_stack/stack.h
        structure/8nd_stack/derivedArrayStack.h
#        structure/8nd_stack/derivedArrayStack.cpp
        structure/8nd_stack/arrayStack.h
#        structure/8nd_stack/arrayStack.cpp
        structure/8nd_stack/derivedArrayStackWithCatch.h
#        structure/8nd_stack/derivedArrayStackWithCatch.cpp
        structure/8nd_stack/derivedLinkedStack.h
#        structure/8nd_stack/derivedLinkedStack.cpp
        structure/8nd_stack/linkedStack.h
#        structure/8nd_stack/linkedStack.cpp
#        structure/8nd_stack/parenthesisMatching.cpp
#        structure/8nd_stack/hanoiRecursive.cpp
#        structure/8nd_stack/hanoiUsingStacks.cpp

        #9nd_queue
        structure/9nd_queue/queue.h
        structure/9nd_queue/arrayQueue.h
#        structure/9nd_queue/arrayQueue.cpp
#        structure/9nd_queue/linkedQueue.cpp
        structure/9nd_queue/linkedQueue.h

        #10nd_skiplist_hash
        structure/10nd_skiplist_hash/dictionary.h
        structure/10nd_skiplist_hash/hash.h
#        structure/10nd_skiplist_hash/hashChains.cpp
        structure/10nd_skiplist_hash/hashChains.h
#        structure/10nd_skiplist_hash/hashTable.cpp
        structure/10nd_skiplist_hash/hashTable.h
        structure/10nd_skiplist_hash/pairNode.h
#        structure/10nd_skiplist_hash/skipList.cpp
        structure/10nd_skiplist_hash/skipList.h
        structure/10nd_skiplist_hash/skipNode.h
#        structure/10nd_skiplist_hash/sortedChain.cpp
        structure/10nd_skiplist_hash/sortedChain.h
#        structure/10nd_skiplist_hash/stringToInt.cpp
#        structure/10nd_skiplist_hash/threeToLong.cpp


        #11nd_binary_tree
        structure/11nd_binary_tree/binaryTree.h
        structure/11nd_binary_tree/binaryTreeNode.h
#        structure/11nd_binary_tree/binaryTreeTraversals.cpp
#        structure/11nd_binary_tree/infix.cpp
#        structure/11nd_binary_tree/linkedBinaryTree.cpp
#        structure/11nd_binary_tree/linkedBinaryTree.h

        #12nd_priority_queue
        structure/12nd_priority_queue/heapSort.cpp
        structure/12nd_priority_queue/heapSort.h
#        structure/12nd_priority_queue/maxHblt.cpp
        structure/12nd_priority_queue/maxHblt.h
#        structure/12nd_priority_queue/maxHeap.cpp
        structure/12nd_priority_queue/maxHeap.h
        structure/12nd_priority_queue/maxPriorityQueue.h
#        structure/12nd_priority_queue/minHeap.cpp
        structure/12nd_priority_queue/minHeap.h
        structure/12nd_priority_queue/minPriorityQueue.h
       )


add_executable(FimicsCPP ${SOURCE_CPP_FILES})
add_executable(FimicsC ${SOURCE_C_FILES})
add_executable(FimicsCLINUX ${SOURCE_SYSTEM_FILES})
add_executable(FimicsCSTRUCTURE ${Fimics_C_STRUCTURE})
