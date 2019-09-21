#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int num =1000;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
void *thr_write(void *arg) {
     while (1){
         pthread_rwlock_wrlock(&rwlock);
         printf("-----%s---self---%lu--beginnum--%d\n",__FUNCTION__,pthread_self(),++num);
         usleep(1000);//模拟占用时间
         pthread_rwlock_unlock(&rwlock);
         usleep(1000);
     }
}

void *thr_read(void *arg) {
    while (1){
        pthread_rwlock_rdlock(&rwlock);
        printf("-----%s---self---%lu--beginnum--%d\n",__FUNCTION__,pthread_self(),num);
        usleep(3000);
        pthread_rwlock_unlock(&rwlock);
        usleep(2000);
    }
}

void run() {
    int n = 10, i = 0;

    pthread_t tid[10];
    for (i = 0; i < 8; ++i) {
        pthread_create(&tid[i], NULL, thr_read, NULL);
    }

    for (i = 0; i <2 ; ++i) {
        pthread_create(&tid[i],NULL,thr_write,NULL);
    }

    for (int j = 0; j <10 ; ++j) {
        pthread_join(tid[i],NULL);
    }
}

//int main() {
//    run();
//    return 0;
//}