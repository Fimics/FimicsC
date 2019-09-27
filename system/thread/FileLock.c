//
// Created by lipengju on 2019-09-22.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>


#define  _FILE_NAME_ "home/root/temp.lock"

/**
 * 文件锁
 * 需求，当前系统进程只能启一个，对应该文件锁
 * @return
 */

void testFileLock(){
    int fd = open(_FILE_NAME_,O_RDWR);
    if(fd<0){
        perror("open err\n");
    }

    struct  flock lk;
    lk.l_type=F_WRLCK;
    lk.l_whence=SEEK_SET;
    lk.l_start=0;
    lk.l_len=0;

    if(fcntl(fd,F_SETLK,&lk)<0){
        perror("get lock error");
    }

    while (1){
        printf("i am alive!\n");
        sleep(1);
    }

}


//int main(){
//    testFileLock();
//    return 0;
//}