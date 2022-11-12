#ifndef MENU_CIVILIZACIONES_H
#define MENU_CIVILIZACIONES_H

#include"civilizaciones.h"
#include"menu_aldeanos.h"

void menu_civilizaciones(Civilizaciones *civilizaciones){
    typedef enum{
        SALIR = 0,
        INSERTAR_INICIO, INSERTAR_FINAL,
        MOSTRAR,
        ELIMINAR_INICIO, ELIMINAR_FINAL,
        BUSCAR
    }MENU_CIVILIZACIONES;

    int op;
    Civilizacion *civilizacion;

    do{
        puts("1. Insertar incio");
        puts("2. Insertar final");
        puts("3. Mostrar");
        puts("4. Eliminar inicio");
        puts("5. Eliminar final");
        puts("6. Buscar");
        puts("0. Salir");
        scanf("%i",&op);
        while(getchar() != '\n');

        switch (op){
            case INSERTAR_INICIO:
                civilizacion = Civilizacion_capturar();

                if(civilizacion == NULL){
                     puts("Civilizacion no tiene memoria");
                    continue;
                }

                if(Civilizaciones_insertar_inicio(civilizaciones,civilizacion)){
                    puts("\nCivilizaciones: se inserto la inicio Civilizacion\n");
                }else puts("\nCivilizaciones: error al insertar al inicio Civilizacion\n");
                break;

            case INSERTAR_FINAL:
                civilizacion = Civilizacion_capturar();

                if(civilizacion == NULL){
                     puts("Civilizacion no tiene memoria\n");
                    continue;
                }

                if(Civilizaciones_insertar_final(civilizaciones,civilizacion)){
                    puts("\nCivilizaciones: se inserto la inicio Civilizacion\n");
                }else puts("\nCivilizaciones: error al insertar al inicio Civilizacion\n");
                break;
            
            case MOSTRAR:
                if(Civilizaciones_mostrar(civilizaciones)){
                    puts("\nCivilizaciones: se mostro civilizaciones\n");
                }else puts("\nCivilizaciones: error al mostrar civilizaciones\n");
                break;
            
            case ELIMINAR_INICIO:
                if(Civilizaciones_eliminar_inicio(civilizaciones)){
                    puts("\nCivilizaciones: se elimino al inicio Civilizacion\n");
                }else puts("\nCivilizaciones: error al eliminar al inicio Civilizacion\n");
                break;

            case ELIMINAR_FINAL:
                if(Civilizaciones_eliminar_final(civilizaciones)){
                    puts("\nCivilizaciones: se elimino al final Civilizacion\n");
                }else puts("\nCivilizaciones: error al eliminar al final Civilizacion\n");
                break;

            case BUSCAR:
                char *nombre = leerCadena("Nombre de la civilizacion: ");

                civilizacion = Civilizaciones_buscar(civilizaciones,nombre);

                if(civilizacion == NULL){
                    printf("Civilizaciones: No se encontro la civilizacion %s\n",nombre);
                    continue;
                }

                menu_aldeanos(civilizacion->aldeanosLista);
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