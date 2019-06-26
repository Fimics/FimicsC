//
// Created by lipnegju on 2019-06-26.
//

#include <printf.h>

void fun(int a, int b, int c){

    a = b;
    b=c;
    c=a+b;
    printf("%d\n",c);

}

void scope(){
  int a=10;
  fun(a,a,a);
}

