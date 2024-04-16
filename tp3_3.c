#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int cantDeNombres=5;
char **nombres;
char nombre;

    //*nombre = (char *)malloc((strlen(palabra)+1)*sizeof(char));

    for(int i; i<cantDeNombres; i++){
        printf("\nIngrese nombre %d", i+1);
        gets(nombre);
    }

    nombres = (char**) malloc((sizeof(char))*5);
}