//
// Created by lipnegju on 2019-07-06.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "YImprove.h"


#if 0
//----------------------------typedef------------------------------
struct Person {
    char name[20];
    int age;
};
typedef struct Person MyPerson;

//上面的简写
typedef struct Person{
    char name[20];
    int age;
}MyPerson;


typedef char * PCHAR;
typedef long long xll; //平台兼容时，统一定义一个方便修改

void testTypeDef(){
    struct Person person;//不想写这么长，可以使用typedef
    MyPerson pp;//

    //char * p1,p2;// p1的类型是char *  ,p2的的类型是char ,如果想让p1,p2的数据类型都是char * 可以使用typedef定义
    PCHAR p1,p2;
}
#endif

#if 0
//---------------------------void 数学类型------------------------------------
/*
void字面意思是"无类型"，void * 无类型指针，无类型指针可以指向任何类型的数据
void定义变量是没有任何意义的，当你定义void a，编辑器会报错
void 真正用在以下两个方面
     1.对函数返回值的限定
     2.对函数参数的限定
*/

//1.void 不能直接定义变量，因为编译器不知道分配多少内存给变量
//2. 当定义一个变量时，编译器必须要知道分配多少内存
struct Dog{
    char name[20];
    int age;
    struct Dog d;//error
};
#endif

#if 0
//-----------------------void 数学类型------------------------------------
/*
基本用法
sizeof(变量)
size 变量
sizeof(类型)
sizeof注意点
   1.sizeof返回的战胜空间大小是这这个变量开辟的大小，而不是它们用到的空间，所以
     对结构体用的时候，大多数情况下就得考虑字节对齐的问题了
   2.sizeof返回的数据结果类型是unsigned int;
   3.要注意数组名和指针变量的区别，通常情况下，我们总觉得数组名和指针变量差不多
   */

#pragma pack(1)//对齐模式影响分配内存空间大小
struct Person {
    char a;
    int b;
};

void testSizeof() {
    printf("int sizeof %ld\n", sizeof(int));
    printf("double sizeof %ld\n", sizeof(double));
    printf("person sizeof %ld\n", sizeof(struct Person));

    unsigned int a = 20;
    if (a - 20 > 0){
        printf("%s\n", "a-20>0");
    }
    else{
        printf("%s\n", "a-20<0");
    }
}

//sizeof计算数组大小
//数组作为函数参数会退化为指向数组首元素的指针
int caculateArraySize(int arr []){ //（int * arr）
    return sizeof(arr);
}

void sizeofArray(){
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    printf("sizeof arr:%d\n", sizeof(arr));
    printf("sizeof arr as params:%d\n", caculateArraySize(arr));
}

#endif

#if 0

//-----------------------变量间接赋值------------------------------------
//指针p的类型大小为n，加p+1=?
struct Person{
    char a;
    int b;
    char c;
    int d;
};
void testValue() {
    int a=10;
    a=100;

    int *p = &a;//间接赋值

    struct Person person ={'a',100,'b',200};
    printf("d value%d\n",person.d);

    person.d=1000;

    printf("%ld\n",(char*)&person+12);
    printf("%ld\n",&(person.d));
    printf("%ld\n",* (int *)((char*)&person+12));//间接取值

}
#endif

#if 0
//-----------------------内存分区------------------------------------

/**
 *内存分区
 *1.运行之前
 *    1.1预处理:宏定义展开，头文件展开，条件编译，这里并不会检查语法
 *    1.2编译  :检查语法，把预处理后的文件编译成汇编文件
 *    1.3汇编  :把汇编文件生成目录文件(二进制文件)
 *    1.4链接  :把目录文件链接为可执行文件
 *
 *2.
 *
 */

void testMemoryArea(){

}

#endif


#if 0
//-----------------------栈区分区------------------------------------
/**
 * 栈区的内存自动申请自动释放，不需要手动管理
 */

int * myFunc(){
    int a=10;
    return &a; //不要返回局部变量的地址
}

char * getString(){
    char str[]="hello world";
    return str;
}

void testStackArea() {
    //我们并不关心值是多少了，因为a是局部变量内在已经被回收，不要返回局部变量的地址
   int *p = myFunc();
//   printf("*p %d\n",*p);
   char *s =getString();//
   printf("%s\n",*s);
}
#endif

#if 0
//-----------------------堆区分区------------------------------------

int * getSpace(){
    int * p = malloc(sizeof(int)*5);
    if(NULL==p){
        return NULL;
    }

    p[0]=100;//只要是连续的内存的空间，都可以用下标赋值
    //++i ，比i++效率高？因为多一个临时变量？优先使用++i

    for (int i = 0; i <5 ; i++) {
        p[i]=100+i;
    }

    return p;
}

/**
 * 定义变量一定要初始化，很多bug产生都是由于没有初始化变量
 * @param p
 */
void allocateSpace(char *p){
    p = malloc(100);
    memset(p,0,100);
    strcpy(p,"hello world");
    //没释放会内存泄漏

}

void allocateSpace1(char **p){
    char *temp = malloc(100);
    memset(temp,0,100);
    strcpy(temp,"hello world");
    *p = temp;

}

void testHeapArea(){

    int * result = getSpace();

    for (int i = 0; i < 5; ++i) {
        printf(" index :%d value %d\n",i,*result+i);
    }

    //用完堆内存一定要释放
    if(result){
        free(result);
        result=NULL;
    }



//    char *p =NULL;
//    allocateSpace(p);
//    printf("%s\n",p);

    char *q =NULL;
    allocateSpace1(&q);//取地址相当于升一级指针
    printf("%s\n",q);
}
#endif

#if 0
//-----------------------全局变量，局部变量，static,extern------------------------

int a=10;//合局区 相当于 extern int a=10 外部链接 c语言默认省略extern关键字
//内部链接
static int b=20;//静态区

/**
 * 1.全局静态变量和局部静态变量都存储在表态区，都是程序运行期间都是合法在效的
 * 2.局部静态变量的可见范围只限于当前函数内部，全局静态变量可见范围从定义到文件结尾
 * 3.外部链接和内部链接的区别
 *    3.1内部链接只能在当前文件内使用
 *    3.2外部链接可以在其他文件使用
 *    3.3.h文件是不用编译的，一个.c文件叫做一个编译单元
 *
 * 4.头文件里只放声明，不要放定义
 */
void testStatic(){
    static int c=30;//静态区
    /**
     * 在其他文件使用全局变量，得先声明,表示告诉编译器这个特号是存在的
     * ，你让我先编译通过，让连接器去找到这个符号在哪
     */
    extern int global;
    int a = global;

    printf("global %d\n",a);

}

#endif

#if 0
//-----------------------const 常量区------------------------

/**
 * 1.全局const变量 在堆上，直接或间接不能修改
 * 2.局部const在栈上，可以修改
 */
const  int a =20;

void testConstGlobal(){
//    a=300; 不能直接修改
     const int b =200;

     int *p =(int *)&a;
     //不能间接修改
     *p =30;
     printf("%d\n",*p);

}

void testConstLocal(){

    const int cc=200;
//    a=200;不能直接修改
    int *p = (int *)&cc;
    *p = 300;
    printf(" %d\n",cc);
}
#endif

#if 1
//-------------------------字符串常量------------------------

void stringConst(){
    char  *p ="hello world";
    printf("%d\n",&"hello world");
    printf("%d\n",p);
}

#endif

void datatype() {

#if 0
    testSizeof();
    sizeofArray();
    testValue();
    testMemoryArea();
    testStackArea();
    testHeapArea();
    testStatic();
    testConstGlobal();
     testConstLocal();
#endif

   stringConst();

}
