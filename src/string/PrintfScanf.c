//
// Created by lipnegju on 2019-06-19.
//

#include <stdlib.h>
#include <stdio.h>

#define W " -------- "
#define H "|"

void table(int x ,int y);
void drawLine(int w);

/**
 *string format
 */
void printfScanf(){

    char arr[100];
    int a,b,c;
    char arr1[88];
    char arr2[100];
    int ch;

    /**
     * 1.接收换行结束，可以接收空格
     */
    //scanf("%[^\n],arr");

    /**
     * 2.在scanf获取数据时，建议不要添加任何字符 空格除外，因为空格代表字符串结束
     * ,scanf中""的格式(可能有换行，逗号)要和输入的格式对应上,
     */
    //scanf("%d,%d,%d",&a,&b,&c);
    //scanf("a=%db=%dc=%d",&a,&b,&c);

    /**
     * 3.每个只能接收指定长度的字符串
     */
    // scanf("%4d%4d%4d",&a,&b,&c);
    //scanf("%1s%3s",arr1,arr2);
    //printf("%s,%s",arr1,arr2);

    /**
     * 4正则限定
     */
     //scanf("%*d%s",arr1);//忽略数字
     //printf("%s",arr1);
     //scanf("%*[12345678]%c",&ch); //忽略【a-z】内的数字
     //printf("%c",ch);

//     printf("%.2f\n",3.32342);//小数点后保留两位
//     printf("%5d\n",12);//左边加空格
//     printf("%05d\n",12);//左边加0
//     printf("%4s\n","abc");
//     printf("%4s\n","ab");


    //printf("%d,%d,%d",a,b,c);
     table(10,10);
}

/**
 * 9X9 table
 */
void table(int x,int y){

    for(int i=1;i<=x;i++){
        drawLine(i);
        for(int j=1;j<=i;j++){
            printf("%s",H);
            printf("%2dx%2d=%2d ",j,i,i*j);
        }
        printf("%s",H);
        printf("\n");
    }
    drawLine(x);
}

void drawLine(int x){
    for(int i=0;i<x;i++){
        if(i<x-1){
            printf("%s",W);
        }else{
            printf("%s\n",W);
        }
    }
}

#if 0

int main(){
    printfScanf();
}

#endif