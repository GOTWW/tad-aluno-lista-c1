CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
OBJ = aluno.o main.o
TARGET = alunos

all: $(TARGET)

aluno.o: aluno.c aluno.h
	$(CC) $(CFLAGS) -c aluno.c -o aluno.o

main.o: main.c aluno.h
	$(CC) $(CFLAGS) -c main.c -o main.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
