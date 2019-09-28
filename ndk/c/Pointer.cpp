//
// Created by lipengju on 2019-09-29.
//


#include <stdio.h>

void testPointerAddr(){
    int i = 100;
    double d = 200;

    printf("i的值是：%d\n",i);
    // 通过 * 获取地址的值
    printf("i的值是：%d\n",*(&i));

    // 指针(地址)变量 指针存放（指向）的就是变量的地址
    // int* 代表的是 int类型的指针（地址）
    int* p = &i;
    // double* p1 = &d;
    printf("i的值是：%d\n", *p);
}

//通过指针修改值
void testModifyValueByPointer(){
    int i = 100;

    int* p = &i;

    i = 200;

    printf("i的值是：%d\n",i);

    // 还有一种方式：获取指针的值进行间接的修改
    *p = 300;
    printf("i的值是：%d", i);
}

// 通过地址来修改
void change(int* p){
    printf("change中i的地址是：%p\n",p);
    *p = 200;
}

// 通过方法修改值
void testUpdateValueByMethod(){
    int i = 100;
    printf("i的地址是：%p\n", &i);
    printf("i的值是：%d\n", i);

    change(&i);

    printf("i修改后的值是：%d\n", i);
    getchar();
}

// 题目：写个方法对两个值进行交换
void testChangeValue(int* a,int* b){ // 2 面试题：对 a,b 两个值进行交换，但是不开辟额外的内存（不能用中间变量）
    // 大家在这里面写
    int temp = *a;

    *a = *b;// a的值 = b 的值

    *b = temp;
}

//int main(){
//
//#if 0
//    testPointerAddr();
//#endif
////    testModifyValueByPointer();
//    testUpdateValueByMethod();
//    return 0;
//}