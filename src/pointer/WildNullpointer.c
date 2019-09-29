//
// Created by lipnegju on 2019-06-23.
//


#include <printf.h>

/**
 * 野指针，空指针，万能指针
 */
void wildNullPointer(){

    int a=10;
    int *p=&a;

    //指向内存编号为100的内存地址
    //0-255都是系统保留的地址，不能读，也不能写
    //*p=100; 野指针是指向一个未知的内存空间，可能在读写的时候出现错误

    printf("%d\n",*p);

   // int *q =NULL;//指向内存编号为0的空间 ,可以作为条件判断使用
   // *p=100;

    void * q =&a;// void * 万能指针，因为所有指针类型用占内存大小都是一样的
    *(int *)q =100; //万能指针使用时要强转
    printf("%d\n",a);
    printf("%d\n",*(int *)q);
}

#if 0
int main(){
    wildNullPointer();
}
#endif