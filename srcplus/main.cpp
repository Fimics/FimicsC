#include <iostream>

using namespace std;

#include "base/Basic.h"
#include "objecto/YObjectO.h"
#include "function/YFunction.h"
#include "design/YDesign.h"
#include "operator/YOperator.h"
#include "array/Array.h"
#include "string/String.h"
#include "extends/FExtends.h"
#include "string/StringDemo.h"
#include "memory/FMemory.h"
#include "funtemplate/FunTemplate.h"

int main() {
#if 0
    basic();
    design();
    objecto();

    yOperator();
    farray();
    stringDemo();
    myString();
    fMemory();
    fExtends();
//    yFunction();
#endif
    funTemplate();
    return 0;
}