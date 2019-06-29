#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu1 {
    //成员列表
    //char name[21];
    char *name;
    float scores[3];
};

void structSort() {
    struct stu1 s[3];
    //struct stu1 *s = malloc(sizeof(struct stu1) * 3);
    for (int i = 0; i < 3; i++) {
        //开辟堆空间
        s[i].name = (char *) malloc(sizeof(char) * 21);
        printf("请您输入学生 姓名   成绩 ：\n");
        scanf("%s%f%f%f", s[i].name, &s[i].scores[0], &s[i].scores[1], &s[i].scores[2]);
    }
    //冒泡排序
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {

            int sum1 = s[j].scores[0] + s[j].scores[1] + s[j].scores[2];
            int sum2 = s[j + 1].scores[0] + s[j + 1].scores[1] + s[j + 1].scores[2];
            if (sum1 > sum2) {
                //结构体交换   交换所有成员列表中的数据
                ////交换姓名
                //char temp[21] = { 0 };
                //strcpy(temp, s[j].name);
                //strcpy(s[j].name, s[j + 1].name);
                //strcpy(s[j + 1].name, temp);

                ////交换成绩

                //for (int k = 0; k < 3; k++)
                //{
                //	float temp=s[j].scores[k];
                //	s[j].scores[k] = s[j + 1].scores[k];
                //	s[j + 1].scores[k] = temp;
                //}

                //结构体变量交换 这种方式最方便
                struct stu1 temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;

            }
        }
    }


    for (int i = 0; i < 3; i++) {
        printf("姓名：%s\n", s[i].name);
        printf("成绩: %.1f   %.1f   %.1f\n", s[i].scores[0], s[i].scores[1], s[i].scores[2]);
    }


    for (int i = 0; i < 3; i++) {
        free(s[i].name);
    }

}