//
// Created by lipnegju on 2019-07-09.
//

/**
 * 1.指针不管什么类型，几级指针，都占用4/8个字节
 * 2.指针降级
 *   int a=10; int *p = &a; *p = int (8)
 * 3.什么情况后产生野指针？
 *   3.1指针变量未初始化
 *   3.2指针释放后未置空
 *   3.3指针操作超出变量作用域，不要返回指向栈内存的指针或引用，因为栈内存在还书结束时会被释放
 * 4.
 */

#include <stddef.h>

#if 1
//------------------------指针步长----------------------------
/**
 * 1.指针变量加1时，指针向后跳多少个字节,步长由指针类型决定
 * 2.指针类型，不但可以决定指针的步长，还决定解引用时从给定地址开始取类型大小的字节
 * 3.
 */

void testStepSize(){

    char * p =NULL;
    printf(" p %d\n",p);
    printf( "p+1  %d\n",p+1);

    int *q = NULL;
    printf(" q %d\n",q);
    printf( "q+1  %d\n",q+1);

}
#endif


void iPointer(){
#if 1
    testStepSize();
#endif
}