//
// Created by lipnegju on 2019-06-29.
//

#include <stdio.h>
#include <string.h>

struct info {
    char name[20];
    int age;
};

void printInfo(struct info in) {
    strcpy(in.name, "李四");
    in.age = 30;
    printf("name :%s, age :%d\n", in.name, in.age);
}

void printInfo1(struct info *in) {
    strcpy(in->name, "王五");
    in->age = 300;
    printf("name :%s, age :%d\n", in->name, in->age);
}

struct info printInfo2() {

    struct info i = {"张三", 199};
    return i;

}

struct info * returnStruct()
{
    struct info s;
    strcpy(s.name, "李四");
    s.age = 20;

    return &s;
}

void structFunction() {

//    struct info i = {"张三", 19};
    //printInfo(i);
//    printInfo1(&i);


//    struct info i= printInfo2();
    struct info * s = returnStruct();
    printf("%s   %d\n", s->name, s->age);
}