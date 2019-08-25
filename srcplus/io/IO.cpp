//
// Created by lipengju on 2019-08-25.
//
#include <iostream>
using namespace std;

void io(){
//  cout<<cin.get(); 一次只能读到一个字符

//
//    char buf[1024]; //读取一个字符串
//    cin.get(buf,1024);
//    cout<<"buf="<<buf<<endl;

//      char buf[1024]; //读取行
//      cin.getline(buf,1024);
//      cout<<"getline="<<buf<<endl;

//       cin.ignore(2);//忽略几个字符
//       char c =cin.get();
//       cout<<c<<endl;

//         char c =cin.peek(); //看一下，缓存区的数据不会改变
//         cout<<c<<endl;
//         char e = cin.peek();
//         cout<<e<<endl;

//           char c = cin.get();
//           cin.putback(c);//放回去
//           char buf[1024];
//           cin.get(buf,1024);
//           cout<<"buf="<<buf<<endl;


        /**
         * cout.put 向缓存区写字符
         * cout.write() 从 buffer中写num个字符到当前输出流中
         */

//         cout.put('a');
           char buf []={'1','2','3'};
           cout.write(buf,2);

}