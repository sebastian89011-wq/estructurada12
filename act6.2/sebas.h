
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    fgets(cadena, tamano, stdin);
    if (cadena)
    {
        longitud = strlen(cadena);
        if (longitud > 0 && cadena[longitud - 1] == '\n')
        {
            cadena[longitud - 1] = '\0';
        }
        return cadena;
    }
    return NULL;
}



