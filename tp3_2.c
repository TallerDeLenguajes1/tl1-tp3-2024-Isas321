#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generadorNumRandom(int min, int max){
    return (min+rand()%(max-min+1));
}

void inicializadorMatrizRandom(int *matriz, int filas, int columnas, int min_valor, int max_valor){
    srand(time(NULL));
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            *(matriz+fila*columnas+columna)=generadorNumRandom(min_valor,max_valor);
        }
    }
}



int main(){
    int anios=5, meses=12;
    int matriz[anios][meses];

    inicializadorMatrizRandom(&matriz[0][0], anios, meses, 10000, 50000);


    return 0;
}


