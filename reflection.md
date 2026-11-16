****_REFLECTION_****

**How I approached the topic:**

I picked run-length encoding from the Data Compression topics because it seemed 
simple enough to fully understand and to write in C with things we already know 
from COMP 211: loops, chars and printf. My first questions were basic: what counts 
as a “run,” how the encoder knows when a run ends, and how you get the original data 
back. From there it turned into a more interesting question: does RLE always make data 
smaller?

**Prompts I used:**

1. “I got AAA B AA. Did I split it correctly?” 
Instead of only asking for answers, I tried an example myself first and asked the AI to check my work. 
This confirmed that an A appearing after a B starts a new run, so AAABAA becomes A3B1A2, not A5B1.

2. “Wait, they both have four A’s and four B’s. Why does one take up more space?” 
This was the most confusing part for me. AAAABBBB shrinks to A4B4, but ABABABAB doubles to A1B1A1B1A1B1A1B1. 
I learned that what matters is how often the character changes, not which characters appear.

3. “In C, I’d count until the character changes, then save the pair. Does that handle the last character?” 
I described my own approach and asked the AI to find the hole in it. It doesn’t handle the last character. 
The last run never sees a new character, so the code needs one more print after the loop. Tracing AABBC 
afterwards showed exactly when each pair gets saved.

**How I engaged with the AI:**

I tried examples myself and asked the AI to check them, asked “wait, why?” when results seemed odd, and 
asked for a trace instead of just the final code. I also asked for edge cases to run. When my alternating 
example got bigger but still said PASS, I asked what was actually passing, and learned that correct 
output and saving space are two separate things. Before presenting, I asked what follow-up questions 
classmates might ask so I could prepare.

**What I’d do differently:**

Checking my own attempts with the AI worked best. Some ideas didn’t stick the first time: I asked 
about the size difference and the AABBC trace twice. Next time I’d explain a concept back in my 
own words right away, to find gaps sooner. I’d also follow up on the questions I still have, 
like how RLE handles data that contains digits. One more thing is that I would start this assignment
a bit earlier than I did because I rushed a little and could have done a better job if I had even 
started one day earlier.
