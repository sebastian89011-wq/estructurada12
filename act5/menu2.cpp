#include <stdio.h>
#include <stdlib.h>

int menu();
void PromedioMateria(void);
void TablasMultiplicar(void);
void ContarDigitos(void);
void CalcularFactorial(void);

int main()
{
    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            PromedioMateria();
            break;
        case 2:
            TablasMultiplicar();
            break;
        case 3:
            ContarDigitos();
            break;
        case 4:
            CalcularFactorial();
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida, intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

//*********************
int menu()
{
    int op;
    printf("\n====== MENU PRINCIPAL ======\n");
    printf("1.- Calcular promedio de una materia\n");
    printf("2.- Imprimir tablas de multiplicar\n");
    printf("3.- Contar digitos de un numero\n");
    printf("4.- Calcular factorial\n");
    printf("5.- Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

//*********************
void PromedioMateria(void)
{
    float promedio, contador = 0, aprobado = 0;

    printf("Ingrese calificacion de materia: ");
    while (contador != 3 && !aprobado)
    {
        do
        {

            contador++;
            scanf("%f", &promedio);
            if (promedio >= 60)
            {
                printf("\nAprobaste el semestre");
                aprobado = 1;
            }
            else
            {
                printf("Reprobaste vuelve a intentarlo\n");
            }
            if (contador == 3)
            {
                printf("Baja academica\n");
            }

        } while (promedio < 0 || promedio > 100);
    }
}
//*********************
void TablasMultiplicar(void)
{
    int contador = 0, multi = 0, cont2;
    while (contador <= 9)
    {
        contador++;
        cont2 = 0;
        while (cont2 <= 9)
        {

            cont2++;
            multi = contador * cont2;
            printf("\n%d * %d = %d", contador, cont2, multi);
        }
    }
}

//*********************
void ContarDigitos(void)
{
    int acumulador = 0, num;
    printf("Introduzca un numero: ");
    scanf("%d", &num);
    while (num > 0)
    {
        acumulador++;
        num = num / 10;
    }

    printf("\nLa cantidad de digitos es: %d", acumulador);
}

//*********************
void CalcularFactorial(void)
{

        int num, i = 1, factorial = 1;

        printf("Ingresa un numero entre 1 y 10: ");
        scanf("%d", &num);

        while (num < 1 || num > 10)
        {
            printf("Numero invalido. Ingresa entre 1 y 10: ");
            scanf("%d", &num);
        }

        while (i <= num)
        {
            factorial *= i;
            i++;
        }

        printf("El factorial de %d es: %d\n", num, factorial);
}
