#include "libs/BasicFuncs.h"
struct Matrix{
    float M[MAX][MAX];
    int nFilas, nColumnas;
    char Nombre[17];
};
void scanMatrix(struct Matrix *mat, int *nMatrices){
    int i, j;
    printf("\nIntroduzca el numero de filas de la matriz: ");
    scanf("%d", &mat->nFilas);
    printf("\nIntroduzca el numero de columnas de la matriz:");
    scanf("%d", &mat->nColumnas);
    for (i=0;i<mat->nFilas;i++){
        for (j=0;j<mat->nColumnas;j++){
            printf ("\n M[%d][%d] = ", i+1, j+1);
            scanf  ("%e", &mat->M[i][j]);
        }
    }
    printf("Introduzca el nombre de la matriz: ");
    scanf("%s",mat->Nombre);
    (*nMatrices)++;
    printf("\n\nGuardada en la matriz como '%s'", mat->Nombre);
    printf("\nAhora tienes guardadas %d matrices\n", *nMatrices);
}
void printMatrix(struct Matrix mat){
    printf("\n\nMatriz '%s'\n", mat.Nombre);
    int i, j;
    for (i=0; i<mat.nFilas; i++){
        for (j=0; j<mat.nColumnas; j++){
            printf("|%.3f", mat.M[i][j]);
        }
        printf("|\n");
    }
}
void listMatrix(struct Matrix *Matriz, int nMatrices){
    if(nMatrices==0)printf("\nNo existe ninguna matriz guardada\n");
    else{
        printf("Hay %d matrices guardadas: \n",nMatrices);
        int i;
        for(i=0; i<nMatrices; i++){
            printMatrix(Matriz[i]);
        }
    }
}
int nombresIguales(struct Matrix mat,char selectn[]){//permite utilizar strcmp en if's de forma mas comoda
    if(strcmp(selectn,mat.Nombre)!=0) return 0;
    else return 1;
}
int selectMatrix(struct Matrix *Matriz,int nMatrices, char selectn[]){
    int i;
    for (i=0; i<nMatrices;i++){
        if(nombresIguales(Matriz[i],selectn))return i;
    }
    return -1;
}
int chooseMatrix(struct Matrix *Matriz,int nMatrices){
    char selectn1[17];
    scanf("%s", selectn1);
    return selectMatrix(Matriz, nMatrices, selectn1);
}
void delMatrix(struct Matrix *Matriz, int *nMatrices){
    int aux, i;
    aux=chooseMatrix(Matriz, *nMatrices);
    if(aux==-1) printf("ERROR: Matriz no encontrada.");
    else{
        for(i=aux; i<(*nMatrices)-1;i++) Matriz[i]=Matriz[i+1];
        (*nMatrices)--;
        printf("\nMatriz eliminada con exito, lista de matrices actualizada (opcion 2.)\n\n");
    }
}
int ynquest(){
    char res;
    scanf("%s",&res);
    tolower(res);
    if(res!='y'&&res!='n'){
        printf("\n ERROR:Introduzca 'y' o 'n' para responder: ");
        return -1;
    }
    else if(res=='y') return 1;
    else return 0;
}
void savematq(struct Matrix *Matriz, struct Matrix *resultado, int *nMatrices){
    printf("\nDesea guardar la matriz anterior? y/n: "); 
    int yn=-1;
    while (yn==-1)
        yn=ynquest(); //Devuelve 1 si responde y e 0 si responde n
        if (yn) {
            printf("Introduzca el nombre de la matriz: ");
            scanf("%s",resultado->Nombre);
            Matriz[*nMatrices]=*resultado;
            printf("Matriz guardada en la posicion %d", *nMatrices+1);
            (*nMatrices)++;
        }
}