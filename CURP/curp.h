// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 20/11/25

void copiar_str(char cadena1[], char cadena2[])
{
    int i;

    for (i = 0; cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];
    }
    cadena1[i] = '\0';
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

int validar_estado(char estado[])
{
    int i;
    char estados[33][3] = {
        "AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG",
        "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC",
        "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
        "YN", "ZS", "NE"};

    for (i = 0; i < 33; i++)
    {
        if (comparar_cadenas(estados[i], estado) == 0)
        {
            return 1;
        }
    }

    return 0;
}
int detectar_pre(char preposicion[])
{
    int i = 0;

    char preposiciones[25][10] =
        {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES",
         "MAC", "MC", "VAN", "VON", "Y", "MARIA", "MA", "MA.", "JOSE", "J", "J."};

    for (i = 0; i < 25; i++)
    {

        if (comparar_cadenas(preposiciones[i], preposicion) == 0)
        {
            return 1;
        }
    }

    return 0;
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
   
    char insultos[80][5] = {
        "BAKA","BUEI","BUEY","CACA","CACO",
        "CAGA","CAGO","CAKA","CAKO","COGE",
        "COGI","COJA","COJE","COJI","COJO",
        "COLA","CULO","FALO","FETO","GETA",
        "GUEI","GUEY","JETA","JOTO","KACA",
        "KACO","KAGA","KAGO","KAKA","KAKO",
        "KOGE","KOGI","KOJA","KOJE","KOJI",
        "KOJO","KOLA","KULO","LILO","LOCA",
        "LOCO","LOKA","LOKO","MAME","MAMO",
        "MEAR","MEAS","MEON","MIAR","MION",
        "MOCO","MOKO","MULA","MULO","NACA",
        "NACO","PEDA","PEDO","PENE","PIPI",
        "PITO","POPO","PUTA","PUTO","QULO",
        "RATA","ROBA","ROBE","ROBO","RUIN",
        "SENO","TETA","VACA","VAGA","VAGO",
        "VAKA","VUEI","VUEY","WUEI","WUEY"
    };


    for (i = 0; i < 80; i++)
    {
        if (comparar_cadenas(insultos[i], insulto) == 0)
        {
            palabra[1] = 'X';
            return 1;
        }
    }



    return -1;
}
int comprobar_existencia(char dato[])
{
    if (contar_caracteres(dato) == 0)
    {
        return 1;
    }

    return 0;
}

void obtener_apellido_valido(char destino[], char paterno[], char materno[])
{
    if (comprobar_existencia(paterno) == 1)
    {
        copiar_str(destino, materno);
    }
    else
    {
        copiar_str(destino, paterno);
    }
}

int validar_fecha(int anio, int mes, int dia)
{
    int cantidad;

    int ano[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (anio % 4 == 0)
    {
        ano[2] = 29;
    }
    cantidad = ano[mes];
    if (dia > cantidad)
    {
        printf("\nFecha incorrecta , favor de volver a ingresar");
        return 1;
    }

    return 0;
}

void espacios(char datos[])
{
    int i = 0, j = 0;
    int len = contar_caracteres(datos);

    
    while (datos[i] == ' ')
    {
        i++;
    }

   
    while (datos[i] != '\0')
    {
        datos[j] = datos[i];
        i++;
        j++;
    }
    datos[j] = '\0';

    j--;
    while (j >= 0 && datos[j] == ' ')
    {
        datos[j] = '\0';
        j--;
    }
}