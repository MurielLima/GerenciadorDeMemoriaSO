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
    int i,pos=0,fre=0,aux=0,diferenca=0,diferencax=0;
    for(i=1;i<=N;i++){//vasculha o vetor
        if(vetor[i-1]==0)
            fre++;
        else{
            if(fre>=alloc){//diminui a quantidade de operações
                if(aux==0)//inicializa o aux na primeira vez em que é executado
                    aux=fre;
                diferenca=fre-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar
                diferencax=aux-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar da ultima resposta 
                if(diferenca<=diferencax){//se a diferença atual for menor significa que é melhor 
                    aux=fre;
                    pos=(i-1)-fre;
                }
            }
            fre=0;
        }
    }
    if(pos)
        return pos;
    else
        return -1;
}
int WorstF(int vetor[N],int alloc){
    int i,pos=0,fre=0,aux=0,diferenca=0,diferencax=0;
    for(i=1;i<=N;i++){//vasculha o vetor
        if(vetor[i-1]==0)
            fre++;
        else{
            if(fre>=alloc){//diminui a quantidade de operações
                if(aux==0)//inicializa o aux na primeira vez em que é executado
                    aux=fre;
                diferenca=fre-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar
                diferencax=aux-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar da ultima resposta 
                if(diferenca>diferencax){//se a diferença atual for menor significa que é melhor 
                    aux=fre;
                    pos=(i-1)-fre;
                }
            }
            fre=0;
        }
    }
    if(pos)
        return pos;
    else
        return -1;
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
            printf("(%i)[%i] \n",vetor[i],i);
        printf(")");    
        printf("\nInforme a quantidade de memoria a ser alocada: ");
        scanf("%i",&aloc);
        if(aloc>0){
            a=FirstF(vetor,aloc);
            if(a==-1){
                printf("Espaço não encontrado.\n");
            }else{
                printf("Espaço encontrado com inicio na posição %i!!\n",a);

            }
            a=BestF(vetor,aloc);
            if(a==-1){
                printf("Melhor espaço não encontrado.\n");
            }else{
                printf("Melhor espaço encontrado com inicio na posição %i!!\n",a);
            }
            a=WorstF(vetor,aloc);
            if(a==-1){
                printf("Pior espaço não encontrado.\n");
            }else{
                printf("Pior espaço encontrado com inicio na posição %i!!\n",a);
            }

        }else
            printf("Não é possível, tente outro numero.\n");

        printf("Deseja continuar? (1/0): ");
        scanf("%i",&i);
    }while(i!=0);
}