#include <stdio.h>
#include <stdlib.h>

#define tamanho 9
        
struct fila{
    int init, end;
    int vet[tamanho];
};    

struct fila f;

void startFile(struct fila *pf);
int emptyFile(struct fila *pf);
int fullFile(struct fila *pf);
int addFile(struct fila *pf, int arg);
int rmvFile(struct fila *pf);
int qtdElementos(struct fila *pf);
int compareFiles(struct fila *pf, struct fila *pf2);

int main(){
    int var, tam;
    struct fila f;
    startFile(&f);
    addFile(&f, 10);
    addFile(&f, 25);
    addFile(&f, 40);
    
    struct fila p;
    struct fila p2;
    startFile(&p);
    startFile(&p2);
   
    
    addFile(&p, 1);
    addFile(&p, 2);
    addFile(&p, 3);
    
    addFile(&p2, 1);
    addFile(&p2, 2);
    addFile(&p2, 3);
    
    compareFiles(&p, &p2);
    
    
    
    printf("Qtde de itens: %d\n", qtdElementos(&f));
    printf("Removendo os itens...\n");
    
    var = rmvFile(&f);    
    printf("Valor de var: %d\n", var);
    
    var = rmvFile(&f);
    printf("Valor de var: %d\n", var);
    
    var = rmvFile(&f);
    printf("Valor de var: %d\n", var);
    
    
    tam = qtdElementos(&f);
    printf("Qtde de elementos: %d\n", tam);
    
    
    return 0;
}

void startFile(struct fila *pf){
    pf->end = -1;
    pf->init = 0;
}

int emptyFile(struct fila* pf){
    if (pf->end < pf->init){
        return 1;
    }
    else
        return 0;
    
}

int fullFile(struct fila *pf){
    if (pf->end == tamanho-1){
        return 1;
    }
    else
        return 0;
}

int addFile(struct fila *pf, int arg){
    if(!fullFile(pf)){
        pf->end ++;
        pf->vet[pf->end] = arg;
        return 1;
    }
    else
        return 0;
    
}

int rmvFile(struct fila *pf){
    int x, i;
    if(!emptyFile(pf)){
        return pf->vet[pf->init++];
    }
    else{
        x = pf->vet[0];
        for (i = 0; i < pf->end; i++){
            pf->vet[i] = pf->vet[i+1];
        }
        pf->end = pf->end-1;
    }
        
}

int qtdElementos(struct fila *pf){
    int x, qtde = 0;
    struct fila aux;
    startFile(&aux);
    while(!emptyFile(pf)){
        x = rmvFile(pf);
        addFile(&aux, x);
        ++qtde;
    }
    
    while(!emptyFile(&aux)){
        x = rmvFile(&aux);
        addFile(pf, x);
    }
    return qtde;
} 

int compareFiles(struct fila *pf, struct fila *pf2){
    int i, var1, var2;
    struct fila aux1;
    struct fila aux2;
    startFile(&aux1);
    startFile(&aux2);
    
    if(qtdElementos(pf) != qtdElementos(pf2))
        return -1;
        
    while(!emptyFile(pf) && !emptyFile(pf2)){
        var1 = rmvFile(pf);
        addFile(&aux1, var1);
        var2 = rmvFile(pf2);
        addFile(&aux2, var2);
        if (var1 != var2)
            break;
    }
    
    while(!emptyFile(&aux1) && !emptyFile(&aux2)){
        var1 = rmvFile(&aux1);
        addFile(pf, var1);
        var2 = rmvFile(&aux2);
        addFile(pf2, var2);
    }    
}