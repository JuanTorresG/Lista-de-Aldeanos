#ifndef MENU_CIVILIZACION_H
#define MENU_CIVILIZACION_H

#include"civilizacion.h"
#include"menu_aldeanos.h"
#include"menu_puerto.h"


void menu_civilizacion(Civilizacion *civilizacion){
    typedef enum{
        SALIR = 0,
        MENU_ALDEANOS,
        MENU_PUERTO,
        INICIO_AGREGAR_BATALLA,
        FINAL_AGREGAR_BATALLA,
        SACAR_BATALLA,
        MOSTRAR_BATALLA,
        BATALLA_MOSTRAR
    }MENU_CIVILIZACION;
    Barco *barco;
    float velocidad;
    float combustible;
    float armadura;
    int op;
    do{

        puts("\n1. Aldeanos");
        puts("2. Puerto");
        puts("3. Inicio agregar a la batalla");
        puts("4. Final agregar a la batalla");
        puts("5. Sacar Batalla");
        puts("6. Mostrar Barcos en batalla");
        puts("0. Salir");

        scanf("%i",&op);

    
        switch(op){
            case MENU_ALDEANOS:
                menu_aldeanos(civilizacion->aldeanosLista);
                break;
            case MENU_PUERTO:
                menu_puerto(civilizacion->puerto);
                break;

            case INICIO_AGREGAR_BATALLA:
                if(Puerto_vacia(civilizacion->puerto)){
                    puts("Puerto: Vacio");
                    continue;
                }

                barco = civilizacion->puerto->inicio->dato;
                if(barco->armadura == 0.0){
                    puts("Barco destruido");
                    Puerto_remover_inicio(civilizacion->puerto);
                    continue;
                }
                if(barco->combustible == 0.0){
                    puts("Barco: no tiene combustible");
                    continue;
                }

                if(barco->combustible > 0.0){
                    float velocidad;
                    barco->velocidad = leerFloat("Velocidad del barco: ");
                }
                if(ColaBarcos_encolar(civilizacion->batalla, barco)){
                    puts("ColaBarcos: se encolo Barco");
                }else puts("ColaBarcos: error al encolar barco");

                Puerto_remover_inicio(civilizacion->puerto);
                
                break;

            case FINAL_AGREGAR_BATALLA:
                if(Puerto_vacia(civilizacion->puerto)){
                    puts("Puerto: Vacio");
                    continue;
                }
                barco = civilizacion->puerto->final->dato;
                if(barco->armadura == 0.0){
                    puts("Barco destruido");
                    Puerto_remover_final(civilizacion->puerto);
                    continue;
                }
                if(barco->combustible == 0.0){
                    puts("Barco: no tiene combustible");
                    continue;
                }
                
                if(barco->combustible > 0.0){
                    barco->velocidad = leerFloat("Velocidad del barco: ");
                }
                if(ColaBarcos_encolar(civilizacion->batalla, barco)){
                    puts("ColaBarcos: se encolo Barco");
                }else puts("ColaBarcos: error al encolar barco");
                Puerto_remover_final(civilizacion->puerto);
                break;

            case SACAR_BATALLA:
                barco = ColaBarcos_tomar(civilizacion->batalla);
                if(Cola_desencolar(civilizacion->batalla)){
                    puts("ColaBarcos: se desencolo Barco");
                }else{
                    puts("ColaBarcos: Error al desencolar Barco");
                    continue;
                }

                barco->velocidad = 0.0;
                barco->armadura = leerFloat("Armadura: ");
                barco->combustible = leerFloat("Combustible: ");

                if(barco->armadura == 0.0){
                    puts("Barco destruido");
                    continue;
                }
                int opc;
                do{
                    
                    puts("1. Insertar al inicio");
                    puts("2. Insertar al final");

                    scanf("%i",&opc);
                    switch(opc){
                        case 1:
                            if(Puerto_insertar_inicio(civilizacion->puerto, barco)){
                            puts("\nPuerto: se agrego al inicio Barco\n");
                            }else puts("\nPuerto: error al insertar al inicio Barco");
                            break;
                        case 2:
                            if(Puerto_insertar_final(civilizacion->puerto, barco)){
                            puts("\nPuerto: se agrego al final Barco\n");
                            }else puts("\nPuerto: error al insertar al final Barco");
                            break;
                        default:
                            puts("Opcion no valida");
                            break;
                    }
                
                }while(opc != 1 && opc != 2);

                
                break;
            case MOSTRAR_BATALLA:
                if(Cola_mostrar(civilizacion->batalla)){
                    puts("\nColaBarcos: se mostro ColaBarcos\n");
                }else puts("\nColaBarcos: error al mostrar ColaBarcos\n");
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