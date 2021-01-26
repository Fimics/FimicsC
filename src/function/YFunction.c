//
// Created by pengju.li on 2019-06-11.
//

#include <stdio.h>


void andOperator() {
    int pooh = 24;
    printf("pooh & %ld \n", &pooh);
    printf("%d,%p\n", pooh, &pooh);

}

/**
 * c是值传递，只是把数传过来，每个C函数都有自己的变量
 * @param value
 */
void passValue(int value) {
    printf("before value is %d\n", value);
    printf("before valuee address %p\n", &value);
    value = value + 1;
    printf("after value is %d\n", value);
    printf("before valuee address %p\n", &value);
}

/**
 * 1.值传递：将实参变量的值复制一份交给形参，即，现在有两个空间，实参空间和形参空间，两空间独立。值传递基本类型的变量而言。
 * 2.引用传递：是对于对象型变量而言的，传递的是该变量的地址，不是对象本身
 * 3.执行exchange函数的时候，将实参a和b的值传递给了形参，就是，将a和b的值各复制一份赋值给形参a和形参b的空间，
 * 所以，函数内对形参空间的操作完全不会影响到实参空间！而伴随着函数调用的结束，形参空间和其内的局部变量将会被释放。
 * 4.C语言没有引用传递，看到很多博文都错把指针传递当做引用传递，只有C++中才存在引用传递
 * @param a
 * @param b
 */
void exchange(int a, int b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void testExchange() {
    int testValue = 1;
    printf("before testValue address %p\n", &testValue);
    passValue(testValue);
    printf("testValue is %d\n", testValue);
    printf("after testValue address %p\n", &testValue);
    printf("%s\n", "---------------------");
    int a = 5;
    int b = 8;
    exchange(a, b);
    printf("a = %d\n", a);
    printf("b = %d", b);
}

void interchange(int u, int v) {
    int temp;

    printf("interchange Originally u = %d and v = %d.\n", u, v);
    temp = u;
    u = v;
    v = temp;
    printf("interchange Now u = %d and v = %d.\n", u, v);
}

void testSwap() {

    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(x, y);
    printf("Now x = %d and y = %d.\n", x, y);
}

void testFunctionPointer() {
    int a = 2;
    int *p = &a;

    printf("p is %ld \n", p);
    printf("*p is %p \n", *p);
}

#if 0

int main() {
//    andOperator();
//    testExchange();
//    testSwap();
    testFunctionPointer();
}

#endif



