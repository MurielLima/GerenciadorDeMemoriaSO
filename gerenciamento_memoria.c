//Disciplina de Algoritmos e Programação
//Criado por:  Muriel José Lima
//
//O programa tem a função de simulador um gerenciador de memória
//
//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 1000
int FirstF(int vetor[N],int alloc){//funçao first fit  localiza o primeiro espaço com o tamanho da alocação e feito
    int i,pos,fre=0;
    for(i=0;i<N;i++)//vasculha o vetor
        if(vetor[i]==0){
            fre++;
            if(alloc==fre){//o espaço encontrado é o certo
                pos=(i-fre)+1;
                return pos;
            }
        }else
            fre=0;
    return -1;
}
int BestF(int vetor[N],int alloc){
    int i,unico,pos=0,fre=0,aux=0,diferenca;
    for(i=0;i<=N;++i){//vasculha o vetor ate N
        if(vetor[i]==0 && i!=N)//Conta N como 1 para fazer a mesma operacao com os ultimos valores
            fre++;
        else{
            if(fre!=0){//diminui operacoes
                if(fre==alloc && unico!=1){//var "unico" utilizado para pegar o primeiro espaco fre==alloc
                    pos=i-fre;
                    unico=1;
                }else{
                    if(fre>alloc){
                        diferenca=fre-alloc;
                        if(aux==0){//pega a primeira vez e deixa como valor para a comparação
                            aux=diferenca;
                            pos=(i-fre);
                        }else{
                            if(diferenca<aux){
                                aux=diferenca;
                                pos=(i-fre);
                            }
                        }
                    }
                }
                fre=0;
            }
        }
            
    }

    if(pos)
        return pos;
    else
        return -1;
}

int WorstF(int vetor[N],int alloc){
    int i,pos=0,fre=0,aux=0,diferenca=0,diferencax=0;
    for(i=0;i<=N;i++){//vasculha o vetor
        if(vetor[i]==0 && i!=N)
            fre++;
        else{
            if(fre>=alloc){//diminui a quantidade de operações
                diferenca=fre-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar
                diferencax=aux-alloc;//diferença entre a quantidade de zeros e o numero pedido para alocar da ultima resposta 
                if(aux==0){//inicializa o aux na primeira vez em que é executado
                    aux=fre;
                    pos=(i-fre);
                }
                if(diferenca>diferencax){//se a diferença atual for MAIOR significa que é PIOR 
                    aux=fre;
                    pos=(i-fre);
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
            printf("(%i) ",vetor[i]);
        printf(")");    
        printf("\nInforme a quantidade de memoria a ser alocada: ");
        scanf("%i",&aloc);
        if(aloc>0){
            a=FirstF(vetor,aloc);
            if(a==-1){
                printf("Primeiro espaço não encontrado.\n");
            }else{
                printf("Primeiro espaço encontrado com inicio na posição %i!!\n",a);

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