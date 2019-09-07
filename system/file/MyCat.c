//
// Created by lipengju on 2019-09-07.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * 文件读写
 * @param argc
 * @param argv
 * @return
 */
//int main(int argc,char* argv[]){
//    if(argc!=2){
//      printf("error\n");
//        return -1;
//    }
//
//    int fd = open(argv[1],O_RDONLY);
//
//    //读文件，输出到屏幕
//    char buf[1024];
//    int ret = read(fd,buf, sizeof(buf));
//    write(STDOUT_FILENO,buf,ret);
//    close(fd);
//    return 0;
//}