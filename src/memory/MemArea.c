//
// Created by lipnegju on 2019-06-27.
//

#include <YMemory.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 1.代码区
 * 存放 CPU 执行的机器指令。通常代码区是可共享的（即另外的执行程序可以调用它），
 * 使其可共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可。代码区通常是只读的，
 * 使其只读的原因是防止程序意外地修改了它的指令。另外，代码区还规划了局部变量的相关信息
 *
 * 加载的是可执行文件代码段，所有的可执行代码都加载到代码区，这块内存是不可以在运行期间修改的。
 *--------------------------------------------------------------------------------------------------
 *
 * 2.全局初始化数据区/静态数据区（data段）
 * 该区包含了在程序中明确被初始化的全局变量、已经初始化的静态变量（
 * 包括全局静态变量和局部静态变量）和常量数据（如字符串常量）
 *
 * 加载的是可执行文件数据段，存储于数据段（全局初始化，静态初始化数据，文字常量(只读)）的数据的生存周期为整个程序运行过程。
 *
 * ---------------------------------------------------------------------------------------------------
 * 3.未初始化数据区（又叫 bss 区）
 * 存入的是全局未初始化变量和未初始化静态变量。未初始化数据区的数据在程序开始执行之前被内核初始化为 0 或者空（NULL）。
 *
 * 程序在加载到内存前，代码区和全局区(data和bss)的大小就是固定的，程序运行期间不能改变。
 * 然后，运行可执行程序，系统把程序加载到内存，除了根据可执行程序的信息分出代码区（text）、
 * 数据区（data）和未初始化数据区（bss）之外，还额外增加了栈区、堆区
 *
 * 加载的是可执行文件BSS段，位置可以分开亦可以紧靠数据段，存储于数据段的数据（全局未初始化，静态未初始化数据）的生存周期为整个程序运行过程。
 *
 *-------------------------------------------------------------------------------------------------------
 *
 * 4.栈区（stack）
 * 栈是一种先进后出的内存结构，由编译器自动分配释放，存放函数的参数值、返回值、局部变量等。
 * 在程序运行过程中实时加载和释放，因此，局部变量的生存周期为申请到释放该段栈空间
 * --->变量，数组，结构体，指针枚举，函数形参，只有c语言把数组放在栈区，其他语言把数组放在堆区
 * int arr[1000000000000],超出栈空间了，如果创建大的数要放在堆区，需要申请内存（栈区 windows 1-8 M）
 *
 * --------------------------------------------------------------------------------------------------------
 * 5.堆区（heap）
 * 堆是一个大容器，它的容量要远远大于栈，但没有栈那样先进后出的顺序。用于动态内存分配。
 * 堆在内存中位于BSS区和栈区之间。一般由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收。
 *
 */

/**
 * 死循环: 会占满CPU,不会占满内存，不会死机
 * 递归  : 会死机 ,会占满栈区，栈溢出
 */


void testMalloc(){
    //开辟堆空间
   // int *p = malloc(1000* sizeof(int));
}

/**
 * 数据的存储范围和内存存储方向
 */

int e;
int f =10;
static int g;
static int h=20;

void testDataStorgeRange(){
    int a = 10;
    static int b;
    static int c = 10;

    int i[10];
    int j[10] = { 0 };

    int *k;
    int *l = &a;

    char *p = "hello world";
    char ch[] = "hello world";

    const int m = 10;

    /**
     * 查看下列哪些地址距离
     */
    printf("局部变量a的地址:%p\n", &a);
    printf("未初始化局部静态变量b的地址:%p\n", &b);
    printf("初始化局部静态变量c的地址:%p\n", &c);
    printf("未初始化全局变量e的地址:%p\n", &e);
    printf("初始化全局变量f的地址:%p\n", &f);
    printf("未初始化静态全局变量g的地址:%p\n", &g);
    printf("初始化静态全局变量h的地址:%p\n", &h);

    printf("未初始化数组i的地址：%p\n", i);
    printf("初始化数组j的地址：%p\n", j);

    printf("未初始化指针k的地址：%p\n", &k);
    printf("初始化指针l的地址：%p\n", &l);

    printf("字符串常量p的地址：%p\n", p);
    printf("常量m的地址：%p\n", &m);

    printf("字符数组ch的地址：%p\n", ch);
}

void testMemArea(){
//   int arr[100000];
    testDataStorgeRange();
}