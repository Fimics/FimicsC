//
// Created by lipnegju on 2019-06-28.
//
#include <stdio.h>
#include <string.h>

/**
 * 结构体定义
 * 结构休一般写在.h文件中
 */
struct student {
    char name[60];
    unsigned int age;
    char tel[16];
    float scores[3];
    char sex;
} stu={"河南省", 22, "13520591502",100,200,300,'M'};

void usingStruct() {

//    struct student 整个是结构体名称

    //1.按照结构体顺序赋值
//    struct student stu={"河南省", 22, "13520591502",100,200,300,'M'};
//      2.
//    struct student stu = {.sex='M', .name="长江", .tel="481209840129",.scores[0]=100,.scores[1]=200,.scores[2]=300,.age=33};

//    3.
//    struct student stu ;
//    strcpy(stu.name,"黄河");
//    stu.age=5000;
//    strcpy(stu.tel,"1398765456");
//    stu.scores[0]=99.3;
//    stu.scores[1]=88.5;
//    stu.scores[2]=77.9;
//    stu.sex='F';

//   4.定义结构体后加结构体变量
    strcpy(stu.name,"黄河");
    stu.age=5000;
    strcpy(stu.tel,"1398765456");
    stu.scores[0]=99.3;
    stu.scores[1]=88.5;
    stu.scores[2]=77.9;
    stu.sex='F';

    printf("name:%s\n", stu.name);
    printf("age:%d\n", stu.age);
    printf("tel:%s\n", stu.tel);
    printf("score1:%.1f   ,socre2:%.1f   ,score3:%.1f\n", stu.scores[0], stu.scores[1], stu.scores[2]);
    printf("sex:%s\n", stu.sex == 'M' ? "男" : "女");

}

void structDefine() {
    usingStruct();
}