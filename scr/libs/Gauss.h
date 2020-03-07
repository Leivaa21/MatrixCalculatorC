#ifndef __gauss__
#define __gauss__
#include "BasicFuncs.h"
int elegirfila(struct Matrix mat, int pivotaux);
int elegircolumna(struct Matrix mat, int fila);
void reducir(struct Matrix *mat, int fila);
void changFila(struct Matrix *mat,int *fila1,int fila2);
void clearColumn(struct Matrix *mat, int columna, int pivotaux);
void reducidagauss(struct Matrix mat, struct Matrix *res);
#endif