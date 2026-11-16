# Run-Length Encoding in C

An exploration of **run-length encoding (RLE)**, one of the simplest ways to compress data, built for COMP 211 using AI as a learning tool.

## What is run-length encoding?

RLE replaces a run of repeated characters with the character and a count:

```
AAAABBBCC  ->  A4B3C2
```

A **run** is a stretch of the same character in a row. It ends when the character changes or the string ends. Decoding just repeats each character by its count, so you always get the exact original back. That makes RLE **lossless** compression.

## What I explored

1. **Finding runs by hand**: reading left to right and splitting the string every time the character changes.
2. **Writing the encoder in C**: a single loop with two variables, `current` and `count`.
3. **Tracing the loop**: working out exactly when each run gets printed.
4. **Writing the decoder**: expanding pairs back into text, including multi-digit counts like `A10`.
5. **Measuring when RLE actually saves space**: comparing inputs with long runs against inputs that change every character.

## Most interesting discoveries

### 1. A run is printed only when the *next* character proves it's over

The encoder can't print a run when it starts, only when a different character shows up. Tracing `AABBC`:

| i | Reads | What happens | Printed so far |
|---|---|---|---|
| 1 | `A` | Same as current → count = 2 | |
| 2 | `B` | Different → print `A2`, start B at 1 | `A2` |
| 3 | `B` | Same → count = 2 | `A2` |
| 4 | `C` | Different → print `B2`, start C at 1 | `A2B2` |
| 5 | `\0` | Loop ends → final printf prints `C1` | `A2B2C1` |

The last run never meets a different character, only the end of the string. Without the extra `printf` after the loop, the output would be `A2B2` and the `C` would be lost.

### 2. Runs never merge

`AAABAA` becomes `A3B1A2`, not `A5B1`. Combining the A's would decode to `AAAAAB` and lose the original order.

### 3. RLE can make data bigger

Same letters, completely different results:

| Input | Runs | Encoded | Size |
|---|---|---|---|
| `AAAABBBB` | 2 | `A4B4` | 8 → 4 |
| `AABBCC` | 3 | `A2B2C2` | 6 → 6 |
| `ABABABAB` | 8 | `A1B1A1B1A1B1A1B1` | 8 → 16 |

Each pair costs one letter plus one digit. A run of 3 or more saves space, a run of 2 breaks even, and a run of 1 doubles in size. What matters isn't which characters you have, but how often the character changes.

## Repository layout

```
run-length-encoding-in-c/
├── README.md          <- you are here
├── resources.md       <- references and the AI conversation
├── code/
│   ├── rle_encode.c   <- encoder with test strings
│   ├── rle_decode.c   <- decoder (handles multi-digit counts)
│   ├── rle_size.c     <- experiment: when does RLE save space?
│   └── Makefile
└── slides/
    └── rle-presentation.pdf
```

## Running the code

You need `gcc` and `make` (both available on the COMP 211 container or any Linux/macOS machine).

```bash
cd code
make run      # builds all three programs and runs them
make clean    # removes the compiled programs
```

To build and run one program on its own:

```bash
gcc -Wall -Wextra -std=c11 -o rle_encode rle_encode.c
./rle_encode
```

Expected output from `make run`:

```
./rle_encode
"AABBC" -> "A2B2C1"
"AAAABBBCC" -> "A4B3C2"
"AAABAA" -> "A3B1A2"
"WWWWWWBBBW" -> "W6B3W1"
"AAAAAAAAAAAA" -> "A12"
"A" -> "A1"
"" -> ""

./rle_decode
"C2D3" -> "CCDDD"
"X3Y1Z2" -> "XXXYZZ"
"A2B2C1" -> "AABBC"
"A10B1" -> "AAAAAAAAAAB"

./rle_size
input                   runs  original  encoded  result
AAAABBBB                   2         8        4  smaller
AABBCC                     3         6        6  same
ABABABAB                   8         8       16  BIGGER
AAAAAAAAAAAAAAAAAAAA       1        20        3  smaller
```

## Questions I still have

- **Digits in the data:** how would you encode a string like `111` without confusing counts with data?
- **Really long runs:** what happens if a run is longer than a one-byte count can hold (255)?
- **Real file formats:** how do they avoid the `ABABAB` blow-up?

## Presentation

The slides from my 5–7 minute class presentation are in [`slides/`](slides/).
