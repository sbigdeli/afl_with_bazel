#include <stddef.h>
#include <stdint.h>
#include "crypt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    // Copy data to a null-terminated string
    char *input = (char *)malloc(size + 1);
    if (input == NULL) {
        return 0;
    }
    memcpy(input, data, size);
    input[size] = '\0';

    const char *salt = "LongSaltStringForOneWayHashing";

    // Call the crypt function
    char *hash = crypt(input, salt);

    //printf("%s\n", hash);

    // Do something with the hash to avoid optimizing it away
    if (hash != NULL) {
        volatile char dummy;
        dummy = hash[0];
    }

    free(input);
    return 0;
}