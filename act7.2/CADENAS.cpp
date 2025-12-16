// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 30/9/25

#include "sebas.h"

int main()
{
    char cadena[100];
    char cadena_sin_esp[100]; 
    int op;

    do
    {
        printf("\n....MENU....");
        printf("\n1. Ingresar cadena");
        printf("\n2. Mostrar en MAYÚSCULAS");
        printf("\n3. Mostrar en MINÚSCULAS");
        printf("\n4. Mostrar en CAPITAL");
        printf("\n5. Contar caracteres");
        printf("\n6. Invertir cadena");
        printf("\n7. Mostrar sin espacios");
        printf("\n8. SALIR\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);
        fflush(stdin); 

        switch (op)
        {
        case 1:
            printf("\nIngrese la cadena: ");
            my_gets(cadena, 100);
            break;
        case 2:
            convertir_mayusculas(cadena);
            printf("\nCadena en MAYÚSCULAS: %s\n", cadena);
            break;
        case 3:
            convertir_minusculas(cadena);
            printf("\nCadena en MINÚSCULAS: %s\n", cadena);
            break;
        case 4:
            capitalizar(cadena);
            printf("\nCadena en CAPITAL: %s\n", cadena);
            break;
        case 5:
            int total;
            total = contar_caracteres(cadena);
            printf("\nEl numero de caracteres es: %d", total);
            break;
        case 6:
            invertir_cadena(cadena);
            printf("\nCadena invertida: %s\n", cadena);
            break;
        case 7:
            eliminar_espacios(cadena, cadena_sin_esp);
            printf("Cadena sin espacios: %s\n", cadena_sin_esp);
            break;
        case 8:
            printf("\nFin del programa...\n");
            break;
        default:
            printf("\nOpción no válida\n");
        }

    } while (op != 8);

    return 0;
}
