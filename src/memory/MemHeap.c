//
// Created by lipnegju on 2019-06-27.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define  MAX 10

/**
 * 1.指针操作切记不能改变指针
 */

void sortOnHeap(){
    srand(time(NULL));

    int * p = malloc(sizeof(int) * 10);

    for(int i=0;i<MAX;i++){
//       *(p+i)=rand()% 100;
         p[i]=rand() % 100;
    }

    for (int j = 0; j <MAX ; j++) {
        printf("index = %d, value =%d\n",j,*(p+j));
    }

    for (int k = 0; k <MAX ; k++) {
        for (int i = 0; i <MAX-k-1 ; i++) {
            if(p[i]>p[i+1]){
                int temp = p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }

    printf("%s\n","--------------------");

//    free(p);
//    printf("%p\n",p);

    for (int j = 0; j <MAX ; j++) {
        printf("index = %d, value =%d\n",j,*(p+j));
    }

    //释放   根据首地址自动释放  如果创建完的堆空间在使用结束之后不释放 会占用系统资源
    //先判断再释放
    if(p)
        free(p);

    //释放完成 变成空指针
    p = NULL;
}

void stringOnHeap(){
    /**
     * 1.开辟多大堆空间，就最多操作堆空间，不然，VS会出错，clion 不会出错，是编译器原因？
     */
    char * p = malloc(sizeof(char) * MAX);
    strcpy(p,"hello nihao");
    printf("%s\n",p);

    if(p!=NULL)
        free(p);

    p=NULL;

    char *pp =malloc(sizeof(char)*MAX*MAX);//可以修改
    char arr[100]="hello world";//可以修改
    arr[1]='A';
    *pp='B';


    char *p1 = "hello world";//不能修改
    char *p2 = "hello world";//不能修改

    printf("arr-> %p\n",arr);
    printf("p1-> %p\n",p1);
    printf("p2-> %p\n",p2);

    strcpy(pp,"hello world");
    printf("pp-> %p\n",pp);
    printf("%s\n",pp);

    if(pp!=NULL)
        free(pp);


}

void memHeap(){
//    sortOnHeap();
stringOnHeap();
}