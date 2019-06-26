//
// Created by lipnegju on 2019-06-26.
//

#include <printf.h>
#include "YMemory.h"

int x =10;
static int y =20;
extern int z = 30;

void fun(int a, int b, int c){

    a = b;
    b=c;
    c=a+b;
    printf("%d\n",c);
    static int d =40;
    printf("%d\n",x);
    printf("%d\n",y);

}

void autoTest(){
    auto int a =10;
    for (int i = 0; i <20 ; ++i) {
        //同名变量，内层变量会隐藏外部变量，当走到外层空间时，外部的变量又会起作用
        auto int a = i;
    }
}

void scope(){
  int a=10;
  fun(a,a,a);
  //autoTest();
}


