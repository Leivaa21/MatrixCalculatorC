#ifndef __BasicFuncs__
#define __BasicFuncs__
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
struct Matrix;
void scanMatrix(struct Matrix *mat);
void printMatrix(struct Matrix mat);
int nombresIguales(struct Matrix *mat,char selectn[]);
int selectMatrix(struct Matrix *Matriz,int nMatrices, char selectn[]);
int chooseMatrix(struct Matrix *Matriz,int nMatrices);
int ynquest();
void savematq(struct Matrix *Matriz, struct Matrix *resultado, int *nMatrices);
#endif