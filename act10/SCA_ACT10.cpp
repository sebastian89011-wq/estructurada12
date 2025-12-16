// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 26/10/25

#include "curp.h"



void generar_curp(char curp[], char nombre_c[], char paterno_c[], char materno_c[], int anio_c, int dia_c, int mes_c, int sexo_c,char estado_c[]);
void agregar(Ts_Alumno alumno[], int max);
void manual(Ts_Alumno alumno[], int max);
void automatico(Ts_Alumno alumno[], int max);
void eliminar_reg(Ts_Alumno alumno[], int max);
void buscar(Ts_Alumno alumno[], int max);
void ordenar(Ts_Alumno alumno[], int max);
void imprimir(Ts_Alumno alumno[], int max);
void modificar_reg(Ts_Alumno alumno[], int max);
int verificar_orden(Ts_Alumno alumnos[], int max);

int main()
{
    srand(time(NULL));
    Ts_Alumno alumno[3500];
    int max = 100;
    int x;

    do
    {
        printf("\n1.AGREGAR");
        printf("\n2.ELIMINAR REGISTRO");
        printf("\n3.BUSCAR");
        printf("\n4.ORDENAR");
        printf("\n5.IMPRIMIR");
        printf("\n6.MODIFICAR REGISTRO");
        printf("\n7.salir");
        scanf("%d", &x);
        limpiar_buffer();

        switch (x)
        {
        case 1:
            agregar(alumno, max);
            break;
        case 2:
            eliminar_reg(alumno, max);
            break;
        case 3:
            buscar(alumno, max);
            break;
        case 4:
            ordenar(alumno, max);
            break;
        case 5:
            imprimir(alumno, max);
            break;
        case 6:
            modificar_reg(alumno, max);
            break;
        case 7: 
             printf("FIN DEL PROGRAMA....");
             return 0;
        default:
             printf("\nOpcion no valida\n");
             break;
        }

    } while (x != 7);

    return 0;
}

