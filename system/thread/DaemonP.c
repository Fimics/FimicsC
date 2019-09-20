//
// Created by lipengju on 2019-09-19.
//

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

#define  FILE_NAME_FORMAT "%s/log/data.%ld"

void touchFile(int num){
    char  *homedir = getenv("HOME");
    char  fileName [256]={0};
    sprintf(fileName,FILE_NAME_FORMAT,homedir,time(NULL));
    printf("filename %s ->>",fileName);
    int fd = open(fileName,O_RDWR|O_CREAT,0666);
    if(fd<0){
        perror("open err");
        exit(1);
    }
    close(1);
}

/**
 * 创建一个守护进程，每秒在HOME/log/创建一个wnejian，程序名.时间戳
 * @return
 */
//int main(){
//
//    //1.创建子进程，父进程退出
//    pid_t  pid = fork();
//    //2.当会长
//    //3.设置掩码
//    umask(0);
//    //4.切换目录
//    chdir(getenv("HOME"));
//    //5.关闭文件描述符
//    //6.执行核心逻辑
//    struct  itimerval myit = {{5,0},{5,0}};
//    setitimer(ITIMER_REAL,&myit,NULL);
//    struct sigaction act;
//    act.sa_flags=0;
//    sigemptyset(&act.sa_mask);
//    act.sa_handler = touchFile;
//    sigaction(SIGALRM,&act,NULL);
//    while (1){
//        //每隔一分钟在/home/log/下创建一个文件
//        sleep(1);
//    }
//    //7.退出
//
//}