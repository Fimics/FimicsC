//
// Created by pengju.li on 2019-06-11.
//

#include <stdio.h>
#include <string.h>
#include <limits.h>    // integer limits
#include <float.h>
#include <memory.h>

#define DENSITY 62.4;
#define PI 3.1415926 //预处理，编译时全局替换

const int MONTHS =12; //只读变量

void stringLen(){
    float weight, volume;
    int size, letters;
    char name[40];        // name is an array of 40 chars

    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n",
           name, volume);
    printf("Also, your first name has %d letters,\n",
           letters);
    printf("and we have %d bytes to store it.\n", size);
}

void stringLenVsSizeof(){
    char names [30] ={'a','b','c'};

    scanf("%s",names);

    printf("stringLen ...%d\n",strlen(names));
    printf("sizeof ...%d\n", sizeof names);
}

void testDefine(){
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI *radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum,
           area);
}

void testDefine2(){
    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
}

void testConst(){
    printf("months %d\n",MONTHS);
}

void testString(){
    //stringLen();
    //stringLenVsSizeof();
    //testDefine();
//    testConst();
//      testDefine2();
}
