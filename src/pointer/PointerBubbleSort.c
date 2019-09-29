//
// Created by lipnegju on 2019-06-23.
//

#include <printf.h>

void bubbleSort(int *p,int len){

    for (int i = 0; i <len-1 ; i++) {
        for (int j = 0; j <len-1-i ; j++) {
            if(*(p+j)<*(p+j+1)){
                int temp = *(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }

}

void pointerBubbleSort(){

    int arr[10]={5,9,3,4,2,6,7,8,4,10};
    //数组名与指针的区别:数组名通过sizeof可以求出数组大小，指针只包含数组首地址信息
    int *p =arr;
    printf("psize %d\n", sizeof(p));
    printf("arrSize %d\n", sizeof(arr));

    int len = sizeof(arr)/ sizeof(arr[0]);
    bubbleSort(arr,len);

    for(int i=0;i<10;i++){
        printf("%d\n",arr[i]);
    }
}

#if 0
int main(){
    pointerBubbleSort();
}
#endif