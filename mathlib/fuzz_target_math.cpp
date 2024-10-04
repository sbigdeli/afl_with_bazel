#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include "mathlib/mathlib.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size < 2) return 0;  // Vi behöver minst två bytes för att göra beräkningar

    int a = data[0]; // Första byte som tal
    int b = data[1]; // Andra byte som tal

    
    // Exempel på olika matematiska operationer
    int sum = MathLib::add(a, b);
    int difference = MathLib::subtract(a, b);
    int product = MathLib::multiply(a, b);
    double quotient = MathLib::divide(a, b); // Kan kasta ett undantag vid division med 0

    std::cerr << "Sum: " << sum << ", Difference: " << difference 
                << ", Product: " << product << ", Quotient: " << quotient << std::endl;
    return 0;
}