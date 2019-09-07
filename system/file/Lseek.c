//
// Created by lipengju on 2019-09-07.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * seek
 * @param argc
 * @param argv
 * @return
 */

#if 0
int main(int argc,char* argv[]){
    if(argc!=2){
      printf("error\n");
        return -1;
    }

    int fd = open(argv[1],O_RDWR|O_CREAT,0666);

    // 10 不用考虑 "\0" ,这时文件的读写位置到了文件末尾了
    write(fd,"hello seek",10);
    char buf[256];

    //移动文件读写位置
    lseek(fd,4,SEEK_SET);
    int ret = read(fd,buf, sizeof(buf));

    if(ret){
        write(STDOUT_FILENO,buf,ret);
    }

    /**
     * 计算文件大小
     */
    //int fileSize = lseek(fd,0,SEEK_END);

    /**
     * 拓展文件
     * 创建一个文件大小为1024的文件
     */
    //int size = lseek(fd,1024,SEEK_END);

    close(fd);
    return 0;
}

#endif