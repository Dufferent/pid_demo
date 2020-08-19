PRO_NAME=demo
OBJ =demo.o pid.o
CC  = g++
CC ?= arm-linux-gnueabihf-g++


$(PRO_NAME):$(OBJ)
	$(CC) -o $@ $^

%.o : %.cpp
	$(CC) -o $@ -c $<

clean:
	rm  -rf $(PRO_NAME) ./*.o ./*.so ./*.a

share:
	$(CC) -o pid.o  -c -O2 -fPIC -std=c++11 pid.cpp  
	$(CC) -o demo.o -c -O2 -fPIC -std=c++11 demo.cpp  
	$(CC) -shared -o libpid.so ./pid.o
	$(CC) -o $(PRO_NAME) demo.o -lpid
	
static:
	$(CC) -o pid.o  -c  pid.cpp
	$(CC) -o demo.o -c  demo.cpp  
	ar    -rcs libpid.a  pid.o 
	$(CC) -o $(PRO_NAME) demo.o -L./ -lpid


