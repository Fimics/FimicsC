//
// Created by lipengju on 2019-09-21.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t blank,full;
#define _SEM_CNT_  5

int queue[_SEM_CNT_];//模拟容器
int num =100;

void *thr_producer(void *arg) {

    int i=0;
    while (1){
        sem_wait(&blank);//申请资源 blank--
        printf("---%s--- self=%lu  --num--=%d\n",__FUNCTION__,pthread_self(),num);
        queue[(i++)%_SEM_CNT_]=num++;
        sem_post(&full);//full++
        sleep(rand()%3);
    }

}

void *thr_customer(void *arg) {
    int i=0;
    int num=0;
    while (1){
        sem_wait(&full);//full--
        num = queue[(i++)% _SEM_CNT_];
        printf("---%s--- self=%lu  --num--=%d\n",__FUNCTION__,pthread_self(),num);
        sem_post(&blank);//blank--
        sleep(rand()%3);
    }
}

void run() {
    sem_init(&blank,0,_SEM_CNT_);
    sem_init(&full,0,0);//消费者一开始的初始化默认没有产品

    pthread_t  tid[2];
    pthread_create(&tid[0],NULL,thr_producer,NULL);
    pthread_create(&tid[1],NULL,thr_customer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    sem_destroy(&blank);
    sem_destroy(&full);
}



//int main(){
//    run();
//    return 0;
//}