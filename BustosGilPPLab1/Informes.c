#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include <string.h>
#include <ctype.h>
#include "Bicicletas.h"
#include "Trabajos.h"
#include "Informes.h"

void listarBicicletasPorColorElegido(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int colorIngresado;
    int flag=0;
    system("cls");
    mostrarColores(colores,tamCol);
    if((utn_getEntero(&colorIngresado,2,"\nIngrese el color de la bicicleta: ","\nError reingrese el color: ",5000,5004))==0)
    {

    }
    else
    {
        printf("\nTe quedaste sin intentos\n\n");

    }

    printf("\n****Listado de Bicicletas****\n");
    printf("id          Marca             Tipo             Color        Rodado      Cliente\n");
    for(int i=0;i<tamBic;i++)
    {
        if(bicicletas[i].idColor == colorIngresado)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTip,colores,tamCol,clientes,tamCli);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay ninguna bicicleta de ese color\n\n");
    }



}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("\n****Menu de informes****\n\n");
    printf("1- Mostrar bicicletas del color seleccionado por el usuario\n");
    printf("2- Mostrar bicicletas de un tipo seleccionado\n");
    printf("3- Informar la o las bicicletas de menor rodado\n");
    printf("4- Mostrar un listado de las bicicletas separadas por tipo\n");
    printf("5- Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo\n");
    printf("6- Mostrar el o los colores mas elegidos por los clientes\n");
    printf("7- Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma\n");
    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma\n");
    printf("11- Salir\n");
    printf("Ingrese una opcion: ");
    //fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}

