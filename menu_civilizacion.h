#ifndef MENU_CIVILIZACION_H
#define MENU_CIVILIZACION_H

#include"civilizacion.h"
#include"menu_aldeanos.h"
#include"menu_puerto.h"

void menu_civilizacion(Civilizacion *civilizacion){
    typedef enum{
        SALIR = 0,
        MENU_ALDEANOS,
        MENU_PUERTO
    }MENU_CIVILIZACION;

    int op;
    do{
        puts("\n1. Aldeanos");
        puts("2. Puerto");
        puts("0. Salir");

        scanf("%i",&op);

    
        switch(op){
            case MENU_ALDEANOS:
                menu_aldeanos(civilizacion->aldeanosLista);
                break;
            case MENU_PUERTO:
                menu_puerto(civilizacion->puerto);
                break;
            case SALIR:
                break;

            default:
                puts("\nOpcion no valida\n");
                break;
        }
    }while(op != SALIR);
    
}

#endif