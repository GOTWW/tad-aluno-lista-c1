#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP_INICIAL 4

Lista* lista_criar(int capacidade) {
    if (capacidade <= 0) capacidade = CAP_INICIAL;
    Lista *l = malloc(sizeof(Lista));
    if (!l) return NULL;
    l->dados = malloc(sizeof(Aluno) * capacidade);
    if (!l->dados) { free(l); return NULL; }
    l->tamanho = 0;
    l->capacidade = capacidade;
    return l;
}

void lista_destruir(Lista *l) {
    if (!l) return;
    free(l->dados);
    free(l);
}

static bool lista_expandir(Lista *l) {
    int nova = l->capacidade * 2;
    Aluno *tmp = realloc(l->dados, sizeof(Aluno) * nova);
    if (!tmp) return false;
    l->dados = tmp;
    l->capacidade = nova;
    return true;
}

bool lista_inserir(Lista *l, Aluno a) {
    if (!l) return false;
    if (l->tamanho == l->capacidade)
        if (!lista_expandir(l)) return false;
    l->dados[l->tamanho++] = a;
    return true;
}

void lista_imprimir(const Lista *l) {
    if (!l || l->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        printf("Matricula: %d | Nome: %s | Nota: %.2f\n",
               l->dados[i].matricula, l->dados[i].nome, l->dados[i].nota);
    }
}

bool lista_alterar_nota(Lista *l, int matricula, float nova_nota) {
    if (!l) return false;
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i].matricula == matricula) {
            l->dados[i].nota = nova_nota;
            return true;
        }
    }
    return false;
}

bool lista_remover(Lista *l, int matricula) {
    if (!l) return false;
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i].matricula == matricula) {
            for (int j = i; j < l->tamanho - 1; j++)
                l->dados[j] = l->dados[j+1];
            l->tamanho--;
            return true;
        }
    }
    return false;
}

Aluno* lista_buscar(Lista *l, int matricula) {
    if (!l) return NULL;
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i].matricula == matricula)
            return &l->dados[i];
    }
    return NULL;
}
