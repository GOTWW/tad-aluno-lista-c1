CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
SRCDIR = src
OBJ = $(SRCDIR)/aluno.o $(SRCDIR)/main.o
TARGET = alunos

all: $(TARGET)

$(SRCDIR)/aluno.o: $(SRCDIR)/aluno.c $(SRCDIR)/aluno.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/aluno.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)
