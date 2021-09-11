#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

#define N 200000
long cont1=0,cont2=0,cont3=0;
long troca1=0,troca2=0,troca3=0;


void bubble(int o[]){

 int i,j,aux;
 float tempo;

 time_t inicio, atual;

 cout <<"Vetor criado";
 for(i=0;i<N;i++){
  o[i]=rand()%100;
 }
 inicio = time(NULL);

  for (i=0;i<(N-1);i++){
    for(j=(N-2);j>=i;j--)
    {
      cont1++;
      if(o[j] > o[j+1]){
        troca1++;
        aux=o[j];
        o[j]=o[j+1];
        o[j+1]=aux;
      }      
    } 
  }
  atual = time(NULL);
	tempo = difftime(atual, inicio);
 cout <<"\nTempo de execução:"<<tempo<<"s";
 cout << "\nQuantidade de comparações :"<< cont1;
 cout << "\nQuantidade de trocas:"<< troca1;
 
  
  }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void bubbleAle(int d[]){

int aux,i,j;
float tempo;

time_t inicio, atual;

cout <<"Vetor criado";
 for(i=0;i<N;i++){
  d[i]=i+1;//rand()%50;
 }
 inicio = time(NULL);

	for (i=0;i<(N-1);i++){
    cont2++;
    for(int j=(N-2);j>=i;j--)
		{			
			if (d[j] > d[j+1])
			{
				troca2++;
				aux = d[j];
				d[j] = d[j+1];
				d[j+1] = aux;
       }
     }
  }
  atual = time(NULL);
	tempo = difftime(atual, inicio);
  cout <<"\nTempo de execução:"<<tempo<<"s";
  cout << "\nQuantidade de comparações :"<< cont2;
  cout << "\nQuantidade de trocas:"<< troca2;
}
void bubbleinverse(int inv[]){

int aux,i,j;
float tempo;

time_t inicio, atual;

   cout <<"Vetor criado";
   for(i=0;i<N;i++){
    inv[i]=N-i;//rand()%50;
        }
        inicio = time(NULL);

  for (i=0;i<(N-1);i++){
    for(j=(N-2);j>=1;j--){
      cont3 ++;
       if (inv[j] > inv[j + 1])
			{
				troca3++;
				aux = inv[j];
				inv[j] = inv[j + 1];
				inv[j + 1] = aux;
			}
    }
  }
  atual = time(NULL);
	tempo = difftime(atual, inicio);
 cout <<"\nTempo de execução:"<<tempo<<"s";
 cout << "\nQuantidade de comparações :"<< cont3;
 cout << "\nQuantidade de trocas:"<< troca3;
}

int main() {

int opc,o[N],a[N],inv[N];
  
  do{
  cout <<"\n\nOrdenacao com Bubble";
  cout <<"\n1 para Vetor previamente ordenado";
  cout <<"\n2 para Vetor preenchido com números aleatórios";
  cout <<"\n3 para Vetor inversamente ordenado ";
  cout <<"\n4 para sair do programa ";
  cout <<"\nDigite sua opcao:";
  cin >> opc;
  cout <<"\n\n\n";


  switch(opc){

  case 1: bubble(o);
  break;
  case 2: bubbleAle(a);
  break;
  case 3: bubbleinverse(inv);
  break;
  }
  }while(opc!=4);
  

}