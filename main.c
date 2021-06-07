#include <stdio.h>
#include <stdlib.h>
#define ESPACAMENTO_PADRAO 10

typedef struct NoduloDeArvore
{
    int dados;
    struct NoduloDeArvore *pai;
    struct NoduloDeArvore *esquerda;
    struct NoduloDeArvore *direita;
} nodulo;

nodulo *criarNodulo(int dados)
{
    nodulo *saida = (nodulo *)malloc(sizeof(nodulo));

    saida->dados = dados;
    saida->pai = NULL;
    saida->esquerda = NULL;
    saida->direita = NULL;

    return saida;
}

void inserirNoduloNaArvore(nodulo *raiz, nodulo *entradaDeDados)
{
    if (raiz == NULL)
    {
        raiz = entradaDeDados;
        return;
    }

    if (entradaDeDados->dados >= raiz->dados)
    {
        if (raiz->direita != NULL)
        {
            inserirNoduloNaArvore(raiz->direita, entradaDeDados);
        }
        else
        {
            raiz->direita = entradaDeDados;
            entradaDeDados->pai = raiz;
        }
    }
    else if (entradaDeDados->dados < raiz->dados)
    {
        if (raiz->esquerda != NULL)
        {
            inserirNoduloNaArvore(raiz->esquerda, entradaDeDados);
        }
        else
        {
            raiz->esquerda = entradaDeDados;
            entradaDeDados->pai = raiz;
        }
    }
}

void mostrarArvore(nodulo *root, int space)
{
    if (root == NULL)
        return;

    space += ESPACAMENTO_PADRAO;

    mostrarArvore(root->direita, space);

    printf("\n");
    for (int i = ESPACAMENTO_PADRAO; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->dados);

    mostrarArvore(root->esquerda, space);
}

int main(int argc, char const *argv[])
{
    nodulo *raiz = criarNodulo(10);
    inserirNoduloNaArvore(raiz, criarNodulo(5));
    inserirNoduloNaArvore(raiz, criarNodulo(4));
    inserirNoduloNaArvore(raiz, criarNodulo(6));
    inserirNoduloNaArvore(raiz, criarNodulo(15));
    inserirNoduloNaArvore(raiz, criarNodulo(14));
    inserirNoduloNaArvore(raiz, criarNodulo(16));

    mostrarArvore(raiz, 0);

    return 0;
}