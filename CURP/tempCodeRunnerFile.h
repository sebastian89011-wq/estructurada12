#include "sebas.h"

Ts_curp generar_curp(char curp[19]);




char consonante_interna(char consonante[])
{
    for (int i = 1; consonante[i] != '\0'; i++)
    {
        if (consonante[i] != 'A' && consonante[i] != 'E' && consonante[i] != 'I' && consonante[i] != 'O' && consonante[i] != 'U')
        {
            return consonante[i];
        }
    }
    return 'X';
}

char letra_inicial(char inicial[])
{
    if (inicial[0] == 'Ñ')
    {
        return 'X';
    }
    else
    {
        return inicial[0];
    }
}

void validar_nombre(char inicial[],char nombre[])
{
    int i = 0,j = 0;
    char primer_nombre[20];

    do
    {
        primer_nombre[i] = inicial[i];

        i++;
    } while (inicial[i] != ' ' && inicial[i] != '\0');
    primer_nombre[i] = '\0';

    if (comparar_cadenas("MARIA", primer_nombre) == 0 || comparar_cadenas("MA", primer_nombre) == 0 || comparar_cadenas("MA.", primer_nombre) == 0 || comparar_cadenas("JOSE", primer_nombre) == 0 || comparar_cadenas("J", primer_nombre) == 0 || comparar_cadenas("J.", primer_nombre) == 0)
    {
        while(inicial[i] == ' ')
        {
            i++;
        }

        while(inicial[i] != ' ' && inicial[i] != '\0')
        {
            nombre[j++] = inicial[i++];
        }
        nombre[j] = '\0';
       
    }
    else
    {
        copiar_str(nombre,primer_nombre);
    }
   
}

