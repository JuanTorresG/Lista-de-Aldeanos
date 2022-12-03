#ifndef UTILIDADES_H
#define UTILIDADES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buffer[100];

char *leerCadena(char *mensaje){
    char *cadena;
    printf("%s",mensaje);
    cadena = fgets(buffer, sizeof(buffer), stdin);
    if(cadena != NULL){
        buffer[strlen(buffer)-1] = '\0';
        cadena = buffer;
    }
    return cadena;
}

int leerInt(char *mensaje){
    int entero;

    printf("%s",mensaje);
    scanf("%i",&entero);
    return entero;
}

size_t leerSize_t(char *mensaje){
    size_t st;

    printf("%s",mensaje);
    scanf("%zu",&st);
    return st;
}

float leerFloat(char *mensaje){
    float f;

    printf("%s",mensaje);
    scanf("%f",&f);
    return f;
}

#endif