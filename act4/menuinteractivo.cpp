#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio();
void tabla();
void mostrarnum20();
void numerosysuma();
void menorespromedio();

int main()
{
int i;
do
{

printf("\n1. Mostrar números del 1 al 10 y su suma.");
printf("\n2. Mostrar números menores a n, suma y promedio.");
printf("\n3. Mostrar suma y promedio de 20 números.");
printf("\n4. Mostrar tabla de multiplicar.");
printf("\n5. Generar números aleatorios.");
scanf("%d",&i);



switch(i)
{
    case 1:
    numerosysuma();
    break;

    case 2:
    menorespromedio();
    break;

    case 3:
    mostrarnum20();
    break;

    case 4:
    tabla();
    break;

    case 5:
    aleatorio();
    break;

    default:
    printf("\nFin del programa");
}
}
while(i<=5);


    return 0;
}

void numerosysuma()
{
    
    int i = 1;
    int suma = 0;

    while (i <= 10)
    {
        printf("%d\n", i);
        suma += i;
        i++;
    }

    printf("Suma total: %d\n", suma);
}

void menorespromedio()
{

    int n;
    printf("Ingrese un numero entero positivo n: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Entrada invalida.\n");
        return;
    }

    if (n <= 1)
    {
        printf("No hay numeros enteros positivos menores a %d.\n", n);
        printf("Suma total: 0\n");
        printf("Promedio: N/A\n");
        return;
    }

    int i;
    int suma = 0;
    int contador = 0;

    for (i = n - 1; i >= 1; i--)
    {
        printf("%d\n", i);
        suma += i;
        contador++;
    }

    printf("Suma total: %d\n", suma);
 
    float promedio = (float)suma / contador;
    printf("Promedio: %.2f\n", promedio);

}

void mostrarnum20()
{
    int i, num, suma = 0;
    for (i = 0; i < 20; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &num);
        suma += num;
    }
    printf("\nSuma total: %d\n", suma);
    printf("Promedio: %.2f\n", (float)suma / 20);
}

void tabla()
{
    float num,multi;
int i;
printf("\nIngrese numero a multiplicar: ");
scanf("%f",&num);

for(i=1;i<=10;i++)
{
multi=num * i;
printf(" \n%.2f x %d = %.2f",num,i,multi);
}
}

void aleatorio()
{
int aleatorio, i;
    srand(time(NULL));

  

    for (i = 1; i <= 25; i++)
    {
        aleatorio = 10 + (rand() % (50 - 10 + 1));
        printf("\n(%d) %d", i, aleatorio);
        if (aleatorio % 2 == 0)
        {
            printf(" Par");
        }
       else
        {
            printf(" Impar");
        }
    }    
}