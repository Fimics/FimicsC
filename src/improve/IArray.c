//
// Created by pengju.li on 2019-07-12.
//

//连续的内存空间都是数组

#include <stddef.h>

void printArray3(int * p, int len){

    for (int i = 0; i <len ; ++i) {
        printf("%d ,",p[i]);//当数组处理
//        printf("--%d\n",*(p+i));//当指针处理
    }

}

void testArrayName(){
    /**
     * 1.数组名是指向首元素的指针，但以下两种情况除外，以下两种情况，数组名是数组类型arr+1 1的步长是数组的整个长度
     *   1.1 sizeof
     *   1.2 对数组名取地址 &arr
     */
    int arr []={1,2,3,4,5,6};
    printf("sizeof arr%d\n", sizeof(arr));
    printf(" &arr %ld &arr+1 %ld\n",&arr,&arr+1);

    int *p =arr;

    //数组名是一个常量指针
    //arr=NULL;
    printArray3(arr, sizeof(arr)/ sizeof(int));

    //数组下标能否是负数
    p+=3;
    printf(" p[-1] %d\n",p[-1]);//等价于 printf(" p[-1] %d\n",*(p-1));

}

/**
 * 如何定义一个指向数组的指针
 */
void testPointerArray(){

    int arr[]={1,2,3,4,5};

    //1.先定义数组类型，再定义数组指针类型
    typedef  int (ARRAY_TYPE)[5]; //typedef unsigned int u32
    ARRAY_TYPE myarray;//==int myarray[5]

    for (int i = 0; i <5 ; ++i) {
        myarray[i]=i;
        printf("index %d value %d\n",i,myarray[i]);
    }

    //对数组取地址代表指向整个数组的指针
    ARRAY_TYPE * p =&myarray;
    //p=&arr;

    printf("-----------------------\n");
    //1.*p 表示拿到p指针指向的整个数组的指针
    //2.*p 类型就是数组名--，指向首元素类型的指针
    for (int j = 0; j <5 ; ++j) {
      printf("%d\n",*(*p+j));
    }

    //2.直接定义数组指针类型
    typedef int (* ARRAY_POINTER)[5];
    ARRAY_POINTER parr= &arr;

    printf("-----------------------\n");
    for (int k = 0; k < 5; ++k) {
        printf("index %d value %d\n",k,*(*parr+k));
    }


    //3.直接定义数组指针变量
    int(* parr1)[5]=&arr;

    printf("-----------------------\n");
    for (int k = 0; k < 5; ++k) {
        printf("index %d value %d\n",k,*(*parr1+k));
    }

}

void printTwoDimensArray(int(*arr)[3],int line,int row){
    for (int i = 0; i <line ; i++) {
        for (int j = 0; j <row ; j++) {
//            printf(" line: %d row :%d value: %d\n",i,j ,*(*(arr+i)+j));
            printf(" line: %d row :%d value: %d\n",i,j ,arr[i][j]);
        }
    }
}

/**
 * 二维数组
 */
void twoDimensionalArray(){

      //1.定义
      int arr[3][3]={
              {1,2,3},
              {4,5,6},
              {7,8,9}
      };

     // printf("2-1  %d\n",*(*(arr+2)+1));

     /**
      * arr 二维数组元素首地址
      * arr+2 ,第三个{7,8,9} 一维数组
      * *(arr+2) 第三个一维数组的指针
      * *(*(arr+2)+1),第三个数组，第二个元素
      *
      */

     printTwoDimensArray(arr,3,3);

//      int arr1[3][3]={1,2,3,4,5,6,7,8,9};
//      int arr1[][3]={1,2,3,4,5,6,7,8,9};

      //2.对于二维数组和一维数组一样，除了 1.sizeof 2.对数组名取地址之外，那么数组名就是指向数组首元素的指针
}

void selectSort(int * arr,int len){

    int min=0;

    for (int i = 0; i <len-1 ; i++) {
        for (int j = i+1; j <len ; j++) {
            if(arr[j]<arr[min]){
                min = j;
                printf("min %d\n",min);
            }
        }

        if(arr[i]>arr[min]){
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

}

void iArray(){
  //testArrayName();
//  testPointerArray();
//    testPointerArray();
//twoDimensionalArray();

 int arr[]={7,2,8,9,4,5,0,1};//
 int len = sizeof(arr)/ sizeof(int);
 selectSort(arr,len);
 printArray3(arr,len);

}