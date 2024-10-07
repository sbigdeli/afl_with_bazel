cc_binary(
   name = "fuzz_target_crypt",
   srcs = ["crypttarget.c", "crypt.h"],
   copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"], 
   linkopts = ["-fsanitize=fuzzer" , "-lcrypt"],
   
)

genrule(
   name = "afl_fuzz_crypt",
   srcs = [":fuzz_target_crypt", "corpus"],
   outs = ["fuzz_output"],
   cmd = "AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -V 300 -i $(location corpus) -o $(location fuzz_output) -- $(location :fuzz_target_crypt) @@",
   tags = ["no-sandbox"],
   executable = True,  
)
