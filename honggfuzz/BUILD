cc_binary(
    name = "honggfuzz_target",
    srcs = ["fuzz_target.c"],  # Kontrollera att filnamnet är korrekt
    copts = ["-fsanitize=address", "-fno-omit-frame-pointer"],
    linkopts = ["-fsanitize=address", "-fsanitize=fuzzer"],
)

genrule(
    name = "honggfuzz_fuzz",
    srcs = ["input_corpus", ":honggfuzz_target"],
    outs = ["output_dir"],
    cmd = "honggfuzz -i $(location input_corpus) -W $(location output_dir) -- $(location :honggfuzz_target) ___FILE___",
    executable = True,  
)
