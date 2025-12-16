// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 15/11/25

#include "sebas.h"
#include "vectores.h"


void cargar_archivo(Ts_indice indi[], int *n_registros,int reg_bin);
void imprimir_registros();
void agregar_automatico(Ts_indice indi[], int *n_registros);
int buscar_registro(Ts_indice indi[], int *n_registros);
void eliminar_registro(Ts_indice indi[], int *n_registros);
void ordenar_registros(Ts_indice indi[], int *n_registros);
void imprimir_ordenados(Ts_indice indi[], int *validos_reg);
void generar_txt(int *n_registros,char archivo[]);
void empaquetar_reg(Ts_indice indi[], int *validos_reg);


int main()
{
    srand(time(NULL));
    int opcion;
    char n_archivo[20];
    int nreg,reg_bin;
    
    nreg = system("contarreg.exe datos.dat"); 
    reg_bin = nreg + nreg/4; 
    printf("\n%d\n",nreg);
    Ts_indice indices[reg_bin];
    int total_registros = 0;
    cargar_archivo(indices, &total_registros,reg_bin);
    int registros_validos = total_registros;

    do
    {
        printf("\nMENU\n");
        printf("1. AGREGAR\n");
        printf("2. ELIMINAR\n");
        printf("3. BUSCAR\n");
        printf("4. ORDENAR\n");
        printf("5. IMPRIMIR REGISTROS\n");
        printf("6. IMPRIMIR REGISTROS ORDENADOS\n");
        printf("7. GENERAR ARCHIVO TEXTO\n");
        printf("8. EMPAQUETAR\n");
        printf("9. SALIR\n");
        printf("Opcion: ");
        opcion = validar(1,9,"");

        switch (opcion)
        {
        case 1:
            agregar_automatico(indices, &total_registros);
            printf("Registro agregado. Total registros (indice): %d\n", total_registros);
            break;

        case 2:
            eliminar_registro(indices, &registros_validos);
            break;
        case 3:
            buscar_registro(indices, &total_registros);
            break;
        case 4:
            ordenar_registros(indices, &total_registros);
            break;
        case 5:
            imprimir_registros();
            break;
        case 6:
            imprimir_ordenados(indices, &registros_validos);
            break;
        case 7: 
        printf("\nnombre del archivo: ");
        my_gets(n_archivo,20);
        generar_txt(&total_registros,n_archivo);
            break;
        case 8:
            empaquetar_reg(indices,&total_registros);
            break;
        case 9:
            break; 
        default:
            printf("Opcion no valida\n");
            break;
        }

    } while (opcion != 9);

    return 0;
}
void cargar_archivo(Ts_indice indi[], int *n_registros,int reg_bin)
{
    FILE *arch;
    int i = 0;
    int posicion = 0;
    Ts_datos reg;
    arch = fopen("datos.dat", "rb");

    if (arch == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }

    while (fread(&reg, sizeof(Ts_datos), 1, arch) == 1 && i < reg_bin)
    {
        if (reg.status == 1)
        {
            indi[i].indice = posicion;
            indi[i].llave = reg.key;
            i++;
        }
        posicion++;
    }

    *n_registros = i;

    fclose(arch);
}

