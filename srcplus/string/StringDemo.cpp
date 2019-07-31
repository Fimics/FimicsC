//
// Created by pengju.li on 2019-07-31.
//

#include <iostream>
#include <string>

using namespace std;

void testInput() {
#if 0
    //   char name[20]={0} ;

    //    char *name = (char *)malloc(sizeof(char)*20);//需要手动释放内存
       char * name = new char[sizeof(char)*20];//不需要手动释放内存
       cin>>name;
       cout<<"name = "<<name;

#endif
    char *text = (char *) malloc(sizeof(char) * 20);
//   cin.getline(text,20);
//    cin.get(text,20);
//    cin.get(text,20).get();
    cout << text;

}

void testString(){
      string name="jack";
      string date="2000-1-1";
      string age="20";
      string address ={"beijing"};
      string content = name+date+age+address;
      cout<<"name ="<<name<<"\ndate = n"+date<<"\nage ="+age<<"\naddress= "<<address<<endl;
      cout<<"\ncontent ="<<content<<"content size "<<content.size();
}


void stringDemo() {
#if 0
    testInput();
#endif
    testString();
}