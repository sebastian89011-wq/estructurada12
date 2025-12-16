#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio(void)
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
        if (aleatorio % 2 != 0)
        {
            printf(" Impar");
        }
    }
}

int main()
{

    aleatorio();

    return 0;
}