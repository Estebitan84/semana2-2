#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[50];
    char descripcion[100];
    char calidad[20];
    float precio;
} Producto;

Producto* productos[100];
int numProductos = 0;

void verProductos() {
    for(int i = 0; i < numProductos; i++) {
        printf("ID: %d\n", productos[i]->id);
        printf("Nombre: %s\n", productos[i]->nombre);
        printf("Descripcion: %s\n", productos[i]->descripcion);
        printf("Calidad: %s\n", productos[i]->calidad);
        printf("Precio: %.2f\n\n", productos[i]->precio);
    }
}

void ingresarProducto() {
    Producto* p = (Producto*)malloc(sizeof(Producto));
    printf("Ingrese el ID del producto: ");
    scanf("%d", &(p->id));
    printf("Ingrese el nombre del producto: ");
    scanf("%s", p->nombre);
    printf("Ingrese la descripcion del producto: ");
    scanf("%s", p->descripcion);
    printf("Ingrese la calidad del producto: ");
    scanf("%s", p->calidad);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &(p->precio));

    productos[numProductos] = p;
    numProductos++;
}

void modificarProducto() {
    int id;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &id);

    for(int i = 0; i < numProductos; i++) {
        if(productos[i]->id == id) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", productos[i]->nombre);
            printf("Ingrese la nueva descripcion del producto: ");
            scanf("%s", productos[i]->descripcion);
            printf("Ingrese la nueva calidad del producto: ");
            scanf("%s", productos[i]->calidad);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &(productos[i]->precio));
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void eliminarProducto() {
    int id;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);

    for(int i = 0; i < numProductos; i++) {
        if(productos[i]->id == id) {
            free(productos[i]);
            productos[i] = productos[numProductos - 1];
            numProductos--;
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

int main() {
    int opcion;

    while(1) {
        printf("1. Ver productos\n");
        printf("2. Ingresar producto\n");
        printf("3. Modificar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                verProductos();
                break;
            case 2:
                ingresarProducto();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                return 0;
            default:
                printf("Opcion no reconocida.\n");
                break;
        }
    }

    return 0;
}
