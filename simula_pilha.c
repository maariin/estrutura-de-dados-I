/*
 Exercicio: 
 * 1- Simular uma pilha, usando fila.(remover o ultimo elemento da fila ao invés do primeiro.
 * 2- Criar uma função denominada de furaFila p/ inserir um elemento no inicio da fila.
 * 3 - Pilhas: Reescrever as funções p/ manipulação de pilha para que o vetor., declarado na estrutura,
 * grade 2 pilhas.
 */

/* 
 * File:   main.c
 * Author: dev.marin
 *
 * Created on 13 de Setembro de 2016, 20:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 6

struct fila{
    int init, end, count;
    int item[SIZE];
};
void inicializa(struct fila *pf);
int vazia(struct fila *pf);
int cheia(struct fila *pf);
void insere(struct fila *pf, int x);
int delete(struct fila *pf);
void filaPush(struct fila *pf, int x);
int filaPop(struct fila *pf);


int main(int argc, char** argv) {
    struct fila fila;
    inicializa(&fila);
    int var, i = 0;
    struct fila aux;
    inicializa(&aux);
    
    filaPush(&fila, 10);
    filaPush(&fila, 20);
    filaPush(&fila, 30);
    filaPush(&fila, 40);
    filaPush(&fila, 50);
    printf("%d\n",filaPop(&fila));
    /*for(i = 0; i < fila.count; i++){
        printf("%d\n", fila.item[i]);
    }*/
    return 0;
}

void inicializa(struct fila *pf){
    pf->end = SIZE-1; //5
    pf->init = 0;
    pf->count = 0;
}

int vazia(struct fila *pf){
    if(pf->count == 0)
        return 1;
    else
        return 0;
}

int cheia(struct fila *pf){
    if(pf->count == SIZE-1)
        return 1;
    else
        return 0;
}

void insere(struct fila *pf, int x){
    if(!cheia(pf)){
        pf->count += 1;
        if(pf->end == SIZE-1){
            pf->end = 0;
        }
        else{ pf->end += 1; }
        
        pf->item[pf->end] = x;
    }
    else { printf("fila cheia...\n"); }
    return;    
}

int delete(struct fila *pf){
    int x;
    if(!vazia(pf)){        
        if(pf->init == SIZE-1){
            pf->init = 0;
        }
        x = pf->item[pf->init];        
        pf->init += 1;
        pf->count -= 1;
        
    }
    else{
        //printf("fila vazia..");
        return -1;
    }        
    return x;
}

void filaPush(struct fila *pf, int x){
    insere(pf, x);
    return;
}

int filaPop(struct fila *pf){
    int var, x, c = 0;
    struct fila aux;
    inicializa(&aux);
    
    while(!vazia(pf)){
        x = delete(pf);
        if(vazia(pf)){
            var = x;
        }
        else{    
            insere(&aux, x);
        }
    }

    /*while(!vazia(&aux)){
        insere(pf, delete(&aux));
    }*/
    return var;
}