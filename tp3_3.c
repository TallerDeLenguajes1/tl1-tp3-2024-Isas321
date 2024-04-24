#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carga_nombre(int posicion, char *buffer){
        printf("\nIngrese nombre [%d]: ", posicion+1);
        fgets(buffer, sizeof(buffer), stdin);
}

void carga_nombre_en_vector(char **nombres, int cantDeNombres){
char buffer[100]; //Lo uso como auxiliar para leer la entrada
    for(int i=0; i<cantDeNombres; i++){
        carga_nombre(i, buffer);
        *(nombres+i) = (char *)malloc((strlen(buffer)+1)*sizeof(char));
        //Casteo
        //Reserva de memoria con malloc -> resguardo la cant de caracteres + el final de linea y los multiplico por su peso
        strcpy(*(nombres+i), buffer);
    }
}

void mostrar_vector_de_nombres(char **nombres, int cantDeNombres){
    for(int i=0; i<cantDeNombres; i++){
        puts(*(nombres+i));
        free(*(nombres+i));
    }
}

void libera_memoria(char **nombres, int cantDeNombres){
    for(int i=0; i<cantDeNombres; i++){
        free(*(nombres+i));
    }
}

int main(){
int cantDeNombres=5;
char **nombres;
    /*Se reserva espacio en memoria para un array de cantDeNombres punteros a char. 
    Cada elemento de nombres será un puntero a una cadena de caracteres (un nombre en este caso) */
    nombres = (char **)malloc(cantDeNombres*sizeof(char *)); 
    carga_nombre_en_vector(nombres,cantDeNombres);
    mostrar_vector_de_nombres(nombres, cantDeNombres);
    libera_memoria(nombres, cantDeNombres);
    getchar();
    return 0;
}