void informar(eBicicleta bicicletas[], int tamBic, eTrabajo trabajos[], int tamTrab,eServicio servicios[],int tamServ,eTipo tipos[], int tamTip, eColor colores[], int tamCol,eCliente clientes[],int tamCli)
{
   char seguir ='s';
   char confirma;

   do
    {
        fflush(stdin);
        switch(menuInformes())
        {
            case 1:
                 listarBicicletasPorColorElegido(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
            case 2:
                 listarBicicletasPorTipoElegido(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
            case 3:
                 informarBicicletasMenorRodado(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
            case 4:
                 informarBicicletasPorTipo(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
            case 5:
                 informarCantBicicletasTipoColor(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
             case 6:
                 colorMasElegido(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);
                 system("pause");
                 break;
             case 7:
                informarTrabajosDeLaBicicleta(bicicletas,tamBic,tipos,tamTip,colores,tamCol,trabajos,tamTrab,servicios,tamServ,clientes,tamCli);
                 system("pause");
                 break;
            case 10:
                listarTrabajosDeUnaFecha(trabajos,tamTrab,servicios,tamServ,bicicletas,tamBic);
                system("pause");
                 break;
            case 11:
                 printf("Confirma salida: ");
                 fflush(stdin);
                 scanf("%c",&confirma);
                 if(confirma=='s')
                 {
                    seguir='n';
                 }
                 break;
        }
    }
    while(seguir =='s');

}

void listarBicicletasPorTipoElegido(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int tipoIngresado;
    int flag=0;
    system("cls");
    mostrarTipos(tipos,tamTip);
    if((utn_getEntero(&tipoIngresado,2,"\nIngrese el tipo de la bicicleta: ","\nError reingrese el tipo: ",1000,1003))==0)
    {
        printf("\n****Listado de Bicicletas****\n");
        printf("id          Marca             Tipo             Color        Rodado       Cliente\n");
        for(int i=0;i<tamBic;i++)
        {
            if(bicicletas[i].idTipo == tipoIngresado)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamTip,colores,tamCol,clientes,tamCli);
                flag=1;
            }
        }
    }
    else
    {
        printf("\nTe quedaste sin intentos\n\n");

    }


    if(flag==0)
    {
        printf("\nNo hay ninguna bicicleta de ese tipo\n\n");
    }



}

void mostrarClientes(eCliente clientes[],int tamCli)
{

    printf("\n****Listado de Clientes****\n");
    printf("id         Nombre     Sexo\n");

    for(int i=0;i<tamCli;i++)
    {
        printf("%d      %10s      %c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
    }

}

void informarBicicletasMenorRodado(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    float menorRodado;

    printf("\nLas bicicletas de menor rodado son: \n");
    for(int i=0;i<tamBic;i++)
    {
        if(i==0)
        {
            menorRodado=bicicletas[i].rodado;

        }
        else
        {
            if(menorRodado>bicicletas[i].rodado)
            {
                menorRodado=bicicletas[i].rodado;
            }
        }
        if(bicicletas[i].isEmpty==0 && menorRodado==bicicletas[i].rodado)
        {
            mostrarBicicleta(bicicletas[i],tipos,tamTip,colores,tamCol,clientes,tamCli);
        }
    }


}

void informarBicicletasPorTipo(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int flag=0;
    system("cls");

    printf("\n****Informe bicicletas por tipo****\n");
    printf("id          Marca          Tipo                Color        Rodado      Cliente\n");

    for(int t=0;t<tamTip;t++)
    {
        printf("Tipo: %s\n",tipos[t].descripcion);
        printf("------\n");

        for(int b=0; b<tamBic ; b++)
        {
            if(bicicletas[b].isEmpty == 0 && bicicletas[b].idTipo == tipos[t].id)
            {
                mostrarBicicleta(bicicletas[b],tipos,tamTip,colores,tamCol,clientes,tamCli);
                flag=1;
            }
        }

        printf("--------------------------------------------------------------------\n\n");
        if(flag==0)
        {
            printf("\nNo hay bicicletas en este tipo\n\n");
        }
    }

}

void informarCantBicicletasTipoColor(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int tipoIngresado;
    int cantBicTipo=0;
    int colorIngresado;
    int cantBicColor=0;
    mostrarTipos(tipos,tamTip);
    printf("\nIngrese el tipo: ");
    scanf("%d",&tipoIngresado);

    mostrarColores(colores,tamCol);
    printf("\nIngrese el color: ");
    scanf("%d",&colorIngresado);

    for(int i=0;i<tamBic;i++)
    {
        if(tipoIngresado==bicicletas[i].idTipo)
        {
            cantBicTipo++;
        }
        if(colorIngresado==bicicletas[i].idColor)
        {
            cantBicColor++;
        }
    }
    printf("La cantidad de bicicletas del color ingresado son/es %d\n",cantBicColor);
    printf("La cantidad de bicicletas del tipo ingresado son/es %d\n\n",cantBicTipo);

}
void informarTrabajosDeLaBicicleta(eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eCliente clientes[], int tamCli)
{
    int bicicletaIngresada;
    int flag=0;
    mostrarBicicletas(bicicletas,tamBic,tipos,tamTip,colores,tamCol,clientes,tamCli);

    if((utn_getEntero(&bicicletaIngresada,2,"\nIngrese el id de la bicicleta: ","\nError reingrese el id: ",1,1000))==0)
    {
        if((buscarBicicleta(bicicletaIngresada,bicicletas,tamBic))!= -1)
        {
            printf("\n****Listado de Trabajos****\n\n");
            printf("id        Servicio     id Bicicleta    Fecha \n");
            for(int i=0;i<tamTrab;i++)
            {
                if(bicicletaIngresada== trabajos[i].idBicicleta)
                {
                    mostrarTrabajo(trabajos[i],servicios,tamServ,bicicletas,tamBic);
                    flag=1;
                }

            }
        }
        else
        {
            printf("\nNo hay ninguna bicicleta con ese id\n\n");
        }

    }
    else
    {
        printf("\nTe quedaste sin intentos\n\n");
    }

    if(flag==0)
    {
        printf("\nEsta bicicleta no tiene ningun trabajo\n\n");
    }


}
void listarTrabajosDeUnaFecha(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ,eBicicleta bicicletas[],int tamBic)
{
    int anioIngresado;
    int mesIngresado;
    int diaIngresado;
    int flag=0;
    int todoOk=-1;

    while(todoOk==-1)
    {
        if((utn_getEntero(&anioIngresado,2,"\nIngrese el anio del trabajo: ","\nError reingrese el anio: ",1950,2050))==0)
        {

        }
        else
        {
            printf("\nTe quedaste sin intentos\n\n");
            todoOk=0;
            break;

        }
        if((utn_getEntero(&mesIngresado,2,"\nIngrese el mes del trabajo: ","\nError reingrese el mes: ",1,12))==0)
        {

        }
        else
        {
            printf("\nTe quedaste sin intentos\n\n");
            todoOk=0;
            break;

        }

        if((utn_getEntero(&diaIngresado,2,"\nIngrese el dia del trabajo: ","\nError reingrese el dia: ",1,31))==0)
        {
            todoOk=1;
        }
        else
        {
            printf("\nTe quedaste sin intentos\n\n");
            todoOk=0;
            break;

        }


    }
    if(todoOk==1)
    {
        printf("\n****Listado de Trabajos****\n\n");
        printf("id        Servicio     id Bicicleta    Fecha \n");

        for(int i=0;i<tamTrab;i++)
        {
            if((trabajos[i].fecha.anio) == anioIngresado &&(trabajos[i].fecha.mes)== mesIngresado && (trabajos[i].fecha.dia)==diaIngresado)
            {
                mostrarTrabajo(trabajos[i],servicios,tamServ,bicicletas,tamBic);
                flag=1;
            }
        }
    }

    if(flag==0)
    {
        printf("\nNo hay ningun trabajo en esa fecha\n\n");
    }
}

void colorMasElegido(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli)
{
    int contador5000Gris=0;
    int contador5001Negro=0;
    int contador5002Blanco=0;
    int contador5003Azul=0;
    int contador5004Rojo=0;

    for(int i=0;i<tamBic;i++)
    {
        if(bicicletas[i].idColor==5000)
        {
            contador5000Gris++;
        }
        if(bicicletas[i].idColor==5001)
        {
            contador5001Negro++;
        }
        if(bicicletas[i].idColor==5002)
        {
            contador5002Blanco++;
        }
        if(bicicletas[i].idColor==5003)
        {
            contador5003Azul++;
        }
        if(bicicletas[i].idColor==5004)
        {
            contador5004Rojo++;
        }
    }
    if(contador5000Gris>contador5001Negro && contador5000Gris>contador5002Blanco && contador5000Gris>contador5003Azul && contador5000Gris>contador5004Rojo)
    {
        printf("\nEl color mas elegido es el gris\n\n");
    }
    else
    {
        if(contador5001Negro>contador5002Blanco && contador5001Negro>contador5003Azul && contador5001Negro>contador5004Rojo)
        {
            printf("\nEl color mas elegido es el negro\n\n");
        }
        else
        {
            if(contador5002Blanco>contador5003Azul && contador5002Blanco>contador5004Rojo)
            {
                printf("\nEl color mas elegido es el blanco\n\n");
            }
            else
            {
                if(contador5003Azul>contador5004Rojo)
                {
                    printf("\nEl color mas elegido es el azul\n\n");
                }
                else
                {
                    printf("\nEl color mas elegido es el rojo\n\n");
                }
            }
        }
    }
}

