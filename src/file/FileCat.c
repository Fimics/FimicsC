//
// Created by lipnegju on 2019-06-30.
//


#include <stdio.h>

void fileCat(){

    char fileName[256];
    printf("请输入您查看的文件：\n");
    scanf("%s", fileName);
    getchar();

    FILE * fp = fopen(fileName, "r");
    if (!fp)
        return ;
    //文件的结束标志  EOF -1
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);


    fclose(fp);

}

#if 0
int main(){
    fileCat();
}

#endif