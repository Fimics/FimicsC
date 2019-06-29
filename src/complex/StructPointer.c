//
// Created by lipnegju on 2019-06-29.
//

#include <stddef.h>
#include <stdio.h>

/**
 * 结构体成员为指针
 */
struct stuinfo {
    char *name;
    int age;
} stu;

struct stu2
{
    //成员列表
    //char name[21];
    char * name;
    float * scores;
};

void structArray1(){
    struct stu2 *p = (struct stu2 *)malloc(sizeof(struct stu2) * 3);
    for (int i = 0; i < 3; i++)
    {
        p[i].name = (char *)malloc(sizeof(char) * 21);
        p[i].scores = (float *)malloc(sizeof(float) * 3);
        //(p+i)->name

        printf("请您输入学生 姓名   成绩 ：\n");
        scanf("%s%f%f%f", p[i].name, &p[i].scores[0], &p[i].scores[1], &p[i].scores[2]);

    }

    //冒泡排序
    for (int i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            float sum1 = p[j].scores[0] + p[j].scores[1] + p[j].scores[2];
            float sum2 = p[j + 1].scores[0] + p[j + 1].scores[1] + p[j + 1].scores[2];
            if (sum1 > sum2)
            {
                struct stu2 temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < 3; i++)
    {

        printf("姓名：%s\n", p[i].name);
        printf("成绩: %.1f   %.1f   %.1f\n", p[i].scores[0], p[i].scores[1], p[i].scores[2]);
    }


    //释放
    for (int i = 0; i < 3; i++)
    {
        free(p[i].name);
        free(p[i].scores);
    }

    free(p);


}

void structPointer() {

//    struct  stuinfo si;------------
//    si.name=malloc(sizeof(char)*21);
//    strcpy(si.name,"hello");
//    si.age=20;
//
//    printf("name :%s\n",si.name);
//    printf("age :%d\n",si.age);
//
//    free(si.name);

    //结构体变量-----------------------------
//    struct stuinfo stu1;
    //结构体指针指向结构体变量
//    struct  stuinfo * s = &stu1;
//    s->name =malloc(sizeof(char)*20);
//    strcpy(s->name,"world");
//    s->age=33;
//    printf("s->name :%s\n",s->name);
//    printf("s->age :%d\n",s->age);
//
//    free(s->name);

    struct stuinfo *p = malloc(sizeof(struct stuinfo));
    p->name = malloc(sizeof(char) * 20);
    strcpy(p->name, "hello");
    p->age = 44;
    printf("s->name :%s\n", p->name);
    printf("s->age :%d\n", p->age);

    if (p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }

    if (p) {
        free(p);
        p = NULL;
    }


}