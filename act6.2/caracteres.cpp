
#include "sebas.h"

#define TAM 100

char *my_gets(char *cadena, int tamano);
int msges();
void menu();
void leecadena(char cadena[], int n);

void patron1(char cadena[]);
void patron2(char cadena[]);
void patron3(char cadena[]);
void patron4(char cadena[]);
void patron5(char cadena[]);
void patron6(char cadena[]);
void patron7(char cadena[]);

int main()
{
    menu();
    return 0;
}



int msges()
{
    int op;
    printf("\nMENU DE PATRONES\n");
    printf("1.- LEER CADENA\n");
    printf("2.- PATRON 1\n");
    printf("3.- PATRON 2\n");
    printf("4.- PATRON 3\n");
    printf("5.- PATRON 4\n");
    printf("6.- PATRON 5\n");
    printf("7.- PATRON 6\n");
    printf("8.- PATRON 7\n");
    printf("0.- SALIR\n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    getchar(); // Limpiar el '\n' pendiente del buffer
    return op;
}

void menu()
{
    char cadena[TAM];
    int op;
    cadena[0] = '\0';

    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            leecadena(cadena, TAM);
            break;
        case 2:
            patron1(cadena);
            break;
        case 3:
            patron2(cadena);
            break;
        case 4:
            patron3(cadena);
            break;
        case 5:
            patron4(cadena);
            break;
        case 6:
            patron5(cadena);
            break;
        case 7:
            patron6(cadena);
            break;
        case 8:
            patron7(cadena);
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }

    } while (op != 0);
}

void leecadena(char cadena[], int n)
{
    printf("\nESCRIBE UNA FRASE O PALABRA: ");
    my_gets(cadena, n);
    printf("\n");
}

void patron1(char cadena[])
{
    printf("\nPATRON 1:\n");
    printf("%s\n\n", cadena);
}

void patron2(char cadena[])
{
    int i;
    printf("\nPATRON 2:\n");
    for (i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c\n", cadena[i]);
    }
}

void patron3(char cadena[])
{
    int i;
    printf("\nPATRON 3:\n");
    for (i = '\0'; cadena[i]>=0; i--)
    {
        printf("%c\n", cadena[i]);
    }
}

void patron4(char cadena[])
{
    printf("\nPATRON 4:\n");
    printf("(Aquí imprimirás la cadena quitando la última letra cada fila)\n");
}

void patron5(char cadena[])
{
    printf("\nPATRON 5:\n");
    printf("(Aquí aplicarás el patrón 4 sobre la cadena invertida)\n");
}

void patron6(char cadena[])
{
    printf("\nPATRON 6:\n");
    printf("(Aquí imprimirás la cadena quitando la primera letra cada fila)\n");
}

void patron7(char cadena[])
{
    printf("\nPATRON 7:\n");
    printf("(Aquí aplicarás el patrón 6 sobre la cadena invertida)\n");
}
