// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 14/10/25


#include "sebas.h"

void agregar_automatico(Ts_Alumno alumnos[]);
void agregar_manual(Ts_Alumno alumnos[]);
void eliminar_registro(Ts_Alumno alumnos[]);
void buscar_alumno(Ts_Alumno alumnos[]);
void ordenar_registros(Ts_Alumno alumnos[]);
void imprimir_registros(Ts_Alumno alumnos[]);
void nombres_aleatorios(char nombre[], char paternos[], char maternos[]);
int verificar_orden(Ts_Alumno alumnos[]);

int main()
{
    int opcion, numero;
    Ts_Alumno reg;
    Ts_Alumno alumnos[10];
    
    srand(time(NULL));

    do
    {

        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. AGREGAR (AUTOMATICO 10 REGISTROS)\n");
        printf("2. AGREGAR MANUAL\n");
        printf("3. ELIMINAR REGISTRO (logico)\n");
        printf("4. BUSCAR\n");
        printf("5. ORDENAR\n");
        printf("6. IMPRIMIR\n");
        printf("7. SALIR\n");
        printf("Seleccione una opcion: ");
        opcion = validar_num();
        if (opcion == -1)
        {
            printf("Error: no es un número válido.\n");
        }

        switch (opcion)
        {
        case 1:
            agregar_automatico(alumnos);
            break;
        case 2:
            agregar_manual(alumnos);
            break;
        case 3:
            eliminar_registro(alumnos);
            break;
        case 4:
            buscar_alumno(alumnos);
            break;
        case 5:
            ordenar_registros(alumnos);
            break;
        case 6:
            imprimir_registros(alumnos);
            break;
        case 7:
            printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("\nOpción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 7);

    return 0;
}

void agregar_automatico(Ts_Alumno alumnos[])
{
    int i, n = 0;
    int matriculas[10];
    printf("\nFUNCION AGREGAR AUTOMÁTICO\n");
    char nombre[20];
    char paternos[20];
    char maternos[20];

    for (i = 0; i < 10; i++)
    {
        do
        {

        alumnos[i].matricula = 100000 + (rand() * (RAND_MAX + 1) + rand()) % 300001;
        }while(busqueda_secuencial_vector(alumnos,i,alumnos[i].matricula) != -1);

        matriculas[i] = alumnos[i].matricula;
        alumnos[i].edad = rand() % (30 - 17 + 1) + 17;
        alumnos[i].sexo = rand() % 2 + 1;
        nombres_aleatorios(nombre, paternos, maternos);
        strcpy(alumnos[i].nombre, nombre);
        strcpy(alumnos[i].paterno, paternos);
        strcpy(alumnos[i].materno, maternos);
        alumnos[i].status = 1;
    }
}

void agregar_manual(Ts_Alumno alumnos[])
{
    int i;
    int matriculas[10];
    int edad[10];
    char nombre[20];
    char paternos[20];
    char maternos[20];
    printf("\nFUNCION AGREGAR MANUAL\n");

    for (i = 0; i < 2; i++)
    {
        do
        {
        printf("\nINGRESAR MATRICULA: ");
        alumnos[i].matricula = validar(100000, 400000, "Ingresar matricula de 100000 a 400000: ");
        }while(busqueda_secuencial_vector(alumnos,i,alumnos[i].matricula) != -1);
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
        scanf("%d",&alumnos[i].sexo);
        limpiarBuffer();
    }

   
}

void eliminar_registro(Ts_Alumno alumnos[])
{
    printf("\nFUNCION ELIMINAR\n");
    int i, eliminar_mat;
    eliminar_mat = validar(100000, 400000, "Ingresar matricula a eliminar de 100000 a 400000: ");
    limpiarBuffer();
    for (i = 0; i < 10; i++)
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

void buscar_alumno(Ts_Alumno alumnos[])
{
    int num, alumno;
    printf("\nFUNCION BUSCAR\n");
    printf("\nIngrese matricula del alumno: ");
    scanf("%d", &num);
    limpiarBuffer();

    printf("\n| MATRICULA |      NOMBRE  |    APELLIDO.P    |    APELLIDO.M    | EDAD |    SEXO    |");
    if (verificar_orden(alumnos) != 1)
    {
        alumno = busqueda_secuencial_vector(alumnos, 10, num);
        if (alumno != -1 && alumnos[alumno].status == 1)
        {
            if (alumnos[alumno].status == 1)
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
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
    else
    {
        if (alumno != -1 && alumnos[alumno].status == 1)
        {

            alumno = busqueda_binaria(alumnos, 10, num);
            if (alumnos[alumno].status == 1)
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
        }
        else
        {
            printf("\nAlumno no encontrado o inactivo.\n");
        }
    }
}

void ordenar_registros(Ts_Alumno alumnos[])
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
        verificar_orden(alumnos);
        burbuja(alumnos, 10);
        break;
    case 2:
        verificar_orden(alumnos);
        seleccion(alumnos, 10);
        break;

    case 3:
        verificar_orden(alumnos);
        insercion(alumnos, 10);
        break;

    default:
        printf("\nopcion no disponible");
        return;
    }
}

void imprimir_registros(Ts_Alumno alumnos[])
{
    int i;
    printf("\nFUNCION IMPRIMIR\n");
    printf("\n| MATRICULA |    NOMBRE    |    APELLIDO.P    |    APELLIDO.M    | EDAD |    SEXO    |");
    for (i = 0; i < 10; i++)
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

void nombres_aleatorios(char nombre[], char paternos[], char maternos[])
{

    char nombres[107][20] = {" Carlos", "Pedro", "Yepiz", "Leonardo", "Fernando", "Filoberto", "Juan", "María", "Carlos", "Ana", "Luis", "Sofía", "Pedro", "Valeria",
                             "José", "Camila", "Miguel", "Lucía", "Fernando", "Isabela", "Diego",
                             "Martina", "Ricardo", "Natalia", "Andrés", "Paula", "Santiago",
                             "Julieta", "Javier", "Fernanda", "Alejandro", "Carolina", "Manuel",
                             "Gabriela", "Héctor", "Mariana", "Raúl", "Daniela", "Víctor", "Renata",
                             "Óscar", "Laura", "Pablo", "Francisco", "Elena", "Emilio", "Patricia",
                             "Enrique", "Claudia", "Roberto", "Verónica", "Eduardo", "Mónica",
                             "Diego", "Lorena", "Antonio", "Juliana", "Ricardo", "Sandra", "Mario",
                             "Cecilia", "Hugo", "Silvia", "Alberto", "Beatriz", "Jorge", "Carla",
                             "Miguel Ángel", "Natalia", "Cristian", "Adriana", "Raúl", "Fabiola",
                             "Sergio", "Marcela", "Alfonso", "Daniela", "Andrés", "Vanessa",
                             "Guillermo", "Clara", "Rafael", "Lorena", "Roberto", "Marisol",
                             "Eduardo", "Jessica", "Víctor", "Camila", "José Luis", "Carolina",
                             "Fernando", "María José", "Ángel", "Valentina", "Pablo", "Gabriela",
                             "Luis Miguel", "Antonella", "Diego", "Fernanda", "Ricardo", "Isabella",
                             "Sebastián", "Paola", "Juan Carlos", "Daniela"};

    int i = rand() % 107;
    int i2 = rand() % 90;
    int i3 = rand() % 97;

    strcpy(nombre, nombres[i]);

    char paterno[90][20] = {"García", "Hernández", "López", "Martínez", "González", "Pérez", "Sánchez", "Ramírez",
                            "Torres", "Flores", "Rivera", "Gómez", "Díaz", "Vargas", "Romero", "Rojas",
                            "Castillo", "Ortiz", "Silva", "Jiménez", "Morales", "Cruz", "Mendoza", "Aguilar",
                            "Medina", "Castro", "Suárez", "Ramos", "Vega", "Guerrero", "Reyes", "Soto",
                            "Navarro", "Domínguez", "Chávez", "Paredes", "Delgado", "Herrera", "Román", "Valencia",
                            "Palacios", "Cordero", "Cabrera", "Cisneros", "Marín", "Escobar", "Quintero", "Aguirre",
                            "Salazar", "Bonilla", "Carrillo", "Figueroa", "Barrera", "Hurtado", "Cárdenas", "Peña",
                            "Sandoval", "Gutiérrez", "Mora", "Sáenz", "Luna", "Mejía", "Bravo", "Parra", "Castañeda",
                            "Montoya", "Vargas", "Pinto", "Maldonado", "Palma", "Cruz", "Orozco", "Ríos", "Varela",
                            "Camacho", "Lara", "Pacheco", "León", "Córdova", "Escalante", "Rincón", "Valenzuela",
                            "Solís", "Carrasco", "Bravo", "Torres", "Villanueva", "Chávez", "Barrios", "Arias"};
    strcpy(paternos, paterno[i2]);

    char materno[97][20] = {"Gómez", "Ramírez", "Torres", "Flores", "Vargas", "Rojas", "Castillo", "Ortiz",
                            "Silva", "Jiménez", "Morales", "Cruz", "Mendoza", "Aguilar", "Medina", "Castro",
                            "Suárez", "Ramos", "Vega", "Guerrero", "Reyes", "Soto", "Navarro", "Domínguez",
                            "Chávez", "Paredes", "Delgado", "Herrera", "Román", "Valencia", "Palacios", "Cordero",
                            "Cabrera", "Cisneros", "Marín", "Escobar", "Quintero", "Aguirre", "Salazar", "Bonilla",
                            "Carrillo", "Figueroa", "Barrera", "Hurtado", "Cárdenas", "Peña", "Sandoval", "Gutiérrez",
                            "Mora", "Sáenz", "Luna", "Mejía", "Bravo", "Parra", "Castañeda", "Montoya", "Varela",
                            "Camacho", "Lara", "Pacheco", "León", "Córdova", "Escalante", "Rincón", "Valenzuela",
                            "Solís", "Carrasco", "Villanueva", "Barrios", "Arias", "Cáceres", "Acosta", "Benítez",
                            "Farias", "Ojeda", "Tapia", "Palacios", "Cáceres", "Sáenz", "Rebolledo", "Ramos",
                            "Vallejo", "Guevara", "Bermúdez", "Meza", "Pizarro", "Galarza", "Chavarría", "Fuentes",
                            "Alvarado", "Cordero", "Ponce", "Guzmán", "Montes", "Orellana", "Bravo", "Carranza"};

    strcpy(maternos, materno[i3]);
}

int verificar_orden(Ts_Alumno alumnos[])
{
    int i, cont = 0;
    for (i = 0; i < 10; i++)
    {
        if (alumnos[i].matricula < alumnos[i + 1].matricula)
        {
            cont++;
        }
    }
    if (cont == 9)
    {
        printf("\nVECTOR YA ORDENADO ");
        return 1;
    }
    return -1;
}