#ifndef BUFFER_OVERFLOW_LIB_H
#define BUFFER_OVERFLOW_LIB_H

#include <cstddef>
#include <cstdint>

void TriggerBufferOverflow(const uint8_t *data, size_t size);

#endif  // BUFFER_OVERFLOW_LIB_H
