#include "scr/libs/BasicMaths.h"
#include "scr/libs/Gauss.h"
#include "scr/libs/Menu.h"

struct Matrix{
    float M[MAX][MAX];
    int nFilas, nColumnas;
    char Nombre[17];
};
int main(){
    int option=1,nMatrices=0;
    while(option!=0){
        option=selectMenu();
        struct Matrix Matriz[MAX];
        switch (option){
        
            case 1: {//Introduccir matrix
                scanMatrix(&Matriz[nMatrices],&nMatrices);
            }break;
            case 2:{ //lista de matrices
                listMatrix(Matriz,nMatrices);
            }break;           
            case 3:{ //eliminar una matriz guardada
                delMatrix(Matriz, &nMatrices);
            }break;
            case 4: { //Sumar dos matrices guardadas
                printf("\n RECUERDE: Para restar matrices deben de tener el mismo orden");
                printf("\nEliga una de las matrices para sumar: ");
                struct Matrix res=Matriz[chooseMatrix(Matriz, nMatrices)];
                printf("\nEliga la segunda matriz para sumarla a la anterior: ");
                struct Matrix mat=Matriz[chooseMatrix(Matriz, nMatrices)];
                if(sameOrder(res,mat)){
                    sumaMatrix(mat,&res);
                    printMatrix(res);
                    savematq(Matriz,&res,&nMatrices);
                }
                else printf("\nNo se pudo realizar la suma porque no son del mismo orden.\n\n");
            }break;
            case 5: { //restar matrices
                printf("\n RECUERDE: Para restar matrices deben de tener el mismo orden");
                printf("\nEliga una de las matrices para restar: ");
                struct Matrix res=Matriz[chooseMatrix(Matriz, nMatrices)];
                printf("\nEliga la segunda matriz para restarla a la anterior: ");
                struct Matrix mat=Matriz[chooseMatrix(Matriz, nMatrices)];
                if(sameOrder(res,mat)){
                    restaMatrix(mat,&res);
                    printMatrix(res);
                    savematq(Matriz,&res,&nMatrices);
                }
                else printf("\nNo se pudo realizar la resta porque no son del mismo orden.\n\n");   
            }break;
            case 6: { //Multiplicar matrices
                printf("\n RECUERDE: Para multiplicar matrices deben de cumplir nColumnas1=nFilas2");
                printf("\nEliga una de las matrices para multiplicar: ");
                struct Matrix mat1=Matriz[chooseMatrix(Matriz, nMatrices)];
                printf("\nEliga la segunda matriz para multiplicarla a la anterior: ");
                struct Matrix mat2=Matriz[chooseMatrix(Matriz, nMatrices)],res;
                if((mat1.nColumnas==mat2.nFilas)){
                    res.nFilas=mat1.nFilas;
                    res.nColumnas=mat1.nColumnas;
                    matxmat(mat1,mat2,&res);
                    printMatrix(res);
                    savematq(Matriz,&res,&nMatrices);
                }
                else {printf("\nNo se pudo realizar la multiplicacion porque no cumplen nColumnas1=nFilas2.\n\n");}
                   
            }break;
            case 7: {// Hayar reducida de gauss
                    printf("\nEliga una de las matrices para realizar la reducida de gauss: ");
                    struct Matrix mat1=Matriz[chooseMatrix(Matriz, nMatrices)],res;
                    reducidagauss(mat1,&res);
                    printMatrix(res);
                    savematq(Matriz,&res,&nMatrices);
            }
            default:{
            }break;
        }
    }
}