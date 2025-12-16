// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 20/10/25

#include "sebas.h"
#include "curp.h"
Ts_curp generar_curp(char curp[19]);
char vocal_interna(char vocal[]);
char consonante_interna(char consonante[]);
char letra_inicial(char inicial[]);
void espacios(char datos[]);
void validar_nombre(char inicial[], char nombre[]);
int validar_fecha(int anio, int mes, int dia);
int caracter_especial(char simbolo[]);
char filtrar_caracter(char caracter);
int validar_groseria(char palabra[]);
void preposicion(char preposicion[]);
int detectar_pre(char preposicion[]);
int comprobar_existencia(char dato[]);
void obtener_apellido_valido(char destino[], char paterno[], char materno[]);
int validar_estado(char estado[]);

int main()
{
    srand(time(NULL));
    Ts_curp lista_datos[100];
    char lista_curp[100][19];
    char opcion;
    int i = 0;
    do
    {

        lista_datos[i] = generar_curp(lista_curp[i]);

        printf("\n--- DATOS CAPTURADOS ---\n");
        printf(" Apellido paterno : %s\n", lista_datos[i].paterno);
        printf(" Apellido materno : %s\n", lista_datos[i].materno);
        printf(" Nombre(s)        : %s\n", lista_datos[i].nombre);
        printf(" Fecha Nac.       : %02d/%02d/%d\n", lista_datos[i].dia, lista_datos[i].mes, lista_datos[i].ano);
        if (lista_datos[i].sexo == 1)
            printf(" Sexo             : H\n");
        else
            printf(" Sexo             : M\n");

        printf(" Estado           : %s\n", lista_datos[i].estado);
        printf("--------------------------\n");
        printf(" CURP GENERADA    : %s\n", lista_curp[i]);
        printf("--------------------------\n");

        printf("\nPresione 1 (y ENTER) para TERMINAR.\n");
        printf("Presione cualquier otra tecla (y ENTER) para continuar: ");

        opcion = getchar();

      
        i++;
        limpiar_buffer();

    } while (opcion != '1');

    printf("\nPrograma terminado.\n");
    return 0;
}

Ts_curp generar_curp(char curp[])
{
    Ts_curp datos;
    char nombre[20];
    int valido, contar;
    char mes[3];
    char ano[5];
    char dia[3];
    char sexo[1];
    char apellido[20];
    char homonimia;
    int aleatorio, homo_numeros;
    char dato_p[20];
    char dato_m[20];
    char dato_n[20];
    aleatorio = rand() % 10;

    printf("\nIngrese apellido paterno: ");
    my_gets(datos.paterno, 30);
    printf("\nIngrese apellido materno: ");
    my_gets(datos.materno, 30);
    printf("\nIngrese su(s) nombre(s) ");
    printf("\nSi tiene dos nombres como \"MARIA FERNANDA\" escríbalos completos: ");
    my_gets(datos.nombre, 30);
    datos.ano = validar(1900, 2025, "\nIngrese año de nacimiento: ");

    convertir_mayusculas(datos.paterno);
    convertir_mayusculas(datos.materno);
    convertir_mayusculas(datos.nombre);
    copiar_str(dato_p,datos.paterno);
    copiar_str(dato_m,datos.materno);
    copiar_str(dato_n,datos.nombre);
    espacios(datos.paterno);
    espacios(datos.materno);
    espacios(datos.nombre);

    preposicion(datos.paterno);
    preposicion(datos.materno);
    preposicion(datos.nombre);

    if (datos.ano >= 1900 && datos.ano <= 1999)
    {
        homonimia = (rand() % 10) + '0';
    }
    else
    {
        if (datos.ano > 1999)
        {
            homonimia = 'A' + rand() % 26;
        }
    }

    datos.mes = validar(1, 12, "\nIngrese mes de nacimiento: ");
    do
    {
        datos.dia = validar(1, 31, "\nIngrese dia de nacimiento: ");
    } while (validar_fecha(datos.ano, datos.mes, datos.dia) == 1);

    datos.sexo = validar(1, 2, "\nIngresar sexo(1. hombre, 2. mujer): ");
    if (datos.sexo == 1)
    {
        sexo[0] = 'H';
    }
    else
    {
        sexo[0] = 'M';
    }
    do
    {
        printf("\nIngresar estado donde nacio (Ingresar su abreviatura postal, ejemplo: baja california = BC) ");
        printf("\nIngrese \"NE\" en caso de ser extrangero: ");
        my_gets(datos.estado, 20);

        convertir_mayusculas(datos.estado);
        contar = contar_caracteres(datos.estado);
        valido = validar_estado(datos.estado);

        if (valido != 1 || contar != 2)
        {
            printf("\nEstado incorrecte, volver a ingresar");
        }
    } while (valido != 1 || contar != 2);
    snprintf(mes, sizeof(mes), "%02d", datos.mes);
    snprintf(ano, sizeof(ano), "%d", datos.ano);
    snprintf(dia, sizeof(dia), "%02d", datos.dia);
   
    obtener_apellido_valido(apellido, datos.paterno, datos.materno);
    validar_nombre(datos.nombre, nombre);
   

    curp[0] = filtrar_caracter(letra_inicial(apellido));
    curp[1] = vocal_interna(apellido);
    if (comprobar_existencia(datos.materno) != 1 || comprobar_existencia(datos.paterno) != 1)
    {
        curp[2] = filtrar_caracter(letra_inicial(datos.materno));
    }
    else
    {
        curp[2] = 'X';
    }
    curp[3] = filtrar_caracter(nombre[0]);
    if (validar_groseria(curp) == 1)
    {
        curp[1] = 'X';
    }
    curp[4] = ano[2];
    curp[5] = ano[3];
    curp[6] = mes[0];
    curp[7] = mes[1];
    curp[8] = dia[0];
    curp[9] = dia[1];
    curp[10] = sexo[0];
    curp[11] = datos.estado[0];
    curp[12] = datos.estado[1];
    curp[13] = filtrar_caracter(consonante_interna(apellido));
    if (comprobar_existencia(datos.materno) != 1)
    {
        curp[14] = filtrar_caracter(consonante_interna(datos.materno));
    }
    else
    {
        curp[14] = 'X';
    }
    curp[15] = filtrar_caracter(consonante_interna(nombre));
    curp[16] = homonimia;
    curp[17] = aleatorio + '0';
    curp[18] = '\0';
    convertir_mayusculas(curp);
    copiar_str(datos.paterno,dato_p);
    copiar_str(datos.materno,dato_m);
    copiar_str(datos.nombre,dato_n);
    return datos;
}

