//
// Created by lipengju on 2019-10-17.
//

#include <iostream>
#include <cmath> //use pow
#include <ctime>

using namespace std;

/**
 * 写一个算法求下面序列之和
 * -1,1,-1,1,...,(-1)N次幂
 */

const int n = 2e6;

int sum1(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(-1, i);
    }
    return sum;
}

int sum2(int n) {
    return (n % 2 == 0 ? 0 : 1);
}


//int main() {
//    time_t startTime, endTime, sumTime;
//    startTime=clock();
////    cout << "sum1Result-->:" << sum2(n) << endl;
//    cout << "sum1Result-->:" << sum2(n) << endl;
//    endTime=clock();
//    sumTime = endTime-startTime;
//    cout << "sumTime-->:" << sumTime << endl;
//}