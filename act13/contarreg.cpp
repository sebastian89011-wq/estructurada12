#include "sebas.h"
#include "vectores.h"

int main()
{
    FILE *arch;
    int n_reg=0;
    Ts_datos reg;
    arch = fopen("datos.dat","rb");

    while(fread(&reg,sizeof(Ts_datos),1,arch) == 1)
    {
        n_reg++;
    }

    fclose(arch);
    return n_reg;

}