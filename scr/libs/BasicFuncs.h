#ifndef __BasicFuncs__
#define __BasicFuncs__
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
struct Matrix;
void scanMatrix(struct Matrix *mat,int *nMatrices);
void printMatrix(struct Matrix mat);
void listMatrix(struct Matrix *Matriz, int nMatrices);
int nombresIguales(struct Matrix mat,char selectn[]);
int selectMatrix(struct Matrix *Matriz,int nMatrices, char selectn[]);
int chooseMatrix(struct Matrix *Matriz,int nMatrices);
void delMatrix(struct Matrix *Matriz, int *nMatrices);
int ynquest();
void savematq(struct Matrix *Matriz, struct Matrix *resultado, int *nMatrices);
#endif