char vocal_interna(char apellido[])
{
    for (int i = 1; apellido[i] != '\0'; i++)
    {
        char c = apellido[i];

        

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return c;
        }
        if (filtrar_caracter(c) == 'X')
        {
            return 'X';
        }
    }
    return 'X';
}

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

void validar_nombre(char inicial[], char nombre[])
{
    int i = 0, j = 0;
    char primer_nombre[20];

    do
    {
        primer_nombre[i] = inicial[i];

        i++;
    } while (inicial[i] != ' ' && inicial[i] != '\0');
    primer_nombre[i] = '\0';

    if (comparar_cadenas("MARIA", primer_nombre) == 0 || comparar_cadenas("MA", primer_nombre) == 0 || comparar_cadenas("MA.", primer_nombre) == 0 || comparar_cadenas("JOSE", primer_nombre) == 0 || comparar_cadenas("J", primer_nombre) == 0 || comparar_cadenas("J.", primer_nombre) == 0)
    {
        while (inicial[i] == ' ')
        {
            i++;
        }

        while (inicial[i] != ' ' && inicial[i] != '\0')
        {
            nombre[j++] = inicial[i++];
        }
        nombre[j] = '\0';
    }
    else
    {
        copiar_str(nombre, primer_nombre);
    }
}

int caracter_especial(char simbolo)
{
    int i;

    if (simbolo >= 'A' && simbolo <= 'Z' || simbolo == 'Ñ' || simbolo == 'ñ'  )
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

void preposicion(char preposicion[])
{
    char palabra[20];
    int i = 0, j = 0;

    while (preposicion[i] != ' ' && preposicion[i] != '\0' && i < 19)
    {
        palabra[i] = preposicion[i];
        i++;
    }
    palabra[i] = '\0';

    while (detectar_pre(palabra) == 1)
    {
     
        while (preposicion[i] == ' ')
        {
            i++;
        }

        if (preposicion[i] == '\0')
        {
            preposicion[0] = '\0';
            return;
        }

     
        j = 0;
        while (preposicion[i] != ' ' && preposicion[i] != '\0' && j < 19)
        {
            palabra[j++] = preposicion[i++];
        }
        palabra[j] = '\0';
    }


    copiar_str(preposicion, palabra);
}




