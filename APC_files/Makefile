CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-parameter -std=c11
OBJ = main.o lists.o operations.o

main.exe : $(OBJ)
	$(CC) $(OBJ) -o main.exe

main.o : main.c calc.h
	$(CC) $(CFLAGS) -c main.c

lists.o : lists.c calc.h
	$(CC) $(CFLAGS) -c lists.c

operations.o : operations.c calc.h
	$(CC) $(CFLAGS) -c operations.c

clean:
	del /Q main.exe $(OBJ)