//
// Created by lipnegju on 2019-06-11.
//

#include <stdio.h>
#include <stdint.h> //可移植数据类型
#include <inttypes.h>


void testScanf() {

    float weight;
    float value;

    printf("Are you worth you weight in platinum?\n");
    printf("Let's check ot out .\n");
    printf("Pleease enter u weight in pounds:");

    scanf("%f",&weight);
    value = 17000.0*weight*14.5833;

    printf("Your weight in platinum is worth $%.2f.\n",value);

}

void  testSizeof(){
    int a; // int ->long int ->unsigned long ->long long
    long b;
    short c;
    unsigned d;
    char e;
    float f;
    double h;
    signed j;
    _Bool  k;
    _Complex l;
    long int li;
    long long int lli;

    unsigned int w;
    signed  int q;

    printf("int sizeof %d \n", sizeof(a));
    printf("int sizeof %d \n", a);
    printf("long sizeof %l \n", sizeof(b));
    printf("short sizeof %d \n", sizeof(c));
    printf("unsigned sizeof %d \n", sizeof(d));
    printf("char sizeof %d \n" , sizeof(e));
    printf("float sizeof %d \n", sizeof(f));
    printf("double sizeof %d \n", sizeof(h));
    printf("signed sizeof %d \n", sizeof(j));
    printf("_Bool sizeof %d \n", sizeof(k));
    printf("_Complex sizeof %d \n", sizeof(l));
    printf("long int sizeof %d \n", sizeof(li));
    printf("long long int sizeof %d \n", sizeof(lli));
    printf("unsigned int sizeof %d \n", sizeof(w));
    printf("signed  int sizeof %d \n", sizeof(q));

    char  cc ='A';
    printf("cc is %d",cc);

   // _Bool 1;

    int32_t  i32t; //32位有符号整数类型
    int_fast8_t intFast8;
    int_least8_t intLeast8;


}

void testDataType() {
    //testScanf();
    testSizeof();
}



