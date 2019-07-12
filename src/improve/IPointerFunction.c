//
// Created by pengju.li on 2019-07-12.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>




#if 1

void allocateSpace(int ** temp){
    int *arr = malloc(sizeof(int)*10);

    for (int i = 0; i <10 ; ++i) {
        arr[i]=i;
    }

    *temp =arr;

    if(arr!=NULL){
        free(arr);
    }

}

#if 0
void freeSpace0(void * p){
    if(p==NULL) return;

    free(p);
    p=NULL;

}
#endif

void freeSpace0(int  ** p){
    if(p==NULL) return;

    free(*p);
    *p=NULL;

}

void printArray(int * arr ,int len){
    for (int i = 0; i <len ; ++i) {
        printf("index : %d value %d\n",i,arr[i]);
    }
}

void testArr(){
    int * arr =NULL;
    allocateSpace(&arr);
    printArray(arr,10);
}
#endif

void iPointerFunction(){
#if 0
#endif
    testArr();
}