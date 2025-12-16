#include <stdio.h>

int main() {
    int numero = 1234;
    char texto[20];  // buffer para guardar el número convertido

    sprintf(texto, "%d", numero);  // convierte el número a texto

    printf("El número como texto es: %s\n", texto);

    return 0;
}
