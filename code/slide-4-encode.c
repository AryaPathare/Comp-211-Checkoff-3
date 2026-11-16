#include <stdio.h>

void print_rle(const char *input) {
    if (input[0] == '\0') return;
    char current = input[0];
    int count = 1;
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == current) {
            count++;
        } else {
            printf("%c%d", current, count);
            current = input[i];
            count = 1;
        }
    }
    printf("%c%d", current, count);
}

int main(void) {
    print_rle("AABBC");   /* prints A2B2C1 */
    putchar('\n');
    return 0;
}
