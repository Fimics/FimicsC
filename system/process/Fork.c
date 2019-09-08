//
// Created by lipengju on 2019-09-08.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

//fork 父进程返回子进程ID,子进程返回0

int main(){
    printf("begin");
    pid_t pid =fork();
    if(pid<0){
        perror("fork err");
        exit(1);
    }

    if(pid==0){
        printf("subpid=%d,pid=%d\n",getpid(),getppid());
    }

    printf("end");
    return 0;
}