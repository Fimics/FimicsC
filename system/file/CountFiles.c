
// Created by lipengju on 2019-09-07.
//
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//统计指定目录的文件数
// find ./ -type f |wc -l

#if 0
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
DIR *fdopendir(int fd);

#include <dirent.h>
struct dirent *readdir(DIR *dirp);

#include <sys/types.h>
#include <dirent.h>
把目录指针恢复到起始位置
void rewinddir(DIR *dirp);

#include <dirent.h>
获取目录读写位置
long telldir(DIR *dirp);


#include <dirent.h>
#修改目录读写位置
void seekdir(DIR *dirp, long loc);

#include <sys/types.h>
#include <dirent.h>
int closedir(DIR *dirp);


#endif

int count;
char * prefix[256]={0};

int dirCount(char * dirname){
    //打开目录
    DIR *dirp = opendir(dirname);

    if(dirp==NULL){
        perror("opendir error");
        return -1;
    }

    struct dirent *dentp=NULL;
    while ((dentp=readdir(dirp))!=NULL){//如果为NULL 代表读到目录末尾
        printf("dirname:%s ,dtype %d\n",dentp->d_name,dentp->d_type);
        //如果是目录
        if(dentp->d_type==DT_DIR){
           if(strcmp(".",dentp->d_name)==0||strcmp("..",dentp->d_name)==0){
               continue; //如果是 . | ..直接跳过
           }

           //注意进程的工作路径不能直接打开子目录
           //使用dirname拼接下一级子目录
           char  newdirname[256]={0};
           sprintf(newdirname,"%s%s",dirname,dentp->d_name);
           dirCount(newdirname);
        }else if(dentp->d_type==DT_REG){
            count++;
        }
    }

    return count;
}
//
//int main(int argc, char *argv[]){
//
//    if(argc!=2){
//        printf("error");
//        return -1;
//    }
//
//    //打开目录
//
//    DIR *dirp = opendir(argv[1]);
//    //循环读目录，判断如果是普通文件count ++
//
//    dirCount(argv[1]);
//
//    printf("count---->%d\n",count);
//    //关闭上当
//    return 0;
//}