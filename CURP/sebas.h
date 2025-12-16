// Sebastian Calderon Avalos
// Grupo: 28
// Fecha:  Ultima modificacion : 19/10/25

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _curp
{
    int edad;
    char nombre[30];
    char paterno[30];
    char materno[30];
    int sexo;
    char estado[20];
    int ano;
    int mes;
    int dia;
 

} Ts_curp;

char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    if (fgets(cadena, tamano, stdin) == NULL)
        return NULL;
    longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n')
    {
        cadena[longitud - 1] = '\0';
    }
    return cadena;
}

int contar_caracteres(char cadena[])
{
    int i = 0,cont =0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            
            
         cont++;
            
        }
        i++;
    }
    return cont;
}

int busqueda_secuencial_vector(Ts_curp vector[], int n, int valor)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i].edad == valor)
        {
            return i;
        }
    }
    return -1;
}

int busqueda_secuencial_matriz(int matriz[4][4], int valor)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (matriz[i][j] == valor)
            {
                return 1;
            }
        }
    }
    return -1;
}

int validar_num()
{
    char cadena[30];
    int valor = 0, i = 0;
    if (fgets(cadena, 30, stdin) == NULL)
        return -1;
    while (cadena[i] == ' ' || cadena[i] == '\t')
        i++;
    if (cadena[i] == '\n' || cadena[i] == '\0')
        return -1;
    for (; cadena[i] != '\0' && cadena[i] != '\n'; i++)
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            valor = valor * 10 + (cadena[i] - '0');
        }
        else
        {
            return -1;
        }
    }
    return valor;
}

int buscar_valor(int vector[], int n, int valor)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        
    }
        
}

int validar(int min, int max, const char *mensaje)
{
    int num;
    do
    {
        printf("%s", mensaje);
        if (scanf("%d", &num) != 1)
        {
            limpiar_buffer();
            printf("Entrada invalida. Intenta de nuevo.\n");
            continue;
        }
        limpiar_buffer();
        if (num < min || num > max)
        {
            printf("Valor fuera de rango (%d - %d). Intenta de nuevo.\n", min, max);
        }
        else
            break;
    } while (1);
    return num;
}
void convertir_mayusculas(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
}



/*
void burbuja(Ts_Alumno vector[], int n)
{
    Ts_Alumno temp;
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vector[j].matricula > vector[j + 1].matricula)
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}


void seleccion(Ts_Alumno vector[], int n)
{
    int i, j, aux;
    Ts_Alumno temp;
    for (i = 0; i < n; i++)
    {
        aux = i;
        for (j = i + 1; j < n; j++)
        {
            if (vector[j].matricula < vector[aux].matricula)
            {
                aux = j;
            }
        }
        temp = vector[i];
        vector[i] = vector[aux];
        vector[aux] = temp;
    }
}

void insercion(Ts_Alumno vector[], int n)
{
    int i;
    Ts_Alumno temp;
    for (i = 1; i < n; i++)
    {
        int j = i;
        temp = vector[i];
        while (j > 0 && temp.matricula < vector[j - 1].matricula)
        {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = temp;
    }
}

int busqueda_binaria(Ts_Alumno vector[], int fin, int valor)
{
    int mitad, inicio = 0;
    while (inicio <= fin)
    {
        mitad = (inicio + fin) / 2;
        if (valor == vector[mitad].matricula)
        {
            return mitad;
        }
        else
        {
            if (valor > vector[mitad].matricula)
            {
                inicio = mitad + 1;
            }
            else
            {
                fin = mitad - 1;
            }
        }
    }
    return -1;
}

*/