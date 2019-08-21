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

void funTemplate(){
//     testSwapInt();
//testMySwap();
 testArraySort();
}