#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"lista_aldeanos.h"
#include"puerto.h"
#include"colabarcos.h"

struct civilizacion{
    char *nombre;
    AldeanosLista *aldeanosLista;
    Puerto *puerto;
    ColaBarcos *batalla;
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
    civilizacion->puerto = Puerto_init();
    civilizacion->batalla = colaBarcos_init();

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
    civilizacion->puerto = Puerto_free(civilizacion->puerto);
    civilizacion = NULL;
    return civilizacion;
} 

bool Civilizacion_mostrar(Civilizacion *civilizacion){
    if(civilizacion == NULL){
        puts("La civilizacion no tiene memoria");
        return false;
    }

    printf("\nNombre Civilizacio: %s\n",civilizacion->nombre);

    printf("\nCantidad de barcos %zu\n",civilizacion->puerto->cantidad);

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

bool Civilizacion_respaldar(Civilizacion *civilizacion, FILE *archivo){
    if(civilizacion == NULL){
        puts("Civilizacion: no tiene memoria");
        return false;
    }
    if(archivo == NULL){
        puts("Civilizacion: archivo nulo");
        return false;
    }

    fprintf(archivo, "%s\n", civilizacion->nombre);

    char nombre_civilizacion[100];
    strcpy(nombre_civilizacion, civilizacion->nombre);
    strcat(nombre_civilizacion, ".txt");

    AldeanosLista_respaldar(civilizacion->aldeanosLista, nombre_civilizacion);

    return true;
}

Civilizacion *Civilizacion_recuperar(FILE *archivo){

    if(archivo == NULL){
        puts("Civilizacion: archivo nulo");
        return NULL;
    }

    char buffer[100];
    fgets(buffer, 100, archivo);
    if(feof(archivo)) return NULL;
    buffer[strlen(buffer)-1] = '\0';

    Civilizacion *civilizacion = Civilizacion_init(buffer);

    //recuperar aldeanos
    char nombre_civilizacion[100];
    strcpy(nombre_civilizacion, civilizacion->nombre);
    strcat(nombre_civilizacion, ".txt");
    AldeanosLista_recuperar(civilizacion->aldeanosLista,nombre_civilizacion);

    return civilizacion;
}

#endif