#include <iostream>
#include "functions.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main() {

    if (objectsFromFile().empty()) {
        // TODO: Suggest user to write some stuff to JSON
    } else {
        mainMenu();


    }

    _CrtDumpMemoryLeaks();
    return 0;
}
