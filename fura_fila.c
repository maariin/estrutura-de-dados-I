/*
 * 2- Criar uma função denominada de furaFila p/ inserir um elemento no inicio da fila.
 */

/* 
 * File:   main.c
 * Author: dev.marin
 *
 * Created on 15 de Setembro de 2016, 14:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * 
 */
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
int furaFila(struct fila *pf, int x);

int main(int argc, char** argv) {
    int i;
    struct fila fila;
    inicializa(&fila);
    
    insere(&fila, 10);
    insere(&fila, 20);
    insere(&fila, 30);
    furaFila(&fila, 40);
    
    for(i = 0; i < fila.count; i++){
        printf("%d\n", fila.item[i]);
    }
    
    return (EXIT_SUCCESS);
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

int furaFila(struct fila *pf, int x){
    int k;
    if(!vazia(pf)){
        for(k = pf->count-1; k >= 0; k--){
            pf->item[k+1] = pf->item[k];        
        }
    }
    pf->item[0] = x;
    pf->count++;
    return 1;
}