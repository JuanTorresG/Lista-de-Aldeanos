#include <stdio.h>
#include <stdlib.h>

#include "civilizacion.h"
#include "menu_aldeanos.h"


int main() {
    
 Civilizacion *civilizacion = Civilizacion_init("Egipcios");
 menu_aldeanos(civilizacion->aldeanosLista);
 civilizacion = Civilizacion_free(civilizacion);

 return 0;
}