cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cpp"],
   copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"], 
   linkopts = ["-fsanitize=fuzzer"],
   
)

genrule(
   name = "afl_fuzz",
   srcs = [":my_fuzz_target", "test_inputs"],
   outs = ["fuzz_output.zip"],  # Changed to a zip file for handling multiple outputs
   cmd = """
   mkdir -p $(RULEDIR)/fuzz_output_dir && \
   AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 \
   afl-fuzz -V 10 -i $(location test_inputs) -o $(RULEDIR)/fuzz_output_dir -- $(location :my_fuzz_target) @@ && \
   zip -r $(location fuzz_output.zip) $(RULEDIR)/fuzz_output_dir
   """,
   tags = ["no-sandbox"],
   executable = True,
)


