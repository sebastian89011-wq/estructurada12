// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 5/10/25

#include "sebas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcion;
int vector[15], n = 15;     
int matriz[4][4];           
int valor, num;


void llenar_vector(int vector[], int n);
void llenar_matriz(int matriz[4][4]);
void imprimir_vector(int vector[], int n);
void imprimir_matriz(int matriz[4][4]);
void ordenar_vector(int vector[], int n);
int buscar_valor2(int vector[], int n, int valor);

int main()
{
    srand(time(NULL));

    do {
        printf("\n===== MENU =====\n");
        printf("1. LLENAR VECTOR\n");
        printf("2. LLENAR MATRIZ\n");
        printf("3. IMPRIMIR VECTOR\n");
        printf("4. IMPRIMIR MATRIZ\n");
        printf("5. ORDENAR VECTOR\n");
        printf("6. BUSCAR VALOR EN VECTOR\n");
        printf("7. SALIR\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
        case 1:
            llenar_vector(vector, n);
            break;
        case 2:
            llenar_matriz(matriz);
            break;
        case 3:
            imprimir_vector(vector, n);
            break;
        case 4:
            imprimir_matriz(matriz);
            break;
        case 5:
            ordenar_vector(vector, n);
            break;
        case 6:
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &valor);
            num = buscar_valor(vector, n, valor);
            if (num  != -1)
            {
                printf("Valor encontrado en la posicion %d\n", num);
            }
            else
            {
                printf("Valor no encontrado.\n");
            }
            break;
        case 7:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 7);

    return 0;
}


void llenar_vector(int vector[], int n)
{
    int i, aleatorio;
    printf("\nLLENANDO VECTOR...\n");

    for (i = 0; i < n; i++)
    {
        do {
            aleatorio = (rand() % (200 - 100 + 1)) + 100;
        } while(busqueda_secuencial_vector(vector, i, aleatorio) != -1);

        vector[i] = aleatorio;
        printf("[%d] = %d\n", i, aleatorio);
    }
}

void llenar_matriz(int matriz[4][4])
{
    int i, j, aleatorio;
    printf("\nLLENANDO MATRIZ 4x4...\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            do {
                aleatorio = (rand() % 16) + 1;
            } while(busqueda_secuencial_matriz(matriz, aleatorio) != -1);

            matriz[i][j] = aleatorio;
        }
    }
}

void imprimir_vector(int vector[], int n)
{
    int i;
    printf("\nVECTOR:\n");
    for(i = 0; i < n; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

void imprimir_matriz(int matriz[4][4])
{
    int i, j;
    printf("\nMATRIZ 4x4:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }
}

int buscar_valor2(int vector[], int n, int valor)
{
    int i,bandera;
    for(i=0;i<n;i++)
    {
        if(vector[i] == valor)
        {
            return i;

        }
    
    }
    return -1;
    
    
}
void ordenar_vector(int vector[], int n)
{
     int temp,j;
    printf("\nVECTOR SIN ORDENAR:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", vector[i]);
    printf("\n");

    for(int i=0;i < n; i++)
    {
        for(j=0;j < n - 1 ; j++)
        {
            if(vector[j] > vector[j + 1])
            {
             temp = vector[j];
             vector[j] = vector[j + 1];
             vector[j + 1] = temp;
            }
            
        }
    }
    for(j=0;j<n;j++)
    {
        printf("\n[%d] == %d",j,vector[j]);

    }


    
    
}

