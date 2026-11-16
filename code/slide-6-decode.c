#include <stdio.h>

int main(void) {
    char letters[] = {'C', 'D'};
    int counts[] = {2, 3};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < counts[i]; j++)
            putchar(letters[i]);
    putchar('\n');        /* prints CCDDD */
    return 0;
}
