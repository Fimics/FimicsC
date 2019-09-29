//
// Created by lipnegju on 2019-06-30.
//

#include <stdio.h>

struct stra{
    int a;
    int b;
    int c;
}abc;

struct strb{
    double d;
    char * e;
    short f;
    struct stra abc;
};


void structstruct(){

    struct strb vstrb;
    vstrb.d=10.f;
    vstrb.abc.a=20;

    printf("strb size %d\n", sizeof(struct strb));
}