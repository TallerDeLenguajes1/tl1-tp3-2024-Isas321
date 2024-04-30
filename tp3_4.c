#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct  {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; 
//es un puntero a una estructura Producto. Esto significa que en cada instancia de la estructura Cliente, 
//el campo Productos apunta a un arreglo dinámico de estructuras Producto.
//El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} Cliente;


int cant_clientes();
int generador_num_random(int min, int max);
void carga_productos(Producto *productos, int cant_productos);
void mostrar_productos(Producto *productos, int cant_productos);
void cargar_cliente(Cliente **cliente, int cantidad_clientes);
float costo_total_producto(Producto *prod);

int main(){
  int cantidad_clientes, id_cliente, i=0;
  float suma=0, total_a_pagar;
  cantidad_clientes = cant_clientes();
  Cliente **clientes=(Cliente **)malloc(cantidad_clientes*sizeof(Cliente *));
  cargar_cliente(clientes, cantidad_clientes);

  for (i = 0; i < cantidad_clientes; i++)
  {
    printf("\n\n\nNombre del cliente: ");
    puts(clientes[i]->NombreCliente);
    mostrar_productos(clientes[i]->Productos, clientes[i]->CantidadProductosAPedir);
    suma+=costo_total_producto(clientes[i]->Productos);
  }
  total_a_pagar=suma/i;
  printf("#####%f", total_a_pagar);
  getchar();
  return 0;
}



int cant_clientes(){
  int n;
  printf("\nCantidad de clientes que se deben ingresar: ");
  scanf("%d", &n); 
  fflush(stdin);
  return n;
}

int generador_num_random(int min, int max){
    return (min+rand()%(max-min+1));
}

void carga_productos(Producto *productos, int cant_productos){
  int id;
  for (int i = 0; i < cant_productos; i++)
  {
    id=generador_num_random(1,5);
    productos[i].ProductoID=id;
    productos[i].Cantidad=generador_num_random(1,10);
    productos[i].TipoProducto=TiposProductos[id-1];
    productos[i].PrecioUnitario=(float)generador_num_random(1,10);
  }
}

void mostrar_productos(Producto *productos, int cant_productos){
  for (int i = 0; i < cant_productos; i++)
  {
    printf("\nID: %d", productos[i].ProductoID);
    printf("\nCantidad: %d", productos[i].Cantidad);
    printf("\nTipo de producto: ");
    puts(productos[i].TipoProducto);
    printf("Precio: %f", productos[i].PrecioUnitario);
    printf("\nCosto por producto = %f\n\n", costo_total_producto(&productos[i])); //Se debe pasar un puntero a productos[i] en lugar de productos[i]
  }
}

void cargar_cliente(Cliente **cliente, int cantidad_clientes){
  char buffer[100];
  for (int i = 0; i < cantidad_clientes; i++)
  {
    cliente[i] = (Cliente *)malloc(sizeof(Cliente));
    cliente[i]->ClienteID = i+1;
    printf("\nIngrese nombre de cliente [%d]: ", cliente[i]->ClienteID);
    gets(buffer);
    cliente[i]->NombreCliente = (char *)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(cliente[i]->NombreCliente, buffer);
    cliente[i]->CantidadProductosAPedir=generador_num_random(1,5);
    cliente[i]->Productos=(Producto * )malloc(cliente[i]->CantidadProductosAPedir*sizeof(Producto));
    carga_productos(cliente[i]->Productos, cliente[i]->CantidadProductosAPedir);
  }
}

float costo_total_producto(Producto *prod){
  float precio = prod->PrecioUnitario;
  int cantidad = prod->Cantidad;
  return (float)(precio*cantidad);
}
