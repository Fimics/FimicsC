//
// Created by pengju.li on 2019-10-29.
//

#include <iostream>
using  namespace std;

template <class T>
bool make2dArray(T ** &x,int rows,int columns){

    try{
        //创建行指针
        x = new T * [rows];
        //为每一行分配空间
        for (int i = 0; i <rows ; i++) {
            x[i]=new T(columns);
        }

        return true;
    }catch (bad_alloc){
        return false;
    }

}

//int main(){
//    int * y = new int(10);
//    delete []y;
//}