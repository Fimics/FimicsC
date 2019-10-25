//
// Created by pengju.li on 2019-10-25.
//

#include <iostream>
using  namespace  std;

int abc(int a,int b,int c){
    return a+b*c;
}

template <class T>
T abc(T a, T b,T c){
    return a+b*c;
}


template <class T>
T abcR(T &a,T &b,T &c){
    return a+b*c;
}



int main(){
    int a =1;
    int b = 2;
    int c= 3;

    int & ar =a;
    int & br = b;
    int & cr = c;

    int result =abcR(ar,br,cr);
    cout<<"result-->"<<result<<endl;
    return 0;
}