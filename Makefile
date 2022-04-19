# Makefile includes all the files for the 
# main file to compile in the CC or GCC. 
# it defines a set of tasks to execute, organizing the code
 
CC=gcc

all: main 

main: course.o student.o

course.o: student.o

clean:
	rm -f -r *.o main

