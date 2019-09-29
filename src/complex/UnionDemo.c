//
// Created by lipnegju on 2019-06-30.
//

#include <stdio.h>

/**
 * 共用体-联合体
 * 所有共用体共用最大成员的内存
 */
union unionTest{

    double a;
    float b;
    int c;
    short d;
    char f;
    char cc [12];
} var;

#if 0
int main(){

    printf("unionTest size of %d\n", sizeof(union unionTest));
    var.a=100;
    //联合体最后一次赋值的元素是准确的
    var.b=3.14;
}

#endif