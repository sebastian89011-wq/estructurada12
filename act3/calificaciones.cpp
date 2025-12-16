#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  float cal1, cal2, cal3, promedio;
  printf("Ingresar calificacion 1: ");
  scanf("%f", &cal1);
  printf("Ingresar calificacion 2: ");
  scanf("%f", &cal2);
  printf("Ingresar calificacion 3: ");
  scanf("%f", &cal3);
  promedio = (cal1 + cal2 + cal3) / 3;
  printf("El promedio es: %.2f ", promedio);

  if (promedio < 30)
  {
    printf("Te toca repetir carnal ");
  }
  else
  {
    if (promedio < 60)
    {
      printf("Extraordinario");
    }
    else
    {
      if (promedio < 70)
      {
        printf("Suficiente");
      }
      else
      {
        if (promedio < 80)
        {
          printf("Regular");
        }
        else
        {
          if (promedio < 90)
          {
            printf("Bien");
          }
          else
          {
            if (promedio < 98)
            {
              printf("Muy bien");
            }
            else
            {
              if (promedio < 100)
              {
                printf("Excelen");
              }
              else
              {
                if (promedio > 100)
                {
                  printf("Error en promedio");
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;
}