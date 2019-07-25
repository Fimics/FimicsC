//
// Created by lipnegju on 2019-07-25.
//

//c++封装 与类成员权限

#include <iostream>
#include "Packing.h"
using namespace std;

/**
 * 1.c++ 的属性与行为绑定到一起
 * 2.严格的类型检查
 * 3.控制权限
 *   public
 *   protected
 *   private
 *
 */

struct Person{
    char * name;
    int age;
    void eat(){

    }
};


void testEat(){
    Person p1;

}

/**
 * struct与class的一个意思，但struct的默认权限是public ,class的默认权限是private
 */
class Animal{
    //如果不声明权限默认是private的
    void eat();//private 在类内部可以访问，类外部不能访问
public:
    void running(){};//public 可以在任何地方访问
protected:
    void sleep(){}; //在子类与当前类可以访问

private:
    int age;
};

class Cube{

public:
    int getW() const {
        return w;
    }

    void setW(int w) {
        Cube::w = w;
    }

    int getH() const {
        return h;
    }

    void setH(int h) {
        Cube::h = h;
    }

    int getL() const {
        return l;
    }

    void setL(int l) {
        Cube::l = l;
    }

    int getS(){
        return 2*(w*h+w*l+h*l);
    }

    int getV(){
        return w*l*h;
    }

    bool isEqual(Cube cube){
        if(getV()==cube.getV()){
            return true;
        }

        return false;
    }

private:
    int w;
    int h;
    int l;
};

/**
 * global
 * @param c1
 * @param c2
 * @return
 */
bool isEqueal(Cube &c1, Cube &c2){
    if(c1.getL()==c2.getL()) return true;
    return false;
}

void packing(){

    Cube cube;
    cube.setH(10);
    cube.setL(10);
    cube.setW(10);

    int s = cube.getS();
    int v = cube.getV();

    cout<<"s="<<s<<" v= "<<v<<"\n";

    Cube cube1;
    cube1.setH(10);
    cube1.setL(10);
    cube1.setW(10);
    bool isGlobalEqual = isEqueal(cube,cube1);
    bool isMemberEqual = cube.isEqual(cube1);

    cout<<"isGlobalEqual ="<<isGlobalEqual<<" isMemberEqual = "<<isMemberEqual<<"\n";


}