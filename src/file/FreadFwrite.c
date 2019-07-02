//
// Created by lipnegju on 2019-07-01.
//

#include "YFile.h"
#include <stdio.h>

#define FILE_PATH "resource/write.txt"
#define FILE_OBJ "resource/obj.txt"
#define SIZE  11


/**
 * 二进制文件读写
 */

int testWrite() {

    char arr[SIZE] = "hello world";
    //int arr [SIZE]={1,2,3,4,5,6,7,8,9,10,11};
    FILE *fp = fopen(FILE_PATH, "w");

    if (!fp)
        return -1;

    fwrite(arr, sizeof(int), SIZE, fp); //buffer = sizeof(int)*SIZE
//  fprintf(fp,"ddddd");
    fclose(fp);
}

int testRead() {

    FILE *fp = fopen(FILE_PATH, "rb");
    if (!fp)
        return -1;

    char arr[12] = {0};
    fread(arr, 1, SIZE, fp);


    int i = 0;
    while (!feof(fp)) {
        fread(&arr[i++], sizeof(char), SIZE, fp);
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%c", arr[i]);
    }

}

struct object{
    char name[20];
    int age;
    char sex;
    char tel[15];
};

typedef struct object obj;

int writeObject(){
    obj o[2]={{"李白",22,'M',"11111"},{"李白",33,'F',"22222"}};

    FILE *fp = fopen(FILE_OBJ,"w");
    if(!fp)
        return -1;

    for (int i = 0; i <2 ; i++) {
        fwrite(&o[i], sizeof(obj),1,fp);
    }

    fclose(fp);

}

int readObject(){

    FILE *fp = fopen(FILE_OBJ,"rb");
    if(!fp)
        return -1;


    obj o[2];

    int i=0;

    while (!feof(fp)){
        fread(&o[i++], 20,2,fp);
    }

    fclose(fp);

    for (int j = 0; j <2 ; j++) {
        printf("%s\n",o[j].name);
    }



}

void freadFwrite() {
//      testWrite();
//    testRead();
//writeObject();
readObject();
}