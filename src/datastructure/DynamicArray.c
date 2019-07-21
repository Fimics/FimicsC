//
// Created by lipnegju on 2019-07-19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArray.h"
#include "YDataStructure.h"

#if 1
/**
 * 动态数组必须知道以下条件
 * 1.存储数据元素的空间的首地址(void *)
 * 2.元素的个数
 * 3.数组容量
 */


struct Red{
    char  * name ;
    int age;
};


/**
 * 初始化数组
 * @return
 */
struct DNCArray * inita(int capacity){
    if(capacity<=0) return NULL;
    struct DNCArray * array = malloc(sizeof(struct DNCArray));

    if(NULL==array) return NULL;

    array->capacity =capacity;
    array->addr =malloc(sizeof(void *)*capacity);
    array->size=0;

    return array;
}

//插入元素
void inserta(struct DNCArray * array,int pos,void *data){
    if(array==NULL || data==NULL) return;

    if (pos<0 ||pos>array->size) pos=array->size;

    //1.判断空间是否足够 不够就加一倍
    if(array->size>=array->capacity){
      int newCapacity = array->capacity*2;
      void ** newSpace = malloc(sizeof(void *)*newCapacity);

      //2.把当前array的数据copy拷贝到新空间
      memcpy(newSpace,array->addr, sizeof(void *)*array->capacity);

      //3.释放原空间
      free(array->addr);

      //4.更新addr指向
      array->addr=newSpace;
      array->capacity=newCapacity;
    }

    //5.移动位置给要插入的元素空出空间
    for (int i = array->size-1; i >=pos ; --i) {
        array->addr[i+1]=array->addr[i];
    }

    //6.插入元素
    array->addr[pos]=data;
    array->size=array->size+1;


}
//遍历
void foreacha(struct DNCArray *array,void(* callback)(void *)){
    if(NULL ==array || callback==NULL) return;

    for (int i = 0; i <array->size ; ++i) {
        callback(array->addr[i]);
    }
}

//删除
void removeItemByIndexa(struct DNCArray * da ,int pos){
    if(NULL==da) return;

    if(pos<0|| pos>da->size-1) return;

    for (int i = pos; i <da->size ; ++i) {
        da->addr[i]=da->addr[i+1];
        break;
    }
}

void removeItemByValuea(struct DNCArray *da,void * data, int(*compare)(void *,void *)){
    if(da==NULL ||data==NULL) return;

    for (int i = 0; i <da->size ; ++i) {
         if(compare(da->addr[i],data)){
             removeItemByIndexa(da,data);
             break;
         }
    }
}

int myCompare(void *data1 , void *data2){

    struct Red *red1 =(struct Red *)data1;
    struct Red *red2 =(struct Red *)data2;

    return strcmp(red1->name,red2->name) && red1->age==red2->age;

}


void destroya(struct DNCArray *da){
    if(da==NULL) return;

    if(da->addr!=NULL){
        free(da->addr);
        da->addr=NULL;
    }

    free(da);
    da=NULL;
}



void printRed(void *data){
    struct Red *red = (struct Red *)data;
    printf("name--> %s  age--> %d\n",red->name,red->age);
}


#endif
void dynamicArray(){
    printf("%s\n","dynamicArray");
    struct DNCArray *da = inita(10);

    for (int i = 0; i <10 ; ++i) {
        struct Red * red =malloc(sizeof(struct Red));
        red->name=malloc(sizeof(char)*64);
        strcpy(red->name,"red");
        red->age=i;
        inserta(da,i,red);
    }

    foreacha(da,*printRed);
}

