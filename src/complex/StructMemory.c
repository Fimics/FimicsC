//
// Created by lipnegju on 2019-06-28.
//
#include <stdio.h>
#include <string.h>
#include "YComplex.h"


void structMem() {

    struct person stu = {"河南省", 22, "13520591502", 100, 200, 300, 'M'};

    printf("name:%s\n", stu.name);
    printf("age:%d\n", stu.age);
    printf("tel:%s\n", stu.tel);
    printf("score1:%.1f   ,socre2:%.1f   ,score3:%.1f\n", stu.scores[0], stu.scores[1], stu.scores[2]);
    printf("sex:%s\n", stu.sex == 'M' ? "男" : "女");
    printf("stu sizeof %d\n", sizeof(stu));
    printf("person size %d\n", sizeof(struct person));

    printf("char size %d\n", sizeof(char));
    printf("unsigned int size %d\n", sizeof(unsigned int));
    printf("float size %d\n", sizeof(float));

}

#if 0

int main() {
    structMem();
}

#endif