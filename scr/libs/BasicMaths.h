#ifndef __BasicMaths__
#define __BasicMaths__
#include "BasicFuncs.h"
int sameOrder(struct Matrix mat1, struct Matrix mat2);
void sumaMatrix(struct Matrix mat2, struct Matrix *res);
void restaMatrix(struct Matrix mat2, struct Matrix *res);
void matxmat(struct Matrix mat1, struct Matrix mat2, struct Matrix *res); 
#endif