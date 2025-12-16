// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 09/11/25

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tkey;

typedef struct _tmascota {
    int status;             
    tkey key;               
    char nombre[50];
    int edad;
    int sexo;              
    char tipo_mascota[50];
    char propietario[70];
    char telefono[20];
} Ts_datos;

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

int busqueda_secuencial_vector(Ts_datos vector[], int n, tkey valor)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i].key == valor)
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
void copiar_str(char cadena1[], char cadena2[])
{
    int i;
    for (i = 0; cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];  
    }
    cadena1[i] = '\0';
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



void burbuja(Ts_datos vector[], int n)
{
    Ts_datos temp;
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vector[j].key > vector[j + 1].key)
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}


void seleccion(Ts_datos vector[], int n)
{
    int i, j, aux;
    Ts_datos temp;
    for (i = 0; i < n; i++)
    {
        aux = i;
        for (j = i + 1; j < n; j++)
        {
            if (vector[j].key < vector[aux].key)
            {
                aux = j;
            }
        }
        temp = vector[i];
        vector[i] = vector[aux];
        vector[aux] = temp;
    }
}

void insercion(Ts_datos vector[], int n)
{
    int i;
    Ts_datos temp;
    for (i = 1; i < n; i++)
    {
        int j = i;
        temp = vector[i];
        while (j > 0 && temp.key < vector[j - 1].key)
        {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = temp;
    }
}

int busqueda_binaria(Ts_datos vector[], int fin, int valor)
{
    int mitad, inicio = 0;
    while (inicio <= fin)
    {
        mitad = (inicio + fin) / 2;
        if (valor == vector[mitad].key)
        {
            return mitad;
        }
        else
        {
            if (valor > vector[mitad].key)
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
int verificar_orden(Ts_datos alumnos[], int max) {
    int i, cont = 0;
    for (i = 0; i < max - 1; i++) {   
        if (alumnos[i].key < alumnos[i + 1].key) {
            cont++;
        }
    }
    if (cont == max - 1) {  
        printf("\nVECTOR YA ORDENADO ");
        return 1;
    }
    return -1;
}





void nombres_perro(char nombre[])
{
    int i = rand() % 107;
    char perros[107][20] = {
    "Firulais","Max","Rocky","Luna","Bobby","Daisy","Toby","Nala","Rex","Maya",
    "Zeus","Coco","Simba","Kira","Bruno","Lola","Lucky","Canela","Thor","Milo",
    "Molly","Spike","Chispa","Bella","Chester","Nube","Sultan","Rita","Oso","Sombra",
    "Toby","Luna","Duke","Perla","Apolo","Moka","Leo","Kira","Choco","Nina",
    "Rambo","Duna","Tommy","Cala","Bimba","Balto","Canelita","Hachi","Maya","Chispi",
    "Rocco","Sasha","Tina","Bimbo","Greta","Tango","Odie","Pelusa","Boby","Kiko",
    "Mora","Danko","Cleo","Toby","Yako","Linda","Sam","Candy","Pirata","Trixie",
    "Kovu","Nina","Bongo","Mimi","Otto","Layla","Bimba","Zoe","Milo","Kenny",
    "Cuca","Rocko","Toby","Duna","Lili","Yuki","Ramses","Noa","Nico","Puca",
    "Sultán","Kali","Lucky","Luna","Rex","Fiona","Thor","Mango","Kira","Simba",
    "Bimba","Max","Lola","Toby","Moka","Nala","Coco"
};

copiar_str(nombre,perros[i]);

}

void nombres_aleatorios(char nombre[])
{
    int i = rand() % 107;

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

  
}

void tipo_mascota(char tipo[])
{
    int i = rand() % 50;
    char mascotas[50][30] = {
    "Perro","Gato","Loro","Canario","Periquito",
    "Hamster","Cobaya","Conejo","PezBetta","Guppy",
    "Tortuga","Iguana","Gecko","SerpienteCornSnake","Camaleon",
    "Cacatua","Agaporni","Huron","Erizo","RatonDomestico",
    "Carpincho","PezGoldfish","PezNeon","Tucan","Pinguino",
    "Salamandra","Axolote","Faisan","Paloma","Gallo",
    "PerroSalchicha","PastorAleman","Siamés","Persa","MaineCoon",
    "Chihuahua","Labrador","ConejoEnano","CobayaAmericana","HurónEuropeo",
    "TortugaAcuatica","TortugaTerrestre","IguanaVerde","GeckoLeopardo","SerpienteReinaCorn",
    "CanarioRizado","AgapornisFischer","PeriquitoAustraliano","PezDisco","PezAngelfish"
};

    copiar_str(tipo,mascotas[i]);


}

void telefono_aleatorio(char numero[])
{
    int i;
    numero[0] = '5';
    numero[1] = '2';
    numero[2] = ' ';
    numero[3] = '6';
    numero[4] = '4';
    numero[5] = '6';
    numero[6] = ' ';


    for(i = 7;i<=13;i++)
    {
        numero[i] = rand() % 10 + '0';
    }
    numero[i] = '\0';
    

}