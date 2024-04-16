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

void mostrar_matriz(int *matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        printf("\n");
        for (int j = 0; j < columnas; j++)
        {
            printf("\t%d", *(matriz+i*columnas+j));
        }
    }
    printf("\n\n");
}

void gananciaPorAnio(int *matriz, int anios, int meses){
    int suma;
    float promedio;
    for (int i = 0; i < anios; i++)
    {
        suma=0;
        promedio=suma/
        printf("\n");
        for (int j = 0; j < meses; j++)
        {
            suma= *(matriz+i*meses+j) + suma;
        }
        promedio=(float)suma/meses;
        printf("\tLa ganancia promedio del anio %d es de: %.2f", i+1, promedio);
    }
    printf("\n\n");
}

int main(){
    int anios=5, meses=12;
    int matriz[anios][meses];

    inicializadorMatrizRandom(&matriz[0][0], anios, meses, 10000, 50000);
    mostrar_matriz(*matriz, anios, meses);
    gananciaPorAnio(*matriz, anios, meses);

    return 0;
}


