#include "libs/Gauss.h"
struct Matrix{
    float M[MAX][MAX];
    int nFilas, nColumnas;
    char Nombre[17];
};
int elegirfila(struct Matrix mat, int pivotaux){
    int i,j;
    for(j=0; j<mat.nColumnas; j++){
        for(i=pivotaux; i<mat.nFilas; i++){
            if(mat.M[i][j]!=0)return i; //retorna la primera fila con un valor diferente a 0
        }
    }
    return -1;
}
int elegircolumna(struct Matrix mat, int fila){
    int j;
    for(j=0;j<mat.nColumnas;j++){
        if(mat.M[fila][j]!=0)return j;
    }
}
void reducir(struct Matrix *mat, int fila){
    int j;
    float val=0;
    val=mat->M[fila][elegircolumna(*mat,fila)];
    if(val!=0)  for(j=0; j<mat->nColumnas;j++)
                    mat->M[fila][j]=(mat->M[fila][j])/val;
    
}
void changFila(struct Matrix *mat,int *fila1,int fila2){
    float aux;
    int j;
    for (j=0; j<mat->nColumnas;j++){
        aux=mat->M[*fila1][j];
        mat->M[*fila1][j]=mat->M[fila2][j];
        mat->M[fila2][j]=aux;
    }
    *fila1=fila2;
}
void clearColumn(struct Matrix *mat, int columna, int pivotaux){
    int i,j;
    float aux;
    for (i=pivotaux+1; i<mat->nFilas;i++){
        aux=mat->M[i][columna];
        for(j=columna; j<mat->nColumnas; j++){
        mat->M[i][j]-=mat->M[pivotaux][j]*aux;
        }
    }
}
void reducidagauss(struct Matrix mat, struct Matrix *res){
    int pivotaux;
    for(pivotaux=0; pivotaux<mat.nFilas; pivotaux++){
        if(pivotaux==(mat.nFilas-1))
            reducir(&mat, pivotaux);
        
        else{
    //elegir fila para pivotarla;
            int fila=elegirfila(mat,pivotaux);
    //si no esta en la primera posicion, moverla;
            if(fila!=pivotaux) changFila(&mat,&fila,pivotaux);
    //reducir fila;
            reducir(&mat, fila);
    //hacer ceros debajo del 1;
            int columna=elegircolumna(mat,fila);
            clearColumn(&mat,columna,fila);
        }
    }
    *res=mat;
    strcpy(res->Nombre,"Resultado");
}