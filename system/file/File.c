//
// Created by lipengju on 2019-09-06.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

void testOpen(){
    //关闭标准输出设备
    close(1);
    //打开一个文件输出
    int fd  = open("../../resource/1.log",O_CREAT|O_TRUNC|O_WRONLY,0644);
    printf("hello linux\n");
    //刷新缓存区
    fflush(stdout);
    //关闭标准输出设备
    close(fd);
}

void testOpenFileMax(){
    int num = 3;
    char filename[128]={0};
    while (1){
        sprintf(filename,"temp_%4d",num++);
        if(open(filename,O_CREAT|O_RDONLY,0666)<0){
            perror("open err");
            break;
        }
    }

    printf("num==%d\n",num);
    return;0;
}

//int main(){
//    testOpen();
//    return 0;
//}