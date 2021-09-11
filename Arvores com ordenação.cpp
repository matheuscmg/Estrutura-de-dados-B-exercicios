#include <iostream>
using namespace std;

struct no
{
    int chave;
    struct no *esq, *dir;
};

int n;

void insere(int n, no **raiz)
{
    if ((*raiz) == NULL){
        (*raiz) = (no *)malloc(sizeof(no));
        (*raiz)->chave = n;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }
    else if (n < (*raiz)->chave)
        insere(n, &(*raiz)->esq);
    else if (n > (*raiz)->chave)
        insere(n, &(*raiz)->dir);
}

int busca(int n, no* raiz)
{
    if (raiz == NULL)
        return (0);
    else if (raiz->chave == n){
        cout <<"O elemento foi encontrado.\n\n";
        return (1);
    }
    else if (n < raiz->chave)
        return (busca(n, raiz->esq));
    else
        return (busca(n, raiz->dir));
}

void EmOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave;
        EmOrdem(raiz->dir);
    }
}
void preOrdem(no *raiz)
{
    if (raiz != NULL)
    { 
      cout << raiz->chave; 
      preOrdem(raiz->esq);      
      preOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz)
{
    if (raiz != NULL)
    {  
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        cout << raiz->chave;        
    }
}

int main()
{
    no *raiz = NULL;
    int opc;

    do
    {
    
    cout <<"\n--Ralize operacoes em Arvores--";    
    cout <<"\n1- Inserir Arvore...........";
    cout <<"\n2- Buscar Elemento em Arvore";
    cout <<"\n3- Listar em Ordem..........";
    cout <<"\n4- Listar em Pre Ordem......";
    cout <<"\n5- Listar em Pos Ordem......";
    cout <<"\n0- Para sair ...............\n";
    cout<<"\nDigite a sua opcao..........:";
    cin >> opc;       
        

        switch (opc)
        {
        case 1:
            cout << "\nInforme o valor a ser inserido:";
            cin >> n;
            insere(n, &raiz);
            break;
        case 2:
            cout << "\nInforme o valor a ser buscado:";
            cin >> n;
            busca(n, raiz);
            break;
        case 3:
            EmOrdem(raiz);
            break;
        case 4:
            preOrdem(raiz);
            break;
        
        case 5:
            posOrdem(raiz);
            break;
        }

    } while (opc != 0);
}