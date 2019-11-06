CC=g++ 
#编译器
bin=Boyfriend 
#生成的可执行文件
src=Boyfriend.cc 
#依赖的源文件
INCLUDE=-Ispeech/
LIB=-ljsoncpp  -lcurl -lcrypto -lpthread

$(bin):$(src)
 #生成bin，依赖的src
	$(CC) -o $@ $^ $(INCLUDE) $(LIB)
#方法
.PHONY:clean
clean:
	rm -f $(bin)
