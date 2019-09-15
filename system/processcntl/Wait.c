//
// Created by lipengju on 2019-09-11.
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#if 0
回收子进程,知道子进程死亡原因
作用
   1.阻塞等待
   2.回收子进程
   3.查看子进程死亡原因
pid_t wait(int *wstatus);

pid
  < -1 -组id
  -1 回收任意
  0  回收和调用进程组id相同组内的子进程
  > 0 回收指定pid
options
  0 与wait相同,也会阻塞
  WNOHANG 如果当前没有子进程退出的,立刻返回
返回值
   如果设置了WNOHANG 如果没有子进程退出返回0,如果有子进程退出返回退出的pid
   失败返回-1(没有子进程)
pid_t waitpid(pid_t pid, int *wstatus, int options);
int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
his is the glibc and POSIX interface; see

#endif


int testWait(){
  pid_t  pid = fork();
  if(pid==0){
      printf("i am child, will die!\n");
      sleep(2);
//      return 100;
       exit(1000);
  } else if (pid>0){
      printf("i am parent ,wait for child die!\n");
      int status;
      pid_t  wpid = wait(&status);
      printf("wait ok,wpid-->%d\n",wpid);
      if(WIFEXITED(status)){
          printf("child exit with%d\n",WEXITSTATUS(status));
          printf("child 正常死亡");
      }

      if(WIFSIGNALED(status)){
          printf("child killed by %d\n",WTERMSIG(status));
          printf("child 非正常死亡");
      }
      while (1){
          sleep(1);
      }
  }

    return 100;

}

int testWaitPid(){
   pid_t  pid = fork();

   if(pid==0){
      printf("i am child,pid=%d\n",getpid());
      sleep(2);
   }else if(pid>0){
       printf("i am parent,pid=%d\n",getpid());
       int status;
       int ret ;
       while (ret=waitpid(-1,&status,WNOHANG)){
           sleep(1);
       }
       printf("ret %d\n",ret);
       printf("status %d\n",status);
       while(1){
           sleep(1);
       }
   }
}

//TODO
//回收多个子进程

//int main(){
////    testWait();
//    testWaitPid();
//    return 0;
//}