int caracter_especial(char simbolo)
{
    int i;

    if (simbolo >= 'A' && simbolo <= 'Z' || simbolo == 'Ñ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char filtrar_caracter(char caracter)
{

    if (caracter_especial(caracter) == 1)
    {
        return caracter;
    }
    else
    {
        return 'X';
    }
}
char vocal_interna(char apellido[])
{
    for (int i = 1; apellido[i] != '\0'; i++)
    {
        char c = apellido[i];

        
        if (filtrar_caracter(c) == 'X')
        {
            return 'X';
        }

      
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return c;
        }
    }
    return 'X';
}

int validar_groseria(char palabra[])
{
    char insulto[5];
    int i;

    for (i = 0; i < 4; i++)
    {
        insulto[i] = palabra[i];
    }
    insulto[i] = '\0';
    if (comparar_cadenas("BAKA", insulto) == 0 ||
        comparar_cadenas("BUEI", insulto) == 0 ||
        comparar_cadenas("BUEY", insulto) == 0 ||
        comparar_cadenas("CACA", insulto) == 0 ||
        comparar_cadenas("CACO", insulto) == 0 ||
        comparar_cadenas("CAGA", insulto) == 0 ||
        comparar_cadenas("CAGO", insulto) == 0 ||
        comparar_cadenas("CAKA", insulto) == 0 ||
        comparar_cadenas("CAKO", insulto) == 0 ||
        comparar_cadenas("COGE", insulto) == 0 ||
        comparar_cadenas("COGI", insulto) == 0 ||
        comparar_cadenas("COJA", insulto) == 0 ||
        comparar_cadenas("COJE", insulto) == 0 ||
        comparar_cadenas("COJI", insulto) == 0 ||
        comparar_cadenas("COJO", insulto) == 0 ||
        comparar_cadenas("COLA", insulto) == 0 ||
        comparar_cadenas("CULO", insulto) == 0 ||
        comparar_cadenas("FALO", insulto) == 0 ||
        comparar_cadenas("FETO", insulto) == 0 ||
        comparar_cadenas("GETA", insulto) == 0 ||
        comparar_cadenas("GUEI", insulto) == 0 ||
        comparar_cadenas("GUEY", insulto) == 0 ||
        comparar_cadenas("JETA", insulto) == 0 ||
        comparar_cadenas("JOTO", insulto) == 0 ||
        comparar_cadenas("KACA", insulto) == 0 ||
        comparar_cadenas("KACO", insulto) == 0 ||
        comparar_cadenas("KAGA", insulto) == 0 ||
        comparar_cadenas("KAGO", insulto) == 0 ||
        comparar_cadenas("KAKA", insulto) == 0 ||
        comparar_cadenas("KAKO", insulto) == 0 ||
        comparar_cadenas("KOGE", insulto) == 0 ||
        comparar_cadenas("KOGI", insulto) == 0 ||
        comparar_cadenas("KOJA", insulto) == 0 ||
        comparar_cadenas("KOJE", insulto) == 0 ||
        comparar_cadenas("KOJI", insulto) == 0 ||
        comparar_cadenas("KOJO", insulto) == 0 ||
        comparar_cadenas("KOLA", insulto) == 0 ||
        comparar_cadenas("KULO", insulto) == 0 ||
        comparar_cadenas("LILO", insulto) == 0 ||
        comparar_cadenas("LOCA", insulto) == 0 ||
        comparar_cadenas("LOCO", insulto) == 0 ||
        comparar_cadenas("LOKA", insulto) == 0 ||
        comparar_cadenas("LOKO", insulto) == 0 ||
        comparar_cadenas("MAME", insulto) == 0 ||
        comparar_cadenas("MAMO", insulto) == 0 ||
        comparar_cadenas("MEAR", insulto) == 0 ||
        comparar_cadenas("MEAS", insulto) == 0 ||
        comparar_cadenas("MEON", insulto) == 0 ||
        comparar_cadenas("MIAR", insulto) == 0 ||
        comparar_cadenas("MION", insulto) == 0 ||
        comparar_cadenas("MOCO", insulto) == 0 ||
        comparar_cadenas("MOKO", insulto) == 0 ||
        comparar_cadenas("MULA", insulto) == 0 ||
        comparar_cadenas("MULO", insulto) == 0 ||
        comparar_cadenas("NACA", insulto) == 0 ||
        comparar_cadenas("NACO", insulto) == 0 ||
        comparar_cadenas("PEDA", insulto) == 0 ||
        comparar_cadenas("PEDO", insulto) == 0 ||
        comparar_cadenas("PENE", insulto) == 0 ||
        comparar_cadenas("PIPI", insulto) == 0 ||
        comparar_cadenas("PITO", insulto) == 0 ||
        comparar_cadenas("POPO", insulto) == 0 ||
        comparar_cadenas("PUTA", insulto) == 0 ||
        comparar_cadenas("PUTO", insulto) == 0 ||
        comparar_cadenas("QULO", insulto) == 0 ||
        comparar_cadenas("RATA", insulto) == 0 ||
        comparar_cadenas("ROBA", insulto) == 0 ||
        comparar_cadenas("ROBE", insulto) == 0 ||
        comparar_cadenas("ROBO", insulto) == 0 ||
        comparar_cadenas("RUIN", insulto) == 0 ||
        comparar_cadenas("SENO", insulto) == 0 ||
        comparar_cadenas("TETA", insulto) == 0 ||
        comparar_cadenas("VACA", insulto) == 0 ||
        comparar_cadenas("VAGA", insulto) == 0 ||
        comparar_cadenas("VAGO", insulto) == 0 ||
        comparar_cadenas("VAKA", insulto) == 0 ||
        comparar_cadenas("VUEI", insulto) == 0 ||
        comparar_cadenas("VUEY", insulto) == 0 ||
        comparar_cadenas("WUEI", insulto) == 0 ||
        comparar_cadenas("WUEY", insulto) == 0)
    {
        return 1;
    }
    return -1;
}

void preposicion(char preposicion[])
{
    char palabra[20];
    int i = 0, j = 0, n = 0;

    do
    {
        palabra[i] = preposicion[i];

        i++;
    } while (preposicion[i] != ' ' && preposicion[i] != '\0');
    palabra[i] = '\0';

    while (detectar_pre(palabra) == 1)
    {

        if (preposicion[i] != '\0')
        {
            if (preposicion[i] == ' ')
            {
                i++;
            }
            j = 0;

            do
            {
                palabra[j] = preposicion[i];

                j++;
                i++;
            } while (preposicion[i] != ' ' && preposicion[i] != '\0');

            palabra[j] = '\0';
        }
        if (detectar_pre(palabra) != 1)
        {
            copiar_str(preposicion, palabra);
        }
    }
}
int detectar_pre(char preposicion[])
{

    if (comparar_cadenas("DA", preposicion) == 0)
    {
        return 1;
    }
    else
    {
        if (comparar_cadenas("DAS", preposicion) == 0)
        {
            return 1;
        }
        else
        {
            if (comparar_cadenas("DE", preposicion) == 0)
            {
                return 1;
            }
            else
            {
                if (comparar_cadenas("DEL", preposicion) == 0)
                {
                    return 1;
                }
                else
                {
                    if (comparar_cadenas("DER", preposicion) == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        if (comparar_cadenas("DI", preposicion) == 0)
                        {
                            return 1;
                        }
                        else
                        {
                            if (comparar_cadenas("DIE", preposicion) == 0)
                            {
                                return 1;
                            }
                            else
                            {
                                if (comparar_cadenas("DD", preposicion) == 0)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (comparar_cadenas("EL", preposicion) == 0)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (comparar_cadenas("LA", preposicion) == 0)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (comparar_cadenas("LOS", preposicion) == 0)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (comparar_cadenas("LAS", preposicion) == 0)
                                                {
                                                    return 1;
                                                }
                                                else
                                                {
                                                    if (comparar_cadenas("LE", preposicion) == 0)
                                                    {
                                                        return 1;
                                                    }
                                                    else
                                                    {
                                                        if (comparar_cadenas("LES", preposicion) == 0)
                                                        {
                                                            return 1;
                                                        }
                                                        else
                                                        {
                                                            if (comparar_cadenas("MAC", preposicion) == 0)
                                                            {
                                                                return 1;
                                                            }
                                                            else
                                                            {
                                                                if (comparar_cadenas("MC", preposicion) == 0)
                                                                {
                                                                    return 1;
                                                                }
                                                                else
                                                                {
                                                                    if (comparar_cadenas("VAN", preposicion) == 0)
                                                                    {
                                                                        return 1;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (comparar_cadenas("VON", preposicion) == 0)
                                                                        {
                                                                            return 1;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (comparar_cadenas("Y", preposicion) == 0)
                                                                            {
                                                                                return 1;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int comprobar_existencia(char dato[])
{
    if(contar_caracteres(dato) == 0)
    {
        return 1;

    }

    return 0;
}

void obtener_apellido_valido(char destino[], char paterno[], char materno[])
{
    if(comprobar_existencia(paterno) == 1)
    {
        copiar_str(destino,materno);
    }
    else
    {
        copiar_str(destino,paterno);
    }

}

/* Devuelve 1 si 'estado' coincide con una clave válida de entidad federativa (CURP),
   0 en caso contrario. Usa comparar_cadenas("XX", estado) == 0 para comparar. */
int validar_estado(char estado[])
{
    if (comparar_cadenas("AS", estado) == 0)
    {
        return 1;
    }
    else
    {
        if (comparar_cadenas("BC", estado) == 0)
        {
            return 1;
        }
        else
        {
            if (comparar_cadenas("BS", estado) == 0)
            {
                return 1;
            }
            else
            {
                if (comparar_cadenas("CC", estado) == 0)
                {
                    return 1;
                }
                else
                {
                    if (comparar_cadenas("CL", estado) == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        if (comparar_cadenas("CM", estado) == 0)
                        {
                            return 1;
                        }
                        else
                        {
                            if (comparar_cadenas("CS", estado) == 0)
                            {
                                return 1;
                            }
                            else
                            {
                                if (comparar_cadenas("CH", estado) == 0)
                                {
                                    return 1;
                                }
                                else
                                {
                                    if (comparar_cadenas("DF", estado) == 0)
                                    {
                                        return 1;
                                    }
                                    else
                                    {
                                        if (comparar_cadenas("DG", estado) == 0)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            if (comparar_cadenas("GT", estado) == 0)
                                            {
                                                return 1;
                                            }
                                            else
                                            {
                                                if (comparar_cadenas("GR", estado) == 0)
                                                {
                                                    return 1;
                                                }
                                                else
                                                {
                                                    if (comparar_cadenas("HG", estado) == 0)
                                                    {
                                                        return 1;
                                                    }
                                                    else
                                                    {
                                                        if (comparar_cadenas("JC", estado) == 0)
                                                        {
                                                            return 1;
                                                        }
                                                        else
                                                        {
                                                            if (comparar_cadenas("MC", estado) == 0)
                                                            {
                                                                return 1;
                                                            }
                                                            else
                                                            {
                                                                if (comparar_cadenas("MN", estado) == 0)
                                                                {
                                                                    return 1;
                                                                }
                                                                else
                                                                {
                                                                    if (comparar_cadenas("MS", estado) == 0)
                                                                    {
                                                                        return 1;
                                                                    }
                                                                    else
                                                                    {
                                                                        if (comparar_cadenas("NT", estado) == 0)
                                                                        {
                                                                            return 1;
                                                                        }
                                                                        else
                                                                        {
                                                                            if (comparar_cadenas("NL", estado) == 0)
                                                                            {
                                                                                return 1;
                                                                            }
                                                                            else
                                                                            {
                                                                                if (comparar_cadenas("OC", estado) == 0)
                                                                                {
                                                                                    return 1;
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (comparar_cadenas("PL", estado) == 0)
                                                                                    {
                                                                                        return 1;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (comparar_cadenas("QT", estado) == 0)
                                                                                        {
                                                                                            return 1;
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (comparar_cadenas("QR", estado) == 0)
                                                                                            {
                                                                                                return 1;
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (comparar_cadenas("SP", estado) == 0)
                                                                                                {
                                                                                                    return 1;
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (comparar_cadenas("SL", estado) == 0)
                                                                                                    {
                                                                                                        return 1;
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if (comparar_cadenas("SR", estado) == 0)
                                                                                                        {
                                                                                                            return 1;
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            if (comparar_cadenas("TC", estado) == 0)
                                                                                                            {
                                                                                                                return 1;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                if (comparar_cadenas("TS", estado) == 0)
                                                                                                                {
                                                                                                                    return 1;
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    if (comparar_cadenas("TL", estado) == 0)
                                                                                                                    {
                                                                                                                        return 1;
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                        if (comparar_cadenas("VZ", estado) == 0)
                                                                                                                        {
                                                                                                                            return 1;
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                            if (comparar_cadenas("YN", estado) == 0)
                                                                                                                            {
                                                                                                                                return 1;
                                                                                                                            }
                                                                                                                            else
                                                                                                                            {
                                                                                                                                if (comparar_cadenas("ZS", estado) == 0)
                                                                                                                                {
                                                                                                                                    return 1;
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    if (comparar_cadenas("NE", estado) == 0)
                                                                                                                                    {
                                                                                                                                        /* Nacido en el extranjero */
                                                                                                                                        return 1;
                                                                                                                                    }
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                        return 0; /* No coincide con ninguna clave válida */
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
