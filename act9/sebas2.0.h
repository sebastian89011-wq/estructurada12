// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 14/11/25

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _alumno
{
    int status;
    int edad;
    char nombre[30];
    char paterno[30];
    char materno[30];
    int matricula;
    int sexo;
} Ts_Alumno;

char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    if (fgets(cadena, tamano, stdin) == NULL) return NULL;
    longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n')
    {
        cadena[longitud - 1] = '\0';
    }
    return cadena;
}

int contar_caracteres(char cadena[])
{
    int i = 0;
    while (cadena[i] != '\0') i++;
    return i;
}

int busqueda_secuencial_vector(Ts_Alumno vector[], int n, int valor)
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
    if (fgets(cadena, 30, stdin) == NULL) return -1;
    while (cadena[i] == ' ' || cadena[i] == '\t') i++;
    if (cadena[i] == '\n' || cadena[i] == '\0') return -1;
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

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int validar(int min, int max, const char *mensaje)
{
    int num;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &num) != 1) {
            limpiarBuffer();
            printf("Entrada invalida. Intenta de nuevo.\n");
            continue;
        }
        limpiarBuffer();
        if (num < min || num > max) {
            printf("Valor fuera de rango (%d - %d). Intenta de nuevo.\n", min, max);
        } else break;
    } while (1);
    return num;
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

void nombres_aleatorios(char nombre[], char paternos[], char maternos[])
{
    char nombres[107][20] = {"Carlos","Pedro","Yepiz","Leonardo","Fernando","Filoberto","Juan","María","Carlos","Ana","Luis","Sofía","Pedro","Valeria",
                             "José","Camila","Miguel","Lucía","Fernando","Isabela","Diego",
                             "Martina","Ricardo","Natalia","Andrés","Paula","Santiago",
                             "Julieta","Javier","Fernanda","Alejandro","Carolina","Manuel",
                             "Gabriela","Héctor","Mariana","Raúl","Daniela","Víctor","Renata",
                             "Óscar","Laura","Pablo","Francisco","Elena","Emilio","Patricia",
                             "Enrique","Claudia","Roberto","Verónica","Eduardo","Mónica",
                             "Diego","Lorena","Antonio","Juliana","Ricardo","Sandra","Mario",
                             "Cecilia","Hugo","Silvia","Alberto","Beatriz","Jorge","Carla",
                             "Miguel Ángel","Natalia","Cristian","Adriana","Raúl","Fabiola",
                             "Sergio","Marcela","Alfonso","Daniela","Andrés","Vanessa",
                             "Guillermo","Clara","Rafael","Lorena","Roberto","Marisol",
                             "Eduardo","Jessica","Víctor","Camila","José Luis","Carolina",
                             "Fernando","María José","Ángel","Valentina","Pablo","Gabriela",
                             "Luis Miguel","Antonella","Diego","Fernanda","Ricardo","Isabella",
                             "Sebastián","Paola","Juan Carlos","Daniela"};
    int i = rand() % 107;
    int i2 = rand() % 90;
    int i3 = rand() % 97;
    strcpy(nombre, nombres[i]);
    char paterno[90][20] = {"García","Hernández","López","Martínez","González","Pérez","Sánchez","Ramírez",
                            "Torres","Flores","Rivera","Gómez","Díaz","Vargas","Romero","Rojas",
                            "Castillo","Ortiz","Silva","Jiménez","Morales","Cruz","Mendoza","Aguilar",
                            "Medina","Castro","Suárez","Ramos","Vega","Guerrero","Reyes","Soto",
                            "Navarro","Domínguez","Chávez","Paredes","Delgado","Herrera","Román","Valencia",
                            "Palacios","Cordero","Cabrera","Cisneros","Marín","Escobar","Quintero","Aguirre",
                            "Salazar","Bonilla","Carrillo","Figueroa","Barrera","Hurtado","Cárdenas","Peña",
                            "Sandoval","Gutiérrez","Mora","Sáenz","Luna","Mejía","Bravo","Parra","Castañeda",
                            "Montoya","Vargas","Pinto","Maldonado","Palma","Cruz","Orozco","Ríos","Varela",
                            "Camacho","Lara","Pacheco","León","Córdova","Escalante","Rincón","Valenzuela",
                            "Solís","Carrasco","Bravo","Torres","Villanueva","Chávez","Barrios","Arias"};
    strcpy(paternos, paterno[i2]);
    char materno[97][20] = {"Gómez","Ramírez","Torres","Flores","Vargas","Rojas","Castillo","Ortiz",
                            "Silva","Jiménez","Morales","Cruz","Mendoza","Aguilar","Medina","Castro",
                            "Suárez","Ramos","Vega","Guerrero","Reyes","Soto","Navarro","Domínguez",
                            "Chávez","Paredes","Delgado","Herrera","Román","Valencia","Palacios","Cordero",
                            "Cabrera","Cisneros","Marín","Escobar","Quintero","Aguirre","Salazar","Bonilla",
                            "Carrillo","Figueroa","Barrera","Hurtado","Cárdenas","Peña","Sandoval","Gutiérrez",
                            "Mora","Sáenz","Luna","Mejía","Bravo","Parra","Castañeda","Montoya","Varela",
                            "Camacho","Lara","Pacheco","León","Córdova","Escalante","Rincón","Valenzuela",
                            "Solís","Carrasco","Villanueva","Barrios","Arias","Cáceres","Acosta","Benítez",
                            "Farias","Ojeda","Tapia","Palacios","Cáceres","Sáenz","Rebolledo","Ramos",
                            "Vallejo","Guevara","Bermúdez","Meza","Pizarro","Galarza","Chavarría","Fuentes",
                            "Alvarado","Cordero","Ponce","Guzmán","Montes","Orellana","Bravo","Carranza"};
    strcpy(maternos, materno[i3]);
}

