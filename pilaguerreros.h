#ifndef PILAGUERREROS_H
#define PILAGUERREROS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "guerrero.h"

struct nodo{
    Guerrero *guerrero;
    struct nodo *siguiente;
};
typedef struct nodo Nodo;

Nodo *nodo_init(Guerrero *guerrero){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));

    if(nodo == NULL){
        puts("Nodo: error al reservar memoria");
        return NULL;
    }

    nodo->guerrero = guerrero;
    nodo->siguiente = NULL;

    return nodo;
}

struct pilaguerreros{
    Nodo *raiz;
    size_t cantidad;
};
typedef struct pilaguerreros PilaGuerreros;

PilaGuerreros *PilaGuerreros_init(){
    PilaGuerreros *pilaguerreros = (PilaGuerreros*)malloc(sizeof(PilaGuerreros));

    if(pilaguerreros == NULL){
        puts("PilaGuerreros: error al reservar memoria");
        return NULL;
    }

    pilaguerreros->raiz = NULL;
    pilaguerreros->cantidad = 0;

    return pilaguerreros;
}

bool PilaGuerreros_apilar(PilaGuerreros *pilaguerreros, Guerrero *guerrero){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        return false;
    }


    Nodo *nuevo = nodo_init(guerrero);

    nuevo->siguiente = pilaguerreros->raiz;

    pilaguerreros->raiz = nuevo;

    pilaguerreros->cantidad++;

    return true;
}

//mostrar en formato tabla
bool PilaGuerreros_mostrar(PilaGuerreros *pilaguerreros){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        return false;
    }

    printf("\ncapacidad: %zu\n\n", pilaguerreros->cantidad);

    Nodo *temp = pilaguerreros->raiz;

    puts("----------------------------------------------");
    printf("%-9s %7s %7s %7s %12s\n","ID","Salud","Fuerza","Escudo","Tipo");

    puts("----------------------------------------------");

    while(temp != NULL){
        Guerrero_mostrar_fila(temp->guerrero);
        temp = temp->siguiente;
    }
    puts("----------------------------------------------");

    return true;
}

bool PilaGuerreros_vacia(PilaGuerreros *pilaguerreros){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        exit(1);
    }

    return pilaguerreros->cantidad == 0;
}

bool PilaGuerreros_deasapilar(PilaGuerreros *pilaguerreros){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        return false;
    }
    if(PilaGuerreros_vacia(pilaguerreros)){
        puts("PilaGerreros: Vacia");
        return false;
    }

    Nodo *temp = pilaguerreros->raiz;

    pilaguerreros->raiz = temp->siguiente;

    free(temp);
    temp = NULL;

    pilaguerreros->cantidad--;

    return true;
}

PilaGuerreros *PilaGuerreros_free(PilaGuerreros *pilaguerreros){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        return NULL;
    }

    while (!PilaGuerreros_vacia(pilaguerreros)){
        PilaGuerreros_deasapilar(pilaguerreros);
    }

    free(pilaguerreros);
    pilaguerreros = NULL;
    
    return pilaguerreros;
}

Guerrero *PilaGuerreros_tope(PilaGuerreros *pilaguerreros){
    if(pilaguerreros == NULL){
        puts("PilaGuerreros: no tiene memoria");
        return NULL;
    }

    if(PilaGuerreros_vacia(pilaguerreros)){
        puts("PilaGuerreros: vacia");
        return NULL;
    }

    return pilaguerreros->raiz->guerrero;
}

#endif