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
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} Cliente;



int cant_clientes();
int generador_num_random(int min, int max);
void carga_nombre(int posicion, char *buffer);
void carga_productos(Producto *productos, int cant_productos);
void mostrar_productos(Producto *productos, int cant_productos);
void cargar_cliente(Cliente **cliente, int id_cliente);
float costo_total_producto(Producto prod);

int main(){
  int cantidad_clientes, id_cliente;
  cantidad_clientes = cant_clientes();
  Cliente **clientes=(Cliente **)malloc(cantidad_clientes*sizeof(Cliente *));
  for (int i = 0; i < cantidad_clientes; i++)
  {
    id_cliente=i+1;
    cargar_cliente(clientes,id_cliente);
  }
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

void carga_nombre(int id_cliente, char *buffer){
        printf("\nIngrese nombre [%d]: ", id_cliente);
        gets(buffer);
}

void carga_productos(Producto *productos, int cant_productos){
  int id;
  printf("\nentro carga productos");
  for (int i = 0; i < cant_productos; i++)
  {
    id=generador_num_random(1,5);
    productos[i].ProductoID=id;
    productos[i].Cantidad=generador_num_random(1,10);
    productos[i].TipoProducto=TiposProductos[id-1];
    productos[i].PrecioUnitario=(float)generador_num_random(1,10);
  }
   mostrar_productos(productos, cant_productos);
}

void mostrar_productos(Producto *productos, int cant_productos){
  for (int i = 0; i < cant_productos; i++)
  {
    printf("\nID: %d", productos[i].ProductoID);
    printf("\nCantidad: %d", productos[i].Cantidad);
    printf("\nTipo de producto: ");
    puts(productos[i].TipoProducto);
    printf("Precio: %f", productos[i].PrecioUnitario);
    printf("\nCosto total = %f\n\n", costo_total_producto(productos[i]));
  }
}

void cargar_cliente(Cliente **cliente, int id_cliente){
  char buffer[100];
  *cliente = (Cliente *)malloc(sizeof(Cliente));
  (*cliente)->ClienteID = id_cliente;
  carga_nombre(id_cliente, buffer);
  (*cliente)->NombreCliente = (char *)malloc((strlen(buffer)+1)*sizeof(char));
  strcpy((*cliente)->NombreCliente, buffer);
  (*cliente)->CantidadProductosAPedir=generador_num_random(1,5);
  (*cliente)->Productos=malloc((*cliente)->CantidadProductosAPedir*sizeof(Producto));
  carga_productos((*cliente)->Productos, (*cliente)->CantidadProductosAPedir);
}

float costo_total_producto(Producto prod){
  float precio = prod.PrecioUnitario;
  int cantidad = prod.Cantidad;
  return (float)(precio*cantidad);
}
/* iv) Implemente una función que calcule el costo total de un producto. Esta función debe
recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
el PrecioUnitario.
 */

