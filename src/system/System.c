//
// Created by lipnegju on 2019-06-17.
//

#include <stdio.h>
#include <stdlib.h>

void testSystem() {
    int ls = system("ls -l");
    int pwd = system("pwd");
    int who =system("who");
    printf("sytem ls -l ls %d ,pwd %d,who %d ",ls,pwd,who);
}

#if 0
int main(){
    testSystem();
}
#endif