#include <stdio.h>
#include <stdlib.h>
#include "civilizaciones.h"
#include "menu_civilizaciones.h"


int main() {
    Civilizaciones *civilizaciones = Civilizaciones_init();
    menu_civilizaciones(civilizaciones);
    civilizaciones = Civilizaciones_free(civilizaciones);

    return 0;
}