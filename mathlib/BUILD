cc_library(
    name = "mathlib",
    srcs = ["mathlib.cpp"],
    hdrs = ["mathlib.h"],
)

cc_binary(
    name = "fuzz_target_math",
    srcs = ["fuzz_target_math.cpp"],
    deps = [":mathlib"],  # Länka mot mathlib
    copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"],
    linkopts = ["-fsanitize=fuzzer"],
)

genrule(
    name = "afl_fuzz_math",
    srcs = [":fuzz_target_math", "test_inputs"],
    outs = ["fuzz_output_math"],
    cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -V 10 -i $(location test_inputs) -o $(location fuzz_output_math) -- $(location :fuzz_target_math) @@",
    tags = ["no-sandbox"],
    executable = True,  
)