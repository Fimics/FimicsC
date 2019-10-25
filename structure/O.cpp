//
// Created by lipengju on 2019-10-09.
//

#include <iostream>
#include <string>

using namespace std;

/**
 * 1.时间复杂度
 *
 * 2.空间复杂度
 */

//O(n)时间复杂度
int sum1(int n) {
    int sum = 0; // 1 step
    for (int i = 0; i <= n; ++i) {
        sum += i; //n step
    }
    return sum; //1 step
}

//O(1)时间复杂度
int sum2(int n) {
    return n * (n + 1) / 2;//1 step
}

//空间复杂度，反转一个字符串 aaa222bbb->bbb222aaa

char *reverseStr1(char *str, int n) {
    char *res = (char *) malloc(sizeof(char) * n);//空间O(n)
    for (int i = 0; i <= n; i++) {//时间O(n)
        res[i] = str[n - i - 1];// why -1? '\0'
    }
    return res;
}

void reverse2(string str, int len) {//空间O(1)
    int mid = len / 2;
    int i = 0;
    while (i < mid) {//时间O(n/2)->O(n)

    }

}

//int main() {
////
////    int sum11 = sum1(100);
////    int sum22 = sum2(100);
////    cout<<"sum11="<<sum11<<" sum22="<<sum22<<endl;
//
//    char *str = "aaa222bbb";
//    int len = strlen(str);
////     char * reverse = reverseStr1(str,len);
////     cout<<"reverse1 = "<<reverse<<endl;
//
//    string string1 = "aaa222bbb";
//    reverse2(string1, len - 1);
//    cout << "reverse2 =" << str << endl;
//
//}