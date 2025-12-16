// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 26/10/25

int casi_orden(Ts_Alumno alumnos[], int max) {
    int i,desorden=0;
    for (i = 0; i < max - 1; i++) {   
        if (alumnos[i].matricula > alumnos[i + 1].matricula)
         {
            desorden++;
        }
        
    }
    if(desorden < (max - 1) * 0.10)
    {
        return 1;

    }
    return -1;
}

void concatenar(char palabra1[], const char palabra2[])
{
    int i=0;
    while(palabra1[i] != '\0')
    {
        i++;
    }
    for(int j = 0;palabra2[j] != '\0';j++)
    {
        palabra1[i] = palabra2[j];
        i++;
    }
    palabra1[i] = '\0';
    
    

}

void copiar_str(char cadena1[], char cadena2[])
{
    int i;
    for (i = 0; cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];  
    }
    cadena1[i] = '\0';
}



int comparar_cadenas(char cadena1[], char cadena2[])
{
    int i;
    for (i = 0; cadena1[i] != '\0' && cadena2[i] != '\0'; i++)
    {
        if (cadena1[i] != cadena2[i])
        {
            return cadena1[i] - cadena2[i];
        }
    }
    return cadena1[i] - cadena2[i];
}
