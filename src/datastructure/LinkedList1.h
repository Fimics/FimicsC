//
// Created by lipnegju on 2019-07-21.
//

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
   extern "C"{
#endif

    typedef void * LinkList;
    typedef void (*FOREACH)(void *);

    //初始化链表
    LinkList init1();
    //插入
    void insert1(LinkList linkList,int pos,void *data);
    //遍历
    void foreach1(LinkList linkList,FOREACH foreach);




#ifdef __cplusplus
}
#endif