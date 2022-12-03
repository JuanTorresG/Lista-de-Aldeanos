#ifndef BARCO_H
#define BARCO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "pilaguerreros.h"

struct barco {
	size_t id;
	float combustible;
	float velocidad;
	float armadura;
	PilaGuerreros *guerreros;
};
typedef struct barco Barco;

Barco *Barco_init(size_t id, float combustible, float velocidad, float armadura){
    Barco *barco = (Barco*)malloc(sizeof(Barco));

    if(barco == NULL){
        puts("\nError al reservar memoria\n");
        return barco;
    }

    barco->id = id;
    barco->combustible = combustible;
    barco->velocidad = velocidad;
    barco->armadura = armadura;

    barco->guerreros = PilaGuerreros_init();

    return barco;
} 

Barco *Barco_free(Barco *barco){
    if(barco == NULL){
        puts("\nError al liberar memoria\n");
        return barco;
    }

    barco->guerreros = PilaGuerreros_free(barco->guerreros);
    barco = NULL;

    return barco;
}

bool Barco_mostrar(Barco *barco){
    if(barco == NULL){
        puts("El barco no tiene memoria");
        return false;
    }
        printf("%-7zu %15.1f %12.1f %11.1f %12zu\n",barco->id,barco->combustible,barco->velocidad,barco->armadura,barco->guerreros->cantidad);

    return true;
}

Barco *Barco_capturar(){
    size_t id = leerSize_t("ID: ");
    float combustible = leerFloat("Combustible: ");
    float velocidad = leerFloat("Velocidad: ");
    float armadura = leerFloat("Armadura: ");

    Barco *barco = Barco_init(id, combustible, velocidad, armadura);

    return barco;
}
#endif