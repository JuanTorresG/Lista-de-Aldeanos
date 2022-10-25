#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"lista_aldeanos.h"

struct civilizacion{
    char *nombre;
    AldeanosLista *aldeanosLista;
};

typedef struct civilizacion Civilizacion;

// reserva memoria con malloc
Civilizacion *Civilizacion_init(char *nombre){
    Civilizacion *civilizacion = (Civilizacion*)malloc(sizeof(Civilizacion));

    if(civilizacion == NULL){
        puts("\nError al reservar memoria\n");
        return civilizacion;
    }

    civilizacion->nombre = strdup(nombre);
    civilizacion->aldeanosLista = AldeanosLista_init();

    if(civilizacion->aldeanosLista == NULL) puts("\nError al crear AldeanosLista\n");

    return civilizacion;
}

// libera memoria con free
Civilizacion *Civilizacion_free(Civilizacion *civilizacion){
    if(civilizacion == NULL){
        puts("\nError al liberar memoria\n");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->aldeanosLista = AldeanosLista_free(civilizacion->aldeanosLista);
    civilizacion = NULL;
    return civilizacion;
} 

#endif