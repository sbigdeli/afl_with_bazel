def read_binary_file(filepath):
    try:
        with open(filepath, 'rb') as f:
            data = f.read()
            for byte in data:
                print(hex(byte), end=' ')  # Skriv ut varje byte i hexadecimalt format
            print()
    except FileNotFoundError:
        print(f"Filen {filepath} hittades inte.")
    except Exception as e:
        print(f"Ett fel inträffade: {e}")

# Använd funktionen för att läsa din specifika fil
read_binary_file('/home/lengdahl/Desktop/afl_with_bazel/bazel-bin/mathlib/fuzz_output_math/default/crashes/id:000000,sig:08,src:000000,time:165,execs:15,op:havoc,rep:1')