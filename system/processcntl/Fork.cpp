//
// Created by lipengju on 2019-09-08.
//

#include <stdio.h>
#include <unistd.h>
#include <gtest/gtest.h>

//fork 父进程返回子进程ID,子进程返回0

void createPorcessWithFork(){
    printf("begin \n");
    pid_t pid =fork();
    if(pid<0){
        perror("fork err");
    }

    if(pid==0){
        printf("subpid=%d,pid=%d\n",getpid(),getppid());
//        while (1){
//            printf("subpid");
//            sleep(1);
//        }
    } else if(pid>0){
        printf("subpid--->%d,pid->%d\n",getpid(),getppid());
    }

    printf("end\n");
}

TEST(fork,createPorcessWithFork){
    createPorcessWithFork();
}

void createMulProcess(){
    int n = 2;
    int i=0;

    pid_t pid = 0;

    for (int i = 0; i <n ; ++i) {
        pid=fork();
        if(pid==0){
            //son
            printf("i am child,pid=%d,ppid=%d\n",getpid(),getppid());
            break;
        } else if(pid>0){
            //father
            printf("i am father,pid=%d,ppid=%d\n",getpid(),getppid());
        }
    }

//    while (1){
//        sleep(1);
//    }

}

TEST(fork,createMulProcess){
    createMulProcess();
}

/**
 * 进程控制，先创建先退出
 */
void testProcessCntl(){
    int n = 5;
    int i=0;

    pid_t pid = 0;

    for (int i = 0; i <n ; ++i) {
        pid=fork();
        if(pid==0){
            //son
            printf("i am child,pid=%d,ppid=%d\n",getpid(),getppid());
            break;
        } else if(pid>0){
            //father
            printf("i am father,pid=%d,ppid=%d\n",getpid(),getppid());
        }
    }

    sleep(i);
}

TEST(fork,testProcessCntl){
    testProcessCntl();
}