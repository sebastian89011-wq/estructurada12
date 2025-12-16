#include <stdio.h>

void mostrarNumerosYSuma(void)
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

int main()
{
    mostrarNumerosYSuma();
    return 0;
}
