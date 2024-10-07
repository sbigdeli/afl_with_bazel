#!/bin/bash

# Bygg fuzzing-target
echo "Bygger fuzzing-target..."
bazel build //:fuzz_target_crypt

# Kör fuzzing-sessionen
echo "Kör fuzzing-session..."
bazel run //:afl_fuzz_crypt

# Skapa mappen afl-plot om den inte redan finns
mkdir -p afl-plot-crypt

# Generera plottar och spara dem i afl-plot-mappen
echo "Genererar AFL-plottar..."
afl-plot bazel-bin/fuzz_output/default afl-plot-crypt

echo "Processen är klar!"
