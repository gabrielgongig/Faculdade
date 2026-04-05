#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;            // valor armazenado
    int alt;             // altura
    struct NO *esquerda; // filho esquerdo
    struct NO *direita;  // filho direito
} typedef NO;

int altNO(NO *no)
{ // retorna a altura da subárvore que tem o no como raiz
    if (no == NULL)
    {
        return (-1);
    }
    else
    {
        return no->alt;
    }
}

int fatorBalanceamento_NO(struct NO *no)
{ // retorna o fator de fator de balanceamento da subárvore que tem o no como raiz
    return labs(altNO(no->esquerda) - altNO(no->direita));
}

int maior(int x, int y)
{ // recebe dois valores e retorna o maior dentre eles. Usado para
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

NO *RotacaoDir(NO *raiz)
{
    NO *no = raiz->esquerda;
    raiz->esquerda = no->direita;
    no->direita = raiz;

    raiz->alt = maior(altNO(raiz->esquerda), altNO(raiz->direita)) + 1;
    no->alt = maior(altNO(no->esquerda), raiz->alt) + 1;

    return no; // nova raiz da subárvore
}

NO *RotacaoEsq(NO *raiz)
{
    NO *no = raiz->direita;
    raiz->direita = no->esquerda;
    no->esquerda = raiz;

    raiz->alt = maior(altNO((raiz)->esquerda), altNO(raiz->direita)) + 1;
    no->alt = maior(altNO(no->direita), raiz->alt) + 1;

    return no; // nova raiz da subárvore
}

NO *RotacaoDEsq(NO *raiz)
{
    raiz = RotacaoEsq(raiz->esquerda);
    raiz = RotacaoDir(raiz);
    return raiz; // nova raiz da subárvore
}

NO *RotacaoDDir(NO *raiz)
{
    raiz = RotacaoDir(raiz->direita);
    raiz = RotacaoEsq(raiz);
    return raiz; // nova raiz da subárvore
}

NO *insere_ArvAVL(NO *raiz, int valor)
{
    if (raiz == NULL)
    {
        NO *novo = (NO *)malloc(sizeof(NO));

        novo->info = valor;
        novo->alt = 0;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (valor < raiz->info)
    {
        raiz->esquerda = insere_ArvAVL(raiz->esquerda, valor);
        if (fatorBalanceamento_NO(raiz) >= 2)
        {
            if (valor < raiz->esquerda->info)
                raiz = RotacaoDir(raiz);
            else
                raiz = RotacaoDDir(raiz);
        }
    }
    else if (valor > raiz->info)
    {
        raiz->direita = insere_ArvAVL(raiz->direita, valor);
        if (fatorBalanceamento_NO(raiz) >= 2)
        {
            if (valor > raiz->direita->info)
                raiz = RotacaoEsq(raiz);
            else
                raiz = RotacaoDEsq(raiz);
        }
    }
    else
    {
        printf("Valor duplicado!!\n");
        return raiz;
    }

    raiz->alt = maior(altNO(raiz->esquerda), altNO(raiz->direita)) + 1;
    return raiz;
}

struct NO *procuraMenor(struct NO *atual)
{
    struct NO *no1 = atual;
    struct NO *no2 = atual->esquerda;
    while (no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esquerda;
    }
    return no1;
}

NO *remove_ArvAVL(NO *raiz, int valor)
{
    if (raiz == NULL)
    {
        printf("Valor não existe!!\n");
        return NULL;
    }

    if (valor < raiz->info)
    {
        raiz->esquerda = remove_ArvAVL(raiz->esquerda, valor);
        if (fatorBalanceamento_NO(raiz) >= 2)
        {
            if (altNO(raiz->direita->esquerda) <= altNO(raiz->direita->direita))
                raiz = RotacaoEsq(raiz);
            else
                raiz = RotacaoDEsq(raiz);
        }
    }
    else if (valor > raiz->info)
    {
        raiz->direita = remove_ArvAVL(raiz->direita, valor);
        if (fatorBalanceamento_NO(raiz) >= 2)
        {
            if (altNO(raiz->esquerda->direita) <= altNO(raiz->esquerda->esquerda))
                raiz = RotacaoDir(raiz);
            else
                raiz = RotacaoDDir(raiz);
        }
    }
    else
    { // valor == raiz->info
        if (raiz->esquerda == NULL || raiz->direita == NULL)
        {
            NO *oldNode = raiz;
            if (raiz->esquerda != NULL)
                raiz = raiz->esquerda;
            else
                raiz = raiz->direita;
            free(oldNode);
        }
        else
        {
            NO *temp = procuraMenor(raiz->direita);
            raiz->info = temp->info;
            raiz->direita = remove_ArvAVL(raiz->direita, temp->info);
            if (fatorBalanceamento_NO(raiz) >= 2)
            {
                if (altNO(raiz->esquerda->direita) <= altNO(raiz->esquerda->esquerda))
                    raiz = RotacaoDir(raiz);
                else
                    raiz = RotacaoDDir(raiz);
            }
        }
    }

    if (raiz != NULL)
        raiz->alt = maior(altNO(raiz->esquerda), altNO(raiz->direita)) + 1;

    return raiz;
}

NO *Buscar(NO *raiz, int chave)
{
    NO *aux = raiz;
    while (aux != NULL && aux->info != chave)
    {
        if (chave < aux->info)
        {
            aux = aux->esquerda;
        }
        else
        {
            aux = aux->direita;
        }
    }
    return aux;
}

void emOrdem_ArvAVL(NO *raiz)
{
    if (raiz == NULL)
        return;
    if (raiz != NULL)
    {
        emOrdem_ArvAVL(raiz->esquerda);
        printf("No %d: H(%d) fb(%d)\n", raiz->info, altNO(raiz), fatorBalanceamento_NO(raiz));
        emOrdem_ArvAVL(raiz->direita);
    }
}

int main()
{
    NO *avl = NULL;
    int dados[10], opcao = 38;

    while (opcao != 0)
    {
        printf("0 - Sair\n1 - Inserir\n2 - Remover\n3 - Buscar\n4 - Imprimir");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            int novo;
            printf("Escreva o novo valor\n");
            scanf("%d", &novo);
            avl = insere_ArvAVL(avl, novo);
            break;
        }
        case 2:
        {
            int chave;
            printf("Escreva o valor a ser removido\n");
            scanf("%d", &chave);
            avl = remove_ArvAVL(avl, chave);
            break;
        }
        case 3:
        {
            int buscado;
            printf("Escreva o valor a buscar\n");
            scanf("%d", &buscado);
            NO *resposta = Buscar(avl, buscado);
            if (resposta != NULL)
            {
                printf("No %d: H(%d) fb(%d)\n", resposta->info, altNO(resposta), fatorBalanceamento_NO(resposta));
            }
            else
            {
                printf("O valor consultado não pertence a arvore\n");
            }
            break;
        }
        case 4:
        {
            emOrdem_ArvAVL(avl);
            break;
        }
        }
    }
}