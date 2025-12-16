// Sebastian Calderon Avalos
// Grupo: 28
// Fecha: 9/11/25


int casi_orden(Ts_datos alumnos[], int max) {
    int i,desorden=0;
    for (i = 0; i < max - 1; i++) {   
        if (alumnos[i].key > alumnos[i + 1].key)
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

void eliminar_espacios(char ordinaria[])
{
    int i=0,j=0;
    char sinespacio[100];
  while(ordinaria[i]!='\0')
  {
    if(ordinaria[i]!=' ')
    {
    sinespacio[j] = ordinaria[i];
    j++;
    }
    i++;
  }
  sinespacio[j] = '\0';
  copiar_str(ordinaria,sinespacio);
}