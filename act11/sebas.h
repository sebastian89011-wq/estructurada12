// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 26/10/25

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tkey;

typedef struct _fecha
{
    int dia;
    int mes;
    int ano;

} Ts_Fecha;

typedef struct _alumno
{
    int status;
    int edad;
    char nombre[20];
    char paterno[20];
    char materno[20];
    tkey matricula;
    int sexo;
    char lugar_nac[20];
    char estado[4];
    Ts_Fecha fecha_nac;
    int contador;
} Ts_Alumno;

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
void copiar_str_seguro(char cadena1[], const char cadena2[], int tam_destino)
{
    int i;
    for (i = 0; i < tam_destino - 1 && cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];
    }
    cadena1[i] = '\0';  
}

int busqueda_secuencial_vector(Ts_Alumno vector[], int n, tkey valor)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i].matricula == valor)
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


int validar_edad(int anio , int edad)
{
    if(edad != (2025 - anio))
    {
        printf("\nLa edad y la fecha no corresponden");
        return -1;

    }

    return 0;

}



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
int verificar_orden(Ts_Alumno alumnos[], int max) {
    int i, cont = 0;
    for (i = 0; i < max - 1; i++) {   
        if (alumnos[i].matricula < alumnos[i + 1].matricula) {
            cont++;
        }
    }
    if (cont == max - 1) {  
        printf("\nVECTOR YA ORDENADO ");
        return 1;
    }
    return -1;
}



int buscars(Ts_Alumno alumno[],int max)
{
    int num, i;
    printf("\nFUNCION BUSCAR\n");
    printf("\nIngrese matricula del alumno: ");
    scanf("%d", &num);
    limpiar_buffer();

    printf("\n| MATRICULA |    NOMBRE    |    APELLIDO.P    |    APELLIDO.M      | EDAD |    SEXO    |     FECHA     |");
    if (verificar_orden(alumno,max) != 1)
    {
        i = busqueda_secuencial_vector(alumno, max, num);
        if (i != -1 && alumno[i].status == 1)
        {   if (alumno[i].status == 1)
            {
                if (alumno[i].sexo == 1)
                {
                  printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Hombre | %2d / %2d / %4d | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano);
                }
                else
                {
                   printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Mujer | %2d / %2d / %4d | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano);
                }
                return i;
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }
    else
    {
        if (i != -1 && alumno[i].status == 1)
        {

            i = busqueda_binaria(alumno, max, num);
            if (alumno[i].status == 1)
            {
                if (alumno[i].sexo == 1)
                {
                   printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Hombre | %2d / %2d / %4d | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano);
                }
                else
                {
                    printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Mujer | %2d / %2d / %4d | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano);
                }
                return i;
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }
}

void nombres_aleatorios(char nombre[], char paternos[], char maternos[])
{
    int i = rand() % 107;
    int i2 = rand() % 90;
    int i3 = rand() % 97;

    char nombres[107][20] = {
        "Carlos","Pedro","Yepiz","Leonardo","Fernando","Filoberto","Juan","Maria","Carlos","Ana","Luis","Sofia","Pedro","Valeria",
        "Jose","Camila","Miguel","Lucia","Fernando","Isabela","Diego",
        "Martina","Ricardo","Natalia","Andres","Paula","Santiago",
        "Julieta","Javier","Fernanda","Alejandro","Carolina","Manuel",
        "Gabriela","Hector","Mariana","Raul","Daniela","Victor","Renata",
        "Oscar","Laura","Pablo","Francisco","Elena","Emilio","Patricia",
        "Enrique","Claudia","Roberto","Veronica","Eduardo","Monica",
        "Diego","Lorena","Antonio","Juliana","Ricardo","Sandra","Mario",
        "Cecilia","Hugo","Silvia","Alberto","Beatriz","Jorge","Carla",
        "Miguel","Natalia","Cristian","Adriana","Raul","Fabiola",
        "Sergio","Marcela","Alfonso","Daniela","Andres","Vanessa",
        "Guillermo","Clara","Rafael","Lorena","Roberto","Marisol",
        "Eduardo","Jessica","Victor","Camila","Jose","Carolina",
        "Fernando","Maria","Angel","Valentina","Pablo","Gabriela",
        "Luis","Antonella","Diego","Fernanda","Ricardo","Isabella",
        "Sebastian","Paola","Juan","Daniela"
    };

    copiar_str_seguro(nombre, nombres[i], 20);

    char paterno[90][20] = {
        "Garcia","Hernandez","Lopez","Martinez","Gonzalez","Perez","Sanchez","Ramirez",
        "Torres","Flores","Rivera","Gomez","Diaz","Vargas","Romero","Rojas",
        "Castillo","Ortiz","Silva","Jimenez","Morales","Cruz","Mendoza","Aguilar",
        "Medina","Castro","Suarez","Ramos","Vega","Guerrero","Reyes","Soto",
        "Navarro","Dominguez","Chavez","Paredes","Delgado","Herrera","Roman","Valencia",
        "Palacios","Cordero","Cabrera","Cisneros","Marin","Escobar","Quintero","Aguirre",
        "Salazar","Bonilla","Carrillo","Figueroa","Barrera","Hurtado","Cardenas","Pena",
        "Sandoval","Gutierrez","Mora","Saenz","Luna","Mejia","Bravo","Parra","Castaneda",
        "Montoya","Vargas","Pinto","Maldonado","Palma","Cruz","Orozco","Rios","Varela",
        "Camacho","Lara","Pacheco","Leon","Cordova","Escalante","Rincon","Valenzuela",
        "Solis","Carrasco","Bravo","Torres","Villanueva","Chavez","Barrios","Arias"
    };

    copiar_str_seguro(paternos, paterno[i2],20);

    char materno[97][20] = {
        "Gomez","Ramirez","Torres","Flores","Vargas","Rojas","Castillo","Ortiz",
        "Silva","Jimenez","Morales","Cruz","Mendoza","Aguilar","Medina","Castro",
        "Suarez","Ramos","Vega","Guerrero","Reyes","Soto","Navarro","Dominguez",
        "Chavez","Paredes","Delgado","Herrera","Roman","Valencia","Palacios","Cordero",
        "Cabrera","Cisneros","Marin","Escobar","Quintero","Aguirre","Salazar","Bonilla",
        "Carrillo","Figueroa","Barrera","Hurtado","Cardenas","Pena","Sandoval","Gutierrez",
        "Mora","Saenz","Luna","Mejia","Bravo","Parra","Castaneda","Montoya","Varela",
        "Camacho","Lara","Pacheco","Leon","Cordova","Escalante","Rincon","Valenzuela",
        "Solis","Carrasco","Villanueva","Barrios","Arias","Caceres","Acosta","Benitez",
        "Farias","Ojeda","Tapia","Palacios","Caceres","Saenz","Rebolledo","Ramos",
        "Vallejo","Guevara","Bermudez","Meza","Pizarro","Galarza","Chavarria","Fuentes",
        "Alvarado","Cordero","Ponce","Guzman","Montes","Orellana","Bravo","Carranza"
    };

    copiar_str_seguro(maternos, materno[i3],20);
}



