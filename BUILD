cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cpp"],
   copts = ["-fsanitize=fuzzer", "-fsanitize=address", "-g", "-o1"],
   linkopts = ["-fsanitize=fuzzer", "-fsanitize=address"],
)
genrule(
   name = "afl_fuzz",
   srcs = [":my_fuzz_target"],
   outs = ["fuzz_output"],
   cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -Q -i test_inputs -o fuzz_output -- $(location :my_fuzz_target)",
   tags = ["manual"],
)