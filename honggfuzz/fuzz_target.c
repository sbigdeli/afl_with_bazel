#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  // Lägg till denna rad för abort()



int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size > 3 && data[0] == 'H' && data[1] == 'O' && data[2] == 'N' && data[3] == 'G') {
        printf("Crash triggered!\n");
        abort();  // Tvingar en segfault
    }
    return 0;
}
