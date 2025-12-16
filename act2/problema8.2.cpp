#include <stdio.h>
int main()
{
    int min, tipo, extra;
    float subtotal, total;
    printf("\nTiempo de llamada: ");
    scanf("%d", &min);
    printf("Tipo de llamada: ");
    printf("\n1. Local ");
    printf("\n2. nacional ");
    printf("\n3. Internacional ");
    scanf("%d", &tipo);
    switch (tipo)
    {
    case 1:
        printf("\nLlamada local");
        subtotal = min * 3;
        total = (subtotal + (subtotal * .16));

        break;

    case 2:
        printf("\nLlamada nacional");
        if (min <= 3)
        {
            subtotal = 7;
            total = (subtotal + (subtotal * .16));
        }
        else
        {
            extra = (min - 3);
            subtotal = 7 + (extra * 2);
            total = (subtotal + (subtotal * .16));
        }
        break;

    case 3:
        printf("\nLlamada internacional");
        if (min <= 2)
        {
            subtotal = 9;
            total = (subtotal + (subtotal * .16));
        }
        else
        {
            extra = (min - 2);
            subtotal = 9 + (extra * 4);
            total = (subtotal + (subtotal * .16));
        }
        break;

    default:
        printf("Opcion no valida");
        break;
    }

    printf("\nEl subtotal es: %f pesos y el total es: %f", subtotal, total);

    return 0;
}