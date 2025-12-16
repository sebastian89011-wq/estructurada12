#include <stdio.h>

void mostrarMenoresSumaPromedio(void)
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

int main(void)
{
    mostrarMenoresSumaPromedio();
    return 0;
}
