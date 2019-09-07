//
// Created by lipengju on 2019-09-07.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>
#include <time.h>

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);

struct stat {
    dev_t     st_dev;         /* ID of device containing file */
    ino_t     st_ino;         /* Inode number */
    mode_t    st_mode;        /* File type and mode */
    nlink_t   st_nlink;       /* Number of hard links */
    uid_t     st_uid;         /* User ID of owner */
    gid_t     st_gid;         /* Group ID of owner */
    dev_t     st_rdev;        /* Device ID (if special file) */
    off_t     st_size;        /* Total size, in bytes */
    blksize_t st_blksize;     /* Block size for filesystem I/O */
    blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */
}
#endif

int testCatFileInfo(int argc, char* argv[]){
    if(argc!=2){
        printf("filename\n");
        return -1;
    }

    struct stat sb;
    stat(argv[1],&sb);
    return 0;
}

#if 0
int main(int argc, char* argv[]){

    if(argc!=2){
        printf("filename\n");
        return -1;
    }

    struct stat sb;
    stat(argv[1],&sb);

    char stmode[11]={0};
    memset(stmode,'-', sizeof(stmode));

    //解析文件类型
    if(S_ISREG(sb.st_mode)) stmode[0]='-';
    if(S_ISDIR(sb.st_mode)) stmode[0]='d';
    if(S_ISCHR(sb.st_mode)) stmode[0]='c';
    if(S_ISBLK(sb.st_mode)) stmode[0]='b';
    if(S_ISFIFO(sb.st_mode)) stmode[0]='p';
    if(S_ISLNK(sb.st_mode)) stmode[0]='l';
    if(S_ISSOCK(sb.st_mode)) stmode[0]='s';

    //解析权限
    if(sb.st_mode & S_IRUSR) stmode[1]='r';
    if(sb.st_mode & S_IWUSR) stmode[2]='w';
    if(sb.st_mode & S_IXUSR) stmode[3]='x';

    if(sb.st_mode & S_IRGRP) stmode[4]='r';
    if(sb.st_mode & S_IWGRP) stmode[5]='w';
    if(sb.st_mode & S_IXGRP) stmode[6]='x';

    if(sb.st_mode & S_IROTH) stmode[7]='r';
    if(sb.st_mode & S_IWOTH) stmode[8]='w';
    if(sb.st_mode & S_IXOTH) stmode[9]='x';

    //获取用户名，组名，pid,uid
    struct tm *filetm = localtime(&sb.st_atim.tv_sec);

    printf("mode %s",stmode);
    return 0;
}

#endif