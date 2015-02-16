CPPFLAGS= -I. -L. -lpthread  -DNODEBUG -DNOCPP11 -lz -Os -ggdb3 -fPIC

default: all

buffer:
	g++ -c buffer.cc ${CPPFLAGS}

compress:
	g++ -c compress.cc ${CPPFLAGS}

compress_function:
	g++ -c compress_function.cc ${CPPFLAGS}

put_header:
	g++ -c put_header.cc ${CPPFLAGS}

thread:
	g++ -c thread.cc ${CPPFLAGS}

thread_pool:
	g++ -c thread_pool.cc ${CPPFLAGS}

write_thread:
	g++ -c write_thread.cc ${CPPFLAGS}

lib: write_thread thread_pool thread put_header compress_function compress buffer
	g++ -shared -pipe -o libmtc.so buffer.o compress.o compress_function.o put_header.o thread.o thread_pool.o write_thread.o ${CPPFLAGS}
	strip libmtc.so

all: lib
	g++ myzlib.cc -o myzlib -lmtc ${CPPFLAGS}
	strip myzlib

clean:
	rm -rf a.out *.o myzlib *.so
