#!/bin/bash

# Bygg fuzzing-target
echo "Bygger fuzzing-target..."
bazel build //:my_fuzz_target

# Kör fuzzing-sessionen
echo "Kör fuzzing-session..."
bazel run //:afl_fuzz

# Skapa mappen afl-plot om den inte redan finns
mkdir -p afl-plot

# Generera plottar och spara dem i afl-plot-mappen
echo "Genererar AFL-plottar..."
afl-plot bazel-bin/fuzz_output/default afl-plot

echo "Processen är klar!"
