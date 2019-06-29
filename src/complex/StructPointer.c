//
// Created by lipnegju on 2019-06-29.
//

/**
 * 结构体成员为指针
 */
struct stuinfo{
    char * name;
    int age;
}stu;

void structPointer(){

//    struct  stuinfo si;
//    si.name=malloc(sizeof(char)*21);
//    strcpy(si.name,"hello");
//    si.age=20;
//
//    printf("name :%s\n",si.name);
//    printf("age :%d\n",si.age);
//
//    free(si.name);

    //结构体变量
    struct stuinfo stu1;
    //结构体指针指向结构体变量
    struct  stuinfo * s = &stu1;
    s->name =malloc(sizeof(char)*20);
    strcpy(s->name,"world");
    s->age=33;
    printf("s->name :%s\n",s->name);
    printf("s->age :%d\n",s->age);

    free(s->name);

}