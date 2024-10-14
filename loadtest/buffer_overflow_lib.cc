#include "buffer_overflow_lib.h"
#include <cstdio>

void TriggerBufferOverflow(const uint8_t *data, size_t size) {
  if (size >= 3 && data[0] == 'F' && data[1] == 'U' && data[2] == 'Z' &&
      data[size] == 'Z') {
    fprintf(stderr, "BUFFER OVERFLOW!\n");
  }
}
