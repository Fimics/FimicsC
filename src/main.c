//
// Created by pengju.li on 2019-06-14.
//

#include <stdio.h>

//#include "YString.h"
//#include "YPointer.h"
//#include "YFunction.h"
//#include "DataType.h"
//#include "YArray.h"
//#include "System.h"
//#include "YDataStructure.h"
//#include "YMemory.h"
//#include "YComplex.h"
//#include "YFile.h"
#include "YImprove.h"

extern void fun(int a, int b, int c);

/**
 * @param argc  接收传递参数的个数
 * @param argv  接收传递参数的内容
 * @return
 */
int main(int argc, char *argv[]) {

#if 0
    structure();
    testString();
    testFunction();
    testPointer();
    memory();
    complex();
    yFile();
    testArray();
    testArray2d();
    testArrayAndPointer();
    testSum2d();
    testSystem();
#endif
    yImprove();

    return 0;
}