cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cpp"],
   copts = ["-fsanitize=fuzzer", "-g", "-o1", "-fno-omit-frame-pointer"], 
   linkopts = ["-fsanitize=fuzzer"],
   
)

genrule(
   name = "afl_fuzz",
   srcs = [":my_fuzz_target"],
   outs = ["fuzz_output"],
   cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -i /home/lengdahl/Desktop/afl_with_bazel/test_inputs -o $(location fuzz_output) -- $(location :my_fuzz_target) @@",
   tags = ["no-sandbox"],
   executable = True,  
)

