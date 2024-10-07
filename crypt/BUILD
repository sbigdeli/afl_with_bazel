cc_binary(
    name = "crypt_fuzz_target",
    srcs = ["crypttarget.c", "crypt.h"],
    copts = ["-fsanitize=fuzzer"],
    linkopts = ["-fsanitize=fuzzer", "-lcrypt"],
)

genrule(
   name = "afl_fuzz",
   srcs = [":crypt_fuzz_target", "corpus"],
   outs = ["fuzz_output"],
   cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -V 10 -i $(location corpus) -o $(location fuzz_output) -- $(location :crypt_fuzz_target) @@",
   tags = ["no-sandbox"],
   executable = True,  
)