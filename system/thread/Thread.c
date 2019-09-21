//
// Created by lipengju on 2019-09-20.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


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
    int num = (int)arg;
    printf("i am a thread! pid=%d,thd = %lu,num= %d\n",getpid(),pthread_self(),num);
    return (void*)(100+num);
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
//     pthread_exit(10);
     void * ret;
//     pthread_join(tid,&ret);//回收线程
//     pthread_cancel(tid);杀死线程

}


void threadDetach(){
    pthread_t  tid;
    pthread_create(&tid,NULL,thread,NULL);
    pthread_detach(tid); //不需要自己回收线程，系统自动回收
    int ret = 0;
    if((ret=pthread_join(tid,NULL))>0){
        printf("join err:%d,%s\n",ret,strerror(ret));
    }
//    pthread_equal() 判断两线程id是否相同，线程在一个进程是唯一的，在操作系统中不一定
}

void threadJoin(){
    pthread_t tid[5];
    int i;
    for (i = 0; i < 5; ++i) {
        pthread_create(&tid[i],NULL,thread,(void*)i);
    }

    for (i = 0; i <5 ; ++i) {
        int  *ret;
        pthread_join(tid[i],&ret);
        printf("i---%d,ret==%d\n",i ,(int)ret);
    }
}


//int main() {
////    threadCreate();
//     threadJoin();
//    return 0;
//}
