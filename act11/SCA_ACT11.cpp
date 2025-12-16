// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 26/10/25
#include "sebas.h"
#include "vectores.h"
int agregar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros);
int cargar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros);
void eliminar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros);
int buscar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros);
void ordenar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros);
void mostrar(const char archivo[], Ts_Alumno alumno[], int n_registros);
void generar_archivo( char archivo[], Ts_Alumno alumno[], int n_registros);
void contar_registros( char archivo[], Ts_Alumno alumno[], int n_registros);
void mostrar_borrados();

#define max 10
#define tama 1500

int main()
{
    Ts_Alumno alumno[1500];
    int opcion, carga = 0;
    char archivo[] = "datos.txt";
    char n_archivo[40];
    char archivito[40];
    int i;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Cargar archivo\n");
        printf("2. Agregar registros automáticos\n");
        printf("3. Eliminar registro\n");
        printf("4. Buscar registro\n");
        printf("5. Ordenar registros\n");
        printf("6. Mostrar todos los registros\n");
        printf("7. Generar archivo\n");
        printf("8. Cantidad de registros en archivo\n");
        printf("9. Mostrar borrados\n");
        printf("0. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (carga == 0)
            {
                i = cargar_archivo(archivo, alumno, i);
                carga = 1;
            }
            else
            {
                printf("\nArchivo ya cargado");
            }
            break;
        case 2:
            i = agregar_archivo(archivo, alumno, i);
            printf("\n%d", i);
            break;
        case 3:
            eliminar_archivo("borrados.txt", alumno, i);
            break;
        case 4:
            buscar_archivo(archivo, alumno, i);
            break;
        case 5:
            ordenar_archivo(archivo, alumno, i);
            break;
        case 6:
            mostrar(archivo, alumno, i);
            break;
        case 7:
            printf("\nIngresar nombre de archivo a generar(no ingresar su tipo): ");
            my_gets(n_archivo, 40);
            generar_archivo(n_archivo, alumno, i);
            break;
        case 8:
            printf("\nIngresar nombre de archivo a contar(no ingresar su tipo): ");
            my_gets(archivito, 40);
            contar_registros(archivito, alumno, i);
            break;
        case 9:
            mostrar_borrados();
            break;
        case 0:
            printf("Programa finalizado.\n");
            break;
        default:
            printf("Opcion invalida. Intenta de nuevo.\n");
            break;
        }

    } while (opcion != 0);

    return 0;
}
int agregar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    FILE *arch;
    int i = 0;
    static int j = 313;
    printf("\nFUNCION AGREGAR AUTOMÁTICO\n");
    arch = fopen(archivo, "a");
    if (arch == NULL)
    {
        printf("Error al abrir el archivo ");
        exit(1);
    }

    for (i = j; i < j + max; i++)
    {
        do
        {
            alumno[i].matricula = 100000 + (rand() * (RAND_MAX + 1) + rand()) % 300001;
        } while (busqueda_secuencial_vector(alumno, i, alumno[i].matricula) != -1);

        alumno[i].sexo = rand() % 2 + 1;
        alumno[i].fecha_nac.ano = rand() % (2008 - 1990 + 1) + 1990;
        alumno[i].edad = 2025 - (alumno[i].fecha_nac.ano);
        alumno[i].fecha_nac.mes = rand() % 12 + 1;

        {
            int dias_por_mes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int anio = alumno[i].fecha_nac.ano;
            int mes = alumno[i].fecha_nac.mes;
            if (anio % 4 == 0)
                dias_por_mes[2] = 29;
            alumno[i].fecha_nac.dia = (rand() % dias_por_mes[mes]) + 1;
        }

        nombres_aleatorios(alumno[i].nombre, alumno[i].paterno, alumno[i].materno);
        alumno[i].status = 1;
        convertir_mayusculas(alumno[i].materno);
        convertir_mayusculas(alumno[i].paterno);
        convertir_mayusculas(alumno[i].nombre);
        n_registros++;
        fprintf(arch, "%3d.-  %6d      %-15s %-15s  %-15s    %3d      %-7s\n", n_registros, alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].sexo == 1 ? "MASCULINO" : "FEMENINO");
    }
    i += max;
    fclose(arch);
    return n_registros;
}

int cargar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    static int cargado = 0;
    int i = 0;
    char basura[10], sexo_str[12];
    FILE *arch = fopen(archivo, "r");

    if (!arch)
    {
        printf("Error al abrir el archivo %s\n", archivo);
        return -1;
    }

    while (i < tama && fscanf(arch, "%s %d %s %s %s %d %s", basura, &alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, &alumno[i].edad, sexo_str) == 7)
    {
        alumno[i].sexo = comparar_cadenas(sexo_str, "MASCULINO") == 0 ? 1 : 2;
        alumno[i].status = 1;

        i++;
    }

    printf("Se cargaron %d registros desde el archivo.\n", i);
    fclose(arch);
    return i;
}

