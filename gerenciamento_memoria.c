//Disciplina de Algoritmos e Programação
//Criado por:  Muriel José Lima
//
//O programa tem a função de simulador um gerenciador de memória
//
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 50
int FirstF(int vetor[N],int alloc){//funçao first fit  localiza o primeiro espaço com o tamanho da alocação e feito
    int i,pos,fre=0;
    for(i=1;i<=N;i++)//vasculha o vetor
        if(vetor[i-1]==0){
            fre++;
            if(alloc==fre){//o espaço encontrado é o certo
                pos=i-alloc;//i iniciou com 1 para o caso do espaço ser 1, ficaria (0-1)=-1 
                return pos;
            }
        }else
                fre=0;
    return -1;
}
int BestF(int vetor[N],int alloc){
    int i,pos,fre=0,aux;
    for(i=1;i<=N;i++)//vasculha o vetor
        if(vetor[i-1]==0)
            fre++;
        else{

            aux=fre;
            fre=0;
        }
}
int main(){
    int vetor[N];
    int i,aloc,a;
    srand(time(NULL));
    for(i=0;i<N;i++)
        vetor[i]=rand() % 2; 
    do{
        printf("(");
        for(i=0;i<N;i++)
            printf("[%i] ",vetor[i]);
        printf(")");    
        printf("\nInforme a quantidade de memoria a ser alocada: ");
        scanf("%i",&aloc);
        a=FirstF(vetor,aloc);
        if(a==-1){
            printf("Espaço não encontrado.\n");
        }else{
            printf("Espaço encontrado com inicio na posição %i!!\n",a);

        }
        printf("Deseja continuar? (1/0): ");
        scanf("%i",&i);
    }while(i!=0);
}