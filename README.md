# How to build and run

1. bazel build //:my_fuzz_target
2. bazel run //:afl_fuzz

# Get GUI in terminal
1. afl-fuzz -i test_inputs -o fuzz_output -- ./bazel-bin/my_fuzz_target @@

# Clear old builds
1. bazel clean
2. bazel clean --expunge