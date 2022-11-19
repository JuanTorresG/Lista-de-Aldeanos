#ifndef MENU_ALDEANOS_H
#define MENU_ALDEANOS_H

#include<stdio.h>
#include<stdlib.h>

#include "lista_aldeanos.h"
#include "menu_puerto.h"

typedef enum{
    SALIR = 0,
    AGREGAR_INICIO,
    AGREGAR_FINAL,
    INSERTAR,
    MOSTRAR,
    MOSTRAR_TABLA,
    ELIMINAR_INICIO,
    ELIMINAR_FINAL,
    ELIMINAR
}MENU_ALDEANOS;

void menu_aldeanos(AldeanosLista *aldeanosLista){
    int op;
    Aldeano *aldeano;
    size_t posicion;
    do{
        puts("\n1.- Agregar Inicio");
        puts("2.- Agregar Final");
        puts("3.- Insertar");
        puts("4.- Mostrar");
        puts("5.- Mostrar Tabla");
        puts("6.- Eliminar Inicio");
        puts("7.- Eliminar Final");
        puts("8.- Eliminar");
        puts("0.- Salir");

        scanf("%i",&op);
        
        while(getchar()!='\n');

        switch(op){
            case AGREGAR_INICIO:
                aldeano = Aldeano_capturar();
                if(aldeano == NULL){
                    puts("\nError al capturar Aldeano\n");
                    continue;
                }
                if(AldeanosLista_agregar_inicio(aldeanosLista, aldeano)){
                    puts("\nSe agrego al inicio\n");
                }else puts("\nError al agragar al inicio\n");
                break;

            case AGREGAR_FINAL:
                aldeano = Aldeano_capturar();
                if(aldeano == NULL){
                    puts("\nError al capturar Aldeano\n");
                    continue;
                }
                if(AldeanosLista_agregar_final(aldeanosLista, aldeano)){
                    puts("\nSe agrego al final\n");
                }else puts("\nError al agregar al final\n");
                break;

            case INSERTAR:
                aldeano = Aldeano_capturar();
                posicion = leerSize_t("Posicion: ");
                if(aldeano == NULL){
                    puts("\nError al capturar Aldeano\n");
                    continue;
                }
                if(AldeanosLista_insertar(aldeanosLista, aldeano, posicion)){
                    puts("\nSe inserto\n");
                }else puts("\nError al insertar\n");
                break;

            case MOSTRAR:
                if(AldeanosLista_mostrar(aldeanosLista)){
                    puts("Se mostro AldeanosLista\n");
                }else puts("\nError al mostrar Aldeanos lista\n");
                break;

            case MOSTRAR_TABLA:
                if(AldeanosLista_motrar_tabla(aldeanosLista)){
                    puts("Se mostro tabla\n");
                }else puts("\nError al mostrar tabla\n");
                break;

            case ELIMINAR_INICIO:
                if(AldeanosLista_eliminar_inicio(aldeanosLista)){
                    puts("Se elimino al inicio\n");
                }else puts("\nError al eliminar al inicio\n");
                break;

            case ELIMINAR_FINAL:
                if(AldeanosLista_eliminar_final(aldeanosLista)){
                    puts("Se elimino al final\n");
                }else puts("\nError al eliminar al final\n");
                break;

            case ELIMINAR:
                posicion = leerSize_t("Posicion: ");
                if(AldeanosLista_eliminar(aldeanosLista,posicion)){
                    puts("Se elimino en posicion\n");
                }else puts("\nError al eliminar\n");
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