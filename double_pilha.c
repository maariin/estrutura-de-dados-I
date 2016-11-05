/*
 * 3 - Pilhas: Reescrever as funções p/ manipulação de pilha para que o vetor., declarado na estrutura,
 * grade 2 pilhas.
 */

/* 
 * File:   main.c
 * Author: dev.marin
 *
 * Created on 15 de Setembro de 2016, 15:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * 
 */
#define size 4

struct pilha{
    int topo, topo2;
    int item[size];
};

void inicia(struct pilha *stack);
int vazia1(struct pilha *stack);
int vazia2(struct pilha *stack);
int cheia(struct pilha *stack);
int push1(struct pilha *stack, int x);
int push2(struct pilha *stack, int x);
int pop(struct pilha *stack);
int pop2(struct pilha *stack);



int main(){
    struct pilha stack;
    inicia(&stack);
    
    int k;
    
    push1(&stack, 10);
    push1(&stack, 20);
    push2(&stack, 40);
    push2(&stack, 30);
    push2(&stack, 50);
    
    
    /*for(k = 0; k < size; k++){
        printf("%d\n", stack.item[k]);
    }*/
    
    return(1);
}

void inicia(struct pilha *stack){
    stack->topo = -1;
    stack->topo2 = size;
}

int vazia1(struct pilha *stack){
    if(stack->topo == -1)
        return 1;
    else
        return 0;
}

int vazia2(struct pilha *stack){
    if(stack->topo2 == size)
        return 1;
    else
        return 0;
}

int cheia(struct pilha *stack){
    if(stack->topo+1 == stack->topo2)
        return 1;
    else
        return 0;
}

int push1(struct pilha *stack, int x){
    if(!cheia(stack)){
        stack->item[stack->topo+1] = x;
        stack->topo++;
        
    }
    else
        return printf("\npilha cheia...\n");
}

int push2(struct pilha *stack, int x){
    if(!cheia(stack)){
        stack->item[stack->topo2-1] = x;       
        stack->topo2--;
    }
    else
        return printf("pilha cheia...\n");
}

int pop(struct pilha *stack){
    return stack->item[stack->topo];
}

int pop2(struct pilha *stack){
    return stack->item[stack->topo2];
}


