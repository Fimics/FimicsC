//
// Created by lipnegju on 2019-07-27.
//

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

//-------------------------友元----------------------------
class Building {

    /**
     * 友元函数的目的是访问类中的私有成员
     * @param building
     */
    friend void goodFriend(Building *building);

    Building() {
        this->name = "friend";
        this->money = 2000;
    }

public:
    string name;
private:
    int money;
};


void goodFriend(Building *building) {
    cout << building->name << building << building->money;
}

//--------------------------整个类做友元-----------------------------
class Student;

//studnet
class Student {
public:

    /**
     * 整个类作为友元类
     * 友元是单向的，友元关系没有传递性
     */
    friend class Teacher;

    Student() {}

public:
    int age;
private:
    int money;

};

class Teacher {
public:
    Teacher();

    void song();

private:
    Student *studnet;
};


Teacher::Teacher() {
    studnet = new Student;
}

void Teacher::song() {
    cout<<"友元函数的目的是访问类中的私有成员"<<"\n";
    cout << "teacher song\n";
    cout << "studnet age" << this->studnet->age << "\nstudent money" << studnet->money << "\n";

}

TEST(友元,testFriendClass) {
    Teacher teacher;
    teacher.song();
}
