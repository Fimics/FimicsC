#include<stdio.h>
#include"./include/head.h"

int main(){
  int a=10;
  int b = 10;

  int addResult = add(a,b);
  int divResult = div(a,b);
  int mulResult = mul(a,b);
  int subResult = sub(a,b);

  printf("\n");
  printf("add result = %d\n",addResult);
  printf("div result = %d\n",divResult);
  printf("mul result = %d\n",mulResult);
  printf("sub result = %d\n",subResult);
  return 1;
}
