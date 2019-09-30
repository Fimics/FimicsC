//
// Created by lipnegju on 2019-07-14.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 字符串
 */
void iSumUpTest(){

    char * arr ={"aaa","bbb","ccc"};
    char  *p1 ="aaa";
    char  *p2 = "bbb";
    char  *p3 = "ccc";

    char * arr1 = {p1,p2,p3};
    //以上两种方式等价

    //返回的是首元素的地址
    char  **arr2 = malloc(sizeof(char *)*4);

//    char ** arr3 ={"aaa","bbb","ccc"}; 写法错误，前面的是指针类型大小为4个字节，后边的为9个字节，不能把9个字节赋值给4个字节的指针

}

void iSumUpArray(){
    //除了sizeof 和对数组名取地址这两种情况下，其他任何情况下数组名都是是指向元素首地址的指针
    int arr [10];// arr 是int *类型

    int arr1[3][3]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    //arr1 是什么类型？int(*)[3]

    char  *arr3[]={"aaa"};
    //arr3 是char ** 类型，因为"aaa"是 char *类型，保存char *类型的地址所以是char **类型
    char  ** arr4[3];//arr4的类型是 char ***



}

void iSumUp(){
// iSumUpTest();
}