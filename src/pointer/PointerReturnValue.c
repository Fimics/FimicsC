//
// Created by lipnegju on 2019-06-25.
//

#include <printf.h>
#include <string.h>

char * charTest(){
//    char arr []="hello world"; 字符数组，创建位置在栈区，退出函数时会销毁
    char * arr ="hello world"; //字符串常量，会在程序运行时放在常量区(不能被修改，但可以读)，在程序结时结束
//    arr=100 X 保证指针地址对应的值是有内容的
    return arr;
}


void pointerReturnValue(){

    char  * arr =charTest();
    printf("%s\n",arr);
}