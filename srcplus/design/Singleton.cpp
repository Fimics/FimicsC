//
// Created by lipnegju on 2019-07-27.
//

#include <iostream>
#include <gtest/gtest.h>
using namespace std;


//----------------------------单列模式------------------------------------

class UserManager {

public:

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        UserManager::age = age;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        UserManager::name = name;
    }

    static UserManager *getInstance() {
        return instance;
    }


private:
    int age;
    string name;

    UserManager() {}

    //拷贝构造函数私有化
    UserManager(const UserManager & userManager){}

    static UserManager *instance;

};

UserManager *UserManager::instance = new UserManager;


TEST(单列,testUserManager) {
    cout<<"单列"<<"\n";
    UserManager *u1 = UserManager::getInstance();
    u1->setAge(20);
    u1->setName("lishi");
    cout << "name = " << u1->getName() << " age = " << u1->getAge()<<"\n";
    UserManager * u2 = UserManager::getInstance();
    if(u2==u1){
        cout<<"u2 == u1\n";
    }
    //拷贝构造
//    UserManager *u3= new UserManager(*u2);
//
//    if(u2==u3){
//       cout<<"u2==u3"<<"\n";
//    }
}
