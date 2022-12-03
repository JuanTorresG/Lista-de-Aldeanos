#ifndef LISTA_ALDEANOS_H
#define LISTA_ALDEANOS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "aldeano.h"

#define CAPACIDAD 5

struct lista_aldeanos {
	Aldeano **aldeanos;
	size_t cantidad;
	size_t capacidad;
};

typedef struct lista_aldeanos AldeanosLista;

AldeanosLista *AldeanosLista_init(){
    AldeanosLista *aldeanosLista = (AldeanosLista*)malloc(sizeof(AldeanosLista));

	if(aldeanosLista != NULL){
		aldeanosLista->aldeanos = (Aldeano**)malloc(sizeof(Aldeano*)*CAPACIDAD);

		if(aldeanosLista->aldeanos == NULL){
			puts("\nError al inicializar arreglos de Aldeanos\n");
			exit(1);
		}

		aldeanosLista->cantidad = 0;
		aldeanosLista->capacidad = CAPACIDAD;
	}
    return aldeanosLista;
}

AldeanosLista *AldeanosLista_free( AldeanosLista *aldeanosLista ){
	if(aldeanosLista != NULL){
		if(aldeanosLista->aldeanos != NULL){
			for(size_t i = 0; i < aldeanosLista->cantidad; i++){
				free(aldeanosLista->aldeanos[i]);
				
			}

			free(aldeanosLista->aldeanos);
			aldeanosLista->aldeanos = NULL;
			free(aldeanosLista);
			aldeanosLista = NULL;
		}
	}
	return aldeanosLista;
}

bool AldeanosLista_expandir(AldeanosLista *aldeanosLista){
	bool NO_ERROR = false;
	if(aldeanosLista != NULL){
		size_t nuevaCapacidad = aldeanosLista->capacidad + CAPACIDAD;
		Aldeano **tem = (Aldeano**)realloc(aldeanosLista->aldeanos, sizeof(Aldeano*)*nuevaCapacidad);
		if(tem != NULL){
			aldeanosLista->aldeanos = tem;
			aldeanosLista->capacidad = nuevaCapacidad;
			NO_ERROR = true;
		}else puts("\nError al expandir AldeanosLista\n");
	}
	return NO_ERROR;
}

bool AldeanosLista_mostrar( AldeanosLista *aldeanosLista ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
        printf("\ncantidad: %zu, capacidad: %zu\n\n",aldeanosLista->cantidad,aldeanosLista->capacidad);
		for(size_t i = 0; i < aldeanosLista->cantidad; i++){
			Aldeano_mostrar(aldeanosLista->aldeanos[i]);
		}											
		NO_ERROR = true;
	}

	return NO_ERROR;
}

bool AldeanosLista_llena( AldeanosLista *aldeanosLista ){
	if(aldeanosLista == NULL){
		puts("\nNo exixte AldeanosLista\n");
		exit(1);
	} 
	return aldeanosLista->cantidad == aldeanosLista->capacidad; 
}
bool AldeanosLista_vacia( AldeanosLista *aldeanosLista ){
    if(aldeanosLista == NULL){
        puts("\nNo existe AldeanosLista\n");
        exit(1);
    }
    return aldeanosLista->cantidad == 0;
}

bool AldeanosLista_agregar_inicio( AldeanosLista *aldeanosLista, Aldeano *aldeano ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
		if(AldeanosLista_llena(aldeanosLista)) AldeanosLista_expandir(aldeanosLista);
		for(size_t i = aldeanosLista->cantidad; i > 0; i--){
			aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
		}
		aldeanosLista->aldeanos[0] = aldeano;
		aldeanosLista->cantidad++;
		NO_ERROR = true;
	}

	return NO_ERROR;
}

bool AldeanosLista_agregar_final( AldeanosLista *aldeanosLista, Aldeano *aldeano ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
		if(AldeanosLista_llena(aldeanosLista)){
			AldeanosLista_expandir(aldeanosLista);
		} 
		aldeanosLista->aldeanos[aldeanosLista->cantidad] = aldeano;
		aldeanosLista->cantidad++;
		NO_ERROR = true;
	}
	
	return NO_ERROR;
}
bool AldeanosLista_insertar( AldeanosLista *aldeanosLista, Aldeano *aldeano, size_t posicion ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
		if(AldeanosLista_llena(aldeanosLista)) AldeanosLista_expandir(aldeanosLista);
		for(size_t i = aldeanosLista->cantidad; i > posicion; i--){
			aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
		}
		aldeanosLista->aldeanos[posicion] = aldeano;
		aldeanosLista->cantidad++;
		NO_ERROR = true;
	}

	return NO_ERROR;	
}

