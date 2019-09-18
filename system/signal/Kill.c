//
// Created by lipengju on 2019-09-18.
//


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

void testKillFather(){
    int i;
    for (i = 0; i <5 ; ++i) {
        pid_t pid = fork();
        if(pid==0){
            break;
        }
    }

    if(i==2){
        printf("i will kill father after 5s\n");
        sleep(5);
        kill(getppid(),SIGKILL);
        while (1){
            sleep(1);
        }
    } else if(i==5){
        while (1){
            printf("i am parent,i am happy!\n");
            sleep(1);
        }
    }
}

/**
 * 给自己发信息
 */
void testRaise(){
    raise(SIGKILL);
    abort();
}

//int main(){
//
//
//    return 0;
//}