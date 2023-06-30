#include <stdio.h>
#include <stdlib.h>

#define MAX_MASCOTAS 100
#define MAX_NOMBRE_MASCOTA 100
#define MAX_NOMBRE_DUENO 100

int main() {
    int opcion;
    int identificador = 1;
    char mascotas[MAX_MASCOTAS][MAX_NOMBRE_MASCOTA];
    char tipos[MAX_MASCOTAS][MAX_NOMBRE_MASCOTA];
    int edades[MAX_MASCOTAS];
    char duenos[MAX_MASCOTAS][MAX_NOMBRE_DUENO];
    int facturaTotal = 0;
    int serviciosRealizados[MAX_MASCOTAS][4];

    for (int i = 0; i < MAX_MASCOTAS; i++) {
        for (int j = 0; j < 4; j++) {
            serviciosRealizados[i][j] = 0;
        }
    }

    do {
        printf("********Menu*********\n");
        printf("1. Ingresar Mascota\n");
        printf("2. Servicios\n");
        printf("3. Facturar\n");
        printf("4. Cerrar programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ha seleccionado 'Ingresar Mascota'\n");
                if (identificador < MAX_MASCOTAS) {
                    printf("Ingrese el nombre de la mascota: ");
                    scanf("%s", mascotas[identificador]);
                    printf("Ingrese el tipo de mascota (Perro, Gato, etc.): ");
                    scanf("%s", tipos[identificador]);
                    printf("Ingrese la edad de la mascota: ");
                    scanf("%d", &edades[identificador]);
                    printf("Ingrese el nombre del dueno: ");
                    scanf("%s", duenos[identificador]);
                    printf("La mascota con ID %d ha sido ingresada\n", identificador);
                    identificador++;
                } else {
                    printf("Limite de mascotas alcanzado\n");
                }
                break;
            case 2:
                printf("Ha seleccionado 'Servicios'\n");
                printf("/////////////////////////////////////////////////////\n");
                printf("| Servicio | Descripcion | Precio | ID Servicio |\n");
                printf("/////////////////////////////////////////////////////\n");
                printf("| Corte de Pelo | Servicio de corte | $5 | 1 |\n");
                printf("| Bano | Servicio de bano | $10 | 2 |\n");
                printf("| Cuidado Dental | Limpieza dental | $8 | 3 |\n");
                printf("| Vacunacion | Vacunacion basica | $15 | 4 |\n");
                printf("//////////////////////////////////////////////////////\n");
                break;
            case 3:
                printf("Ha seleccionado 'Facturar'\n");
                int idMascota;
                int servicio;
                int otroServicio;
                int precioServicio = 0;
                int totalServicios = 0;

                printf("Ingrese el ID de la mascota: ");
                scanf("%d", &idMascota);

                for (int i = 0; i < 4; i++) {
                    serviciosRealizados[idMascota][i] = 0;
                }
                totalServicios = 0;

                printf("Ingrese el servicio realizado (Ingrese el ID del servicio): ");
                scanf("%d", &servicio);

                do {
                    switch (servicio) {
                        case 1:
                            precioServicio = 5;
                            serviciosRealizados[idMascota][0] = 1;
                            break;
                        case 2:
                            precioServicio = 10;
                            serviciosRealizados[idMascota][1] = 1;
                            break;
                        case 3:
                            precioServicio = 8;
                            serviciosRealizados[idMascota][2] = 1;
                            break;
                        case 4:
                            precioServicio = 15;
                            serviciosRealizados[idMascota][3] = 1;
                            break;
                        default:
                            printf("ID de servicio invalido. Por favor, seleccione un ID de servicio valido.\n");
                            break;
                    }

                    if (precioServicio > 0) {
                        totalServicios += precioServicio;
                        printf("Servicio agregado correctamente.\n");
                    }

                    printf("¿Desea realizar otro servicio? (1 = Si, 0 = No): ");
                    scanf("%d", &otroServicio);

                    if (otroServicio) {
                        printf("Ingrese el siguiente servicio (Ingrese el ID del servicio): ");
                        scanf("%d", &servicio);
                    }
                } while (otroServicio);

                printf("\n******** Factura *********\n");
                printf("ID Mascota: %d\n", idMascota);
                printf("Nombre: %s\n", mascotas[idMascota]);
                printf("Edad: %d\n", edades[idMascota]);
                printf("Tipo: %s\n", tipos[idMascota]);
                printf("Dueno: %s\n", duenos[idMascota]);
                printf("Servicios realizados:\n");

                printf("/////////////////////////////////////////////////////\n");
                printf("| Servicio | Descripcion | Precio | ID Servicio |\n");
                printf("/////////////////////////////////////////////////////\n");
                if (serviciosRealizados[idMascota][0]) {
                    printf("| Corte de Pelo | Servicio de corte | $5 | 1 |\n");
                }
                if (serviciosRealizados[idMascota][1]) {
                    printf("| Bano | Servicio de bano | $10 | 2 |\n");
                }
                if (serviciosRealizados[idMascota][2]) {
                    printf("| Cuidado Dental | Limpieza dental | $8 | 3 |\n");
                }
                if (serviciosRealizados[idMascota][3]) {
                    printf("| Vacunacion | Vacunacion basica | $15 | 4 |\n");
                }
                printf("////////////////////////////////////////////////////\n");

                facturaTotal += totalServicios;
                printf("El total a pagar de todas las facturas es: %d\n", facturaTotal);
                break;
            case 4:
                printf("Cerrando programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }

        printf("\n");
    } while (opcion != 4);

    return 0;
}