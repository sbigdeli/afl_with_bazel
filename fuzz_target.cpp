#include <stdint.h>
#include <stddef.h>
#include <iostream>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
   if (size < 4) return 0;
   // Example of fuzz target code
   if (data[0] == 'A' && data[1] == 'B' && data[2] == 'C' && data[3] == 'D') {
       std::cerr << "Crash detected!" << std::endl;
       abort();  // Simulate a crash
   }
   return 0;
}