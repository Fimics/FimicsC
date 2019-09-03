#get all .c file
srcFiles=$(wildcard *.c)
#all.c files->.o files
objectFiles=$(patsubst %.c,%.o,$(srcFiles))

all:app app1

#目标文件用法$(var)
app:$(objectFiles)
	gcc -o $@ -I./include $(objectFiles) -g

app1:$(objectFiles)
	gcc -o $@ -I./include $(objectFiles) -g

#模式匹配规则，$@,$<这样的变量只能在规则中出现
%.o:%.c
#	gcc -c $< -I ./include
	gcc -c $< -I ./include -o $@ -g
test:
	@echo $(srcFiles)
	@echo $(objectFiles)


#如果在src下 touch clean 再make clean 就不会反选了，解决方式如下
.PHONY:clean all  #clean是一个伪目标，只是makefile里有的

clean:
	#指令前加"-"的作用，当这第指令出错了会继续执行
	-@rm -f *.o
	#指令前加@ 就不会输出该指令，但会执行该指令
	@rm -f app apip1
