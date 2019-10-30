//
// Created by pengju.li on 2019-10-30.
//
#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

class illegalParameterValue {
public:
    illegalParameterValue(string theMessage = "Illegal parameter value") {
        message = theMessage;
    }

    void outputMessage() { cout << message << endl; }

private:
    string message;
};

class illegalIndex {
public:
    illegalIndex(string theMessage = "Illegal index") //初始化
    {
        message = theMessage;
    }

    void outputMessage() { cout << message << endl; }

private:
    string message;

};

