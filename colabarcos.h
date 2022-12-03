#ifndef COLABARCOS_H
#define COLABARCOS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"barco.h"

struct cola_nodo{
    Barco *dato;
    struct cola_nodo *anterior;
    struct cola_nodo *siguiente;
};
typedef struct cola_nodo NodoCola;

NodoCola *NodoCola_init(Barco *dato){
    NodoCola *nodo = (NodoCola*)malloc(sizeof(NodoCola));

    if(nodo == NULL){
        puts("NodoCola: error al reservar memoria");
        return NULL;
    }

    nodo->dato = dato;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;

    return nodo;
}

struct cola{
    NodoCola *inicio;
    NodoCola *final;
    size_t cantidad;
};
typedef struct cola ColaBarcos;

ColaBarcos *colaBarcos_init(){
    ColaBarcos *colabarcos = (ColaBarcos*)malloc(sizeof(ColaBarcos));

    if(colabarcos ==  NULL){
        puts("Cola: error al reservar memoria");
        return NULL;
    }

    colabarcos->inicio = NULL;
    colabarcos->final = NULL;
    colabarcos->cantidad = 0;

    return colabarcos;
}

bool ColaBarcos_vacia(ColaBarcos *colabarcos){
    if(colabarcos == NULL){
        puts("ColaBarcos: no tiene memoria");
        exit(1);
    }

    return colabarcos->cantidad == 0;
}

bool ColaBarcos_encolar(ColaBarcos *colabarcos, Barco *dato){
    if(colabarcos == NULL){
        puts("Cola: no tiene memoria");
        return false;
    }
    // crear un nuevo nodoDoble
    NodoCola *nuevo = NodoCola_init(dato);
    if(ColaBarcos_vacia(colabarcos)){
        colabarcos->inicio = nuevo;
        colabarcos->final = nuevo;
        colabarcos->cantidad++;

        return true;
    }

    nuevo->anterior = colabarcos->final;
    colabarcos->final->siguiente = nuevo;
    colabarcos->final = nuevo;

    colabarcos->cantidad++;

    return true;
}


bool Cola_mostrar(ColaBarcos *colabarcos){
    if(colabarcos == NULL){
        puts("ColaBarcos: no tiene memoria");
        return false;
    }

    printf("\nCapacidad de Barcos: %zu\n",colabarcos->cantidad);

    NodoCola *temp = colabarcos->inicio;

    puts("-------------------------------------------------------------");
    printf("%-7s %15s %12s %11s %12s\n","ID","Combustible","Velocidad","Armadura","Guerreros");

    puts("-------------------------------------------------------------");

    while(temp != NULL){
        Barco_mostrar(temp->dato);
        temp = temp->siguiente;
    }
    puts("-------------------------------------------------------------");

    return true;
}

bool Cola_desencolar(ColaBarcos *colabarcos){
    if(colabarcos == NULL){
        puts("Cola: no tiene memoria");
        exit(1);
    }
    if(ColaBarcos_vacia(colabarcos)){
        puts("Cola: vacia");
        return false;
    }
    // repaldar el nodoDoble inicial
    NodoCola *temp = colabarcos->inicio;
    // enlazar raiz hacia el nodoDoble siguiente
    colabarcos->inicio = temp->siguiente; 
    
    
    // decrementar la cantidad
    colabarcos->cantidad--;

    if(ColaBarcos_vacia(colabarcos)){
        colabarcos->final = NULL;
    }else{
        colabarcos->inicio->anterior = NULL;
    }
    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

ColaBarcos *ColaBarcos_free(ColaBarcos *colabarcos){
    if(colabarcos== NULL){
        puts("ColaBarcos: no tiene memoria");
        return NULL;
    }

    while(!ColaBarcos_vacia(colabarcos)){
        Cola_desencolar(colabarcos);
    }

    free(colabarcos);
    colabarcos = NULL;

    return colabarcos;
}

Barco *ColaBarcos_tomar(ColaBarcos *colabarcos){
    if(colabarcos== NULL){
        puts("ColaBarcos: no tiene memoria");
        return NULL;
    }

    if(ColaBarcos_vacia(colabarcos)){
        puts("ColaBarcos: vacia");
        return NULL;
    }

    return colabarcos->inicio->dato; //cola->inicio->dato;
}


#endif