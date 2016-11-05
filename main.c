/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marin
 *
 * Created on 1 de Novembro de 2016, 10:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista* inicio = NULL;

struct professor{
  int codigo;
  char nome [50];
};

struct curso{
  int codigo;
  char nome[30];
  struct professor professor;
};

struct aluno{
  int matricula;
  char nome[50];
  struct curso curso;
};

struct lista{
  struct aluno aluno;
  struct lista* proximo;
};

struct curso criaCurso(int cod, char nome[50], struct professor prof){
  struct curso curso;
  curso.codigo = cod;
  curso.professor = prof;
  strcpy(curso.nome, nome);
  return curso;
}

struct aluno criaAluno(int matricula, char nome[50], struct curso curso){
  struct aluno aluno;
  aluno.matricula = matricula;
  strcpy(aluno.nome, nome);
  aluno.curso = curso;
  return aluno;
}

struct professor criaProfessor(int codigo, char nome[50]){
  struct professor prof;
  prof.codigo = codigo;
  strcpy(prof.nome, nome);
  return prof;
}

void insereInicio(struct aluno a){
  struct lista* lista;
  lista = (struct lista*)malloc(sizeof(struct lista));
  lista->aluno = a;
  lista->proximo = inicio;
  inicio = lista;  
}

void removeInicio(){
  printf("\n\nREMOVENDO PRIMEIRO ITEM.....\n\n");
  struct lista* aux;
  aux = (struct lista*)malloc(sizeof(struct lista));
  aux = inicio;
  inicio = inicio->proximo;
  free(aux);
  
}

void insereFinal(struct aluno a){
  struct lista* aux, *lista;
  aux = (struct lista*)malloc(sizeof(struct lista));
  lista = (struct lista*)malloc(sizeof(struct lista));  
  aux = inicio;
  while(aux->proximo != NULL){
    aux = aux->proximo;
  }
  lista->aluno = a;
  lista->proximo = NULL;
  aux->proximo = lista;
}

void removeFinal(){
  printf("\n\nREMOVENDO ULTIMO ITEM.....\n\n");
  struct lista *aux, *at;
  aux = (struct lista*)malloc(sizeof(struct lista));
  aux = inicio;
  at = aux->proximo;
  while(at->proximo != NULL){
    aux = aux->proximo;
    at = at->proximo;
  }  
  aux->proximo = NULL;
  free(at);
}

void insereOrdenado(struct aluno a){
  struct lista *aux, *lista;
  aux = (struct lista*)malloc(sizeof(struct lista));
  lista = (struct lista*)malloc(sizeof(struct lista));
  aux = inicio;
  if(aux == NULL || a.matricula < aux->aluno.matricula){
    insereInicio(a);
    return;
  }
  lista = aux;
  while(lista != NULL && lista->aluno.matricula < a.matricula ){
    lista = lista->proximo;
  }
  
}

void imprimeLista(){
  struct lista *aux;
  aux = inicio;
  while(aux != NULL){
    printf("\nMatricula: %d\n", aux->aluno.matricula);
    printf("Nome do Aluno: %s\n", aux->aluno.nome);
    printf("Curso: %s\n", aux->aluno.curso.nome);
    printf("Professor: %s\n", aux->aluno.curso.professor.nome);
    aux = aux->proximo;
  }
}

/*
 *
 * inicio do main
 * 
 */

int main() {
  struct lista lista;
  struct curso curso1, curso2;
  struct aluno aluno1, aluno2, aluno3, aluno4;
  struct professor prof1, prof2;
  prof1 = criaProfessor(1, "orsi");
  prof2 = criaProfessor(2, "fabiano");
  curso1 = criaCurso(1, "ciencias", prof1);
  curso2 = criaCurso(2, "filosofia", prof2);
  aluno1 = criaAluno(1, "alexandre", curso1);
  aluno2 = criaAluno(0, "roberto", curso2);
  aluno3 = criaAluno(3, "fernando", curso2);
  aluno4 = criaAluno(2, "maria", curso1);
 
  //insereInicio(aluno1);
  //insereInicio(aluno2);
  //insereFinal(aluno1);
  insereOrdenado(aluno1);
  insereOrdenado(aluno2);
  insereOrdenado(aluno3);
  insereOrdenado(aluno4);
  imprimeLista();
  removeFinal();
  imprimeLista();
  
  
  //printf("%s", aluno1.curso.professor.nome);
  
}

