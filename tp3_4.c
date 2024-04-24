#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};

typedef struct Producto Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

typedef struct Cliente Cliente;

/* void cant_clientes(int *n){
  printf("\nCantidad de clientes que se deben ingresar: ");
  scanf("%d", n); //Guardo en la posicion del puntero el valor ingresado
  getchar();
} */

int cant_clientes(){
  int n;
  printf("\nCantidad de clientes que se deben ingresar: ");
  scanf("%d", &n); //Guardo en la posicion del puntero el valor ingresado
  return n;
}

int generador_num_random(int min, int max){
    return (min+rand()%(max-min+1));
}

int main(){

  int cantidad_clientes;

  cantidad_clientes=cant_clientes();

  Cliente *clientes=(Cliente *)malloc(sizeof(Cliente)*cantidad_clientes);
  
  getchar();
  return 0;
}