#include <stdio.h>
#include <string.h>

#define IVA_PORCENTAJE 21.0f

typedef struct {
  char nombre[50];
  char direccion[100];
  char nif[15];
} Vendedor;

typedef struct {
  char nombre[50];
  char direccion[100];
  char nif[15];
} Cliente;

typedef struct {
  char description[100];
  float precio_unitario;
  int cantidad;
} Producto;

void imprimir_cabecera(Vendedor vendedor, Cliente cliente) {
  printf("========================================================\n");
  printf("**Factura**\n");
  printf("========================================================\n");
  printf("**Vendedor:**\n");
  printf("%s\n", vendedor.nombre);
  printf("%s\n", vendedor.direccion);
  printf("NIF: %s\n", vendedor.nif);
  printf("**Cliente:**\n");
  printf("%s\n", cliente.nombre);
  printf("%s\n", cliente.direccion);
  printf("NIF: %s\n", cliente.nif);
}

void imprimir_linea_producto(Producto producto) {
  printf("%-50s %10.2f %3d %10.2f\n", producto.description,
         producto.precio_unitario, producto.cantidad,
         producto.precio_unitario * producto.cantidad);
}

void imprimir_pie(float importe_sin_impuestos, float iva, float importe_total) {
  printf("========================================================\n");
  printf("**Importe sin impuestos:** %10.2f\n", importe_sin_impuestos);
  printf("**IVA (%0.2f%%):** %10.2f\n", IVA_PORCENTAJE, iva);
  printf("**Importe total:** %10.2f\n", importe_total);
  printf("========================================================\n");
}


int main() {

  Vendedor vendedor;
  Cliente cliente;
  Producto productos[100];
  int num_productos = 0;
  float importe_sin_impuestos = 0.0f;
  float iva = 0.0f;
  float importe_total = 0.0f;

  strcpy(vendedor.nombre, "Empresa Ejemplo");
  strcpy(vendedor.direccion, "Calle Mayor, 123");
  strcpy(vendedor.nif, "A12345678");

  strcpy(cliente.nombre, "Juan Pérez López");
  strcpy(cliente.direccion, "Calle del Sol, 456");
  strcpy(cliente.nif, "B87654321");

  strcpy(productos->description, "Champu");
  strcpy(productos->precio_unitario, 20.50 );
  strcpy(productos->cantidad, 2);

  for (int i = 0; i < num_productos; i++) {
    importe_sin_impuestos +=
        productos[i].precio_unitario * productos[i].cantidad;
  }

  iva = importe_sin_impuestos * IVA_PORCENTAJE / 100;

  importe_total = importe_sin_impuestos + iva;

  imprimir_cabecera(vendedor, cliente);
  for (int i = 0; i < num_productos; i++) {
    imprimir_linea_producto(productos[i]);
  }

  imprimir_pie(importe_sin_impuestos, iva, importe_total);

  return 0;
}
