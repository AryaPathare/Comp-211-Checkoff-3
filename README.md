# Run-Length Encoding

For this project, I used AI to learn about run-length encoding (RLE), a really simple way to compress data. I picked it because it's easy to understand and I could write it in C with stuff we already know from COMP 211.

## The idea

If a letter repeats, you write the letter once and how many times it shows up:

```
AAAABBBCC  ->  A4B3C2
```

To get the original back, you just repeat each letter by its number.

## What I found interesting

- **The last group needs special care.** The code only prints a group when it sees a new letter. The last group never sees one, so you need one more `printf` after the loop or it gets lost.
- **Groups don't combine.** `AAABAA` turns into `A3B1A2`, not `A5B1`. Otherwise, you'd get the wrong string back.
- **It can make things bigger.** `AAAABBBB` shrinks to `A4B4`, but `ABABABAB` turns into `A1B1A1B1A1B1A1B1`, which is twice as long. It only helps when letters repeat a lot.

## Running the code

```bash
cd code

gcc -o rle_encode rle_encode.c
./rle_encode      # A2B2C1

gcc -o rle_decode rle_decode.c
./rle_decode      # CCDDD
```

## Slides

My presentation slides are in the `slides` folder.

## AI chat

Here's the conversation I used to learn this: https://chatgpt.com/share/6afb5120-0e48-83ea-898f-470d3567b2e7
