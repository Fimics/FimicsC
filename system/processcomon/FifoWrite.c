//
// Created by lipengju on 2019-09-16.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <string.h>


#if 0
NAME
   mkfifo, mkfifoat - make a FIFO special file (a named pipe)

SYNOPSIS
   #include <sys/types.h>
   #include <sys/stat.h>

   int mkfifo(const char *pathname, mode_t mode);

   #include <fcntl.h>           /* Definition of AT_* constants */
   #include <sys/stat.h>

   int mkfifoat(int dirfd, const char *pathname, mode_t mode);

Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

   mkfifoat():
       Since glibc 2.10:
           _POSIX_C_SOURCE >= 200809L
       Before glibc 2.10:
           _ATFILE_SOURCE
#endif

//int main(int argc, char *argv[]){
//
//    if(argc!=2){
//       perror("file error");
//        return -1;
//    }
//
//    //当前目录有一个fifo文件
//    //打开fifo文件
//    int fd = open(argv[1],O_WRONLY);
//    //写
//    char buf[256];
//    int num=1;
//    while (1){
//        memset(buf,0x00, sizeof(buf));
//        sprintf(buf,"mkfifo %04d",num++);
//        write(fd,buf,strlen(buf));
//        sleep(1);
//    }
//
//    close(fd);
//    return 0;
//}
