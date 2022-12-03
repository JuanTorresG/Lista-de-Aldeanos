#ifndef PUERTO_H
#define PUERTO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"barco.h"

struct nodo_doble_barco{
    Barco *dato;
    struct nodo_doble_barco *siguiente;
    struct nodo_doble_barco *anterior;
};
typedef struct nodo_doble_barco NodoDobleBarco;

NodoDobleBarco *NodoDobleBarco_init(Barco *dato){
    NodoDobleBarco *nodoDoble = (NodoDobleBarco* )malloc(sizeof(NodoDobleBarco));

    if(nodoDoble == NULL){
        printf("NodoDoble: error la reservar memoria");
        return NULL;
    }

    nodoDoble->dato = dato;
    nodoDoble->siguiente = NULL;
    nodoDoble->anterior = NULL;

    return nodoDoble;
}

struct puerto{
    NodoDobleBarco *inicio;
    NodoDobleBarco *final;
    size_t cantidad;
};
typedef struct puerto Puerto;

Puerto *Puerto_init(){
    Puerto *listaLigadaDoble = (Puerto*)malloc(sizeof(Puerto));

    if(listaLigadaDoble == NULL){
        puts("Error al reservar memoria");
        return NULL;
    }

    listaLigadaDoble->final = NULL;
    listaLigadaDoble->inicio = NULL;
    listaLigadaDoble->cantidad = 0;

    return listaLigadaDoble;
}

bool Puerto_vacia(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }
    return listaLigadaDoble->cantidad == 0;
}

bool Puerto_insertar_inicio(Puerto *listaLigadaDoble, Barco *dato){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return false;
    }

    //crear un nueco nodoDoble
    NodoDobleBarco *nuevo = NodoDobleBarco_init(dato);

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;

        return true;
    }

    nuevo->siguiente = listaLigadaDoble->inicio;
    listaLigadaDoble->inicio->anterior = nuevo;
    listaLigadaDoble->inicio = nuevo;

    listaLigadaDoble->cantidad++;

    return true;
}

bool Puerto_insertar_final(Puerto *listaLigadaDoble, Barco *dato){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return false;
    }

    //crear un nueco nodoDoble
    NodoDobleBarco *nuevo = NodoDobleBarco_init(dato);

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;

        return true;
    }

    nuevo->anterior = listaLigadaDoble->final;
    listaLigadaDoble->final->siguiente = nuevo;
    listaLigadaDoble->final = nuevo;

    listaLigadaDoble->cantidad++;

    return true;
}

bool Puerto_eliminar_inicio(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(Puerto_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble inicial
    NodoDobleBarco *temp = listaLigadaDoble->inicio;

    // enlazar raiz hacia el nodoDoble siguiente
    listaLigadaDoble->inicio = temp->siguiente; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->final = NULL;
    }else{
        listaLigadaDoble->inicio->anterior = NULL;
    }

    Barco_free(temp->dato);

    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

bool Puerto_eliminar_final(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(Puerto_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble final
    NodoDobleBarco *temp = listaLigadaDoble->final;

    // enlazar raiz hacia el nodoDoble anterio
    listaLigadaDoble->final = temp->anterior; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = NULL;
    }else{
        listaLigadaDoble->final->siguiente = NULL;
    }

    Barco_free(temp->dato);

    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}
bool Puerto_remover_inicio(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(Puerto_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble inicial
    NodoDobleBarco *temp = listaLigadaDoble->inicio;

    // enlazar raiz hacia el nodoDoble siguiente
    listaLigadaDoble->inicio = temp->siguiente; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->final = NULL;
    }else{
        listaLigadaDoble->inicio->anterior = NULL;
    }
    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

bool Puerto_remover_final(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(Puerto_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble final
    NodoDobleBarco *temp = listaLigadaDoble->final;

    // enlazar raiz hacia el nodoDoble anterio
    listaLigadaDoble->final = temp->anterior; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(Puerto_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = NULL;
    }else{
        listaLigadaDoble->final->siguiente = NULL;
    }
    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

Puerto *Puerto_free(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return NULL;
    }

    while(!Puerto_vacia(listaLigadaDoble)){
        Puerto_eliminar_inicio(listaLigadaDoble);
    }

    free(listaLigadaDoble);
    listaLigadaDoble = NULL;

    return listaLigadaDoble;
}

bool Puerto_mostrar(Puerto *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria\n");
        return false;
    }

    printf("\nCapacidad de Barcos: %zu\n",listaLigadaDoble->cantidad);

    NodoDobleBarco *temp = listaLigadaDoble->inicio;

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

Barco *Puerto_buscar(Puerto *puerto, size_t id){
    if(puerto == NULL){
        puts("Puerto: no tiene memoria");
        return NULL;
    }

    NodoDobleBarco *temp = puerto->inicio;

    while (temp != NULL){
        if(id == temp->dato->id){
            return temp->dato;
        }

        temp = temp->siguiente; //salto al siguiente nodoDoble
    }

    return NULL;
}


#endif
