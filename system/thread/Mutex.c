//
// Created by lipengju on 2019-09-21.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int sum=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thr1(void *arg){
    while (1){
        //给临界区代码加锁
        pthread_mutex_lock(&mutex);
        //以下代码叫临界区
        printf("hello-");
        sleep(rand()%3);
        printf("world\n");
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
}

void *thr2(void *arg){
    while (1){
        //给临界区代码加锁
        pthread_mutex_lock(&mutex);
        //以下代码叫临界区
        printf("HELLO-");
        sleep(rand()%3);
        printf("WORLD\n");
        pthread_mutex_unlock(&mutex);
        sleep(rand()%3);
    }
}

void run(){
   pthread_t  tid[2];
   pthread_create(&tid[0],NULL,thr1,NULL);
   pthread_create(&tid[1],NULL,thr2,NULL);

   pthread_join(tid[0],NULL);
   pthread_join(tid[1],NULL);
}

//int main(){
//    run();
//    return 0;
//}