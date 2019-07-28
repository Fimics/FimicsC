//
// Created by lipnegju on 2019-07-28.
//
#include <cstdio>
#include <iostream>
#include "Array.h"
using namespace std;

MyArray::MyArray() {
   this->capacity=100;
   this->size=0;
   this->paddress= new int[this->capacity];
}

MyArray::MyArray(int capacity) {
     this->capacity=capacity;
     this->size=0;
     this->paddress=new int[this->capacity];
}

void MyArray::push(int value) {
    this->paddress[this->size]=value;
    this->size++;
}

int MyArray::get(int index) {
    return this->paddress[index];
}

void MyArray::update(int index, int value) {
    this->paddress[index]=value;
}

MyArray::MyArray(const MyArray &array) {
      this->paddress = new int[array.capacity];
      this->size=array.size;
      this->capacity=array.capacity;

    for (int i = 0; i <array.size ; ++i) {
        paddress[i]=array.paddress[i];
    }
}

MyArray::~MyArray() {
    if(this!=NULL){
        cout<<"destroy";
        delete [] this->paddress;
        this->paddress=NULL;
    }
}

void farray(){
    //堆区创建
    MyArray * array = new MyArray(30);

    for (int i = 0; i <10 ; ++i) {
        array->push(i);
    }

    for (int j = 0; j <10 ; ++j) {
        cout<<array->get(j);
    }

   delete [] array;
}