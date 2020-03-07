#include "libs/BasicMaths.h"
struct Matrix{
    float M[MAX][MAX];
    int nFilas, nColumnas;
    char Nombre[17];
};
int sameOrder(struct Matrix mat1, struct Matrix mat2){
    if(mat1.nFilas!=mat2.nFilas||mat1.nColumnas!=mat2.nColumnas) return 0;
    return 1;
}
void sumaMatrix(struct Matrix mat2, struct Matrix *res){
    int i,j;
    for(i=0; i<res->nFilas; i++){
        for(j=0; j<res->nColumnas; j++){
            res->M[i][j]+=mat2.M[i][j];
        }
    }
    strcpy(res->Nombre,"Resultado");
}
void restaMatrix(struct Matrix mat2, struct Matrix *res){
    int i,j;
    for(i=0; i<res->nFilas; i++){
        for(j=0; j<res->nColumnas; j++){
            res->M[i][j]-=mat2.M[i][j];
        }
    }
    strcpy(res->Nombre,"Resultado");
}
void matxmat(struct Matrix mat1, struct Matrix mat2, struct Matrix *res){
    int i,j,k;
    res->nFilas=mat1.nFilas;
    res->nColumnas=mat2.nColumnas;
    for(i=0; i<res->nFilas; i++){
        for(j=0; j<res->nColumnas; j++){
            res->M[i][j]=0;
            for(int aux=0; aux<mat1.nColumnas;aux++)
                res->M[i][j]+=mat1.M[i][aux]*mat2.M[aux][j];
        }
    }
    strcpy(res->Nombre,"Resultado");
}