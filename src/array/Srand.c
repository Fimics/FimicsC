//
// Created by lipnegju on 2019-06-18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testRand(){

    srand((unsigned int)time(NULL));

    for (int i = 0; i <100 ; i++) {
        int randNum = rand()%10+50;
        printf("randNum is %d\n",randNum);

    }

}