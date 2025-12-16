// Sebastian Calderon Avalos
// Grupo: 932
// Fecha: 15/11/25

#include "sebas.h"
#include "vectores.h"

void agregar_usuario();
void eliminar_usuario();
void modificar_nivel();
void quitar_bloqueo();
void capturar_contrasena(char contra[], int max);

int main()
{
    int opc;

    do
    {
        printf("\n===== MENU DE CONTROL DE USUARIOS =====\n");
        printf("1. Agregar Usuario\n");
        printf("2. Eliminar Usuario\n");
        printf("3. Modificar Nivel\n");
        printf("4. Quitar Estatus Bloqueado\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            printf("\n--- Agregar Usuario ---\n");
            agregar_usuario();
            break;

        case 2:
            printf("\n--- Eliminar Usuario ---\n");
            eliminar_usuario();
            break;

        case 3:
            printf("\n--- Modificar Nivel ---\n");
            modificar_nivel();
            break;

        case 4:
            printf("\n--- Quitar Estatus Bloqueado ---\n");
            quitar_bloqueo();
            break;

        case 5:
            printf("\nSaliendo del sistema...\n");
            break;

        default:
            printf("\nOpcion invalida. Intente de nuevo.\n");
            break;
        }

    } while (opc != 5);

    return 0;
}

void agregar_usuario()
{
    FILE *arch;
    int letras, error, cont;
    char usuario[20];
    int repetido;
    Ts_usuario usua;
    char contra[20];
    char confirmacion[20];
    int nivel;

    arch = fopen("claves.dll", "ab+");

    nivel = validar(1, 3, "\nNivel de usuario: ");

    do
    {
        printf("\nIngrese nuevo usuario: ");
        my_gets(usuario, 20);
        repetido = 0;
        fseek(arch, 0, SEEK_SET);

        while (fread(&usua, sizeof(Ts_usuario), 1, arch) == 1)
        {
            if (comparar_cadenas(usua.nombre, usuario) == 0)
            {
                repetido = 1;
            }
        }
        if (repetido == 1)
        {
            printf("\nNombre de usuario ya existente, favor de volver a ingresa");
        }

    } while (repetido == 1);

    

    do
    {
        error = 0;
        printf("\nIngresar nueva contrasena: ");
        capturar_contrasena(contra, 20);

        printf("\nConfirmar contrasena: ");
        capturar_contrasena(confirmacion, 20);

        if (comparar_cadenas(contra, confirmacion) != 0)
        {
            printf("\nLas contrasenas no coinciden\n");
            error = 1;
        }

        
        if (nivel == 1)
        {
            letras = validar_letras(contra);
            cont = contar_caracteres(contra);
            if (letras != 0)
            {
                printf("\nCaracteres no validos , vuelva a ingresar");
                error = 1;
            }
            if (cont < 8)
            {
                printf("\nvalor minimo de caractes es 8 , vuelva a ingresar");
                error = 1;
            }
        }
        else
        {
            if (nivel == 2)
            {
                letras = validar_letras_numeros(contra);
                cont = contar_caracteres_numeros(contra);
                if (letras != 0)
                {
                    printf("\nCaracteres no validos , vuelva a ingresar");
                    error = 1;
                }
                if (cont < 10)
                {
                    printf("\nvalor minimo de caractes es 10 , vuelva a ingresar");
                    error = 1;
                }
                if (encontrar_numero(contra) != 0)
                {
                    printf("\nFavor de ingresar por lo menos un numero");
                    error = 1;
                }
            }
            else
            {
                cont = contar_caracteres_todo(contra);

                if (cont < 12)
                {
                    printf("\nvalor minimo de caractes es 12 , vuelva a ingresar\n");
                    error = 1;
                }
                if (validar_nivel3(contra) != 0)
                {
                    printf("\nNo cumple con la estructura adecuada de la contrasena ");
                    printf("\nRecuerde incluir almenos una mayuscula, un numero y un caracter especial");
                    error = 1;
                }
            }
        }

    } while (error == 1);
    copiar_str(usua.nombre, usuario);
    copiar_str(usua.contra, contra);
    usua.nivel = nivel;
    usua.intentos = 0;
    usua.status = 1;

    fwrite(&usua, sizeof(Ts_usuario), 1, arch);
    fclose(arch);
}