void agregar(Ts_Alumno alumno[], int max)
{

    int x;

    do
    {

        printf("\n1.Automatico");
        printf("\n2.Manual");
        printf("\n3.salir");
        scanf("%d", &x);
        limpiar_buffer();

        switch (x)
        {
        case 1:
            automatico(alumno, max);
            break;
        case 2:
            manual(alumno, max);
            break;
        case 3:
            return;
        default:
            printf("\nOpcion no valida\n");
            break;
        }

    } while (x != 3);
}
void eliminar_reg(Ts_Alumno alumno[], int max)
{
    printf("\nFUNCION ELIMINAR\n");
    int i, eliminar_mat;
    eliminar_mat = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");
    for (i = 0; i < max; i++)
    {
        if (alumno[i].matricula == eliminar_mat && alumno[i].status == 1)
        {
            alumno[i].status = 0;
            printf("\nELIMINANDO ---> matricula == [%d]\n", alumno[i].matricula);
            return;
        }
    }
    printf("\nNo se encontro la matricula a eliminar");
}
void buscar(Ts_Alumno alumno[], int max)
{
    int num, i;
    printf("\nFUNCION BUSCAR\n");
    printf("\nIngrese matricula del alumno: ");
    num = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");

    printf("\n| MATRICULA |     NOMBRE      |    APELLIDO.P    |    APELLIDO.M     | EDAD |     SEXO      |     FECHA      |      CURP      |");
    if (verificar_orden(alumno, max) != 1)
    {
        i = busqueda_secuencial_vector(alumno, max, num);
        if (i != -1 && alumno[i].status == 1)
        {
            if (alumno[i].sexo == 1)
            {
                 printf("\n| %9d | %-15s | %-16s | %-16s | %5d |    HOMBRE    | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
            else
            {
                 printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     MUJER    | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
    else
    {
        i = busqueda_binaria(alumno, max, num);
        if (i != -1 && alumno[i].status == 1)
        {
            if (alumno[i].sexo == 1)
            {
                 printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     HOMBRE    | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
            else
            {
                 printf("\n| %9d | %-15s | %-16s | %-16s | %5d |     MUJER     | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
}
void ordenar(Ts_Alumno alumno[], int max)
{
    int x;
    printf("\nFUNCION ORDENAR\n");
    printf("\n1. burbuja");
    printf("\n2. seleccion ");
    printf("\n3. insercion\n");
    scanf("%d", &x);
    limpiar_buffer();

    switch (x)
    {
    case 1:
        verificar_orden(alumno, max);
        burbuja(alumno, max);
        break;
    case 2:
        verificar_orden(alumno, max);
        seleccion(alumno, max);
        break;

    case 3:
        verificar_orden(alumno, max);
        insercion(alumno, max);
        break;

    default:
        printf("\nOpcion no disponible");
        return;
    }
}
void imprimir(Ts_Alumno alumno[], int max)
{
    int i;
    printf("\nFUNCION IMPRIMIR\n");
    printf("\n| MATRICULA |     NOMBRE      |    APELLIDO.P    |    APELLIDO.M    | EDAD  |  SEXO  |     FECHA      |         CURP         | ");
    for (i = 0; i < max; i++)
    {
        if (alumno[i].status == 1)
        {
            convertir_mayusculas(alumno[i].nombre);
            convertir_mayusculas(alumno[i].paterno);
            convertir_mayusculas(alumno[i].materno);

            if (alumno[i].sexo == 1)
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |    HOMBRE   | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
            else
            {
                printf("\n| %9d | %-15s | %-16s | %-16s | %5d |    MUJER    | %02d / %02d / %4d | %-20s | ", alumno[i].matricula, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].edad, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.ano, alumno[i].curp);
            }
        }
    }
}
void modificar_reg(Ts_Alumno alumno[], int max)
{
    int i, otp, aux;
    char A_paterno[20];
    char A_materno[20];
    char N_nombre[20];
    int N_edad, N_sexo;
    int N_ano, N_mes, N_dia;
    i = buscars(alumno, max);
    if (i != -1)
    {
        do
        {
            printf("\nSELECCIONE LO QUE QUIERE MODIFICAR DEL REGISTRO: ");
            printf("\n1. Apellido paterno");
            printf("\n2. Apellido materno");
            printf("\n3. Nombre");
            printf("\n4. Fecha de nacimiento y edad");
            printf("\n5. Sexo");
            printf("\n9. Salir\n");
            scanf("%d", &otp);

            switch (otp)
            {
            case 1:
                printf("\nNuevo apellido paterno: ");
                my_gets(A_paterno, 20);
                copiar_str(alumno[i].paterno, A_paterno);
                break;

            case 2:
                printf("\nNuevo apellido materno: ");
                my_gets(A_materno, 20);
                copiar_str(alumno[i].materno, A_materno);
                break;

            case 3:
                printf("\nNuevo nombre: ");
                my_gets(N_nombre, 20);
                copiar_str(alumno[i].nombre, N_nombre);
                break;

            case 4:
                alumno[i].edad = validar(17, 50, "\nNueva edad: ");
                do
                {
                    alumno[i].fecha_nac.ano = validar(1900, 2025, "\nNuevo anio de nacimiento: ");
                } while (validar_edad(alumno[i].fecha_nac.ano, alumno[i].edad));
                alumno[i].fecha_nac.mes = validar(1, 12, "\nMES DE NACIMIENTO: ");
                do
                {
                    alumno[i].fecha_nac.dia = validar(1, 31, "\nDIA DE NACIMIENTO: ");
                    aux = validar_fecha(alumno[i].fecha_nac.ano, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.dia);
                } while (aux == 1);
                break;

            case 5:
                alumno[i].sexo = validar(1, 2, "\nNueva sexo: ");
                break;

            case 9:
                break;

            default:
                 printf("\nOpcion no valida\n");
                 break;
            }

        } while (otp != 9);
        printf("\nSaliendo...");
    }
}
void manual(Ts_Alumno alumno[], int max)
{
    int aux, contar, valido;
    for (int i = 0; i < 1; i++)
    {

        do
        {
            printf("\nINGRESAR MATRICULA: ");
            alumno[i].matricula = validar(100000, 400000, "Ingresar matricula de 100000 a 400000: ");
        } while (busqueda_secuencial_vector(alumno, i, alumno[i].matricula) != -1);
        printf("\nINGRESAR NOMBRE: ");
        my_gets(alumno[i].nombre, 20);
        printf("\nAPELLIDO.P: ");
        my_gets(alumno[i].paterno, 20);
        printf("\nAPELLIDO.M: ");
        my_gets(alumno[i].materno, 20);
        alumno[i].edad = validar(17, 40, "\nEDAD: ");
        do
        {
            alumno[i].fecha_nac.ano = validar(1900, 2025, "\nANIO DE NACIMIENTO:");
        } while (validar_edad(alumno[i].fecha_nac.ano, alumno[i].edad));
        alumno[i].fecha_nac.mes = validar(1, 12, "\nMES DE NACIMIENTO: ");
        do
        {
            alumno[i].fecha_nac.dia = validar(1, 31, "\nDIA DE NACIMIENTO: ");
            aux = validar_fecha(alumno[i].fecha_nac.ano, alumno[i].fecha_nac.mes, alumno[i].fecha_nac.dia);
        } while (aux == 1);
        alumno[i].status = 1;
        alumno[i].sexo = validar(1, 2, "\nSEXO (masculino = 1  , femenino = 2): ");
        do
        {
            printf("\nIngresar estado donde nacio (Ingresar su abreviatura postal, ejemplo: baja california = BC) ");
            printf("\nIngrese \"NE\" en caso de ser extrangero: ");
            my_gets(alumno[i].estado, 4);

            convertir_mayusculas(alumno[i].estado);
            contar = contar_caracteres(alumno[i].estado);
            valido = validar_estado(alumno[i].estado);

            if (valido != 1 || contar != 2)
            {
                printf("\nEstado incorrecto, volver a ingresar");
            }
        } while (valido != 1 || contar != 2);
        generar_curp(alumno[i].curp, alumno[i].nombre, alumno[i].paterno, alumno[i].materno, alumno[i].fecha_nac.ano, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes, alumno[i].sexo,alumno[i].estado);
    }
}


void automatico(Ts_Alumno alumno[], int max)
{
    int i;
    printf("\nFUNCION AGREGAR AUTOMÁTICO\n");

    for (i = 0; i < max; i++)
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
            int dias_por_mes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            int anio = alumno[i].fecha_nac.ano;
            int mes = alumno[i].fecha_nac.mes;
            if (anio % 4 == 0) dias_por_mes[2] = 29;
            alumno[i].fecha_nac.dia = (rand() % dias_por_mes[mes]) + 1;
        }

        nombres_aleatorios(alumno[i].nombre, alumno[i].paterno, alumno[i].materno);
        alumno[i].status = 1;
        estados_aleatorios(alumno[i].estado);
        generar_curp(alumno[i].curp, alumno[i].nombre, alumno[i].paterno, alumno[i].materno,
                     alumno[i].fecha_nac.ano, alumno[i].fecha_nac.dia, alumno[i].fecha_nac.mes,
                     alumno[i].sexo, alumno[i].estado);
    }
}



void generar_curp(char curp[], char nombre_c[], char paterno_c[], char materno_c[], int anio_c, int dia_c, int mes_c, int sexo_c,char estado_c[])
{
    char nomb[30],pat[30],mat[30];
    char nombre[30];
    int valido, contar;
    char mes[3];
    char ano[5];
    char dia[3];
    char sexo[2];
    char apellido[30];
    char homonimia;
    int aleatorio;

    aleatorio = rand() % 10;

    copiar_str(nomb,nombre_c);
    copiar_str(pat,paterno_c);
    copiar_str(mat,materno_c);

    convertir_mayusculas(nomb);
    convertir_mayusculas(pat);
    convertir_mayusculas(mat);


    preposicion(pat);
    preposicion(mat);
    preposicion(nomb);

    if (anio_c >= 1900 && anio_c <= 1999)
    {
        homonimia = (rand() % 10) + '0';
    }
    else
    {
        if (anio_c > 1999)
        {
            homonimia = 'A' + rand() % 26;
        }
    }

    if (sexo_c == 1)
    {
        sexo[0] = 'H';
    }
    else
    {
        sexo[0] = 'M';
    }
    sexo[1] = '\0';

    snprintf(mes, sizeof(mes), "%02d", mes_c);
    snprintf(ano, sizeof(ano), "%d", anio_c);
    snprintf(dia, sizeof(dia), "%02d", dia_c);
    espacios(pat);
    espacios(mat);
    espacios(nomb);
    obtener_apellido_valido(apellido, pat, mat);
    validar_nombre(nomb, nombre);

    curp[0] = filtrar_caracter(letra_inicial(apellido));
    curp[1] = vocal_interna(apellido);
    if (comprobar_existencia(mat) != 1 || comprobar_existencia(pat) != 1)
    {
        curp[2] = filtrar_caracter(letra_inicial(mat));
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
    curp[11] = estado_c[0];
    curp[12] = estado_c[1];
    curp[13] = filtrar_caracter(consonante_interna(apellido));
    if (comprobar_existencia(mat) != 1)
    {
        curp[14] = filtrar_caracter(consonante_interna(mat));
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
}