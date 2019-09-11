//
// Created by lipengju on 2019-09-11.
//
#include <unistd.h>
#include <stdio.h>

#if 0

extern char **environ;

int execl(const char *path, const char *arg, ...
               /* (char  *) NULL */);
1.file 要执行的程序
2.args 参数列表
3.返回值,只有失败才返回
int execlp(const char *file, const char *arg, ...
               /* (char  *) NULL */);
int execle(const char *path, const char *arg, ...
               /*, (char *) NULL, char * const envp[] */);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
               char *const envp[]);

#endif



//int main(){
////    execlp("ls","ls","-l",NULL);
////    execlp("ls","ls","-l","--color=auto",NULL);
//    execl("/bin/ls","ls","-l","--color=auto",NULL);
//    perror("execl err");
//    return 0;
//}