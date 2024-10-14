#include "buffer_overflow_lib.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  TriggerBufferOverflow(data, size);
  return 0;
}
