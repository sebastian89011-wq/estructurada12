#include "sebas.h"
int vector[10000], n = 10000;

void llenar_vector(int vector[], int n);
void menu();
void ordenar(int vector[], int n);
void buscar(int vector[], int n);
void secuencial(int vector[], int n);
void binaria(int vector[], int n);
void burbuja(int vector[], int n);
void seleccion(int vector[], int n);
void quicksort(int vector[], int n);
void shellsort(int vector[], int n);
void mergesort(int vector[], int n);
void quick_particion();

int main() {
    menu();
}

void menu() {
    srand(time(NULL));
    int otp;
    do {
        printf("\n1 ORDENAR VECTOR ");
        printf("\n2.BUSCAR VALOR EN VECTOR\n");
        scanf("%d", &otp);
        switch (otp) {
            case 1:
                ordenar(vector, n);
                break;
            case 2:
                buscar(vector, n);
                break;
            default:
                printf("\nFIN DEL PROGRAMA");
        }
    } while (otp != 3);
}

void ordenar(int vector[], int n) {
    int otp;
    do {
        printf("\n1 Burbuja (Bubble Sort)");
        printf("\n2 Seleccion (Selection Sort)");
        printf("\n3 Quicksort");
        printf("\n4 Shellsort");
        printf("\n5 Mergesort");
        printf("\n6. SALIR\n");
        scanf("%d", &otp);
        switch (otp) {
            case 1:
                burbuja(vector, n);
                break;
            case 2:
                seleccion(vector, n);
                break;
            case 3:
                quicksort(vector, n);
                break;
            case 4:
                shellsort(vector, n);
                break;
            case 5:
                mergesort(vector, n);
                break;
            default:
                printf("\nFIN DEL SUBMENU");
        }
    } while (otp != 6);
}

void buscar(int vector[], int n) {
    int otp;
    do {
        printf("\n1.SECUENCIAL");
        printf("\nBINARIA");
        scanf("%d", &otp);
        switch (otp) {
            case 1:
                secuencial(vector, n);
                break;
            case 2:
                binaria(vector, n);
                break;
            default:
                printf("\nFIN DEL PROGRAMA");
        }
    } while (otp != 3);
}

void burbuja(int vector[], int n) {
    int i, temp, j;
    llenar_vector(vector, n);
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    printf("Primeros 10 elementos:\n");
    for (int i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);
    printf("Últimos 10 elementos:\n");
    for (int i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);
}

void secuencial(int vector[], int n) { }

void binaria(int vector[], int n) { }

void seleccion(int vector[], int n) {
    int i,j,temp,min,aux;
    llenar_vector(vector, n);
    for(i=0;i<n;i++) {
        min = vector[i];
        for(j=i;j<n-1;j++) {
            if(vector[j + 1] < min) {
                min = vector[j + 1];
                aux = j + 1;
            }
        }
        temp = vector[i];
        vector[i] = min;
        vector[aux] = temp;
    }
    for(int m = 0;m<n;m++) {
        printf("\n[%d] == %d",m,vector[m]);
    }
}

void quicksort(int vector[], int n) {
    int i,j,pivote;
    llenar_vector(vector,n);
    pivote = vector[0];
    for(i=1;vector[i]<pivote;i++) {
    }
}

void shellsort(int vector[], int n) { }

void mergesort(int vector[], int n) { }

void llenar_vector(int vector[], int n) {
    int i, aleatorio;
    for (i = 0; i < n; i++) {
        do {
            aleatorio = (rand() % (15000 - 1 + 1)) + 1;
        } while (busqueda_secuencial_vector(vector, i, aleatorio) != -1);
        vector[i] = aleatorio;
    }
}
