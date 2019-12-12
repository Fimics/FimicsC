//
// Created by pengju.li on 2019-12-12.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//-------------------------------printf scanf-------------------------------------
#define W " -------- "
#define H "|"

void table(int x, int y);

void drawLine(int w);

/**
 *string format
 */
void printfScanf() {

    char arr[100];
    int a, b, c;
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
    table(10, 10);
}

/**
 * 9X9 table
 */
void table(int x, int y) {

    for (int i = 1; i <= x; i++) {
        drawLine(i);
        for (int j = 1; j <= i; j++) {
            printf("%s", H);
            printf("%2dx%2d=%2d ", j, i, i * j);
        }
        printf("%s", H);
        printf("\n");
    }
    drawLine(x);
}

void drawLine(int x) {
    for (int i = 0; i < x; i++) {
        if (i < x - 1) {
            printf("%s", W);
        } else {
            printf("%s\n", W);
        }
    }
}

//-------------------------------puts gets-------------------------------------
/**
 * gets() 获取字符串
 * puts()
 * scanf()
 * getchar() 获取一个字符
 * 功能：从标准的输入读入字符，并保存到指定的内存空间，直到出现换行符，或读到文件结尾为止
 * 参数:s 字符串首地址
 *
 * gets(str)与scanf(str)的区别
 * 1.gets允许输入的字符串含有空格
 * 2.scanf不允许含有空格
 *
 * 由于sacnf()和gets()无法知道字符串s的大小，必须遇到换行或读到文件结尾才接
 * 收输入，因此容易导致字符串数组越界(缓存区溢出)的情况
 *
 * 返回值
 * 成功:非负数
 * 失败:-1
 */
void putsGets() {
    char s[1];
    gets(s);
    //scanf("%[^\n]",s);
    //输出一个字符串并换行
    //puts(s);

    char *p = gets(s);
    //同样可以接收
    printf("%s", p);
}

//-------------------------------fgets fputs-------------------------------------
/**
 * char *fgets(char *s ,int size,FILE *stream)
 * 功能:
 * 从stream的文件内读入字符，保存到所指定的内存空间，直到出现换行字符，读到文件末尾
 * 或已经读了size-q个字符为止，最后会自动加上字符'\0'，作为字符串结束
 *
 * 参数
 * s :字指针
 * size:指定读取最大字符串的长度(size-1)
 * stream:文件指针,如果读取键盘的输入的字符串，固定写为stdin
 *
 * 返回值
 * 成功：
 * 失败：读到文件尾或出错NULL
 *-------------------------------------------------------------------
 * fputs(const char * str, FILE * stream)
 * 功能:
 *    把str所指定的字符串写入到stream所指写的文件中，字符串结束符'\0'不写入文件
 *
 * 参数：
 *   str:字符串
 *   stream:文件指针，如查把字符串输出到屏幕，固定写stdout
 * 返回值：
 *   成功：0
 *   失败：-1
 *
 * 注意
 *
 */
void fgetsFputs() {
//    FILE * fileOut = "../resource/b.txt";

    char file[10];
    fgets(file, 10, stdin);
    //puts(file);

    fputs(file, stdout);
}


//-------------------------------sprint fsscanf-------------------------------------
/**
 *根据参数字符串来转换并格式化数据，然后把结果输出到str指定的空间，直到出现字符串结束符
 */
void sprintfsscanf() {

    int a1 = 123;
    char arr1[] = "hello";
    char dest1[100];
    sprintf(dest1, "%s %d", arr1, a1);//把 arr,a的内容写入到dest中
    printf("%s\n", dest1);

    int a;
    int b, c;
    char arr[100];
    char dest[100] = "1+2=";
    sscanf(dest, "%d+%d", &b, &c);//把dest里的内容读取到，b,c中
    printf("%d+%d=%d", b, c, b + c);
}

//-------------------------------strFind-------------------------------------
/**
 * strchr(const char *s,int c) ,在字符串s中查找c第一次出现的位置
 * strstr(const char *s, const char *c)在s中查找字符串c出现的位置
 */

void strFind() {
    char s[] = "hello world ,e ,9 hello world ,jump";
    char c = 'j';

//    char * pOne = strchr(s,c);
//    printf("one find index %s\n",pOne);
    char *pMany = strstr(s, "e");
    printf("many find index %s\n", pMany);
}

//-------------------------------stratoi-------------------------------------

void stratoi() {

    char arr[] = "http://www.google.com";
    //将切割点用\0表示，这样切割会改变原始字符串
    char *p = strtok(arr, ".");
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, ".");
    }

    /**
     * atoi()会扫描字符串，跳过前面的空格字符，直到遇到数字，或正负号才开始做转换，而遇到非数字或字符串结束符才结束转换，并将结果返回
     * atof() 把一个数形式的字符串转化为一个浮点数
     * atol() 把一个字符串转化为log类型
     */

    char arri[] = "  -12  3";
    int ai = atoi(arri);
    printf("atoi %d\n", ai);

}

//-------------------------------strLen-------------------------------------

/**
 * 字符串有效长度
 */
void strLen() {
//    char  arr[] ="hello";
    char arr[] = {'h', 'e', 'l', 'l', 'o'};//strlen 不能处理字符数组
    int len = strlen(arr);
    printf("字符串的有效长度：%d", len); //忽略字符串结束符号
    printf("字符串的长度:%d", sizeof(arr));
}


//-------------------------------strCpy-------------------------------------
/**
 * strcpy ,strncpy(dest,src,n) 拷贝n个
 */
void strCpy() {
    char arr1[] = "hello world";
    char arr2[100];
    //参数: 1目标字符串，2源字符串 ,会拷贝'\0'
//  if(strcpy(arr2,arr1)){
//      printf("%s",arr2);
//      printf("字符串的长度:%d", sizeof(arr2));
//  }

// srcncpy不会拷贝'\0' 可以手到加一个
    if (strncpy(arr2, arr1, 3) != NULL) {
        arr2[3] = '\0';
        printf("%s", arr2);
        printf("字符串的长度:%d", sizeof(arr2));
    }
}

//-------------------------------strCat-------------------------------------

/**
 * strcat ,strncat 会把'\0'追加过去
 *字符串追加 stringBuffer |stringBuilder
 */
void strCat() {
    char arr1[22] = "hello";
    char arr2[] = "world";
    //把2的内容追加到1里
    strcat(arr1, " ");
    //strcat(arr1,arr2);
    //有限追加
    strncat(arr1, arr2, 2);
    printf("arr1 %s\n", arr1);
    printf("arr2 %s\n", arr2);

}

//-------------------------------strCmp-------------------------------------
/**
 * strcmp strncmp
 * 比较字符的ASSIC码,不同的操作系统返回的值不同，有的返回ASSIC差值，有的返回 0，1 -1
 */

void strCmp() {
    char arr1[] = "hello12dd";
    char arr2[] = "hello1";
    //把2的内容追加到1里
    //int result =strcmp(arr1,arr2);
    int result = strncmp(arr1, arr2, 7);
    printf("result %d\n", result);
}


#if 0

int main() {
//    printfScanf();
//    putsGets();
//      fgetsFputs();
//    sprintfsscanf();
//      strFind();
//      stratoi();
    strLen();
    strCpy();
    strCat();
    strCmp();
    return 1;
}

#endif