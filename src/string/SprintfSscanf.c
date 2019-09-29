//
// Created by lipnegju on 2019-06-21.
//

#include <stdio.h>
#include <string.h>

/**
 *根据参数字符串来转换并格式化数据，然后把结果输出到str指定的空间，直到出现字符串结束符
 */
void sprintfsscanf(){

    int a1 =123;
    char arr1[] ="hello";
    char dest1[100];
    sprintf(dest1,"%s %d",arr1,a1);//把 arr,a的内容写入到dest中
    printf("%s\n",dest1);

    int a ;
    int b,c;
    char arr[100] ;
    char dest[100]="1+2=";
    sscanf(dest,"%d+%d",&b,&c);//把dest里的内容读取到，b,c中
    printf("%d+%d=%d",b,c,b+c);
}

#if 0
int main(){
    sprintfsscanf();
}
#endif