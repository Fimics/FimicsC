//
// Created by lipnegju on 2019-07-19.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * 1.预处理是在程序源代码编译之前，由预处理器对程序源代码进行的处理，这个过程并不是对程序的源
 * 代码语法进行解析，但它会把源代码分割或处理成为特定的符号，为下一步编译做准备工作
 *
 * 2.文件包含指令(#include)
 * 3.宏常量 define max 24 在编译期间是看不到max 这个符号，因为是直接替换，只有在定义的文件内起作用
 * 4.宏函数 define add(x,y) (x+y)
 * 5.条件编译
 *
 *
 * 1. __FILE__ 宏所在文件的文件名
 * 2. __LINE__ 宏所在行的行号
 * 3. __DATA__ 代码编译的日期
 * 4. __TIME__ 代码编译的时间
 */

#define FLAG_64 1
/**
 * 条件编译
 */
#if FLAG_64
void condationCompile(long a){

}
#else
void condationCompile1(int a){

}
#endif



#ifndef __FLAG_64 1
#define __FLAG_64 1
#endif __FLAG_64 1

