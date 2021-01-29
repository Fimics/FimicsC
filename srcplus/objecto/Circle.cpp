//
// Created by lipnegju on 2019-07-24.
//

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

const double pi = 3.14;

class Circle {

public: //公共权限
    double radius;

    void setRadius(double radius) {
        Circle::radius = radius;
    }

    double getArea() {
        double area = radius * radius * pi;
        return area;
    }
};

TEST(public,private){
    Circle circle;
    circle.setRadius(20);
    double area = circle.getArea();
    cout << "ares is " << area;
}
