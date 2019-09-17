//
// Created by lipengju on 2019-09-18.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <wait.h>

typedef struct _Student{
     int sid;
     char sname[20];
} Student;

int main(int argc,char * argv[]){
    if(argc!=2){
        perror("argc err");
        return -1;
    }

    int fd = open(argv[1],O_RDWR);
    int len = sizeof(struct Student);
    ftruncate(fd,len);//设置文件大小

    Student * stu = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    if(stu==MAP_FAILED){
        perror("mmap err");
        return -1;
    }

    int num =1;

    while (1){
        printf("sid=%d,sname=%s\n",stu->sid,stu->sname);
        sleep(1);
    }

    munmap(fd,len);
    close(fd);
    return 0;
}