int verificar_orden(Ts_Alumno alumnos[], int tamano)
{
    int i, cont = 0;
    for (i = 0; i < tamano - 1; i++)
    {
        if (alumnos[i].matricula < alumnos[i + 1].matricula)
        {
            cont++;
        }
    }
    if (cont == tamano - 1)
    {
        printf("\nVECTOR YA ORDENADO ");
        return 1;
    }
    return -1;
}

void agregar_automatico(Ts_Alumno alumnos[], int tamano)
{
    char nombre[20];
    char paternos[20];
    char maternos[20];
    for (int i = 0; i < tamano; i++)
    {
        do
        {
            alumnos[i].matricula = rand() % (400000 - 100000 + 1) + 100000;
        } while (busqueda_secuencial_vector(alumnos, i, alumnos[i].matricula) != -1);
        alumnos[i].edad = rand() % (30 - 17 + 1) + 17;
        alumnos[i].sexo = rand() % 2 + 1;
        nombres_aleatorios(nombre, paternos, maternos);
        strcpy(alumnos[i].nombre, nombre);
        strcpy(alumnos[i].paterno, paternos);
        strcpy(alumnos[i].materno, maternos);
        alumnos[i].status = 1;
    }
}


void agregar_manual(Ts_Alumno alumnos[], int tamano)
{
    int i;
    int matriculas[10];
    int edad[10];
    char nombre[20];
    char paternos[20];
    char maternos[20];
    for (i = 0; i < tamano; i++)
    {
        do
        {
            printf("\nINGRESAR MATRICULA: ");
            alumnos[i].matricula = validar(100000, 400000, "Ingresar matricula de 100000 a 400000: ");
        } while (busqueda_secuencial_vector(alumnos, i, alumnos[i].matricula) != -1);
        limpiarBuffer();
        printf("\nINGRESAR NOMBRE: ");
        my_gets(alumnos[i].nombre, 20);
        printf("\nAPELLIDO.P: ");
        my_gets(alumnos[i].paterno, 20);
        printf("\nAPELLIDO.M: ");
        my_gets(alumnos[i].materno, 20);
        printf("\nEDAD: ");
        scanf("%d", &alumnos[i].edad);
        limpiarBuffer();
        alumnos[i].status = 1;
        printf("\nSEXO (masculino = 1  , femenino = 2): ");
        scanf("%d", &alumnos[i].sexo);
        limpiarBuffer();
    }
}

