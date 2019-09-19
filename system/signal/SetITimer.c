//
// Created by lipengju on 2019-09-18.
//
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void testItimer() {
    struct itimerval myit = {{0, 0},
                             {3, 0}};//3s以后发送SIGALRM信号
    setitimer(ITIMER_REAL, &myit, NULL);

    while (1) {
        printf("setitimer...\n");
        sleep(1);
    }
}

void catchSig(int num) {
    printf("cat %d sig\n", num);
}

void testITimer2() {
    signal(SIGALRM, catchSig);
    struct itimerval myit = {{3, 0},
                             {5, 0}};//第一次等待5s 之后每隔3s
    setitimer(ITIMER_REAL,&myit,NULL);
    while (1){
        printf("who can kill me!\n");
        sleep(1);
    }
}



//int main() {
////    testItimer();
//    testITimer2();
//    return 0;
//}