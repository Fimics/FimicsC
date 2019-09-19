//
// Created by lipengju on 2019-09-19.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


//void catch_sig(int num){
//    printf("catch %d sig\n",num);
//}

/**
 * 信号捕捉
 * @return
 */
//int main(){
//
//    //注册捕捉函数
//    struct sigaction act;
//    act.sa_flags=0;
//    act.sa_handler=catch_sig;
//    sigemptyset(&act.sa_mask);
//    sigaction(SIGALRM,&act,NULL);
//
//    //setitimer
//    struct itimerval myit ={{3,0},{5,0}};
//    setitimer(ITIMER_REAL,&myit,NULL);
//    while (1){
//        printf("who can kill me!\n");
//        sleep(1);
//    }
//
//    return 0;
//}