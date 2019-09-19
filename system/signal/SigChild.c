//
// Created by lipengju on 2019-09-19.
//

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void catch_sig(int num) {
    pid_t wpid = waitpid(-1, NULL, WNOHANG);
    if (wpid > 0) {
        printf("wait child %d ok\n", wpid);
    }
}

//int main() {
//    int i = 0;
//    pid_t pid;
//    for (i = 0; i <10; ++i) {
//        pid = fork();
//        if(pid==0){
//            break;
//        }
//    }
//
//    if(i==10){
//        struct sigaction act;
//        act.sa_flags=0;
//        sigemptyset(&act.sa_mask);
//        act.sa_handler = catch_sig;
//
//        sigaction(SIGCHLD,&act,NULL);
//        while (1){
//            sleep(1);
//        }
//    } else if(i<10){
//        printf("i am %d child,pid =%d\n",i,getpid());
//        sleep(1);
//    }
//}