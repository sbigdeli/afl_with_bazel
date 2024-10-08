export AFL_I_DONT_CARE_ABOUT_CRASHES=1
export AFL_SKIP_CPUFREQ=1
afl-fuzz -i ./corpus -o bazel-out/k8-fastbuild/bin/fuzz_output -- bazel-out/k8-fastbuild/bin/fuzz_target_crypt @@ ##Obs, glöm inte ändra namn på in- & output samt fuzztarget