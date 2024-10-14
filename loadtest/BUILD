load("@rules_fuzzing//fuzzing:cc_defs.bzl", "cc_fuzz_test")

cc_library(
    name = "buffer_overflow_lib",
    srcs = ["buffer_overflow_lib.cc"],
    hdrs = ["buffer_overflow_lib.h"],
)

cc_fuzz_test(
    name = "fuzz_test",
    srcs = ["fuzz_test.cc"],
    deps = [":buffer_overflow_lib"],  # Länka till biblioteket
)
