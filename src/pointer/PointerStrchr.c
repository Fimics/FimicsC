//
// Created by lipnegju on 2019-06-23.
//

#include <string.h>
#include <printf.h>


char * strchrPointer(const char *arr, char ch){

    int i=0;
    while (arr[i]!='\0'){
        if(arr[i]==ch){
            return &arr[i];
        }
        i++;
    }

    return NULL;

}


char * strchrPointer1(const char *arr, char ch){

    char * p = arr;

    while (*p!='\0'){
        if(*p==ch){
            return p;
        }
        p++;
    }

    return NULL;
}

void pointerStrchr(){

    char  arr[] ="hello world";
    char  ch ='o';
    //char  *p = strchr(arr,ch);
    char *p =strchrPointer1(arr,ch);
    printf("%s\n",p);
}