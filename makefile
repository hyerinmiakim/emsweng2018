.PHONY: clean

libmyfuncs.so libmyfuncs.so.1: libmyfuncs.so.1.0
        ln -s libmyfuncs.so.1.0 libmyfuncs.so.1
        ln -s libmyfuncs.so.1.0 libmyfuncs.so

libmyfuncs.so.1.0: func1.o func2.o
        #gcc -fPIC -shared -Wl,-soname=libmyfuncs.so.1 *.o -o   \
        #libmyfuncs.so.1.0 -lc
        ld -shared -soname=libmyfuncs.so.1 *.o -o libmyfuncs.so.1.0 -lc

func1.o: func1.c
        gcc -fPIC -c -I../include func1.c

func2.o: func2.c
        gcc -fPIC -c -I../include func2.c


clean:
        rm *.o libmyfuncs.*


