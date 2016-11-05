/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estacionamento.c
 * Author: dev.marin
 *
 * Created on 9 de Setembro de 2016, 21:16
 */

#include <stdio.h>
#include <stdlib.h>

#define size 10

/*
 * 
 */
struct car {
    char placa[8];
    int manobras;
};

struct stack {
    int top, qtde;
    int itens[size];
};



int start(struct stack *s);
int empty(struct stack *s);
int full(struct stack *s);
void push(struct stack* s, char *pc);
char pop(struct stack* s);




int main(int argc, char** argv) {
    
    struct stack s;
    start(&s);
    
    push(&s, "HDL1234");
    printf("%s", s);
    
    system("pause");
    return 0;
}

int start(struct stack* s){
    s->top = -1;
    s->qtde = 0;
}

int empty(struct stack* s){
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int full(struct stack* s){
    if (s->top == size-1)
        return 1;
    else
        return 0;
}

int push(struct stack* s, int x){
    if (!full(s)){
        ++(s->top);
        s->itens[s->top] = x;
    }
    else
        return 0;
}

int pop(struct stack* s){
    if (empty(s)){
        return -1;
    }
    else
        return s->itens[--(s->top)];
}

//Função para comparar o valor do topo com o parametro inteiro passado
int topTest(struct stack* s, int var){
    if(s->top-1 == var)
        return 1;
    else
        return 0;
}

//Funcao que retorna a quantidade de elementos em uma pilha
int qtdItens(struct stack* s){
    int x;
    x = s->top-1;
    return x;
}

int stackCompare(struct stack* s1, struct stack* s2){
    int x = s1->top-1;
    int y = s2->top-1;
    if(x == y){
        
    } 
}





