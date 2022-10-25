#ifndef ALDEANO_H
#define ALDEANO_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#include"utilidades.h"

struct aldeano{
    char *nombre;
    int edad;
    int salud;
};

typedef struct aldeano Aldeano;

// reserva memoria con malloc
Aldeano *Aldeano_init(char *nombre, int edad, int salud){
    Aldeano *aldeano = (Aldeano*)malloc(sizeof(Aldeano));
    if(aldeano != NULL){
        aldeano->nombre = strdup(nombre);
        aldeano->edad = edad;
        aldeano->salud = salud;
    }
    return aldeano;
}

// libera memoria con free
Aldeano *Aldeano_free(Aldeano *aldeano){
    if(aldeano != NULL){
        free(aldeano->nombre);
        aldeano->nombre = NULL;
        free(aldeano);
        aldeano = NULL;
    }
    return aldeano;
} 

// pide al usuario cada atributo
Aldeano *Aldeano_capturar(){
    char *nombre = leerCadena("\nNombre: ");
    int edad = leerInt("Edad: ");
    int salud = leerInt("Salud: ");

    Aldeano *aldeano = Aldeano_init(nombre, edad, salud);

    return aldeano;
} 

bool Aldeano_mostrar(Aldeano *aldeano){
    bool NO_ERROR = false;

    if(aldeano != NULL){
        printf("Nombre: %s\n",aldeano->nombre);
        printf("Edad: %i\n",aldeano->edad);
        printf("Salud: %i\n\n",aldeano->salud);

        NO_ERROR = true;
    }

    return NO_ERROR;
}

bool Aldeano_mostrar_fila(Aldeano *aldeano){
    bool NO_ERROR = false;

    if(aldeano != NULL){
    
        printf("%-12s %9i %7i\n",aldeano->nombre,aldeano->edad,aldeano->salud);

        NO_ERROR = true;
    }

    return NO_ERROR;
}

#endif