#include <iostream>
#include <time.h>
using namespace std;
#define N 200000

long   menor, trocar = 0, comp = 0, troca, time1=0;

void select(int v[])
{
    trocar = 0, comp = 0, time1 = 0;
    time_t inicio = time(NULL), atual;
    int i,j;
    cout<<"Realizando ordenacao...";
    for (i=0; i<(N-1); i++)
    {
        menor = i;
    for (j=(i+1); j<N; j++)
    {
     comp++;
     if (v[j] < v[menor])
      menor = j;
    }
    if (menor!=i)
    {
       trocar++;
       troca = v[i];
       v[i] = v[menor];
       v[menor] = troca;
    }
         
    }
    atual = time(NULL), time1 = difftime(atual, inicio);
    cout << "\n Tempo total: " << time1<< "s";
    cout << "\n Numero de trocas : " << trocar;
    cout << "\n Numero de comparacoes: " << comp;
}
  


int main()
{
    int v[N], opc,i;

    do
    {   
        cout << "\n 1- Para vetor ordenado :";
        cout << "\n 2- Para vetor aleatorio :";
        cout << "\n 3- Para vetor inversamente ordenado :";
        cout << "\n Qual ordenacao deja fazer:";
        cin >> opc;

        if(opc==1)
        {
        for (int i = 0; i < N; i++)
                v[i]=i+1;
        }
        if(opc==2)
        {
        for(i=0;i<N;i++)
          v[i]=rand()%100;
        }
        if(opc==3)
         {
           for (int i = 0; i < N; i++)
                v[i] = N - i + 1;
        }    
           

        switch (opc)
        {
        case 1:            
            select(v);
            break;

        case 2:            
            select(v);
            break;
        case 3:            
            select(v);
            break;        
        }
    } while (opc != 0);
}