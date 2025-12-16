#include "sebas.h"
#include "curp.h"
void espacios(char datos[]);
int main()
{
    char datos[20];

    my_gets(datos,20);
    espacios(datos);
    printf("\n%s",datos);



}

void espacios(char datos[])
{
    int i=0,n,j=0;
    char nuevo[20];
    

    while(datos[i] == ' ')
    {
        i++;
    }
    n = contar_caracteres(datos);
    

    while(datos[i] !='\0')
    {
    nuevo[j] = datos[i];
    i++;
    j++;

    }
    nuevo[j] = '\0';
    while(nuevo[j-1] == ' ')
    {
        j--;
    }
    nuevo[j] = '\0';

    copiar_str(datos,nuevo);

    
}