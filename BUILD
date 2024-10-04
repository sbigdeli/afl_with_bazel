cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cpp", "mylib.cpp", "mylib.h"],
   copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"], 
   linkopts = ["-fsanitize=fuzzer"],
)

genrule(
   name = "afl_fuzz",
   srcs = [":my_fuzz_target", "test_inputs"],
   outs = ["fuzz_logs.logs", "fuzz_output.tar"],  
   cmd = """
   mkdir -p fuzz_output && \
   AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -V 10 -i $(location test_inputs) -o fuzz_output -- $(location :my_fuzz_target) @@ 2>&1 | tee $(location fuzz_logs.logs) && \
   tar -czf $(location fuzz_output.tar) fuzz_output
   """,
)


