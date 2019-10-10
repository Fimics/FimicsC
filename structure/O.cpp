//
// Created by lipengju on 2019-10-09.
//

#include <iostream>
using namespace std;

/**
 * 1.时间复杂度
 *
 * 2.空间复杂度
 */

//O(n+2)
int sum1(int n){
    int sum =0; // 1 step
    for (int i = 0; i <=n; ++i) {
        sum+=i; //n step
    }
    return sum; //1 step
}

//O(1)
int sum2(int n){
    return n*(n+1)/2;//1 step
}

int main(){

    int sum11 = sum1(100);
    int sum22 = sum2(100);
    cout<<"sum11="<<sum11<<" sum22="<<sum22<<endl;
}