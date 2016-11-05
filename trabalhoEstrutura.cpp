/* CRIAR O MENU COM AS OPÇÕES DE 
 * INCLUIR ALUNO
 * REMOVER ALUNO SÓ SE N TIVER LIVROS CADASTRADOS
 * MOSTRAR ALUNOS
 * BUSCAR ALUNO
 * INCLUIR LIVRO
 * REMOVER LIVRO
 * MOSTRAR LIVROS
 * BUSCAR LIVRO
 * 
 * File:   main.cpp
 * Author: marin
 *
 * Created on 25 de Outubro de 2016, 21:52
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

struct livro{
  int cod;
  char titulo[50];
  char autor[40];
};

struct listaLivro{
  struct livro livro;
  struct listaLivro *proximo;
};

struct aluno{
  int codigo;
  char nome[50];
  char curso[35];
  struct listaLivro* livros;
};

struct lista{
  struct aluno aluno;
  struct lista* proximo;
};



struct lista* insereInicio(struct lista* inicio, struct aluno a){
  struct lista *lista;
  lista = (struct lista*)malloc(sizeof(struct lista));
  lista->aluno = a;
  lista->proximo = inicio;
  inicio = lista;
  return inicio;
}

struct listaLivro* insereLivroInicio(struct listaLivro* inicio, struct livro l){
  struct listaLivro *lista;
  lista = (struct listaLivro*)malloc(sizeof(struct listaLivro));
  lista->livro = l;
  lista->proximo = inicio;
  inicio = lista;
  return inicio;
}

struct lista* removeInicio(struct lista* inicio){
  struct lista *aux;
  aux = inicio;
  inicio = inicio->proximo;
  free(aux);
  return inicio;
}

struct listaLivro* removeLivroInicio(struct listaLivro* inicio){
  struct listaLivro *aux;
  aux = inicio;
  inicio = inicio->proximo;
  free(aux);
  return inicio;
}

void insereDepois(struct lista *inicio, struct aluno a){
  struct lista *lista;
  lista=(struct lista*)malloc(sizeof(struct lista));
  lista->aluno = a;
  lista->proximo = inicio->proximo;
  inicio->proximo = lista;
}

void insereLivroDepois(struct listaLivro *inicio, struct livro l){
  struct listaLivro *lista;
  lista=(struct listaLivro*)malloc(sizeof(struct listaLivro));
  lista->livro = l;
  lista->proximo = inicio->proximo;
  inicio->proximo = lista;
}

struct lista* insereFinal(struct lista* inicio, struct aluno a){
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
  return inicio;
}

void removeDepois(struct lista *inicio){
  struct lista *aux;
  aux = inicio->proximo;
  inicio->proximo = aux->proximo;
  free(aux);
}

void removeLivroDepois(struct listaLivro* inicio){
  struct listaLivro *aux;
  aux = inicio->proximo;
  inicio->proximo = aux->proximo;
  free(aux);
}

void print(struct lista* inicio){
  if(inicio == NULL){
    printf("NENHUM ALUNO CADASTRADO!!!");
    getchar();
    return;
  }
  printf("\nLISTA DE ALUNOS\n");
  struct lista *l;
  l = inicio;
  while(l != NULL){
    printf("\nCódigo: %d\nNome: %sCurso: %s\n", l->aluno.codigo, l->aluno.nome,l->aluno.curso);
    l = l->proximo;
  }
  getchar();
}

void printBooks(struct listaLivro* inicio){
  if(inicio == NULL){
    printf("NENHUM LIVRO ENCONTRADO!!!");
    getchar();
    return;
  }
  printf("\nLISTA DE LIVROS\n");
  struct listaLivro* l;
  l = inicio;
  while(l != NULL){
    printf("\nCódigo: %d\nTitulo: %sAutor: %s\n", l->livro.cod, l->livro.titulo,l->livro.autor);
    l = l->proximo;
  }
  getchar();
}

struct listaLivro* insereLivroOrdenado(struct listaLivro* inicio, struct livro l){
  struct listaLivro *p, *q;
  p = inicio;
  if((p == NULL) || (l.cod < p->livro.cod)){
    inicio = insereLivroInicio(inicio, l);
    return inicio;
  }
  q = p;
  while((q != NULL) && (q->livro.cod < l.cod)){
    p = q;
    q = p->proximo;
  }
  if((q == NULL) || (q->livro.cod > l.cod))
    insereLivroDepois(p, l);
  else
    printf("\nCódigo de livro já existente!!\n\n");
  
  return inicio;
}

struct lista* insereOrdenado(struct lista* inicio, struct aluno a){
  struct lista *p, *q;
  p = inicio;
  if((p == NULL) || (a.codigo < p->aluno.codigo)){
    inicio = insereInicio(inicio, a);
    return inicio;
  }
  q = p;
  while((q != NULL) && (q->aluno.codigo < a.codigo)){
    p = q;
    q = p->proximo;
  }
  if((q == NULL) || (q->aluno.codigo > a.codigo))
    insereDepois(p, a);
  else
    printf("\nCódigo de aluno já existente!!\n\n");
  
  return inicio;
}


struct lista* removeOrdenado(struct lista* inicio, struct aluno a){
  struct lista *p, *q;
  p = inicio;
  if(p == NULL){
    printf("\nLista vazia!\n");
    getchar();
    return inicio;
  }
  if(a.codigo == p->aluno.codigo){
    inicio = removeInicio(inicio);
    return inicio;
  }
  q = p;
  while((q != NULL) && (q->aluno.codigo < a.codigo)){
    p = q;
    q = p->proximo;
  }
  if((q != NULL) && (q->aluno.codigo == a.codigo))
   removeDepois(p);  
  else {
    printf("\nAluno não cadastrado!");
    getchar();
  }   
  
  return inicio;
}

struct listaLivro* removeLivroOrdenado(struct listaLivro* inicio, struct livro l){
  struct listaLivro *p, *q;
  p = inicio;
  if(p == NULL){
    printf("\nLista vazia!\n");
    getchar();
    return inicio;
  }
  if(l.cod == p->livro.cod){
    inicio = removeLivroInicio(inicio);
    return inicio;
  }
  q = p;
  while((q != NULL) && (q->livro.cod < l.cod)){
    p = q;
    q = p->proximo;
  }
  if((q != NULL) && (q->livro.cod == l.cod))
   removeLivroDepois(p);  
  else {
    printf("\nLivro não cadastrado!");
    getchar();
  }   
  
  return inicio;
}

struct aluno criaAluno(int cod, char nome[50], char curso[30]){
  struct aluno a;
  a.codigo = cod;
  strcpy(a.nome, nome);
  strcpy(a.curso, curso);  
  return a;
}

struct livro criaLivro(int cod, char titulo[50], char autor[40]){
  struct livro l;
  l.cod = cod;
  strcpy(l.titulo, titulo);
  strcpy(l.autor, autor);
  return l;
}

struct aluno buscaAluno(struct lista* l, int cod){
  struct aluno aluno;
  while(l != NULL){
    if(l->aluno.codigo == cod){
      aluno = l->aluno;
    }
    l = l->proximo;
  }   
  return aluno;
}

struct livro buscaLivro(struct listaLivro* l, int cod){
  struct livro livro;
  while(l != NULL){
    if(l->livro.cod == cod){
      livro = l->livro;
    }
    l = l->proximo;
  }
  return livro;
}


void imprime(struct aluno a){
  if(a.codigo == NULL){
    printf("ATENÇÃO!!! CADASTRO INEXISTENTE!!!");
    getchar();
    return;
  }
  printf("\n**ALUNO**");
  printf("\nCÓDIGO: %d\n", a.codigo);
  printf("NOME: %s", a.nome);
  printf("CURSO: %s", a.curso);
  getchar();
}

void imprimeLivro(struct livro l){
  printf("\n**LIVRO**");
  printf("\nCÓDIGO: %d\n", l.cod);
  printf("TÍTULO: %s", l.titulo);
  printf("AUTOR: %s", l.autor);
  
  
}


main() {
  struct lista *inicioAluno = NULL;
  struct listaLivro *inicioLivro = NULL;

  
  while(true){
    system("clear");
    int opt;
    printf("---------------------------------\n");
    printf("TRABALHO ESTRUTURA DE DADOS\n");
    printf("---------------------------------\n\n\n");
    printf("---------------------------------\n");
    printf("[1]ALUNOS | [2]LIVROS | [3]SAIR\n");
    printf("---------------------------------\n\n");
    printf("DIGITE SUA OPÇÃO: ");    
    scanf("%d", &opt);
    switch(opt){
      case 1:{
        system("clear");
        printf("---------------------------------\n");
        printf("TRABALHO ESTRUTURA DE DADOS\n");
        printf("---------------------------------\n\n\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("[1]INSERIR ALUNO | [2]REMOVER ALUNO | [3]MOSTRAR ALUNO | [4]RELAÇÃO DE ALUNOS | [5]LOCAR LIVRO\n");
        printf("----------------------------------------------------------------------------------------------\n\n");
        printf("DIGITE SUA OPÇÃO: ");
        scanf("%d", &opt);
        switch(opt){
          case 1: {
            system("clear");
            struct aluno x;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS ORSI\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("INSERÇÃO DE ALUNO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO: ");
            scanf("%d", &x.codigo);
            __fpurge(stdin);
            printf("NOME: ");
            fgets(x.nome, 50, stdin);
            printf("CURSO: ");
            fgets(x.curso, 50, stdin);
            printf("Inserindo aluno...");
            inicioAluno = insereOrdenado(inicioAluno, x);
            getchar();
            break;
          }        
          case 2: {
            system("clear");
            int i;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("REMOVER ALUNO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO DO ALUNO A SER REMOVIDO: ");
            scanf("%d",&i);
            struct aluno aluno = buscaAluno(inicioAluno, i);
            __fpurge(stdin);
            printf("Removendo aluno...");
            removeOrdenado(inicioAluno, aluno);
            getchar();
            break;
          }
          case 3: {
            system("clear");
            int i;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("MOSTRAR ALUNO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO DO ALUNO A SER MOSTRADO: ");
            scanf("%d", &i);            
            printf("Buscando...\n");
            struct aluno aluno = buscaAluno(inicioAluno, i);   
            imprime(aluno);
            getchar();
            break;
          }
          case 4: {
            system("clear");
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("RELAÇÃO DE ALUNOS\n");
            printf("---------------------------------\n\n");
            print(inicioAluno);
            getchar();
            break;
          }
          case 5: {
            system("clear");
            int i, cod, opt;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("EMPRESTAR LIVRO\n");
            printf("---------------------------------\n");
            printf("CÓDIGO DO LIVRO A SER EMPRESTADO: ");
            scanf("%d", &i);
             __fpurge(stdin);
             struct livro livro = buscaLivro(inicioLivro, i);
             imprimeLivro(livro);
             printf("\nCÓDIGO DO ALUNO: ");
             scanf("%d", &cod);
             __fpurge(stdin);
             struct aluno aluno = buscaAluno(inicioAluno, cod);           
             imprime(aluno);
             printf("CONFIRMA O EMPRESTIMO? [1- sim | 0 -não]: ");
             switch(opt){
               case 1: {
                 aluno.livros = insereLivroOrdenado(aluno.livros, livro);
                 break;
               }
               case 2: {
                 break;
               }
               break;
             }
            
            getchar();
            break;
          }
          break;
        }
        break;
      }
      
      case 2: {
        system("clear");
        printf("---------------------------------\n");
        printf("TRABALHO ESTRUTURA DE DADOS\n");
        printf("---------------------------------\n\n\n");
        printf("------------------------------------------------------------------------\n");
        printf("[1]INSERIR LIVRO | [2]REMOVER LIVRO | [3]MOSTRAR LIVRO | [4]RELAÇÃO DE LIVROS\n");
        printf("------------------------------------------------------------------------\n\n");
        printf("DIGITE SUA OPÇÃO: ");
        scanf("%d", &opt);
        switch(opt){
          case 1:{
            system("clear");
            struct livro l;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("INSERÇÃO DE LIVRO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO: ");
            scanf("%d", &l.cod);
            __fpurge(stdin);
            printf("TÍTULO: ");
            fgets(l.titulo, 50, stdin);
            printf("AUTOR: ");
            fgets(l.autor, 50, stdin);
            printf("Inserindo livro...");
            inicioLivro = insereLivroOrdenado(inicioLivro, l);
            getchar();
            break;
          }
          case 2:{
            system("clear");
            int cod;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("REMOÇÃO DE LIVRO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO DO LIVRO A SER REMOVIDO: ");
            scanf("%d", &cod);
            __fpurge(stdin);
            printf("Removendo livro...");
            getchar();
            break;
          }
          case 3: {
            system("clear");
            int cod;
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("BUSCA DE LIVRO\n");
            printf("---------------------------------\n\n");                     
            printf("CÓDIGO DO LIVRO A SER MOSTRADO: ");
            scanf("%d", &cod);
            __fpurge(stdin);
            printf("Buscando...\n");
            struct livro livro = buscaLivro(inicioLivro, cod);
            imprimeLivro(livro);
            getchar();
            break;
          }
          case 4: {
            system("clear");
            printf("---------------------------------\n");
            printf("TRABALHO ESTRUTURA DE DADOS\n");
            printf("---------------------------------\n\n\n");
            printf("---------------------------------\n");
            printf("RELAÇÃO DE LIVROS\n");
            printf("---------------------------------\n\n");
            printBooks(inicioLivro);
            getchar();
          }
          break;
        }
        break;
      }
      case 3: {
        
        exit;
      }
    }
  }
  
  /*  
  l1 = criaLivro(1, "Estrutura de dados", "Tanembaum");
  l2 = criaLivro(2, "Sistemas Operacionais", "Tanembaum");  
  a1 = criaAluno(1, "Alexandre", "Ciencia");
  a2 = criaAluno(7, "Ricardo", "Biologia");
  a3 = criaAluno(3, "Fernando", "Direito");
  a5 = criaAluno(5, "Natalia", "Engenharia");
  a6 = criaAluno(6, "Rafael", "CC");
  inicio1 = insereLivroOrdenado(inicio1, l1);
  inicio1 = insereLivroOrdenado(inicio1, l2);
  printBooks(inicio1);
  inicio1 = removeLivroInicio(inicio1);
  printBooks(inicio1);
  a1.livros.livro = l1;
  printf("%s", a1.livros.livro.titulo);
  inicio = insereOrdenado(inicio,a1);
  inicio = insereOrdenado(inicio, a2);
  inicio = insereOrdenado(inicio, a3);
  inicio = insereOrdenado(inicio, a3);
  print(inicio);
  inicio = removeOrdenado(inicio, a2);
  print(inicio);
  struct aluno a4 = criaAluno(8, "Maria", "Letras");
  inicio = insereOrdenado(inicio, a4);
  inicio = insereOrdenado(inicio, a5);
  print(inicio);
  inicio = insereFinal(inicio, a6);
  print(inicio);*/
}

