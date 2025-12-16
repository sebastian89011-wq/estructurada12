// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 9/11/25

#include "sebas.h"
#include "vectores.h"

int automatico(Ts_datos vector[], int *total_registros);
void eliminar_registro(Ts_datos vector[], int total_registros);
int buscar_registro(Ts_datos vector[], int total_registros);
void imprimir_registros(Ts_datos vector[], int *total_registros);
void ordenar_registro(Ts_datos vector[], int total_registros);
void generar_txt(Ts_datos vector[], int total_registros, char archivo[]);
void ver_archivotxt(char archivo[]);
void editar_registro(Ts_datos vector[], int total_registros);
void crear_binario(Ts_datos vector[], int total_registros);
int cargar_binario(Ts_datos vector[], int total_registros);
void mostrar_eliminados();

#define MAX 100
#define tama 5000

int main()
{
    Ts_datos vector[tama];
    int total_registros = 0;
    int cargado = 0;
    char archivo[30];
    char archivito[30];

    int opcion;
    srand(time(NULL));

    do
    {
        printf("\n============================================\n");
        printf("      SISTEMA DE CONTROL DE MASCOTAS\n");
        printf("============================================\n");
        printf("1. AGREGAR (100 registros aleatorios)\n");
        printf("2. EDITAR REGISTRO\n");
        printf("3. ELIMINAR REGISTRO\n");
        printf("4. BUSCAR REGISTRO\n");
        printf("5. ORDENAR POR CLAVE (PK)\n");
        printf("6. IMPRIMIR REGISTROS\n");
        printf("7. GENERAR ARCHIVO DE TEXTO\n");
        printf("8. VER ARCHIVO DE TEXTO\n");
        printf("9. CREAR ARCHIVO BINARIO\n");
        printf("10. CARGAR ARCHIVO BINARIO\n");
        printf("11. MOSTRAR REGISTROS ELIMINADOS\n");
        printf("0. SALIR\n");
        printf("============================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiar_buffer();

        switch (opcion)
        {
        case 1:
            automatico(vector, &total_registros);
            break;

        case 2:
            editar_registro(vector, total_registros);
            break;

        case 3:
            eliminar_registro(vector, total_registros);
            break;

        case 4:
            buscar_registro(vector, total_registros);
            break;

        case 5:
            ordenar_registro(vector, total_registros);
            break;

        case 6:
            imprimir_registros(vector, &total_registros);
            break;

        case 7:
            printf("\nIngresar nombre de archivo (sin su extension): ");
            my_gets(archivo, 30);
            generar_txt(vector, total_registros, archivo);
            break;

        case 8:
            printf("\nIngresar nombre de archivo (sin su extension): ");
            my_gets(archivito, 30);
            ver_archivotxt(archivito);

            break;

        case 9:
            crear_binario(vector, total_registros);
            break;

        case 10:
            if (cargado == 0)
            {
                total_registros = cargar_binario(vector, total_registros);
                cargado = 1;
            }
            else
            {
                printf("\nArchivo ya cargado");
            }
            break;

        case 11:
            mostrar_eliminados();
            break;

        case 0:
            printf("\nSaliendo del programa...\n");
            break;

        default:
            printf("\nOpción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

int automatico(Ts_datos vector[], int *total_registros)
{
    static int i = 0;          
    int limite = i + MAX;       

    if (i >= tama) {
        printf("\nNo se pueden agregar más registros, vector lleno.\n");
        return *total_registros;
    }

    if (limite > tama) {        
        limite = tama;
    }


    for (; i < limite; i++)
    {
        do
        {
            vector[i].key = 100000 + (rand() * (RAND_MAX + 1) + rand()) % 300001;
        } while (busqueda_secuencial_vector(vector, i, vector[i].key) != -1);

        vector[i].sexo = rand() % 2 + 1;
        vector[i].edad = rand() % 20;
        nombres_aleatorios(vector[i].propietario);
        nombres_perro(vector[i].nombre);
        tipo_mascota(vector[i].tipo_mascota);
        vector[i].status = 1;
        telefono_aleatorio(vector[i].telefono);
    }

    *total_registros = i;  
    return *total_registros;
}

void eliminar_registro(Ts_datos vector[], int total_registros)
{
    int matricula, resp, i;

    i = buscar_registro(vector, total_registros);

    if (i != -1)
    {
        printf("\nDesea eliminar este alumno?(1.SI , 2.NO): ");
        scanf("%d", &resp);
        if (resp == 1)
        {
            vector[i].status = 0;
            printf("\nELIMINANDO ---> matricula == [%d]\n", vector[i].key);
            return;
        }
        else
        {
            printf("\nVolviendo al menu");
            return;
        }
    }
}

int buscar_registro(Ts_datos vector[], int total_registros)
{
    int num, i;
    num = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");
    printf("\n|     ID    |          MASCOTA          |   NOMBRE  |  SEXO   |  EDAD  |   PROPIETARIO   |    N.TELEFONO   |");

    if (verificar_orden(vector, tama) != 1)
    {
        i = busqueda_secuencial_vector(vector, tama, num);
        if (i != -1 && vector[i].status == 1)
        {
            printf("\n| %9d | %-25s | %-10s| %-7s | %6d | %-15s | %-15s | ", vector[i].key, vector[i].tipo_mascota, vector[i].nombre, vector[i].sexo == 1 ? "MACHO" : "HEMBRA", vector[i].edad, vector[i].propietario, vector[i].telefono);

            return i;
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }
    else
    {
        i = busqueda_binaria(vector, tama, num);
        if (i != -1 && vector[i].status == 1)
        {
            printf("\n| %9d | %-25s | %-10s| %-7s | %6d | %-15s | %-15s | ", vector[i].key, vector[i].tipo_mascota, vector[i].nombre, vector[i].sexo == 1 ? "MACHO" : "HEMBRA", vector[i].edad, vector[i].propietario, vector[i].telefono);
            return i;
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }

    return 0;
}

void imprimir_registros(Ts_datos vector[], int *total_registros)
{
    int j = 0;

    char opcion;
    printf("\n|     ID    |          MASCOTA          |   NOMBRE  |  SEXO   |  EDAD  |   PROPIETARIO   |    N.TELEFONO   |");
    do
    {
        int i = 0;
        while (i < 40 && j <= *total_registros)
        {

            if (vector[j].status == 1)
            {
                printf("\n| %9d | %-25s | %-10s| %-7s | %6d | %-15s | %-15s | ", vector[j].key, vector[j].tipo_mascota, vector[j].nombre, vector[j].sexo == 1 ? "MACHO" : "HEMBRA", vector[j].edad, vector[j].propietario, vector[j].telefono);
                i++;
            }
            j++;
        }

        printf("\nPresione 1 (y ENTER) para TERMINAR.");
        printf("\nPresione cualquier otra tecla (y ENTER) para continuar: ");
        opcion = getchar();
        limpiar_buffer();

    } while (opcion != '1' && j < *total_registros);
}

void ordenar_registro(Ts_datos vector[], int total_registros)
{
    int desi;
    if (casi_orden(vector, total_registros) == 1)
    {
        printf("\nUsando Insert Sort...");
        insercion(vector, total_registros);
    }
    else
    {
        if (total_registros > 1000)
        {
            printf("\nUsando Selection Sort...");
            seleccion(vector, total_registros);
        }
        else
        {
            printf("\nUsando Bubble Sort...");
            burbuja(vector, total_registros);
        }
    }
}

void generar_txt(Ts_datos vector[], int total_registros, char archivo[])
{
    FILE *arch;
    concatenar(archivo, ".txt");
    arch = fopen(archivo, "w");
    if (arch == NULL)
    {
        printf("Error al abrir el archivo ");
        exit(1);
    }

    for (int i = 0; i < total_registros; i++)
    {
        if (vector[i].status == 1)
        {

            fprintf(arch, "\n| %9d | %-25s | %-10s| %-7s | %6d | %-15s | %-15s | ", vector[i].key, vector[i].tipo_mascota, vector[i].nombre, vector[i].sexo == 1 ? "MACHO" : "HEMBRA", vector[i].edad, vector[i].propietario, vector[i].telefono);
        }
    }

    fclose(arch);
}

void ver_archivotxt(char archivo[])
{
    FILE *arch;
    char linea[256];

    concatenar(archivo, ".txt");
    arch = fopen(archivo, "r");

    if (arch == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), arch))
    {
        printf("%s", linea);
    }

    fclose(arch);
}

void editar_registro(Ts_datos vector[], int total_registros)
{
    int i, otp, aux;
    char m_nombre[20];
    char m_tipo[20];
    char n_propietario[20];
    char n_telefono[20];

    i = buscar_registro(vector, total_registros);

    if (i != -1 && vector[i].status == 1)
    {
        do
        {
            printf("\nSELECCIONE LO QUE QUIERE MODIFICAR DEL REGISTRO: ");
            printf("\n1. Nombre de la mascota");
            printf("\n2. Edad de la mascota ");
            printf("\n3. Sexo ");
            printf("\n4. tipo de mascota");
            printf("\n5. Nombre del propietario");
            printf("\n6. Numero de telefono");
            printf("\n0. Salir\n");
            scanf("%d", &otp);

            switch (otp)
            {
            case 1:
                printf("\nModificando nombre de la mascota: ");
                my_gets(m_nombre, 20);
                copiar_str(vector[i].nombre, m_nombre);
                break;

            case 2:
                vector[i].edad = validar(0, 100, "\nModificando edad de la mascota: ");
                break;

            case 3:
                vector[i].sexo = validar(1, 2, "\nNuevo sexo (1.MACHO , 2.HEMBRA): ");
                break;

            case 4:
                printf("\nModificando tipo de mascota: ");
                my_gets(m_tipo, 20);
                copiar_str(vector[i].tipo_mascota, m_tipo);
                break;

            case 5:
                printf("\nModificando nombre del propietario: ");
                my_gets(n_propietario, 20);
                copiar_str(vector[i].propietario, n_propietario);
                break;

            case 6:
                printf("\nModificando numero de telefono: ");
                my_gets(n_telefono, 20);
                copiar_str(vector[i].telefono, n_telefono);
                break;

            default:
                printf("\nOpcion no valida\n");
                break;
            }

        } while (otp != 0);
        printf("\nSaliendo...");
    }
}

void crear_binario(Ts_datos vector[], int total_registros)
{
    int i;
    if (total_registros != 0)
    {
        if (rename("datos.dll", "datos.tpm") != 0)
        {
            printf("\nArchivo no existente o ya existe un respaldo, creando uno nuevo");
        }

        FILE *arch;
        arch = fopen("datos.dll", "wb");

        if (arch == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }

        for (i = 0; i < total_registros; i++)
        {

            fwrite(&vector[i], sizeof(Ts_datos), 1, arch);
        }
        printf("\nSe guardaron %d registros en datos.dll\n", i);

        fclose(arch);
    }
    else
    {
        printf("\nEl archivo no se puede crear por falta de registros");
    }
}

int cargar_binario(Ts_datos vector[], int total_registros)
{
    int i = 0, leidos;
    FILE *arch;
    arch = fopen("datos.dll", "rb");

    if (arch == NULL)
    {
        printf("Archivo no existente\n");
        exit(1);
    }
    while (fread(&vector[i], sizeof(Ts_datos), 1, arch) == 1 && i < tama)
    {
        i++;
    }
    total_registros += i;
    fclose(arch);
    return total_registros;
}

void mostrar_eliminados()
{
    Ts_datos eliminados[tama];
    int i = 0;
    FILE *arch = fopen("datos.dll", "rb");

    if (arch == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    while (fread(&eliminados[i], sizeof(Ts_datos), 1, arch) == 1 && i < tama)
    {
        i++;
    }

    fclose(arch);

    printf("\n=== REGISTROS ELIMINADOS ===\n");
    printf("\n|     ID    |          MASCOTA          |   NOMBRE  |  SEXO   |  EDAD  |   PROPIETARIO   |    N.TELEFONO   |");
    for (int j = 0; j < i; j++)
    {
        if (eliminados[j].status == 0)
        {
            printf("\n| %9d | %-25s | %-10s | %-7s | %6d | %-15s | %-15s |", eliminados[j].key, eliminados[j].tipo_mascota, eliminados[j].nombre, eliminados[j].sexo == 1 ? "MACHO" : "HEMBRA", eliminados[j].edad, eliminados[j].propietario, eliminados[j].telefono);
        }
    }
}