// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 14/10/25
#include "sebas2.0.h"


int main()
{
    int MAX_ALUMNOS = 2500;
    int opcion;
    Ts_Alumno alumnos[MAX_ALUMNOS];
    srand(time(NULL));

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. AGREGAR (AUTOMÁTICO)\n");
        printf("2. AGREGAR MANUAL\n");
        printf("3. ELIMINAR REGISTRO\n");
        printf("4. BUSCAR\n");
        printf("5. ORDENAR\n");
        printf("6. IMPRIMIR\n");
        printf("7. SALIR\n");
        printf("Seleccione una opción: ");
        scanf("%d",&opcion);
        if (opcion == -1)
        {
            printf("Error: no es un número válido.\n");
        }
    

        switch(opcion) {
            case 1: agregar_automatico(alumnos,MAX_ALUMNOS); 
            break;
            case 2: agregar_manual(alumnos,MAX_ALUMNOS); 
            break;
            case 3: eliminar_registro(alumnos,MAX_ALUMNOS); 
            break;
            case 4: buscar_alumno(alumnos,MAX_ALUMNOS); 
            break;
            case 5: ordenar_registros(alumnos,MAX_ALUMNOS); 
            break;
            case 6: imprimir_registros(alumnos,MAX_ALUMNOS); 
            break;
            case 7: printf("Saliendo del programa...\n"); 
            break;
        }
    } while(opcion != 7);

    return 0;
}
