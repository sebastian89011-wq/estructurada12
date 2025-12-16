// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 7/10/25

#include "sebas.h"
int vector[10000],n=10000;

void quicksort_rec(int v[], int low, int high);
int partition_lomuto(int v[], int low, int high);
void mergesort_rec(int v[], int l, int r, int aux[]);
void merge(int v[], int l, int m, int r, int aux[]);

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

int main()
{
    menu();
}

void menu()
{
    srand(time(NULL));
    int otp;

    do
    {
        printf("\n1 ORDENAR VECTOR ");
        printf("\n2.BUSCAR VALOR EN VECTOR\n");
        scanf("%d", &otp);
        switch (otp)
        {
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

void ordenar(int vector[], int n)
{
    int otp;

    do
    {
        printf("\n1 Burbuja (Bubble Sort)");
        printf("\n2 Seleccion (Selection Sort)");
        printf("\n3 Quicksort");
        printf("\n4 Shellsort");
        printf("\n5 Mergesort");
        printf("\n6. SALIR\n");

        scanf("%d", &otp);
        switch (otp)
        {
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

void buscar(int vector[], int n)
{
    int otp;

    do
    {
        printf("\n1.SECUENCIAL");
        printf("\n2.BINARIA\n");
        scanf("%d", &otp);
        switch (otp)
        {
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

void burbuja(int vector[], int n)
{
    int i, temp, j;

    llenar_vector(vector, n);

    clock_t start = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTiempo burbuja: %f segundos\n", time_taken);

    printf("Primeros 10 elementos:\n");
    for (i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);

    printf("Últimos 10 elementos:\n");
    for (i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);
}

void secuencial(int vector[], int n)
{
    int x;
    llenar_vector(vector, n);
    printf("Ingrese valor a buscar: ");
    scanf("%d", &x);

    clock_t start = clock();
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        if (vector[i] == x)
        {
            found = i;
            break;
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found != -1)
        printf("Valor %d encontrado en la posicion %d\n", x, found);
    else
        printf("Valor %d no encontrado\n", x);

    printf("Tiempo busqueda secuencial: %f segundos\n", time_taken);
}

void binaria(int vector[], int n)
{
    int x;
    llenar_vector(vector, n);
    clock_t sort_start = clock();
    quicksort_rec(vector, 0, n - 1);
    clock_t sort_end = clock();
    double sort_time = ((double)(sort_end - sort_start)) / CLOCKS_PER_SEC;
    printf("Vector ordenado (quicksort) en %f segundos\n", sort_time);

    printf("Ingrese valor a buscar: ");
    scanf("%d", &x);

    clock_t start = clock();
    int low = 0, high = n - 1, mid, found = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (vector[mid] == x)
        {
            found = mid;
            break;
        }
        else if (vector[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found != -1)
        printf("Valor %d encontrado en la posicion %d\n", x, found);
    else
        printf("Valor %d no encontrado\n", x);

    printf("Tiempo busqueda binaria: %f segundos\n", time_taken);
}

void seleccion(int vector[], int n)
{
    int i, j, temp, minValue, minIndex;

    llenar_vector(vector, n);

    clock_t start = clock();
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        minValue = vector[i];
        for (j = i + 1; j < n; j++)
        {
            if (vector[j] < minValue)
            {
                minValue = vector[j];
                minIndex = j;
            }
        }
        temp = vector[i];
        vector[i] = vector[minIndex];
        vector[minIndex] = temp;
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTiempo seleccion: %f segundos\n", time_taken);

    printf("Primeros 10 elementos:\n");
    for (i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);

    printf("Últimos 10 elementos:\n");
    for (i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);
}

void quicksort(int vector[], int n)
{
    llenar_vector(vector, n);

    clock_t start = clock();
    quicksort_rec(vector, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTiempo quicksort: %f segundos\n", time_taken);

    printf("Primeros 10 elementos:\n");
    for (int i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);

    printf("Últimos 10 elementos:\n");
    for (int i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);
}

void shellsort(int vector[], int n)
{
    llenar_vector(vector, n);

    clock_t start = clock();
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = vector[i];
            for (j = i; j >= gap && vector[j - gap] > temp; j -= gap)
            {
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTiempo shellsort: %f segundos\n", time_taken);

    printf("Primeros 10 elementos:\n");
    for (i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);

    printf("Últimos 10 elementos:\n");
    for (i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);
}

void mergesort(int vector[], int n)
{
    llenar_vector(vector, n);

    int *aux = (int *)malloc(sizeof(int) * n);
    if (!aux)
    {
        printf("Error: no se pudo asignar memoria para mergesort\n");
        return;
    }

    clock_t start = clock();
    mergesort_rec(vector, 0, n - 1, aux);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTiempo mergesort: %f segundos\n", time_taken);

    printf("Primeros 10 elementos:\n");
    for (int i = 0; i < 10; i++)
        printf("[%d] == %d\n", i, vector[i]);

    printf("Últimos 10 elementos:\n");
    for (int i = n - 10; i < n; i++)
        printf("[%d] == %d\n", i, vector[i]);

    free(aux);
}

void quicksort_rec(int v[], int low, int high)
{
    if (low < high)
    {
        int p = partition_lomuto(v, low, high);
        quicksort_rec(v, low, p - 1);
        quicksort_rec(v, p + 1, high);
    }
}

int partition_lomuto(int v[], int low, int high)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    int tmp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = tmp;
    return (i + 1);
}

void mergesort_rec(int v[], int l, int r, int aux[])
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergesort_rec(v, l, m, aux);
    mergesort_rec(v, m + 1, r, aux);
    merge(v, l, m, r, aux);
}

void merge(int v[], int l, int m, int r, int aux[])
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= m)
        aux[k++] = v[i++];
    while (j <= r)
        aux[k++] = v[j++];
    for (i = l; i <= r; i++)
        v[i] = aux[i];
}

void llenar_vector(int vector[], int n)
{
    int i, aleatorio;

    for (i = 0; i < n; i++)
    {
        do
        {
            aleatorio = (rand() % (15000 - 1 + 1)) + 1;
        } while (busqueda_secuencial_vector(vector, i, aleatorio) != -1);

        vector[i] = aleatorio;
    }
}
