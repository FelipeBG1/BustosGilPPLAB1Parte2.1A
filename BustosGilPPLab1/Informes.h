#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();
void listarBicicletasPorColorElegido(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli);
void listarBicicletasPorTipoElegido(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli);
void informar(eBicicleta bicicletas[], int tamBic, eTrabajo trabajos[], int tamTrab,eServicio servicios[],int tamServ,eTipo tipos[], int tamTip, eColor colores[], int tamCol,eCliente clientes[],int tamCli);
void mostrarClientes(eCliente clientes[],int tamCli);
void informarBicicletasMenorRodado(eBicicleta bicicletas[],int tamBic,eTipo tipos[],int tamTip, eColor colores[],int tamCol,eCliente clientes[],int tamCli);
void informarBicicletasPorTipo(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli);
void informarCantBicicletasTipoColor(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli);
void informarTrabajosDeLaBicicleta(eBicicleta bicicletas[], int tamBic,eTipo tipos[],int tamTip,eColor colores[],int tamCol,eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eCliente clientes[], int tamCli);
void listarTrabajosDeUnaFecha(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ,eBicicleta bicicletas[],int tamBic);
void colorMasElegido(eBicicleta bicicletas[],int tamBic, eTipo tipos[],int tamTip,eColor colores[],int tamCol,eCliente clientes[],int tamCli);
