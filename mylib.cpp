#include "mylib.h"
#include <iostream>
#include <cstdlib> // För abort()

void mylib_function(const uint8_t *data, size_t size) {
    // Kontrollera datainnehållet och simulera en krasch
    if (size < 4) return; // Kontrollera att datastorleken är tillräcklig
    if (data[0] == 'A' && data[1] == 'B' && data[2] == 'C' && data[3] == 'D') {
        std::cerr << "Crash detected in mylib!" << std::endl;
        abort();  // Simulera en krasch
    }
}