void eliminar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    int i, eliminar_mat, resp = 0;
    printf("\nFUNCION ELIMINAR\n");
    FILE *arch;

    arch = fopen(archivo, "a");

    if (arch == NULL)
    {
        printf("Error al abrir el archivo ");
        exit(1);
    }

    eliminar_mat = buscar_archivo(archivo, alumno, i);
    i = busqueda_secuencial_vector(alumno, tama, eliminar_mat);
    if (eliminar_mat != -1)
    {
        printf("\nDesea eliminar este alumno?(1.SI , 2.NO): ");
        scanf("%d", &resp);
    }
    if (resp == 1)
    {
        alumno[i].status = 0;
        printf("\nELIMINANDO ---> matricula == [%d]\n", alumno[i].matricula);
        fprintf(arch, "%3d.-  %6d      %-15s %-15s  %-15s    %3d      %-7s\n", i, alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].sexo == 1 ? "MASCULINO" : "FEMENINO");
        fclose(arch);
        return;
    }
    else
    {
        printf("\nVolviendo al menu");
        return;
    }
}

int buscar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    int num, i;
    FILE *arch;
    arch = fopen(archivo, "r");
    printf("\nFUNCION BUSCAR\n");
    printf("\nIngrese matricula del alumno: ");
    num = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");

    printf("\n| MATRICULA |     NOMBRE      |    APELLIDO.P    |    APELLIDO.M    | EDAD |     SEXO      |");
    if (verificar_orden(alumno, tama) != 1)
    {
        i = busqueda_secuencial_vector(alumno, tama, num);
        if (i != -1 && alumno[i].status == 1)
        {
            if (alumno[i].sexo == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |    HOMBRE    | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad);
            }
            else
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     MUJER    |  ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad);
            }
            return num;
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }
    else
    {
        i = busqueda_binaria(alumno, tama, num);
        if (i != -1 && alumno[i].status == 1)
        {
            if (alumno[i].sexo == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     HOMBRE    | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad);
            }
            else
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     MUJER     | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad);
            }
            return num;
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
            return -1;
        }
    }

    fclose(arch);
    return 0;
}

void ordenar_archivo(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    int desi;
    if (casi_orden(alumno, n_registros) == 1)
    {
        printf("\nUsando Insert Sort...");
        insercion(alumno, n_registros);
    }
    else
    {
        if (n_registros > 1000)
        {
            printf("\nUsando Selection Sort...");
            seleccion(alumno, n_registros);
        }
        else
        {
            printf("\nUsando Bubble Sort...");
            burbuja(alumno, n_registros);
        }
    }
    
}

void mostrar(const char archivo[], Ts_Alumno alumno[], int n_registros)
{
    static int j = 0;

    char opcion;
    printf("\n| MATRICULA |     NOMBRE      |    APELLIDO.P    |    APELLIDO.M    | EDAD  |     SEXO      |");
    do
    {
        int i = 0;
        while (i < 40 && j <= n_registros)
        {

            if (alumno[j].status == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d | %-7s | ", alumno[j].matricula, alumno[j].nombre, alumno[j].paterno, alumno[j].materno, alumno[j].edad, alumno[j].sexo == 1 ? "MASCULINO" : "FEMENINO");
                i++;
            }
            j++;
        }

        printf("\nPresione 1 (y ENTER) para TERMINAR.");
        printf("\nPresione cualquier otra tecla (y ENTER) para continuar: ");
        opcion = getchar();
        limpiar_buffer();

    } while (opcion != '1' && j < n_registros);
}

void generar_archivo( char archivo[], Ts_Alumno alumno[], int n_registros)
{
    FILE *arch;

    concatenar(archivo,".txt");
    arch = fopen(archivo, "w");
    if (arch == NULL)
    {
        printf("Error al abrir el archivo ");
        exit(1);
    }
    

    for (int i = 0; i < n_registros; i++)
    {
        if (alumno[i].status == 1)
        {
            fprintf(arch, "%3d.-  %6d      %-15s %-15s  %-15s    %3d      %-7s\n", i, alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].sexo == 1 ? "MASCULINO" : "FEMENINO");
        }
    }

    fclose(arch);
}

void contar_registros( char archivo[], Ts_Alumno alumno[], int n_registros)
{
    FILE *arch;
    int c;
    int i=0;
    concatenar(archivo,".txt");

    arch = fopen(archivo,"r");
    while((c = fgetc(arch)) != EOF)
    {
        if(c == '\n')
        {
            i++;
        }
        
    }
    printf("\nEl numero de registros es: %d",i);


    fclose(arch);
}

void mostrar_borrados()
{
    FILE *arch;
    char basura[10];
    char sexo_str[10];
    int i = 0,j =0;
    int c;
    Ts_Alumno borrados[1500];
    arch = fopen("borrados.txt","r");
   
    while (i < tama && fscanf(arch, "%s %d %s %s %s %d %s", basura, &borrados[i].matricula, borrados[i].nombre, borrados[i].paterno, borrados[i].materno, &borrados[i].edad, sexo_str) == 7)
    {
        borrados[i].sexo = comparar_cadenas(sexo_str, "MASCULINO") == 0 ? 1 : 2;
        i++;
        j++;
    }
  
    for(i = 0;i<j;i++)
    {
      printf("\n%3d.-  %6d     %-15s %-15s  %-15s    %3d      %-7s\n", i, borrados[i].matricula, borrados[i].nombre, borrados[i].paterno, borrados[i].materno, borrados[i].edad, borrados[i].sexo == 1 ? "MASCULINO" : "FEMENINO");

    }
    


    fclose(arch);
}