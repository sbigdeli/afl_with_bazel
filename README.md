# afl_with_bazel

To run AFL++ fuzz tests with **Bazel**, you will need to integrate AFL++ with Bazel and set up a suitable build environment. Here are the general steps to follow:
### 1. **Set Up AFL++**
First, make sure you have AFL++ installed. You can install it on Linux using the following commands:
```bash
git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
make distrib
sudo make install
extra installationskommand:
sudo apt-get install build-essential pkg-config libglib2.0-dev libpixman-1-dev
sudo apt-get install cmake
sudo apt-get install autoconf
sudo apt-get install automake


```
After installation, you should be able to use the `afl-fuzz` command.
### 2. **Set Up Bazel Rules for Fuzzing**
You need to configure Bazel to use AFL++ for building fuzz tests. Since Bazel supports custom build rules, you can create a new rule for AFL++. Here's a general approach to set up a fuzz test in Bazel.
- **Define a custom AFL++ rule** in a Bazel build file that tells Bazel how to instrument the binary for fuzzing.
Create a `BUILD` file that looks something like this:
```python
cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cc"],
   copts = ["-fsanitize=fuzzer", "-fsanitize=address"],
   linkopts = ["-fsanitize=fuzzer", "-fsanitize=address"],
   deps = [
       "//some:dependency",
   ],
)
genrule(
   name = "afl_fuzz",
   srcs = [":my_fuzz_target"],
   outs = ["fuzz_output"],
   cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -i test_inputs -o fuzz_output -- $(location :my_fuzz_target)",
   tags = ["manual"],
)
```
Here is an explanation of the `BUILD` file components:
- `cc_binary`: Defines the fuzz target as a C++ binary. You use sanitizers like AddressSanitizer (`-fsanitize=address`) or libFuzzer (`-fsanitize=fuzzer`) for better fuzzing results.
- `genrule`: Defines a custom rule that runs AFL++ using the compiled fuzz target. It uses the `afl-fuzz` command with required parameters:
 - `-i test_inputs`: Directory where input seeds are stored.
 - `-o fuzz_output`: Directory where fuzzing outputs (like crashes) are stored.
 - `-- $(location :my_fuzz_target)`: The fuzz target binary.
### 3. **Prepare Your Fuzz Target**
Create a fuzzing target (e.g., `fuzz_target.cc`). A simple fuzz target looks like this:
```cpp
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
```
### 4. **Create Input Seeds Directory**
AFL++ needs a directory with initial seed inputs. Create this directory:
```bash
mkdir test_inputs
echo "AAAA" > test_inputs/input1
```
### 5. **Run AFL++ Fuzzing with Bazel**
You can now run AFL++ fuzzing using Bazel:
```bash
bazel build //:afl_fuzz
```
After building, manually run AFL++ from the generated binary:
```bash
bazel-bin/afl_fuzz
```
Alternatively, run AFL++ directly using Bazel commands:
```bash
bazel run //:afl_fuzz
```
This will launch AFL++ with your fuzz target, and it will begin fuzzing.
### 6. **Optional: Use AFL++'s Custom Instrumentation**
For improved fuzzing, you can use AFL++'s custom instrumentation by adding the appropriate compile options:
```bash
copts = ["-fuse-ld=gold", "-fsanitize=address", "-fsanitize-coverage=trace-pc-guard"],
linkopts = ["-fsanitize=fuzzer", "-fsanitize=address"],
```
Make sure that AFL++ is aware of these options during runtime.
### 7. **Monitor and Analyze Results**
AFL++ will generate the fuzzing results in the `fuzz_output` directory. You can check this directory for crashes or test cases that triggered interesting behaviors.
---
By following these steps, you should be able to integrate AFL++ with Bazel and run fuzz tests successfully. If you need to scale this up or automate AFL++ usage with Bazel, you may want to explore using custom Bazel rules or Skylark scripts to streamline the process.