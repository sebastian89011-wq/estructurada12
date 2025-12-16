#include <stdio.h>
#include <stdlib.h>
#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Fibonacci(void);
void Factorial(void);
void Digitos(void);
void Dentro_rango(void);
void VALIDAR(void);

//****  main principal  *********
int main()
{
	menu();
	return 0;
}

//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
	int op;
	printf("  \n M  E   N   U \n");
	printf("1.- LECTURA DE DATOS DENTRO DE UN RANGO \n");
	printf("2.- VALIDAR ENTRADA DENTRO DE UN RANGO \n");
	printf("3.- DIGITOS DE UN NUMERO \n");
	printf("4.- FIBONACCI \n");
	printf("0.- SALIR  \n");
	printf("ESCOGE UNA OPCION: ");
	scanf("%d", &op);
	return op;
}

//****************
void menu()
{
	int op;
	do
	{
		op = msges();
		switch (op)
		{
		case 1:
			Dentro_rango();
			break;
		case 2:
			VALIDAR();
			break;
		case 3:
			Digitos();
			break;
		case 4:
			Fibonacci();
			break;
		}
	} while (op != 0);
}

//*********************
void Dentro_rango(void)
{
	int num1, acumulador1 = 0, acumulador2 = 0, total = 0;
	float dentro;

	printf("Introducir numeros entre el 10 y el 50 : ");

	do
	{
		scanf("%d", &num1);
		if (num1 != 0)
		{
			total++;
		}

		if (num1 >= 10 && num1 <= 50)
		{
			acumulador2++;
		}
	} while (num1 != 0);

	if (total == 0)
	{
		printf("Division entre cero\n");
	}
	dentro = (float)acumulador2 / (total);
	printf("\nHay un total de %d dentro del rango 10-50 ", acumulador2);
	printf("\nEl porcentaje de numeros dentro del rango es: %f%%", dentro * 100);
	printf("\nEl total de numeros leidos es: %d", total);
}

//*********************
void Fibonacci(void)
{
	int num1 = 0, num2 = 1, total = 1, acumulador = 0, num;

	printf("   FIBONACCI\n");
	printf("Cual numero de Fibonacci desea? ");
	scanf("%d", &num);

	if (num < 10 || num > 5000)
	{
		printf("Numero fuera del rango");
		return;
	}

	do
	{
		total = num1 + num2;
		printf("\n %d + %d = %d", num1, num2, total);
		num2 = num1;
		num1 = total;
		acumulador++;
	} while (acumulador <= num);
}

//*************************
void VALIDAR(void)
{
	int num;

	printf("   VALIDAR rango\n");
	printf("\nIntroducir dato entre el rango del 1 al 100: ");

	do
	{
		scanf("%d", &num);
		if (num < 1 || num > 100)
		{
			printf("\nERROR FUERA DEL RANGO VOLVER A INGRESAR: ");
		}
	} while (num < 1 || num > 100);
}

//****************************
void Digitos(void)
{
	int acumulador = 0, num;

	printf("   DIGITOS\n");
	scanf("%d", &num);

	do
	{
		acumulador++;
		num = num / 10;
	} while (num > 0);

	printf("\nLa cantidad de digitos es: %d", acumulador);
}
