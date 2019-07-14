//
// Created by lipnegju on 2019-07-13.
//
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * 总结
 * 1.源代码的可读性几乎总是比程序运行时效率更为重要
 * 2.只要可能，函数的指针形参都应该申明为const
 * 3.在多维数组的初始列表中使用完整的多层花括号提供可读性
 * 4.在绝大多数表达式中，数组名的值是指向数组的第1个元素的指针，这个规则只有两个例外，sizeof 和对数组名&
 * 5.指针和数组并不相等，当我们申明一个数组的时候，同时也分配了内存空间，但申明指针的时候，只分配容纳指针本身的空间
 * 6.当数组名做为函数参数时，实际传递给函数的是一个指向数组第一个元素的指针
 * 7.我们不单可以创建指向普通变更的指针，也可以创建指向数组的指针
 */

#if 0
//----------------------结构体定义--------------------------
/**
 * 定义结构体类型不要直接给成员赋值，结构体只是一个类型，编译器还没有为其分配空间，
 * 只有根据其类型定义变量时，才分配空间，有空间后才能赋值
 */
typedef struct Person{
    char name[20];
    int age;
}MyPerson;

//typedef struct Person MyPerson;

struct Teacher{
    char name[64];
    int age;
}teacher;

void testTeacher(){
    strcpy(teacher.name,"Lily");
    teacher.age=30;

    printf("teacher name %s age %d\n",teacher.name,teacher.age);

    //在栈上分配结构体变量空间
    struct Teacher teacher1={"hanmeimei",30};
    //在堆上分配结构体变量空间
    struct Teacher *teacher2=malloc(sizeof(struct Teacher));
    strcpy(teacher2->name,"hello");
    teacher2->age=40;
    printf("teacher name %s age %d\n",teacher2->name,teacher2->age);
}

void printStructs(struct Teacher * t,int len){

    for (int i = 0; i <len ; ++i) {
        struct  Teacher teacher1 = t[i];
        printf("teacher name %s age %d\n",teacher1.name,teacher1.age);
    }
}

/**
 * 多个结构体变量
 */
void testMultiStruct(){

    //在栈上分配结构体数组空间
    struct Teacher teacher1[]={
            {"aa",10},
            {"bb",20},
            {"cc",30},
            {"dd",40},
            {"ee",50},
    };

    int len = sizeof(teacher1)/ sizeof(struct Teacher);
    printStructs(teacher1,len);


    //2.在堆上分配结构体数组空间
    struct Teacher * teacher2=malloc(sizeof(struct Teacher)*6);
    for (int i = 0; i <6 ; ++i) {
        sprintf(teacher2[i].name,"name_%d",i);
        teacher2[i].age=i;
    }

    printStructs(teacher2,6);


}

struct {
    char name[64];
    int age;
} dog;

void testDog(){
    strcpy(dog.name,"Lily");
    dog.age=30;

    printf("teacher name %s age %d\n",dog.name,dog.age);
}

struct {
    char name[64];
    int age;
} tiger={"tiger",22};

void testTiger(){

    printf("teacher name %s age %d\n",tiger.name,tiger.age);
}
#endif


#if 0
//----------------------结构体赋值注意点--------------------------
/**
* 1.如果结构体内部有指针并且指针指向堆空间，如果发生赋值行为 会产生两个致命问题
*   1.1 同一块空间会被释放两次，会crash
*   1.2 发生内存泄漏
*/
struct Teacher{
    char * name;
    int age;
};

//结构体拷贝
void testStructValue(){

    struct Teacher t1 = {"aaa",1};
    struct Teacher t2 ={"bbb",2};

    printf("t1 name %s age %d\n",t1.name,t1.age);
    printf("t2 name %s age %d\n",t2.name,t2.age);

    //结构体赋值，浅拷贝，拷贝的是引用(地址)
    struct Teacher t3 = t1;
    printf("t3 name %s age %d\n",t3.name,t3.age);

    //结构体赋值，浅拷贝，拷贝的是引用(地址)
    struct Teacher t4;
    t4.name=malloc(sizeof(char) * 128);
    memset(t4.name,0,128);
    strcpy(t4.name,"t4t4t4");
    t4.age=4;

    struct Teacher t5;
    t5.name=malloc(sizeof(char) * 128);
    memset(t5.name,0,128);
    strcpy(t5.name,"t5t5t5");
    t5.age=5;

    /**
     * 1.如果结构体内部有指针并且指针指向堆空间，如果发生赋值行为 会产生两个致命问题
     *   1.1 同一块空间会被释放两次，会crash
     *   1.2 发生内存泄漏
     * 2.如果结构体内部有指针指向堆空间，那么就不能使用编译器默认的赋值行为(t5=t4),应该手动控制赋值过程
     */
//    t5=t4;//发生错误
    if(t4.name!=NULL){
        free(t4.name);
        t4.name=NULL;
    }

    //深拷贝 不使用默认赋值
    t4.name=malloc(sizeof(t5.name)+1);
    strcpy(t4.name,t5.name);
    t4.age=t5.age;
    printf("t4 name %s age %d\n",t4.name,t4.age);
    printf("t5 name %s age %d\n",t5.name,t5.age);

    //释放堆空间
    if(t4.name!=NULL){
        free(t4.name);
        t4.name=NULL;
    }

    //释放堆空间
    if(t5.name!=NULL){
        free(t5.name);
        t5.name=NULL;
    }
}

#endif

#if 1
//----------------------结构体嵌套一级指针--------------------------
struct Teacher{
    char * name;
    int age;
};

struct Teacher** allocateSpace1(){
    struct  Teacher **t = malloc(sizeof(struct Teacher *)*3);
    for (int i = 0; i <3 ; ++i) {
        t[i]=malloc(sizeof(struct Teacher));
        t[i]->name=malloc(sizeof(char)*64);
        sprintf(t[i]->name,"name_%d",i);
        t[i]->age=i;
    }

    return t;
}

void printTeacher(struct Teacher ** t){
    int i=0;
    for (i = 0; i <3 ; ++i){
        printf("index %d name %s age %d\n",i,t[i]->name,t[i]->age);
    }
}

void freeTeacher(struct Teacher ** teacher){
    for (int i = 0; i < 3; ++i) {
        if(teacher[i]->name!=NULL){
            free(teacher[i]->name);
            teacher[i]->name=NULL;
        }
    }
}

void testStructPointer(){
    struct Tercher ** t = NULL;
    t = allocateSpace1();
    printTeacher(t);
   freeTeacher(t);

}
#endif

void iStruct(){
//testTeacher();
//testDog();
//testTiger();
//testMultiStruct();
//testStructValue();
testStructPointer();
}