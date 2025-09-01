#include <stdio.h>
#include <string.h>
#include "aluno.h"

int main() {
    Lista *l = lista_criar(4);

    Aluno a1 = {1, "Maria", 7.5};
    Aluno a2 = {2, "João", 8.0};
    Aluno a3 = {3, "Ana", 9.2};

    lista_inserir(l, a1);
    lista_inserir(l, a2);
    lista_inserir(l, a3);

    printf("\n--- Lista de alunos ---\n");
    lista_imprimir(l);

    printf("\nAlterando nota do aluno 2...\n");
    lista_alterar_nota(l, 2, 9.0);
    lista_imprimir(l);

    printf("\nRemovendo aluno 1...\n");
    lista_remover(l, 1);
    lista_imprimir(l);

    Aluno *achado = lista_buscar(l, 3);
    if (achado)
        printf("\nAluno encontrado: %s com nota %.2f\n", achado->nome, achado->nota);

    lista_destruir(l);
    return 0;
}
