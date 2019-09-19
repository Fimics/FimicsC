//
// Created by lipengju on 2019-09-19.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if 0
信号集处理函数
#include <signal.h>
清空信号集
int sigemptyset(sigset_t *set);
填充信号集
int sigfillset(sigset_t *set);
添加某个信号到信号集
int sigaddset(sigset_t *set, int signum);
从集合中移除某个集合
int sigdelset(sigset_t *set, int signum);
是否为集合里的成员  返回1代表在集合中
int sigismember(const sigset_t *set, int signum);

设置阻塞,解除某个信号
/* Prototype for the glibc wrapper function */
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

/* Prototype for the underlying system call */
int rt_sigprocmask(int how, const kernel_sigset_t *set,
                  kernel_sigset_t *oldset, size_t sigsetsize);

/* Prototype for the legacy system call (deprecated) */
int sigprocmask(int how, const old_kernel_sigset_t *set,
               old_kernel_sigset_t *oldset);

#endif


//int main() {
//
//    sigset_t pend,sigproc;
//    sigemptyset(&sigproc);
//    sigaddset(&sigproc,SIGINT);
//    //设置阻塞信号，等待按键产生信号
//    sigprocmask(SIG_BLOCK,&sigproc,NULL);//2号信号阻塞
//    //循环取未决信号集，打印
//
//    while (1){
//        sigpending(&pend);
//        int i = 1;
//        for (int i = 0; i < 32; ++i) {
//            if(sigismember(&pend,i)==1){//在这个集合里
//                printf("1");
//            } else{
//                printf("0");
//            }
//        }
//
//        printf("\n\n");
//        sleep(1);
//    }
//
//    return 0;
//}