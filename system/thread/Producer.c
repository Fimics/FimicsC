//
// Created by lipengju on 2019-09-21.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int beginnum = 100;

typedef struct _ProdInfo {
    int num;
    struct _ProdInfo *next;
} ProdInfo;

ProdInfo *head = NULL;


void *thr_producer(void *arg) {

    while (1) {
        ProdInfo * prod = malloc(sizeof(struct _ProdInfo));
        prod->num = beginnum++;
        printf("----%s---self=%lu--num=%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_lock(&mutex);
        //add to list
        prod->next = head;
        head = prod;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        sleep(rand()%2);
    }
}

void *thr_customer(void *arg) {
     ProdInfo * prod=NULL;
    while (1){
        pthread_mutex_lock(&mutex);
        while (head==NULL){
            pthread_cond_wait(&cond,&mutex);
        }
        prod=head;
        head=head->next;
        printf("----%s---self=%lu--num=%d\n",__FUNCTION__,pthread_self(),prod->num);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%5);
        free(prod);
    }
}

void run() {

    pthread_t tid[2];
    pthread_create(&tid[0], NULL, thr_producer, NULL);
    pthread_create(&tid[1], NULL, thr_customer, NULL);

    for (int i = 0; i < 2; ++i) {
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}

//int main() {
//    run();
//    return 0;
//}