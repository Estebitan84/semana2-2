#include <stdio.h>
#include <stdlib.h>
// Esteban Guamán, Pablo Montalvo
int main(int argc, char *argv[]) {

  char nombre[100];
  char cedula[100];

  float precioA = 150, precioB = 55, precioC = 180, precioD = 70, precioE = 120;
  float numA = 0, numB = 0, numC = 0, numD = 0, numE = 0, numF = 0;
  float subtotalA = 0, subtotalB = 0, subtotalC = 0, subtotalD = 0,
        subtotalE = 0;
  float subtotal = 0, total = 0;

  int opcion = 0, opcion2 = 0;
  int menu = 0;

  do {
    printf("1) Crear Facturación\n");
    printf("2) Facturarción\n");
    printf("3) Abandonar\n");
    printf("Que necesita hacer?\n");
    scanf("%d", &menu);

    switch (menu) {
    case 1:
      do {
        printf(
            "+++++++++++Escoja los items que desee facturar: +++++++++++++\n");
        printf("1) Num de Llantas (Precio seleccionado: $150)\n");
        printf("2) Kit de Pastillas frenos (Precio seleccionado: $55)\n");
        printf("3) Kit de embragues (Precio seleccionado: $180)\n");
        printf("4) Faro (Precio selecionado: $70)\n");
        printf("5) Radiador (Precio seleccionado: $120)\n");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
          printf("ingrese la cantidad de Llantasque requiera comprar: \n");
          scanf("%f", &numA);
          break;

        case 2:
          printf("ingrese la cantidad de Kit de pastillas de frenos que "
                 "requiera comprar: \n");
          scanf("%f", &numB);
          break;

        case 3:
          printf("ingrese la cantidad de Kit de embargue que requiera comprar: "
                 "\n");
          scanf("%f", &numC);
          break;

        case 4:
          printf("ingrese el numero correspondiente de Faros: \n");
          scanf("%f", &numD);
          break;

        case 5:
          printf("ingrese el numero correspondiente de Radiadores:\n");
          scanf("%f", &numE);
          break;
        }
        if (opcion > 5) {
          printf("Falla de productos, mas eleccion intente de nuevo\n");
        }
        printf("Quiere elegir mas productos?  Si=1  No=0\n");
        scanf("%d", &opcion2);
      } while (opcion2 == 1);
      break;

    case 2:
      printf("nombre y apellido del cliente: \n");
      scanf("%s\n", nombre);
      printf("numero de cedula del cliente: \n");
      scanf("%s\n", cedula);

      printf("\n++++++++++Datos del Cliente++++++++\n");
      printf("Nombre: %s\n", nombre);
      printf("Cedula: %s\n", cedula);

      subtotalA = numA * precioA;
      subtotalB = numB * precioB;
      subtotalC = numC * precioC;
      subtotalD = numD * precioD;
      subtotalE = numE * precioE;

      printf("\n+++++++++++Facturación Final++++++++++++\n");
      printf("Items                     Cantidaddes              Precio        "
             "         Precio total\n");
      if (numA != 0) {
        printf("Llanta                  %.2f                  %.2f             "
               "         %.2f\n",
               numA, precioA, subtotalA);
      }
      if (numB != 0) {
        printf("Kits de frenos               %.2f                  %.2f        "
               "              %.2f\n",
               numB, precioB, subtotalB);
      }
      if (numC != 0) {
        printf("Kits de embrague             %.2f                  %.2f        "
               "              %.2f\n",
               numC, precioC, subtotalC);
      }
      if (numD != 0) {
        printf("Numero de Faros                    %.2f                  %.2f  "
               "                    %.2f\n",
               numD, precioD, subtotalD);
      }
      if (numE != 0) {
        printf("Numeros de Radidadores                %.2f                  "
               "%.2f                      %.2f\n",
               numE, precioE, subtotalE);
      }

      subtotal = subtotalA + subtotalB + subtotalC + subtotalD, subtotalE;

      if (subtotal > 501 && subtotal <= 1000) {
        subtotal = subtotal * 0.04;
      } else if (subtotal > 1001 && subtotal <= 5000) {
        subtotal = subtotal * 0.07;
      } else if (subtotal > 5000) {
        subtotal = subtotal * 0.09;
      }

      total = subtotal * 1.12;

      printf("subtotal correspondiente es: %.2f\n", subtotal);
      printf("total correspondiente es: %.2f\n\n\n", total);
      break;
    }
        
  } while (menu != 3);

  return 0;
}