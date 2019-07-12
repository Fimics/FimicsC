//
// Created by lipnegju on 2019-07-12.
//

/**
 * 1.const修饰全局变量放在常量区
 * 2.const修饰局部变量，放在栈上，不能直接修改值
 */

#if  1
struct Person{
    char name[64];
    int age;
    int id;
    double score;
};

/**
 * 规避地址传递地副作用(在使用对象指针 的情况下，有可能意外修改数据)
 * @param p
 */
void printObject(const struct Person *p){
    printf("name: %s age:%d id: %d score %f",p->name,p->age,p->id,p->score);
}

void testConst(){
 struct  Person p ={"Trump",30,333,99.9};
 printObject(&p);
}
#endif


void iConst(){
#if 1
    testConst();
#endif
}