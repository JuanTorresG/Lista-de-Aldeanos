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

bool Civilizacion_mostrar(Civilizacion *civilizacion){
    if(civilizacion == NULL){
        puts("La civilizacion no tiene memoria");
        return false;
    }

    printf("\nNombre Civilizacio: %s\n",civilizacion->nombre);

    if(AldeanosLista_motrar_tabla(civilizacion->aldeanosLista)){
        puts("AldeanosLista: se mostro lista de aldenos");
    }else{
        puts("AldeanosLista: error al mostrar lista de aldeanos");
        return false;
    }

    return true;
}

Civilizacion *Civilizacion_capturar(){
    char *nombre = leerCadena("\nNombre de la civilizacion: ");

    Civilizacion *civilizacion = Civilizacion_init(nombre);

    return civilizacion;
}
#endif