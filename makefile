CC = gcc
CFLAGS = -Wall
all:
	$(CC) $(CFLAGS) main.c -o main
	ar rv libfuncs.a main *.txt new_2018_ese.csv.0

main.c: funnel_a2.c printinfo.c gpa.c printGrades.c
	
clean:
	rm -f main libfuncs.a