void eliminar_usuario()
{
    FILE *arch;
    Ts_usuario reg;
    char nombre[20];
    int opc;

    arch = fopen("claves.dll", "rb+");
    if (!arch)
    {
        printf("\nError al abrir el archivo.\n");
        return;
    }

    printf("\nIngrese nombre de usuario: ");
    my_gets(nombre, 20);

    while (fread(&reg, sizeof(Ts_usuario), 1, arch) == 1)
    {
        if (reg.status == 1)
        {
            if (comparar_cadenas(nombre, reg.nombre) == 0)
            {

                printf("\n |STATUS|     USUARIO     | NIVEL |\n");
                printf(" --------------------------------------\n");

                printf(" |  %3d | %-15s |  %4d |\n", reg.status, reg.nombre, reg.nivel);

                printf("\n¿Desea eliminar este usuario?");
                printf("\n1. Si");
                printf("\n2. No");
                printf("\nOpcion: ");
                opc = validar(1, 2, "");

                if (opc == 1)
                {
                    reg.status = 0;
                    fseek(arch, -sizeof(Ts_usuario), SEEK_CUR);
                    fwrite(&reg, sizeof(Ts_usuario), 1, arch);
                    printf("\nUsuario eliminado correctamente.\n");
                }
                else
                {
                    printf("\nEliminacion cancelada.\n");
                }

                fclose(arch);
                return;
            }
        }
    }

    printf("\nUsuario no encontrado.\n");
    fclose(arch);
}

void modificar_nivel()
{
    FILE *arch;
    Ts_usuario reg;
    char nombre[20];
    int num;

    arch = fopen("claves.dll", "rb+");
    if (!arch)
    {
        printf("\nError al abrir el archivo.\n");
        return;
    }

    printf("\nIngresar nombre del usuario: ");
    my_gets(nombre, 20);

    while (fread(&reg, sizeof(Ts_usuario), 1, arch) == 1)
    {

        if (comparar_cadenas(nombre, reg.nombre) == 0)
        {

            if (reg.status != 1)
            {
                printf("\nEl usuario existe pero está inactivo/bloqueado.\n");
                fclose(arch);
                return;
            }

            num = validar(1, 3, "\nSeleccione nuevo nivel del usuario (1 - 3): ");
            reg.nivel = num;

            fseek(arch, -sizeof(Ts_usuario), SEEK_CUR);
            fwrite(&reg, sizeof(Ts_usuario), 1, arch);

            printf("\nUsuario cambiado al nivel %d\n", num);
            fclose(arch);
            return;
        }
    }

    printf("\nUsuario no encontrado.\n");
    fclose(arch);
}

void quitar_bloqueo()
{
    FILE *arch;
    Ts_usuario reg;
    char nombre[20];

    arch = fopen("claves.dll", "rb+");
    if (!arch)
    {
        printf("\nError al abrir el archivo.\n");
        return;
    }

    printf("\nIngresar nombre del usuario a desbloquear: ");
    my_gets(nombre, 20);

    while (fread(&reg, sizeof(Ts_usuario), 1, arch) == 1)
    {

        if (comparar_cadenas(nombre, reg.nombre) == 0)
        {

            if (reg.status != 2)
            {
                printf("\nEl usuario existe, pero NO está bloqueado.\n");
                fclose(arch);
                return;
            }

            reg.status = 1;
            reg.intentos = 0;

            fseek(arch, -sizeof(Ts_usuario), SEEK_CUR);
            fwrite(&reg, sizeof(Ts_usuario), 1, arch);

            printf("\nUsuario '%s' ha sido desbloqueado correctamente.\n", reg.nombre);

            fclose(arch);
            return;
        }
    }

    printf("\nUsuario no encontrado.\n");
    fclose(arch);
}

void capturar_contrasena(char contra[], int max) {
    char c;
    int i = 0;

    while (1) {
        c = getch();  

        
        if (c == 13) {
            contra[i] = '\0';
            printf("\n");
            break;
        }

        if (c == 8 && i > 0) {
            i--;
            printf("\b \b"); 
            continue;
        }

        
        if (i < max - 1 && c >= 32 && c <= 126) {
            contra[i++] = c;
            printf("*");
        }
    }
}
