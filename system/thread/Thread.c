//
// Created by lipengju on 2019-09-20.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


#if 0
#include <pthread.h>
thread 线程id ,传出参数
attr 线程属性
void *func(void*) 函数指针
arg线程执行函数的参数
返回值
    成功返回 0
    失败返回 error
编译的时候需要加pthread 库
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);

Compile and link with -pthread.

#endif

void *thread(void *arg){
    printf("i am a thread! pid=%d,thd = %lu\n",getpid(),pthread_self());
    return NULL;
}

//run gcc Thread.c -lpthread
void threadCreate(){
     pthread_t  tid;
     pthread_create(&tid,NULL,thread,NULL);
     printf("i am a main thread,pid =%d, tid = %lu\n",getpid(),pthread_self());
     sleep(15);
     /**
      * 1.在线程中使用pthread_exit
      * 2.主线程中使用return 代表退出进程
      * 3.exit 代表退出整个进程
      */
     pthread_exit(10);
}

int main() {
    threadCreate();
    return 0;
}