void imprimir_registros()
{
    FILE *arch;
    int i = 0;
    Ts_datos reg;

    arch = fopen("datos.dat", "rb");

    if (arch == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    printf("\n |status|  KEY   |     NOMBRE     |      APELLIDO1      |      APELLIDO2      |   SEXO  |     PUESTO     |ESTADO| EDAD |    CELULAR    |\n");
    while (fread(&reg, sizeof(Ts_datos), 1, arch) == 1)
    {
        
        if(reg.status == 1)
        {
          printf(" |%6d| %7ld| %-15s| %-20s| %-20s| %-8s| %-15s|%-6s| %5d| %14ld|\n", reg.status, reg.key, reg.name, reg.last_name_1, reg.last_name_2, reg.sex, reg.job_pstion, reg.state, reg.age, reg.cell_phone);
        }
    }

    fclose(arch);
}

void agregar_automatico(Ts_indice indi[], int *n_registros)
{
    FILE *arch;
    int j = rand() % 2;
    long int posicion;
    char sexo[2][10] = {"MUJER", "HOMBRE"};
    Ts_datos reg;
    arch = fopen("datos.dat", "ab+");
    if (arch == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    do
    {
        reg.key = 100000 + (rand() * (RAND_MAX + 1) + rand()) % 300001;
    } while (busqueda_secuencial_vector(indi, n_registros, reg.key) != -1);
    nombres_aleatorios(reg.name, reg.last_name_1, reg.last_name_2);
    reg.cell_phone = 1000000 + rand() % 300001;
    puesto_aleatorio(reg.job_pstion);
    validar_estado(reg.state);
    copiar_str_seguro(reg.sex, sexo[j], 15);
    reg.age = rand() % (70 - 18 + 1) + 18;
    reg.status = 1;
    fseek(arch, 0, SEEK_END);
    posicion = ftell(arch) / sizeof(Ts_datos);

    if (fwrite(&reg, sizeof(Ts_datos), 1, arch) == 1)
    {
        indi[*n_registros].llave = reg.key;
        indi[*n_registros].indice = posicion;
        (*n_registros)++;
        printf("Registro escrito en el archivo en la posicion %ld (registro #%d).\n", posicion, *n_registros);
    }
    else
    {
        printf("Error al escribir registro\n");
    }

    fclose(arch);
}

int buscar_registro(Ts_indice indi[], int *n_registros)
{
    int i, num;
    Ts_datos reg;
    num = validar(100000, 400000, "Ingresar matricula(100000 a 300000): ");
    FILE *arch;
    arch = fopen("datos.dat", "rb");

    printf("\n |status|  KEY   |     NOMBRE     |      APELLIDO1      |      APELLIDO2      |   SEXO  |     PUESTO     |ESTADO| EDAD |    CELULAR    |\n");
    if (verificar_orden(indi, n_registros) != 1)
    {
       
        i = busqueda_secuencial_vector(indi, n_registros, num);
        if (i == -1)
        {
            printf("\nAlumno no encontrado");
            fclose(arch);
            return -1;
        }
    }
    else
    {
        i = busqueda_binaria(indi, n_registros, num);
        if (i == -1)
        {
            printf("\nAlumno no encontrado");
            fclose(arch);
            return -1;
        }
    }

    fseek(arch, indi[i].indice * sizeof(Ts_datos), SEEK_SET);
    if (fread(&reg, sizeof(Ts_datos), 1, arch) == 1)
    {
        printf(" |%6d| %7ld| %-15s| %-20s| %-20s| %-8s| %-15s|%-6s| %5d| %14ld|\n", reg.status, reg.key, reg.name, reg.last_name_1, reg.last_name_2, reg.sex, reg.job_pstion, reg.state, reg.age, reg.cell_phone);
        fclose(arch);
        return i;
    }
    else
    {
        printf("\nNo se pudo leer el archivo");
        fclose(arch);
        return -1;
    }
}

void eliminar_registro(Ts_indice indi[], int *n_registros)
{
    int i, opcion;
    int pos;
    Ts_datos reg;
    FILE *arch;
    arch = fopen("datos.dat", "rb+");
    i = buscar_registro(indi, n_registros);
    opcion = validar(1, 2, "\nDeseas eliminar este registro?(1.SI , 2.NO): ");
    if (opcion == 1)
    {

        if (i != -1)
        {
            printf("\nEliminando......");
            pos = indi[i].indice;
            fseek(arch, pos * sizeof(Ts_datos), SEEK_SET);
            fread(&reg, sizeof(Ts_datos), 1, arch);
            reg.status = 0;
            fseek(arch, -1 * sizeof(Ts_datos), SEEK_CUR);
            fwrite(&reg, sizeof(Ts_datos), 1, arch);
            *n_registros--;
        }
    }

    fclose(arch);
}

void ordenar_registros(Ts_indice indi[], int *n_registros)
{
    int desi;
    if(verificar_orden(indi,n_registros) == -1 )
    {
    if (casi_orden(indi, n_registros) == 1)
    {
        printf("\nUsando Insert Sort...");
        insercion(indi, n_registros);
    }
    else
    {
        if (*n_registros > 1000)
        {
            printf("\nUsando Selection Sort...");
            seleccion(indi, n_registros);
        }
        else
        {
            printf("\nUsando Bubble Sort...");
            burbuja(indi, n_registros);
        }
    }
}
else
{
    printf("\nya ordenado");
}
   

}

void imprimir_ordenados(Ts_indice indi[], int *validos_reg)
{
    FILE *arch;
    int i = 0;
    int pos, opc;
    Ts_datos reg;
    arch = fopen("datos.dat", "rb");
     if (arch == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    opc = validar(1, 2, "\nQuieres los registros ya ordenados?(1.SI , 2.NO)");
    printf("\n |status|  KEY   |     NOMBRE     |      APELLIDO1      |      APELLIDO2      |   SEXO  |     PUESTO     |ESTADO| EDAD |    CELULAR    |\n");
    if (opc == 1)
    {
        
        ordenar_registros(indi,validos_reg);
        while (i < *validos_reg)
        {
            pos = indi[i].indice;
            fseek(arch, pos * sizeof(Ts_datos), SEEK_SET);
            fread(&reg, sizeof(Ts_datos), 1, arch);
            printf(" |%6d| %7ld| %-15s| %-20s| %-20s| %-8s| %-15s|%-6s| %5d| %14ld|\n", reg.status, reg.key, reg.name, reg.last_name_1, reg.last_name_2, reg.sex, reg.job_pstion, reg.state, reg.age, reg.cell_phone);
            i++;
        }
    }
    else
    {
        while (i < *validos_reg)
        {
            pos = indi[i].indice;
            fseek(arch, pos * sizeof(Ts_datos), SEEK_SET);
            fread(&reg, sizeof(Ts_datos), 1, arch);
            printf(" |%6d| %7ld| %-15s| %-20s| %-20s| %-8s| %-15s|%-6s| %5d| %14ld|\n", reg.status, reg.key, reg.name, reg.last_name_1, reg.last_name_2, reg.sex, reg.job_pstion, reg.state, reg.age, reg.cell_phone);
            i++;
        }
    }

    fclose(arch);
}


void generar_txt(int *n_registros,char archivo[])
{
    Ts_datos reg;
    int opc;
    concatenar(archivo,".txt");
    FILE *txt = fopen(archivo,"w");
    FILE *bin = fopen("datos.dat","rb");
     if (bin == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
     if (txt == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    

    while(fread(&reg, sizeof(Ts_datos), 1, bin) == 1)
    {
        fprintf(txt, "%6d %7ld %-15s %-20s %-20s %-8s %-15s %-3s %3d %15ld\n", reg.status, reg.key, reg.name, reg.last_name_1, reg.last_name_2, reg.sex, reg.job_pstion, reg.state, reg.age, reg.cell_phone);
    }



    fclose(txt);
    fclose(bin);


}

void empaquetar_reg(Ts_indice indi[], int *validos_reg)
{
    Ts_datos reg;
    
    FILE *arch3 = fopen("datos.dat","rb");
    FILE *arch1 = fopen("respaldo.bak","wb");
    FILE *arch2 = fopen("tmp.dat","wb");
    if (arch1 == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
     if (arch2 == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    if (arch3  == NULL)
    {
        printf("Archivo no existente\n");
        return;
    }
    printf("\nEMPAQUETANDO....");

    while(fread(&reg,sizeof(Ts_datos),1,arch3) == 1)
    {
        fwrite(&reg,sizeof(Ts_datos),1,arch1);
        if(reg.status == 1)
        {
        fwrite(&reg,sizeof(Ts_datos),1,arch2);
        }
      
        
    }



    fclose(arch1);
    fclose(arch2);
    fclose(arch3);
    
    remove("datos.dat");
    rename("tmp.dat","datos.dat");
}


