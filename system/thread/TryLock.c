//
// Created by lipengju on 2019-09-21.
//


//
// Created by lipengju on 2019-09-21.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int sum=0;
pthread_mutex_t mutex ;

void *thr1(void *arg){
    while (1){
        pthread_mutex_lock(&mutex);
        printf("hello-world");
        sleep(rand()%30);
        pthread_mutex_unlock(&mutex);
    }
}


void run(){
    pthread_mutex_init(&mutex,NULL);
    pthread_t  tid;
    pthread_create(&tid,NULL,thr1,NULL);
    sleep(1);
    while (1){
        int ret = pthread_mutex_trylock(&mutex);
        if(ret>0){
            printf("ret %d,strerror %s\n",ret,strerror(ret));
        }
        sleep(1);
    }
}

int main(){
    run();
    return 0;
}