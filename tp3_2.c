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

void min_max_ganancia(int *matriz, int anios, int meses){
    int min, max, aux, anio_min, mes_min, anio_max, mes_max;
    min=*matriz;
    max=*matriz;
    for (int i = 0; i < anios; i++)
    {
        for (int j = 0; j < meses; j++)
        {
            if(min>*(matriz+i*meses+j)){
                min=*(matriz+i*meses+j);
                anio_min=i;
                mes_min=j;
            }
            if(max<*(matriz+i*meses+j)){
                max=*(matriz+i*meses+j);
                anio_max=i;
                mes_max=j;
            }
        }
    }
    printf("\n\tEl minimo de ganancia sucedio en el anio:%d mes:%d es de Minimo=%d", anio_min, mes_min, min);
    printf("\n\tEl maximo de ganancia sucedio en el anio:%d mes:%d es de Maximo=%d", anio_max, mes_max, max);
    printf("\n\n");
}

int main(){
    int anios=5, meses=12;
    int matriz[anios][meses];

    inicializadorMatrizRandom(&matriz[0][0], anios, meses, 10000, 50000);
    mostrar_matriz(*matriz, anios, meses);
    gananciaPorAnio(*matriz, anios, meses);
    min_max_ganancia(*matriz, anios, meses);
    getchar();

    return 0;
}



