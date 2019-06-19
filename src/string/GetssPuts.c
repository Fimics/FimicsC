//
// Created by lipnegju on 2019-06-18.
//

#include <stdio.h>
#include <YString.h>
#include <stdlib.h>


/**
 * gets() 获取字符串
 * puts()
 * scanf()
 * getchar() 获取一个字符
 * 功能：从标准的输入读入字符，并保存到指定的内存空间，直到出现换行符，或读到文件结尾为止
 * 参数:s 字符串首地址
 *
 * gets(str)与scanf(str)的区别
 * 1.gets允许输入的字符串含有空格
 * 2.scanf不允许含有空格
 *
 * 由于sacnf()和gets()无法知道字符串s的大小，必须遇到换行或读到文件结尾才接
 * 收输入，因此容易导致字符串数组越界(缓存区溢出)的情况
 *
 * 返回值
 * 成功:非负数
 * 失败:-1
 */
void putsGets(){
  char s [1];
  gets(s);
  //scanf("%[^\n]",s);
  //输出一个字符串并换行
  //puts(s);

  char *p = gets(s);
  //同样可以接收
  printf("%s",p);
}
