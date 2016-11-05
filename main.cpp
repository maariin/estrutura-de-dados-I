/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marin
 *
 * Created on 25 de Outubro de 2016, 21:13
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

struct lista{
  int info;
  struct lista *proximo;
};

struct lista* insereInicio(struct lista* inicio, int x){
  struct lista *aux;
  aux = (struct lista*)malloc(sizeof(struct lista));
  aux->info = x;
  aux->proximo = inicio;
  inicio = aux;
  return inicio;
}

struct lista* removeInicio(struct lista* inicio){
  struct lista *aux;
  aux = inicio;
  inicio = inicio->proximo;
  free(aux);
  return inicio;
}

void insereDepois(struct lista *p, int x){
  struct lista *aux;
  aux=(struct lista*)malloc(sizeof(struct lista));
  aux->info = x;
  aux->proximo = p->proximo;
  p->proximo = aux;
}

void removeDepois(struct lista *p){
  struct lista *aux;
  aux = p->proximo;
  p->proximo = aux->proximo;
  free(aux);
}

void percorreLista(struct lista* inicio){
  struct lista *p;
  p = inicio;
  while(p != NULL){
    printf("\n%d", p->info);
    p = p->proximo;
  }
  getchar();
}

struct lista* insereOrdenado(struct lista* inicio, int x){
  struct lista *p, *q;
  p = inicio;
  if((p == NULL) || (x < p->info)){
    inicio = insereInicio(inicio, x);
    return inicio;
  }
  q = p; //q = inicio
  while((q != NULL) && (q->info < x)){
    p = q;
    q = p->proximo;
  }
  if((q == NULL) || (q->info > x))
    insereDepois(p, x);
  else
    printf("\nElemento já existe!!");
  
  return inicio;
}

struct lista* removeOrdenado(struct lista* inicio, int x){
  struct lista *p, *q;
  p = inicio;
  if(p == NULL){
    printf("Lista vazia!");
    getchar();
    return inicio;
  }
  if(x == p->info){
    inicio = removeInicio(inicio);
    return inicio;
  }
  q = p;
  while(q != NULL &&q->info < x){
    p = q;
    q = p->proximo;
  }
  if(q != NULL && q->info == x)
    removeDepois(p);
  else{
    printf("\nElemento não cadastrado!");
    getchar();
  }   
  return inicio;
}


main(){
  struct lista *inicio = NULL;
  inicio = insereOrdenado(inicio,10);
  inicio = insereOrdenado(inicio, 5);
  inicio = insereOrdenado(inicio, 20);
  
  percorreLista(inicio);
  removeOrdenado(inicio, 10);
  percorreLista(inicio);
}