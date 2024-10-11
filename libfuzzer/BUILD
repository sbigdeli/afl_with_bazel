# BUILD
cc_binary(
    name = "fuzz_target",
    srcs = ["fuzz_target.cpp"],
    copts = ["-fsanitize=fuzzer,address"],  # libFuzzer och AddressSanitizer
    linkopts = ["-fsanitize=fuzzer,address"],  # länkningsinställningar för libFuzzer
)
