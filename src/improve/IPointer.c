//
// Created by lipnegju on 2019-07-09.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * 书<<c与指针>>
 * 1.指针不管什么类型，几级指针，都占用4/8个字节
 * 2.指针降级
 *   int a=10; int *p = &a; *p = int (8)
 * 3.什么情况后产生野指针？
 *   3.1指针变量未初始化
 *   3.2指针释放后未置空
 *   3.3指针操作超出变量作用域，不要返回指向栈内存的指针或引用，因为栈内存在还书结束时会被释放
 * 4.
 */




//------------------------指针步长----------------------------
/**
 * 1.指针变量加1时，指针向后跳多少个字节,步长由指针类型决定
 * 2.指针类型，不但可以决定指针的步长，还决定解引用时从给定地址开始取类型大小的字节
 * 3.指针发生类型转换后，指针步长就变了
 */

struct Person{
    int a;
    int b;
    char buf[64];
    int d;
};

void testStepSize(){

    char * p =NULL;
    printf("sizeof p %d\n", sizeof(p));
    printf(" p %d\n",p);
    printf( "p+1  %d\n",p+1);

    int *q = NULL;
    printf("siizeof q %d\n", sizeof(q));
    printf(" q %d\n",q);
    printf( "q+1  %d\n",q+1);

    char buf [1024]={0};
    int a=100;
    memcpy(buf+1,&a, sizeof(int));

    char *b =buf;
    printf("b %d\n",*(int *)(b+1));


    struct Person person = {10,'a',"hello world",5};
    printf("a offset b %d\n",offsetof(struct Person,b));//从struct首地址到b的地址偏移量
    //TODO 下面这行怎么理解？？？
    printf("d %d\n", *(int *) ((char *)&person+offsetof(struct Person,d)));


}



//------------------------指针间接赋值----------------------------
void changeValuei(int *p){
    *p =100;
}

void test1i(){
    int a =10;
    changeValuei(&a);
    printf("a %d",a);

    printf("&a %ld",&a);
    //140732735154716

//    int * p =140732735154716;//这种方式也可以取到正确的值
//    *(int *)p=200;
//    printf("a %d",a);

}
void changePointeri(int ** val){
    *val=(int *)0x008;//函数参数一定要对等
}

void test2i(){
    int * p =NULL;
    changePointeri(&p);
}



//------------------------指针做函数参数的输入输出特性----------------------------

/**
 * 指针输入特性->主调函数分配内存，被调函数使用内存
 *
 */
void inputPointeri( char * str){
    printf("%s\n",str+2);
}

void printArrayi(int * arr,int len){
    for (int i = 0; i <len ; i++) {
        printf("index %d, value %d \n",i,*(arr+i));
    }
}

void printCharArrayi(char ** arr,int len){
    //    arr[0]=char * 类型
    for (int i = 0; i <len ; i++) {
        printf("index %d, value %s \n",i,arr[i]);
    }
}

void testInputi(){
    //堆上分配内存
    char *s = malloc(sizeof(char)*100);
    memset(s,0,100);
    strcpy(s,"hello world");
    inputPointeri(s);

    //数组名作函数参数就会退化为指向数组首元素的指针
    int  arr []={1,2,3,4,5,6};
    int arrlen = sizeof(arr)/ sizeof(arr[0]);
    printArrayi(arr,arrlen);

    //栈上分配
    char * strs[]={
            "aaa",
            "bbbb"
            "ccc",
            "ddd",
            "eee"
    };

    int len = sizeof(strs)/ sizeof(strs[0]);
    printCharArrayi(strs,len);

}

/**
 * 输出特性，被调函数分配内存，主调函数使用内存
 */
void outputPointeri(char ** temp){
   char *p=malloc(100);
   memset(p,0,100);
   strcpy(p,"hello world");
   //指针间接赋值
   *temp = p;
}

void testOutputi(){
    char *p =NULL;
    outputPointeri(&p);
    printf("p=%s\n",p);
};



#if 1
//------------------------指针易错点----------------------------

/**
 * 1.指针越界
 * 2.指针叠加会改变指针的指向
 * 3.返回局部变量地址
 * 4.同一块内存多次释放
 */
void errorPointer() {

    char buf1[3] = "hello";
    printf("%s\n", buf1);


}

#endif

#if 0

int main(){

    testStepSize();
//     test1i();
//     testInputi();
//     testOutputi();
//     errorPointer();
}

#endif