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
                struct Matrix *mat=Matriz + nMatrices;
 
                scanMatrix(mat);
                nMatrices++;
                printf("\n\nGuardada en la matriz como '%s'", mat->Nombre);
                printf("\nAhora tienes guardadas %d matrices\n", nMatrices);
            }break;
            case 2:{ //lista de matrices
                if(nMatrices==0)printf("\nNo existe ninguna matriz guardada\n");
                else{
                    printf("Hay %d matrices guardadas: \n",nMatrices);
                    struct Matrix *mat;
                    int i;
                    for(i=0; i<nMatrices; i++){
                        mat=&Matriz[i];
                        printMatrix(*mat);
                    }
                }
            }break;           
            case 3:{ //eliminar una matriz guardada
                int aux, i;
                aux=chooseMatrix(Matriz, nMatrices);
                if(aux==-1) printf("ERROR: Matriz no encontrada.");
                else{
                    for(i=aux; i<nMatrices-1;i++){
                        Matriz[i]=Matriz[i+1];
                    }
                    nMatrices--;
                    printf("\nMatriz eliminada con exito, lista de matrices actualizada (opcion 2.)\n\n");
                }
            }break;
            case 4: { //Sumar dos matrices guardadas
                if(nMatrices<2)printf("\nNo existen suficientes matrices para realizar la siguiente operacion\n\n");
                else{
                    printf("\n RECUERDE: Para restar matrices deben de tener el mismo orden");
                    printf("\nEliga una de las matrices para sumar: ");
                    struct Matrix mat1=Matriz[chooseMatrix(Matriz, nMatrices)];
                    printf("\nEliga la segunda matriz para sumarla a la anterior: ");
                    struct Matrix mat2=Matriz[chooseMatrix(Matriz, nMatrices)],res;
                    if((mat1.nFilas==mat2.nFilas)&&(mat1.nColumnas==mat2.nColumnas)){
                        res.nFilas=mat1.nFilas;
                        res.nColumnas=mat1.nColumnas;
                        sumaMatrix(&mat1,&mat2,&res);
                        printMatrix(res);
                        savematq(Matriz,&res,&nMatrices);
                    }
                    else {printf("\nNo se pudo realizar la suma porque no son del mismo orden.\n\n");}
                }
            }break;
            case 5: { //restar matrices
                if(nMatrices<2)printf("\nNo existen suficientes matrices para realizar la siguiente operacion\n\n");
                else{
                    printf("\n RECUERDE: Para restar matrices deben de tener el mismo orden");
                    printf("\nEliga una de las matrices para restar: ");
                    struct Matrix mat1=Matriz[chooseMatrix(Matriz, nMatrices)];
                    printf("\nEliga la segunda matriz para restarla a la anterior: ");
                    struct Matrix mat2=Matriz[chooseMatrix(Matriz, nMatrices)],res;
                    if((mat1.nFilas==mat2.nFilas)&&(mat1.nColumnas==mat2.nColumnas)){
                        res.nFilas=mat1.nFilas;
                        res.nColumnas=mat1.nColumnas;
                        restaMatrix(&mat1,&mat2,&res);
                        printMatrix(res);
                        savematq(Matriz,&res,&nMatrices);
                    }
                    else {printf("\nNo se pudo realizar la resta porque no son del mismo orden.\n\n");}
                }   
            }break;
            case 6: { //Multiplicar matrices
                if(nMatrices<2)printf("\nNo existen suficientes matrices para realizar la siguiente operacion\n\n");
                else{
                    printf("\n RECUERDE: Para multiplicar matrices deben de cumplir nColumnas1=nFilas2");
                    printf("\nEliga una de las matrices para multiplicar: ");
                    struct Matrix mat1=Matriz[chooseMatrix(Matriz, nMatrices)];
                    printf("\nEliga la segunda matriz para multiplicarla a la anterior: ");
                    struct Matrix mat2=Matriz[chooseMatrix(Matriz, nMatrices)],res;
                    if((mat1.nColumnas==mat2.nFilas)){
                        res.nFilas=mat1.nFilas;
                        res.nColumnas=mat1.nColumnas;
                        matxmat(&mat1,&mat2,&res);
                        printMatrix(res);
                        savematq(Matriz,&res,&nMatrices);
                    }
                    else {printf("\nNo se pudo realizar la multiplicacion porque no cumplen nColumnas1=nFilas2.\n\n");}
                }   
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