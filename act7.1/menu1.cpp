// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 29/9/25

#include "sebas.h"

int vector1[10];
int vector2[10];
int vector3[20];
int matriz[4][4];
char cadenas[10][30];

void menu();
void llenar_manual();
void llenar_aleatorio();
void llenar_vecxvec();
void imprimir_vec();
void llenar_matriz();
void imprimir_matriz();
void vector_cadenas();
void imprimir_cadenas();

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

void menu()
{
    int i, op;

    do
    {
        printf("\n....MENU....");
        printf("\n1. LLENAR VECTOR 1 (MANUALMENTE)");
        printf("\n2. LLENAR VECTOR 2 (ALEATORIAMENTE)");
        printf("\n3. LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)");
        printf("\n4. IMPRIMIR VECTORES");
        printf("\n5. LLENAR MATRIZ 4x4");
        printf("\n6. IMPRIMIR MATRIZ");
        printf("\n7. VECTOR DE CADENAS");
        printf("\n8. IMPRIMIR VECTOR DE CADENAS");
        printf("\n9. SALIR\n");
        scanf("%d", &op);
        getchar(); 

        switch (op)
        {
        case 1:
            llenar_manual();
            break;

        case 2:
            llenar_aleatorio();
            break;

        case 3:
            llenar_vecxvec();
            break;

        case 4:
            imprimir_vec();
            break;

        case 5:
            llenar_matriz();
            break;

        case 6:
            imprimir_matriz();
            break;

        case 7:
            vector_cadenas();
            break;

        case 8:
            imprimir_cadenas();
            break;

        default:
            printf("\nFin del programa......");
        }
    } while (op != 9);
}

void llenar_manual()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        do
        {
            printf("\n[%d] = ", i);
            scanf("%d", &vector1[i]);
            getchar(); 
            if (vector1[i] < 30 || vector1[i] > 70)
            {
                printf("\nFuera de rango");
            }
        } while (vector1[i] < 30 || vector1[i] > 70);
    }
}
void llenar_aleatorio()
{

    int i, aleatorio;
    printf("\nVector 2");

    for (i = 0; i < 10; i++)
    {
        aleatorio = (rand() % (20 - 1 + 1)) + 1;
        vector2[i] = aleatorio;
        printf("\n[%d] == %d", i, aleatorio);
    }
}
void llenar_vecxvec()
{
    int i, j = 0;
    printf("\nVector 3");
    printf("\nFusionando vector 1 y vector 2..... ");
    for (i = 0; i < 10; i++)
    {
        vector3[i] = vector1[i];
    }
    i = 10;
    while (i < 20 && j < 10)
    {
        vector3[i] = vector2[j];
        i++;
        j++;
    }
}
void imprimir_vec()
{
    int i, op;
    printf("Cual vector desea ver: ");
    printf("\n1. Vector 1");
    printf("\n2. Vector 2");
    printf("\n3. Vector 3\n");
    scanf("%d", &op);
    getchar(); 

    switch (op)
    {
    case 1:
        for (i = 0; i < 10; i++)
        {
            printf("\n[%d] == %d", i, vector1[i]);
        }
        break;

    case 2:
        for (i = 0; i < 10; i++)
        {
            printf("\n[%d] == %d", i, vector2[i]);
        }
        break;
    case 3:
        for (i = 0; i < 20; i++)
        {
            printf("\n[%d] == %d", i, vector3[i]);
        }
        break;

    default:
        printf("\nOpcion no disponible");
        return;
    }
}
void llenar_matriz()
{
    int i, j, m = 0;
    printf("LLENANDO MATRIZ....");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz[i][j] = vector3[m];
            m++;
        }
    }
}
void imprimir_matriz()
{
    int i, j;
    printf("\n...MATRIZ...\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void vector_cadenas()
{
    int i, continuar;
    printf("\n...VECTOR DE CADENAS...");
    for (i = 0; i < 10; i++)
    {
        printf("\n[%d] == ", i);
        my_gets(cadenas[i], 30);

        if (i < 9)
        {
            printf("\nQuieres introducir otra cadena?(1.Si  ,  2.No) ");
            scanf("%d", &continuar);
            getchar(); 
            if (continuar == 2)
            {
                return;
            }
        }
    }
}
void imprimir_cadenas()
{
    int i;
    printf("IMPRIMIENDO...");
    for (i = 0; i < 10; i++)
    {
        printf("\n[%d] == %s",i, cadenas[i]);
    }
}
