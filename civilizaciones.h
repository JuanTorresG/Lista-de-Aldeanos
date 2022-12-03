#ifndef CIVILIZACIONES_H
#define CIVILIZACIONES_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"civilizacion.h"

struct nodo_doble{
    Civilizacion *dato;
    struct nodo_doble *siguiente;
    struct nodo_doble *anterior;
};

typedef struct nodo_doble NodoDoble;

NodoDoble *NodoDoble_init(Civilizacion *dato){
    NodoDoble *nodoDoble = (NodoDoble* )malloc(sizeof(NodoDoble));

    if(nodoDoble == NULL){
        printf("NoodoDoble: error la reservar memoria");
        return NULL;
    }

    nodoDoble->dato = dato;
    nodoDoble->siguiente = NULL;
    nodoDoble->anterior = NULL;

    return nodoDoble;
}

struct listaLigadaDoble{
    NodoDoble *inicio;
    NodoDoble *final;
    size_t cantidad;
};
typedef struct listaLigadaDoble ListaLigadaDoble;

ListaLigadaDoble *ListaLigadaDoble_init(){
    ListaLigadaDoble *listaLigadaDoble = (ListaLigadaDoble*)malloc(sizeof(ListaLigadaDoble));

    if(listaLigadaDoble == NULL){
        puts("Error al reservar memoria");
        return NULL;
    }

    listaLigadaDoble->final = NULL;
    listaLigadaDoble->inicio = NULL;
    listaLigadaDoble->cantidad = 0;

    return listaLigadaDoble;
}

bool ListaLigadaDoble_vacia(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }
    return listaLigadaDoble->cantidad == 0;
}

bool ListaLigadaDoble_insertar_inicio(ListaLigadaDoble *listaLigadaDoble, Civilizacion *dato){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return false;
    }

    //crear un nueco nodoDoble
    NodoDoble *nuevo = NodoDoble_init(dato);

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
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

bool ListaLigadaDoble_insertar_final(ListaLigadaDoble *listaLigadaDoble, Civilizacion *dato){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return false;
    }

    //crear un nueco nodoDoble
    NodoDoble *nuevo = NodoDoble_init(dato);

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
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

bool ListaLigadaDoble_eliminar_inicio(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble inicial
    NodoDoble *temp = listaLigadaDoble->inicio;

    // enlazar raiz hacia el nodoDoble siguiente
    listaLigadaDoble->inicio = temp->siguiente; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->final = NULL;
    }else{
        listaLigadaDoble->inicio->anterior = NULL;
    }

    Civilizacion_free(temp->dato);

    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

bool ListaLigadaDoble_eliminar_final(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        exit(1);
    }

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("ListaLigadaDoble: vacia");
        return false;
    }

    // repaldar el nodoDoble final
    NodoDoble *temp = listaLigadaDoble->final;

    // enlazar raiz hacia el nodoDoble anterio
    listaLigadaDoble->final = temp->anterior; 
    
    // decrementar la cantidad
    listaLigadaDoble->cantidad--;

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = NULL;
    }else{
        listaLigadaDoble->final->siguiente = NULL;
    }

    Civilizacion_free(temp->dato);

    // liberar el respaldo
    free(temp);
    temp = NULL;

    return true;
}

ListaLigadaDoble *ListaLigadaDoble_free(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria");
        return NULL;
    }

    while(!ListaLigadaDoble_vacia(listaLigadaDoble)){
        ListaLigadaDoble_eliminar_inicio(listaLigadaDoble);
    }

    free(listaLigadaDoble);
    listaLigadaDoble = NULL;

    return listaLigadaDoble;
}

bool ListaLigadaDoble_mostrar(ListaLigadaDoble *listaLigadaDoble){
    if(listaLigadaDoble == NULL){
        puts("ListaLigadaDoble: no tiene memoria\n");
        return false;
    }

    printf("\nCantidad de Civilizaciones: %zu\n",listaLigadaDoble->cantidad);

    NodoDoble *temp = listaLigadaDoble->inicio;

    while (temp != NULL){
        if(Civilizacion_mostrar(temp->dato)){
            puts("Civilizacion: se mostro Civilizacion");
        }else puts("Civilizacion: error al mostrar Civilizacion\n");

        temp = temp->siguiente; //salto al siguiente nodoDoble
    }
    
    return true;
}

typedef struct listaLigadaDoble Civilizaciones;

#define Civilizaciones_init ListaLigadaDoble_init
#define Civilizaciones_free ListaLigadaDoble_free
#define Civilizaciones_insertar_inicio ListaLigadaDoble_insertar_inicio
#define Civilizaciones_insertar_final ListaLigadaDoble_insertar_final
#define Civilizaciones_eliminar_inicio ListaLigadaDoble_eliminar_inicio
#define Civilizaciones_eliminar_final ListaLigadaDoble_eliminar_final
#define Civilizaciones_mostrar ListaLigadaDoble_mostrar

Civilizacion *Civilizaciones_buscar(Civilizaciones *civilizaciones, char *nombre){
    if(civilizaciones == NULL){
        puts("civilizaciones: no tiene memoria");
        return NULL;
    }

    NodoDoble *temp = civilizaciones->inicio;

    while (temp != NULL){
        if(strcmp(nombre,temp->dato->nombre) == 0){
            return temp->dato;
        }

        temp = temp->siguiente; //salto al siguiente nodoDoble
    }

    return NULL;
}

bool Civilizaciones_respaldar(Civilizaciones *civilizaciones){
    if(civilizaciones == NULL){
        puts("Civilizaciones: no tiene memoria");
        return false;
    }

    if(civilizaciones->cantidad == 0){
        puts("Civilizaciones: no hay civilizaciones");
        return false;
    }

    FILE *archivo = fopen("civilizaciones.txt", "w");
    if(archivo == NULL){
        puts("Civilizaciones: error al crear archivo");
        return false;
    }

    NodoDoble *temp = civilizaciones->inicio;
    while(temp != NULL){
        Civilizacion_respaldar(temp->dato, archivo);
        temp = temp->siguiente;
    }

    fclose(archivo);

    return true;
}

bool Civilizaciones_recuperar(Civilizaciones *civilizaciones){
    if(civilizaciones == NULL){
        puts("Civilizaciones: no tiene memoria");
        return false;
    }

    FILE *archivo = fopen("civilizaciones.txt", "r");
    if(archivo == NULL){
        puts("Civilizaciones: error al abrir el archivo");
        return false;
    }

    while (true){
        Civilizacion *civilizacion = Civilizacion_recuperar(archivo);
        if(civilizacion == NULL) break;
        Civilizaciones_insertar_final(civilizaciones, civilizacion);
    }

    fclose(archivo);

    return true;
    
}

#endif