//
// Created by lipengju on 2019-09-25.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>

#define IP "127.0.0.1"
#define PORT 9090



int main(int argc , const char * argv[]){

    if(argc<2){
        printf("./a.out port\n");
        exit(1);
    }

    int port = atoi(argv[1]);

    //创建套接字
    int fd =socket(AF_INET,SOCK_STREAM,0);
    //连接服务器

    struct  sockaddr_in server;
    memset(&server,9, sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
//    server.sin_addr.s_addr=

    inet_pton(AF_INET,IP,&server.sin_addr.s_addr);
    connect(fd,(struct sockaddr*)&server, sizeof(server));

    //通信
    while (1){
        //发送数据
        char  buf[1024];
        printf("please input:\n");
        fgets(buf, sizeof(buf),STDIN_FILENO);
        write(fd,buf,strlen(buf));

        //等待接收数据
        int len = read(fd,buf, sizeof(buf));
        if(len==-1){
            perror("read err");
            exit(1);
        }

        //server关闭连接，不再阻塞
        if(len==0){
            perror("server closed");
            exit(1);
        }else{
            //正常接收到数据
            printf("recv buf:\n",buf);
        }
    }
    close(fd);
    return 0;
}

