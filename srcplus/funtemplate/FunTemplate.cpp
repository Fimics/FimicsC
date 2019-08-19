//
// Created by lipengju on 2019-08-18.
//

#include <iostream>
using namespace std;

/**
 * 函数模板->泛型
 */


void swapInt(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
}

void swapDouble(double &a, double&b);

void testSwapInt(){
    int a=10;
    int b =20;
    swapInt(a,b);
    cout<<"a= "<<a<<"  b= "<<b<<endl;
}


/**
 * 类型参数化，泛型-模板
 * 1.告诉编译器，下面如果出现T不要报错，T是一个能用类型
 * @tparam T
 */
template <class T>


void mySwap(T &a,T &b){
    T tmp = a;
    a = b;
    b=tmp;
}

template <typename T>
void mySwap2(){};

void testMySwap(){
    int a = 10;
    int b = 20;
    char c='c';
    //自动类型推倒
    mySwap(a,b);
//    mySwap(a,c); 推倒不出类型，所以报错不能运行

    //显式指定类型
    mySwap<int>(a,b);

    //模板必须指定出T才能使用
//    mySwap2(); 不能运行
    cout<<"a= "<< a<<" b= "<<b<<endl;
}

//----------------------------通用数组排序------------------------------------

/**
 * 从大到小，选择排序
 */

template <class T>
void tSwap(T &a,T &b){
    T tmp =a;
    a=b;
    b=tmp;
}

template <class T>
void arraySort(T arr[],int len){
    for (int i = 0; i <len ; i++) {
        int max =i;

        for (int j = i+1; j <len ; j++) {
            if(arr[max]<arr[j]){
                //交换下标
                max=j;
            }
        }

        if(max!=i){
            //交换数据
            tSwap(arr[max],arr[i]);
        }
    }
}

template <class T>
void printArr(T arr[],int len){
    for (int i = 0; i < len; ++i) {
        cout<<arr[i]<<endl;
    }
}

void testArraySort(){
   int arr []={4,9,1,3,6,8,0};
   int len = sizeof(arr)/ sizeof(int);
   arraySort(arr,len);
   printArr(arr,len);
}

//---------------------------函数模板与普通函数的区别以及调用规则-----------------------------------
/**
 *
 * 类型转换
 * 1.普通函数可以进行隐式类型转换
 * 2.函数模板不能进行隐式类型转换
 *
 * 调用规则
 * 1.如果出现了重载，优先使用普通函数
 * 2.如果想强制调用模板函数，可以使用空参数列表 myPrint<>(a,b);
 * 3.如果函数模板可以产生更好的匹配，优先调用函数模板，
 */

template <typename T>
T myPlus(T a,T b){
    return a+b;
}

int myPlus2(int a,int b){
    return a+b;
}

void testMyPlus(){
    int a=10;
    int b=10;
    int c='c';

    int r1 = myPlus(a,b);
    int r2 = myPlus2(a,c);

    cout<<"r1 "<<r1<<" r2 :"<<r2<<endl;
}

//-----------------------------模板机制-------------------------------

/**
 * 模板机制
 * 1.编译器并不是把函数模板处理成能够处理任何类型的函数(函数模板不是万能的)
 * 2.函数模板通过具体类型产生的函数叫模板函数
 * 3.编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译
 */

//------------------------------函数模板的局限性，模板的具体化-------------------------------------

void funTemplate(){
//     testSwapInt();
//testMySwap();
// testArraySort();
testMyPlus();
}