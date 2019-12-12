//
// Created by lipnegju on 2019-06-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //可移植数据类型
#include <inttypes.h>

//------------------------------------------dataType------------------------------------------------
void testScanf() {
    float weight;
    float value;

    printf("Are you worth you weight in platinum?\n");
    printf("Let's check ot out .\n");
    printf("Pleease enter u weight in pounds:");

    scanf("%f", &weight);
    value = 17000.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
}

void testSizeof() {
    int a; // int ->long int ->unsigned long ->long long
    long b;
    short c;
    unsigned d; //无符号
    char e;
    float f;
    double h;
    signed j; //有符号
    _Bool k;
    _Complex l;
    long int li;
    long long int lli;

    unsigned int w;
    signed int q;

    int32_t aa;//可移植数据类型

    printf("int sizeof %d \n", sizeof(a));
    printf("long sizeof %lu \n", sizeof(b));
    printf("short sizeof %d \n", sizeof(c));
    printf("unsigned sizeof %d \n", sizeof(d));
    printf("char sizeof %d \n", sizeof(e));
    printf("float sizeof %d \n", sizeof(f));
    printf("double sizeof %d \n", sizeof(h));
    printf("signed sizeof %d \n", sizeof(j));
    printf("_Bool sizeof %d \n", sizeof(k));
    printf("_Complex sizeof %d \n", sizeof(l));
    printf("long int sizeof %d \n", sizeof(li));
    printf("long long int sizeof %d \n", sizeof(lli));
    printf("unsigned int sizeof %d \n", sizeof(w));
    printf("signed  int sizeof %d \n", sizeof(q));

    char cc = 'A';
    printf("cc is %d", cc);

    // _Bool 1;

    int32_t i32t; //32位有符号整数类型
    int_fast8_t intFast8;
    int_least8_t intLeast8;


}

//------------------------------------------char------------------------------------------------

void getCharPutChar() {
    char ch;
    while ((ch = getchar()) != 'q') {
        putchar(ch);
    }

//    while ((ch=getchar()!=EOF)) 判断文件末尾
}

void testFileEof() {
    int ch;
    FILE *fp;
    char fname[50];         // to hold the file name

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // open file for reading
    if (fp == NULL)         // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(1);            // quit program
    }
    // getc(fp) gets a character from the open file
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}

//------------------------------------------BinaryConvert--------------------------------------

/**
 * 原码(原始的二进制数)
 * 1.最高位为符号位，0表示正数，1为负数
 * 2.其他数值部分就是数值本身绝对值的二进制数
 * 3.负数的原码是在其绝对值的基础上，最高位变为1
 *
 * 反码
 * 1.正数的反码与原码相同
 * 2.对于负数，符号位不变，其他部分取反(0->1,1->0)
 *
 * 补码 (在计算机中数值一侓用补码存储)
 * 1。对于正数，原码，反码，补码相同
 * 2.负数，其补码为它的反码加1
 * 3.补码符号位不动，其他位求反，最后整个数加1，得到原码
 */

void binaryOutput() {
    //十进制数10
    int a = 10;
    printf("%d\n", a);
    //八进制
    int b = 010;
    printf("%o\n", b);
    //十六进制
    int c = 0X10;
    printf("%0x\n", c);

    printf("%d\n", b);
    printf("%d\n", c);
}

/**
 * 有符号
 * 一部分为符号位，一部分为数值位
 * 无符号
 * 全是数值位
 */
void testUnSinged() {
    int a = -1;
    printf(" unsinged %u", a);
    printf(" singed %d", a);
}

/**
 * 类型限定符
 */
void testTypeDef() {

    /**
     * 声明一个变量，extern声明的变量没有建立存储空间
     */
    extern int a;

    /**
     * 定义一个常量，常量的值不能修改，但可以能过指针修改，不安全的
     */
    const int b = 10;

    /**
     * 防止编译器优化
     */
    volatile int f;

    /**
     * 定义寄存器变量，提高效率，register是建议型指令，而不是命令型指令，
     * 如果CPU有空闲寄存器，那么register生效，如果没有空闲寄存器，那么register无效
     */
    register int d;


}

//------------------------------------------main-----------------------------------------------

#if 0

int main() {
//    testScanf();
//    testSizeof();
//    getCharPutChar();
//    testFileEof();
//    binaryOutput();
//    testUnSinged();
    return 0;
}

#endif



