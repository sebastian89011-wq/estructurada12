#include <stdio.h>

int main()
{
    float iva, metros, costo, subtotal, total;
    printf("Consumo mesual de agua en metros cubicos: ");
    scanf("%f", &metros);

    if (metros < 5)
    {
        costo = 50;
    }
    else
    {
        if (metros < 16)
        {
            costo = 50 + (metros - 4) * 8;
        }

        else
        {
            if (metros < 51)
            {
                costo = 50 + (11 * 8) + (metros - 15) * 10;
            }

            else
            {
                if (metros >= 51)
                {
                    costo = 50 + (11 * 8) + (35 * 10) + (metros - 50) * 11;
                }
            }
        }
    }
    
    iva = costo * 0.16;
    total = costo + iva;
    printf("\nEl subtotal por %.2f metros cubicos es: %f", metros, costo);
    printf("\nEl iva es: %.2f ", iva);
    printf("\nEl total es: %.2f ", total);
    return 0;
}