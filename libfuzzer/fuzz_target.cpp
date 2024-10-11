// fuzz_target.cpp
#include <cstdint>
#include <cstdlib>
#include <iostream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size < 5) {
        return 0;  // ignorera inputs som är för små
    }

    // Simulera en krasch om input har ett specifikt mönster
    if (data[0] == 'c' && data[1] == 'r' && data[2] == 'a' && data[3] == 's' && data[4] == 'h') {
        std::cout << "Krasch!" << std::endl;
        abort();  // krascha programmet
    }
    return 0;  // inga problem, fuzz test fortsätter
}
