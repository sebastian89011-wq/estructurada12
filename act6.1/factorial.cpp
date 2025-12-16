#include <stdio.h>
void factorial();
void aleatorios();
void calificacion();
void examen();
void sueldo();
void tablas();

int main()
{
    int i;
    do
    {

        printf("\n1. Factorial de un numero. ");
        printf("\n2. Generacion de numeros aleatorios. ");
        printf("\n3. Evaluacion de calificaciones en Algebra.");
        printf("\n4. Derecho al examen de nivelacion.");
        printf("\n5. Calculo de sueldo y comisiones.");
        printf("\n6. Tablas de multiplicar. ");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            factorial();
            break;

        case 2:
            aleatorios();
            break;

        case 3:
            calificacion();
            break;

        case 4:
            examen();
            break;

        case 5:
            sueldo();
            break;

        case 6:
            tablas();
            break;

        default:
            printf("\nFin del programa");
        }
    } while (i <= 5);

    return 0;
}

void factorial()
{
    int num, contador = 1, n = 1;
    printf("\nIntrodusca un menor positivo menor a 15: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("\nFuera del rango");
        return;
    }
    if (num > 14)
    {
        printf("Fuera del rango");
        return;
    }

    while (contador <= num)
    {

        n *= contador;
        contador++;
    }

    printf("\n%d! = %d ", num, n);
}

#include <stdlib.h>
#include <time.h>
void aleatorios()
{
    int aleatorio, i, contador = 0, contador2 = 0, acumulador = 0, media;
    srand(time(NULL));
    while (contador < 5)
    {
        contador++;
        aleatorio = (rand() % (200 - 100 + 1)) + 100;
        printf("\n(%d) %d ", contador, aleatorio);

        if (aleatorio % 2 == 0)
        {
            printf("Par");
            acumulador += aleatorio;
            contador2++;
        }
        else
        {
            printf("Impar");
        }
        if (contador2 == 13)
        {
            return;
        }
    }
    media = acumulador / contador2;
    printf("\nLa suma de los numeros pares es: %d", acumulador);
    printf("\nLa media de los numeros pares es %d ", media);
}
void calificacion()
{
    int i, j, calificacion;

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 1; j++)
        {
            printf("\nIngrese calificacion: ");
            scanf("%d", &calificacion);
            if (calificacion >= 60)
            {
                printf("\nPuedes continuar el siguiente semestre");
                return;
            }
            else
            {
                printf("Te toca repetir");
            }

            if (i == 3)
            {
                printf("\nReprobaste");
                return;
            }
        }
    }
}

void examen()
{
    int i, j, reprobados;
    float cal, promedio, acumulador;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            printf("\nIngresar Calificacion del alumno(%d) en la unidad unidad(%d) = ", i, j);
            scanf("%f", &cal);
            acumulador += cal;
        }
        promedio = acumulador / 5;
        if (promedio < 50)
        {
            reprobados++;
        }
        printf("\nEl promedio del alumno(%d) es: %.2f ", i, promedio);
        acumulador = 0;
    }
    printf("\nEl numero de alumnos sin derecho a examen son: %d ", reprobados);
}

void sueldo()
{
    int i, ventas, j, vendedores;
    float comision, ganancia_x_venta, ganancia_total = 0, sueldo;
    printf("\nSUELDO BASE = 2000$ ");
    printf("\nNumero de vendedores: ");
    scanf("%d", &vendedores);

    for (i = 1; i <= vendedores; i++)
    {
        printf("\n\nCuantas ventas tuvo el vendedor(%d) esta semana? ", i);
        scanf("%d", &ventas);
        printf("\nDesgloce lo obtenido por cada venta: ");
        for (j = 1; j <= ventas; j++)
        {
            printf("Venta(%d) = ", j);
            scanf("%f", &ganancia_x_venta);
            ganancia_total += ganancia_x_venta;
        }
        comision = ganancia_total * 0.10;
        sueldo = 2000 + comision;
        printf("\nEl vendedor(%d) obtuvo de comision = %.2f ", i, comision);
        printf("\nEl sueldo total del vendedor(%d) es = %.2f", i, sueldo);
        ganancia_total = 0;
    }
}
#include <conio.h>

void tablas()
{
    int i,j,multi;
     
    printf("\nTABLAS DEL 1 AL 10");
     for(int k=0; k<50; k++) printf("\n");  
   

    for(i=1;i<=10;i++)
    {
        

        for(j=1;j<=10;j++)
        {
            multi=i*j;
            printf("\n%d x %d = %d",i,j,multi);

        }
        printf("\nPresiona ENTER para continuar...");
        getchar();  
        getchar(); 
        
    }



    
}