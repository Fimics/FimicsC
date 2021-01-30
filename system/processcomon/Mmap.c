//
// Created by lipengju on 2019-09-17.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <wait.h>


#if 0
addr 传NULL
length 映射区长度
prot 可读,可写
    PROT_EXEC  Pages may be executed.
    PROT_READ  Pages may be read.
flags 共享的 私有的  对内存的修改会影响到原文件
fd  文件描述符
offset 偏移量(文件从哪开始取)
创建映射区
void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
释放映射区
int munmap(void *addr, size_t length);

#endif

int testMmap() {
    int fd = open("./mem.txt", O_RDWR);
    //创建映射区
    char *mem = mmap(NULL, 256, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    if(mem == MAP_FAILED){
        perror("mmap err");
        return -1;
    }

    //拷贝数据
    strcpy(mem,"hello world txt hello mmap txt -->");
    //释放mmap
    munmap(mem,256);
    close(fd);
    return 0;
}

void testMmapFork(){
    /**
     * 1.先创建映射区
     * 2.fork子进程
     * 3.父子进程交替修改数据
     */

    int fd = open("mem.txt",O_RDWR);
    int *mem = mmap(NULL,8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(mem==MAP_FAILED){
        perror("mmap err");
    }

    pid_t  pid = fork();
    if(pid==0){
        //son
        *mem = 100;
        printf("child *mem=%d\n",*mem);
        sleep(3);
        printf("child *mem=%d\n",*mem);
    } else{
        //parent
        sleep(1);
        printf("parent *mem=%d\n",*mem);
        *mem=1000;
        printf("parent *mem=%d\n",*mem);
        wait(NULL);
    }

    munmap(mem,fd);
    close(fd);
}

//int main() {
////    testMmap();
//    testMmapFork();
//    return 0;
//}