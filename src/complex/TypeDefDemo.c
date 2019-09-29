//
// Created by lipnegju on 2019-06-30.
//

#include <stdio.h>

/**
 * typedef 为已有数据重新定义一个别名
 */

typedef unsigned long long ull;

struct studentsInfoList
{
	char name[20];
	char sex;
};
typedef struct studentsInfoList sinfo;

void typedefDemo(){
    sinfo s1;

    ull a = 10;

    printf("%d\n", a);
}