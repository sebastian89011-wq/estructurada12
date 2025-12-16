// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 7/10/25

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


int contar_caracteres(char cadena[])
{
    int i=0;
    do
    {
        i++;
    }while(cadena[i]!='\0');
    return i;
        

}



int busqueda_secuencial_vector(int vector[], int n, int valor)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(vector[i] == valor)
		{
			return i;
		}

	}
	return -1;
}

int busqueda_secuencial_matriz( int matriz[4][4],  int valor  )
{
    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(matriz[i][j] == valor)
            {
                return 1;
            }
        }
    }


    return -1;
}

int validar_num()
{
    int i,valor;
    char cadena[30];

    while(cadena[i]!='\0')
    {
        fgets(cadena,30,stdin);
        if(cadena[i]>='0' && cadena[i]<='9')
        {
            valor = valor * 10 + (cadena[i] - '0');
            

        }
        else 
        {
            return -1;

        }
        i++;
    }
    return 1;
}
int buscar_valor(int vector[], int n, int valor)
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