bool AldeanosLista_eliminar_inicio( AldeanosLista *aldeanosLista ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
		if(!AldeanosLista_vacia(aldeanosLista)){
			aldeanosLista->aldeanos[0] = Aldeano_free(aldeanosLista->aldeanos[0]);
		}
		if(aldeanosLista->aldeanos[0] == NULL){
			for (size_t i = 0; i < aldeanosLista->cantidad; i++){
				aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
			}
            puts("\nSe libero Aldeano\n");
            aldeanosLista->cantidad--;
            NO_ERROR = true;
		} else {
			puts("\nError al librerar Aldeano\n");
		}
	}
	return NO_ERROR;
}

bool AldeanosLista_eliminar_final( AldeanosLista *aldeanosLista ){
	bool NO_ERROR = false;

	if(aldeanosLista != NULL){
		if(!AldeanosLista_vacia(aldeanosLista)){
			aldeanosLista->aldeanos[aldeanosLista->cantidad-1] = Aldeano_free(aldeanosLista->aldeanos[aldeanosLista->cantidad-1]);
		
			if(aldeanosLista->aldeanos[aldeanosLista->cantidad-1] == NULL){
				puts("\nSe libero Aldeano\n");
				aldeanosLista->cantidad--;
				NO_ERROR = true;
			}else {
				puts("Error al liberar Aldeano\n");
			}
		}
	}
	return NO_ERROR;
}
bool AldeanosLista_eliminar( AldeanosLista *aldeanosLista, size_t posicion ){
	bool NO_ERROR = false;
	if(posicion >= aldeanosLista->cantidad){
		return NO_ERROR;
	}
	if(aldeanosLista != NULL){
		if(!AldeanosLista_vacia(aldeanosLista)){
			aldeanosLista->aldeanos[posicion] = Aldeano_free(aldeanosLista->aldeanos[posicion]);
		
			if(aldeanosLista->aldeanos[posicion] == NULL){
				for (size_t i = posicion; i < aldeanosLista->cantidad; i++){
					aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
				}
				puts("\nSe libero Aldeano\n");
				aldeanosLista->cantidad--;
				NO_ERROR = true;
			}else{
				puts("Error al liberar Aldeano\n");
			}
		}
	}
	return NO_ERROR;
}

bool AldeanosLista_motrar_tabla(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;

    if(aldeanosLista != NULL){
        printf("\n%-12s %9s %7s\n","Nombre", "Edad", "Salud");
        for(size_t i = 0; i < aldeanosLista->cantidad; i++){
			puts("--------------------------------");
            Aldeano_mostrar_fila(aldeanosLista->aldeanos[i]);
        }
		puts("--------------------------------");
        printf("cantidad: %zu, capacidad: %zu\n\n",aldeanosLista->cantidad,aldeanosLista->capacidad);
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_respaldar(AldeanosLista* aldeanoslista, char *nombre_civilizacion){
	if(aldeanoslista == NULL){
		puts("Aldeanoslista: no tiene memoria");
		return false;
	}

	FILE * archivo = fopen(nombre_civilizacion, "w");
	if(archivo == NULL){
		puts("aldeanosLista: error al crear el archivo");
		return false;
	}

	for (size_t i = 0; i < aldeanoslista->cantidad; i++){
		//respaldar aldeano
		Aldeano_respaldar(aldeanoslista->aldeanos[i],archivo);

	}

	fclose(archivo);

	return true;
}

bool AldeanosLista_recuperar(AldeanosLista *aldeanoslista,char *nombre_civilizacion){
	if(aldeanoslista == NULL){
		puts("Aldeanoslista: no tiene memoria");
		return false;
	}

	FILE * archivo = fopen(nombre_civilizacion, "r");
	if(archivo == NULL){
		puts("aldeanosLista: error al abrir el archivo");
		return false;
	}

	while(true){
		//recuperar aldeano
		Aldeano *aldeano = Aldeano_recuperar(archivo);
		if(aldeano == NULL) break;
		AldeanosLista_agregar_final(aldeanoslista, aldeano);
	}

	fclose(archivo);

	return true;
}

#endif 

