#ifndef MENU_PILAGUERREROS_H
#define MENU_PILAGUERREROS_H

#include<stdio.h>
#include<stdlib.h>

#include "pilaguerreros.h"



void menu_pilaguerreros(PilaGuerreros *pilaguerreros){
    typedef enum{
        SALIR = 0,
        AGREGAR,
        ELIMINAR,
        MOSTAR_TOPE,
        MOSTRAR
    }MENU_PILAGUERREROS;

    int op;
    Guerrero *guerrero;

    do{
        puts("1. Agregar Guerrero");
        puts("2. Eliminar Guerrero");
        puts("3. Mostrar ultimo guerrero");
        puts("4. Mostrar todos los Guerreros");
        puts("0. Salir");

        scanf("%i",&op);

        while(getchar()!='\n');

        switch(op){
            case AGREGAR:
                guerrero = Guerrero_capturar();
                if(guerrero == NULL){
                    puts("\nError al capturar Guerrero");
                    continue;
                }
                if(PilaGuerreros_apilar(pilaguerreros, guerrero)){
                    puts("\nSe agrego Guerrero\n");
                }else puts("\nError al agregar Guerrero\n");
                break;
            
            case ELIMINAR:
                if(PilaGuerreros_deasapilar(pilaguerreros)){
                    puts("\nSe elimino Guerrero\n");
                }else puts("\nError al eliminar guerrero\n");
                break;

            case MOSTAR_TOPE:
                printf("\n%10s","---Ultimo Guerrero---\n");
                if(Guerrero_mostrar(PilaGuerreros_tope(pilaguerreros))){
                    puts("\nSe mostro ultimo Guerrero\n");
                }else puts("\nError al mostrar ultimo Guerrero\n");
                break;
            
            case MOSTRAR:
                if(PilaGuerreros_mostrar(pilaguerreros)){
                    puts("\nSe mostro PilaGuerreros\n");
                }else puts("\nError al mostrar PilaGuerreros\n");
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