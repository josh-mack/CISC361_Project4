# choose your compiler
CC=gcc
#CC=gcc -Wall

testT: ud_thread.c ud_thread.h
	$(CC) -g ud_thread.c -o testT -pthread


clean:
	rm -rf ud_thread.o testT

