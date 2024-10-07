#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include "mylib.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    mylib_function(data, size); // Anropa funktionen i mylib
    return 0;
}
