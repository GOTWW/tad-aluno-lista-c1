#ifndef ALUNO_H
#define ALUNO_H

#include <stdbool.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

typedef struct {
    Aluno *dados;
    int tamanho;
    int capacidade;
} Lista;

Lista* lista_criar(int capacidade);
void lista_destruir(Lista *l);

bool lista_inserir(Lista *l, Aluno a);
void lista_imprimir(const Lista *l);
bool lista_alterar_nota(Lista *l, int matricula, float nova_nota);
bool lista_remover(Lista *l, int matricula);
Aluno* lista_buscar(Lista *l, int matricula);

#endif