void eliminar_registro(Ts_Alumno alumnos[], int tamano)
{
    int i, eliminar_mat;
    eliminar_mat = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");
    limpiarBuffer();
    for (i = 0; i < tamano; i++)
    {
        if (alumnos[i].matricula == eliminar_mat && alumnos[i].status == 1)
        {
            alumnos[i].status = 0;
            printf("\nELIMINANDO ---> matricula == [%d]\n", alumnos[i].matricula);
            return;
        }
    }
    printf("\nNo se encontro la matricula a eliminar");
}

void buscar_alumno(Ts_Alumno alumnos[], int tamano)
{
    int num, alumno;
    printf("\nFUNCION BUSCAR\n");
    printf("\nIngrese matricula del alumno: ");
    scanf("%d", &num);
    limpiarBuffer();
    printf("\n| MATRICULA |      NOMBRE  |    APELLIDO.P    |    APELLIDO.M    | EDAD |    SEXO    |");
    if (verificar_orden(alumnos, tamano) != 1)
    {
        alumno = busqueda_secuencial_vector(alumnos, tamano, num);
        if (alumno != -1 && alumnos[alumno].status == 1)
        {
            if (alumnos[alumno].sexo == 1)
            {
                printf("\n| %9d | %-15.15s | %-15.15s | %-15.15s | %4d | Masculino | ", alumnos[alumno].matricula, alumnos[alumno].nombre, alumnos[alumno].paterno, alumnos[alumno].materno, alumnos[alumno].edad);
            }
            else
            {
                printf("\n| %9d | %-15.15s | %-15.15s | %-15.15s | %4d | Femenino | ", alumnos[alumno].matricula, alumnos[alumno].nombre, alumnos[alumno].paterno, alumnos[alumno].materno, alumnos[alumno].edad);
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
    else
    {
        alumno = busqueda_binaria(alumnos, tamano - 1, num);
        if (alumno != -1 && alumnos[alumno].status == 1)
        {
            if (alumnos[alumno].sexo == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Masculino | ", alumnos[alumno].matricula, alumnos[alumno].nombre, alumnos[alumno].paterno, alumnos[alumno].materno, alumnos[alumno].edad);
            }
            else
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Femenino | ", alumnos[alumno].matricula, alumnos[alumno].nombre, alumnos[alumno].paterno, alumnos[alumno].materno, alumnos[alumno].edad);
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
}

void ordenar_registros(Ts_Alumno alumnos[], int tamano)
{
    int x;
    printf("\nFUNCION ORDENAR\n");
    printf("\n1. burbuja");
    printf("\n2. seleccion ");
    printf("\n3. insercion\n");
    scanf("%d", &x);
    limpiarBuffer();
    switch (x)
    {
    case 1:
        verificar_orden(alumnos, tamano);
        burbuja(alumnos, tamano);
        break;
    case 2:
        verificar_orden(alumnos, tamano);
        seleccion(alumnos, tamano);
        break;
    case 3:
        verificar_orden(alumnos, tamano);
        insercion(alumnos, tamano);
        break;
    default:
        printf("\nopcion no disponible");
        return;
    }
}

void imprimir_registros(Ts_Alumno alumnos[], int tamano)
{
    int i;
    printf("\nFUNCION IMPRIMIR\n");
    printf("\n| MATRICULA |    NOMBRE    |    APELLIDO.P    |    APELLIDO.M    | EDAD |    SEXO    |");
    for (i = 0; i < tamano; i++)
    {
        if (alumnos[i].status == 1)
        {
            if (alumnos[i].sexo == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Masculino | ", alumnos[i].matricula, alumnos[i].nombre, alumnos[i].paterno, alumnos[i].materno, alumnos[i].edad);
            }
            else
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d | Femenino | ", alumnos[i].matricula, alumnos[i].nombre, alumnos[i].paterno, alumnos[i].materno, alumnos[i].edad);
            }
        }
    }
}
