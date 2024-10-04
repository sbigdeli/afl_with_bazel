# How to run

1. bazel build //:my_fuzz_target
2. bazel build //:afl_fuzz
    - You will get fuzz_logs.logs and fuzz_output.tar bazel-bin
    - (optional) cd to bazel-bin 
    - run tar -xzf fuzz_output.tar -C desired/file/path
    - There you will find crashes, hangs, fuzzer stats etc.. 

# Explanation of build file   

cc_binary(
   name = "my_fuzz_target",
   srcs = ["fuzz_target.cpp"],
   copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"], 
   linkopts = ["-fsanitize=fuzzer"],
)

- cc_binary: Skapar ett körbart program i C++.
- name = "my_fuzz_target": Namnet på den körbara filen som Bazel bygger.
- srcs = ["fuzz_target.cpp"]: Källkoden som ska kompileras.
- copts = ["-fsanitize=fuzzer", "-g", "-O1", "-fno-omit-frame-pointer"]: Kompileringsflaggor för att aktivera fuzzing-sanitizern, debug-information, 
optimering för fuzzing och korrekt ramhantering.
- linkopts = ["-fsanitize=fuzzer"]: Länkningsflaggor som inkluderar fuzzing-sanitizern, vilket gör att programmet kan användas för fuzz-testing.
----------------------------------------------------------------------------------------------------------------------------------------------------------

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

- genrule: Skapar ett anpassat kommando som körs av Bazel.
- name = "afl_fuzz": Namn på målet.
- srcs = [":my_fuzz_target", "test_inputs"]: Inkluderar beroenden som my_fuzz_target (fuzzing-binären) och testdata (test_inputs).
- outs = ["fuzz_logs.logs", "fuzz_output.tar"]: Utdatafiler som Bazel spårar: loggfilen fuzz_logs.logs och arkivet fuzz_output.tar (som innehåller fuzz-resultaten).
- cmd = """...""": Kommandot som körs:

    Skapar katalogen fuzz_output.
    Kör AFL++-fuzzing på my_fuzz_target med testdata från test_inputs.
    Sparar fuzzing-loggarna i fuzz_logs.logs och skapar en tar-fil (fuzz_output.tar) som innehåller alla fuzzing-resultat.
