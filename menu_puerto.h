#ifndef MENU_PUERTO_H
#define MENU_PUERTO_H

#include"puerto.h"
#include"menu_pilaguerreros.h"

void menu_puerto(Puerto *puerto){
    typedef enum{
        SALIR = 0,
        INSERTAR_INICIO, INSERTAR_FINAL,
        MOSTRAR,
        ELIMINAR_INICIO, ELIMINAR_FINAL,
        BUSCAR
    }MENU_PUERTO;

    int op;

    Barco *barco;

    do{
        puts("\n1. Agregar Barco Inicio");
        puts("2. Agregar Barco final");
        puts("3. Mostrar todos los Barcos");
        puts("4. Eliminar Barco Inicio");
        puts("5. Eliminar Barco Final");
        puts("6. Buscar barcos");
        puts("0. Salir");

        scanf("%i",&op);

        while(getchar() != '\n');

        switch(op){
            case INSERTAR_INICIO:
                barco = Barco_capturar();

                if(barco == NULL){
                    puts("Barco no tiene memoria");
                    continue;
                }

                if(Puerto_insertar_inicio(puerto, barco)){
                    puts("\nPuerto: se agrego al inicio Barco\n");
                }else puts("\nPuerto: error al insertar al inicio Barco");
                break;
            
            case INSERTAR_FINAL:
                barco = Barco_capturar();

                if(barco == NULL){
                    puts("Barco no tiene memoria");
                    continue;
                }

                if(Puerto_insertar_final(puerto, barco)){
                    puts("\nPuerto: se agrego al final Barco\n");
                }else puts("\nPuerto: error al insertar al final Barco");
                break;

                case MOSTRAR:
                    if(Puerto_mostrar(puerto)){
                    puts("\nPuerto: se mostro Puerto\n");
                }else puts("\nPuerto: error al mostrar Puerto\n");
                break;
            case ELIMINAR_INICIO:
                if(Puerto_eliminar_inicio(puerto)){
                    puts("\nPuerto: se elimino al inicio Puerto\n");
                }else puts("\nPuerto: error al eliminar al inicio Puerto\n");
                break;

            case ELIMINAR_FINAL:
                if(Puerto_eliminar_final(puerto)){
                    puts("\nPuerto: se elimino al final Puerto\n");
                }else puts("\nPuerto: error al eliminar al final Puerto\n");
                break;
            case BUSCAR:
                size_t id = leerSize_t("ID del barco: ");

                barco = Puerto_buscar(puerto,id);

                if(barco == NULL){
                    printf("Puerto: No se encontro el barco con el ID:  %zu\n",id);
                    continue;
                }
                menu_pilaguerreros(barco->guerreros);
                

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