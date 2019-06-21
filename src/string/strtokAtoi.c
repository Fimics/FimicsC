//
// Created by lipnegju on 2019-06-21.
//

#include <stdio.h>
#include "YString.h"
#include <string.h>
#include <stdlib.h>

void strtopatoi(){

    char arr []="http://www.google.com";
    //将切割点用\0表示，这样切割会改变原始字符串
    char *p =strtok(arr,".");
    while (p!=NULL){
        printf("%s\n",p);
        p=strtok(NULL,".");
    }

    /**
     * atoi()会扫描字符串，跳过前面的空格字符，直到遇到数字，或正负号才开始做转换，而遇到非数字或字符串结束符才结束转换，并将结果返回
     * atof() 把一个数形式的字符串转化为一个浮点数
     * atol() 把一个字符串转化为log类型
     */

    char arri[] ="  -12  3";
    int ai = atoi(arri);
    printf("atoi %d\n",ai);

}