// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 15/11/25

int casi_orden(Ts_indice alumnos[], int *max)
{
    int i, desorden = 0;
    for (i = 0; i < *max - 1; i++)
    {
        if (alumnos[i].llave > alumnos[i + 1].llave)
        {
            desorden++;
        }
    }
    if (desorden < (*max - 1) * 0.10)
    {
        return 1;
    }
    return -1;
}

void concatenar(char palabra1[], const char palabra2[])
{
    int i = 0;
    while (palabra1[i] != '\0')
    {
        i++;
    }
    for (int j = 0; palabra2[j] != '\0'; j++)
    {
        palabra1[i] = palabra2[j];
        i++;
    }
    palabra1[i] = '\0';
}

int comparar_cadenas(char cadena1[], char cadena2[])
{
    int i;
    for (i = 0; cadena1[i] != '\0' && cadena2[i] != '\0'; i++)
    {
        if (cadena1[i] != cadena2[i])
        {
            return cadena1[i] - cadena2[i];
        }
    }
    return cadena1[i] - cadena2[i];
}

void eliminar_espacios(char ordinaria[])
{
    int i = 0, j = 0;
    char sinespacio[100];
    while (ordinaria[i] != '\0')
    {
        if (ordinaria[i] != ' ')
        {
            sinespacio[j] = ordinaria[i];
            j++;
        }
        i++;
    }
    sinespacio[j] = '\0';
    copiar_str(ordinaria, sinespacio);
}

int validar_letras(char cadena[])
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
        }
        else
        {
            return -1;
        }

        i++;
    }

    return 0;
}

int validar_letras_numeros(char cadena[])
{

    int i = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
        }
        else
        {
            if (cadena[i] >= '0')
            {
                if (cadena[i] <= '9')
                {
                }
                else
                {
                    return -1;
                }
            }
        }

        i++;
    }

    return 0;
}

int contar_caracteres(char cadena[])
{
    int i = 0, cont = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {

            cont++;
        }
        i++;
    }
    return cont;
}

int contar_caracteres_numeros(char cadena[])
{
    int i = 0, cont = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cont++;
        }
        else
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cont++;
            }
            else
            {
                if (cadena[i] >= '0' && cadena[i] <= '9')
                {
                    cont++;
                }
            }
        }
        i++;
    }

    return cont;
}

int encontrar_numero(char cadena[])
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] >= '0')
        {
            if (cadena[i] <= '9')
            {
                return 0;
            }
        }
        i++;
    }

    return -1;
}

int contar_caracteres_todo(char cadena[])
{
    int i = 0, cont = 0;

    while (cadena[i] != '\0')
    {
        cont++;
        i++;
    }

    return cont;
}

validar_nivel3(char cadena[])
{

    int i = 0;
    int especial, numero, mayuscula;
    int total;

    while (cadena[i] != '\0')
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                mayuscula = 1;
            }
        }

        if (cadena[i] >= '0')
        {
            if (cadena[i] <= '9')
            {
                numero = 1;
            }
        }

        if(!(cadena[i]>='A' && cadena[i]<='Z'))
        {
            if(!(cadena[i]>='a' && cadena[i]<='z'))
            {
                if(!(cadena[i]>='0' && cadena[i]<='9'))
                {
                    especial = 1;
                }
            }
        }

        i++;
    }
    total = mayuscula + especial + numero;
    if(total == 3)
    {
        return 0;
    }

    return -1;
}