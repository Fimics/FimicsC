//
// Created by lipnegju on 2019-06-28.
//

#ifndef FIMICSCPP_YCOMPLEX_H
#define FIMICSCPP_YCOMPLEX_H

/**
 * 结构休需要根据数据类型，进行内存对齐，
 * 定义结构体时，应该按照数据类型从大到小定义
 */
extern struct person {
    char name[20];
    unsigned int age;
    char tel[17];
    float scores[3];
    char sex;
};

void complex();
void structDefine();
void structMemory();
void structArray();
void structSort();
void structPointer();
void structFunction();
void structstruct();
void unionDemo();
void enumDemo();
void typedefDemo();
#endif //FIMICSCPP_YCOMPLEX_H
