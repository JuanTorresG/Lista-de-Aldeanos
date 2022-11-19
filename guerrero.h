#ifndef GUERRERO_H
#define GUERRERO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"utilidades.h"

struct guerrero{
    size_t id;
    int salud;
    float fuerza;
    float escudo;
    char *tipo; 
};
typedef struct guerrero Guerrero;

Guerrero *Guerrero_init(size_t id, int salud, float fuerza, float escudo, char *tipo){
    Guerrero *guerrero = (Guerrero*)malloc(sizeof(Guerrero));

    if(guerrero != NULL){
        guerrero->id = id;
        guerrero->salud = salud;
        guerrero->fuerza = fuerza;
        guerrero->escudo = escudo;
        guerrero->tipo = strdup(tipo);
    }
    return guerrero;
}

Guerrero *Guerrero_free(Guerrero *guerrero){
    if(guerrero != NULL){
        free(guerrero->tipo);
        guerrero->tipo = NULL;
        free(guerrero);
        guerrero = NULL;
    }

    return guerrero;
}

Guerrero *Guerrero_capturar(){
    size_t id = leerSize_t("\nID: ");
    int salud = leerInt("Salud: ");
    float fuerza= leerFloat("Fuerza: ");
    float escudo = leerFloat("Escudo: ");
    while(getchar()!='\n');
    char *tipo = leerCadena("Tipo: ");

    Guerrero *guerrero = Guerrero_init(id, salud, fuerza, escudo, tipo);

    return guerrero;
}


bool Guerrero_mostrar(Guerrero *guerrero){
    bool NO_ERROR = false;

    if(guerrero != NULL){
        printf("\nID: %i\n",guerrero->id);
        printf("Salud: %i\n",guerrero->salud);
        printf("Fuerza: %.1f\n",guerrero->fuerza);
        printf("Escudo: %.1f\n",guerrero->escudo);
        printf("Tipo: %s\n",guerrero->tipo);

        NO_ERROR = true;
    }

    return NO_ERROR;
}

bool Guerrero_mostrar_fila(Guerrero *guerrero){
    bool NO_ERROR = false;

    if(guerrero != NULL){
    
        printf("%-9zu %7i %7.1f %7.1f %12s\n",guerrero->id,guerrero->salud,guerrero->fuerza,guerrero->escudo,guerrero->tipo);

        NO_ERROR = true;
    }

    return NO_ERROR;
}
#endif