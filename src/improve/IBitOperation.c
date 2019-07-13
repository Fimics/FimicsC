//
// Created by lipnegju on 2019-07-13.
//

/**
 * float不能进行位运算不能，只适用shot long int char
 * 1.按位取反 ~
 * 2.位与(AND) &
 * 3.位或（OR）|
 * 4.位异或 ^
 *
 * 5.左移 <<
 * 6.右移 >>
 */

void testOperation(){

    //1.按位取反 ~
    int number=2;//010 101 负数使用补码存储110+1 ,111 -3
    printf("~number：%d\n",~number);


    //2.位与 &  可以把指定位置设置成0

    int a =1;//011  &1判断奇数偶数
    int b =6;//101
    printf("a & b %d\n",a&b);


    //3.位或，可以把指定位置，设置成1
    int c =5;
    int d =3;
    printf("c | d %d\n",c|d);


    //4.位异或  两个位上的一样都是0，不一样的为1

    int e =5; //101
    int f =3; //011  ->110
    printf("e | f %d\n",e^f);

    //5.左移
    int j =1;
    printf("j %d\n",j<<2);

    //6.右移
    int k=8;
    printf("k %d\n",k>>2);

}

void iBitOperation(){
     testOperation();
}