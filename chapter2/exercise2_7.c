#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
    int position = p + 1 - n;

    return (x >> position) & ~(~0 << n);
}

void uintAsBits(unsigned x) {
    int i;

    for(i = sizeof(unsigned)*8-1; i>=0; i--) {
        printf("%d", getbits(x, i, 1));
        if(!(i%4))putchar(' ');
    }
    putchar('\n');
}

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = ~(~0 << n);
    int shiftNumber = p + 1 - n;
    unsigned shiftedMask = (mask << shiftNumber);
    unsigned result = x ^ shiftedMask;

    printf("\n\n  Setting bits step by step:\n");
    printf("  Mask:                              ");
    uintAsBits(mask);
    printf("  Mask,  shifted with %d positions:   ", shiftNumber);
    uintAsBits(shiftedMask);
    printf("  X:                                 ");
    uintAsBits(x);
    printf("  Final result:                      ");
    uintAsBits(result);
    printf("\n\n");

    return result;
}

int main() {
    int offset = 13;
    int length = 5;
    unsigned x = 0x87654321;

    printf("offset: %u  length: %u\n", offset, length);
    uintAsBits(x);

    unsigned invertedBits = invert(x, offset, length);
    uintAsBits(invertedBits);

    printf("%08x %08x\n", x, invertedBits);

    return 0;
}
