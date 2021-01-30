//
// Created by lipengju on 2019-09-12.
//

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define _GNU_SOURCE

#if 0
#include <unistd.h>

pipefd 读写文件描述符,0 代表读，1代表写
返回值 失败返回 -1 ，成功返回0
int pipe(int pipefd[2]);

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>

int pipe2(int pipefd[2], int flags);

#endif

/**
 * pip 简单发送数据
 */
void testPipe(){
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if(pid==0){
        write(fd[1],"hello p",7);

    } else if(pid>0){
        char buf[1024]={0};
        int ret = read(fd[0],buf, sizeof(buf));
        if(ret>0){
            write(STDOUT_FILENO,buf,ret);
        }

        write(fd[1],"hello s",7);
    }
}

/**
 * pipe 实现父子进程间通信 实现 ps aux|grep bash功能
 */
void testPipParentChildComon(){
  int fd[2];
  pipe(fd);

  pid_t  pid = fork();
  if(pid==0){

      close(fd[0]);
      //标准输出重定向到管道写入端
      dup2(fd[1],STDOUT_FILENO);
      execlp("ps","ps","aux",NULL);
  } else if(pid>0){
      close(fd[1]);
      //标准输入重定向到管道读取端
      dup2(fd[0],STDIN_FILENO);
      execlp("grep","grep","bash","--color=auto",NULL);
  }
}

