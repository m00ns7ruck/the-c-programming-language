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

unsigned setbits(unsigned x, int p, int n,unsigned y) {
    unsigned mask = ~(~0 << n);
    int position = p + 1 - n;
    unsigned shiftedMask = (mask << position);
    unsigned result = (x & ~(shiftedMask)) | ((y & mask) << position);

    printf("\n\n  Setting bits step by step:\n");
    printf("  Mask:                              ");
    uintAsBits(mask);
    printf("  ~Mask:                             ");
    uintAsBits(~mask);
    printf("  Mask,  shifted with %d positions:   ", position);
    uintAsBits(shiftedMask);
    printf("  ~(Mask, shifted with %d positions): ", position);
    uintAsBits(~(shiftedMask));
    printf("  X:                                 ");
    uintAsBits(x);
    printf("  X & shifted ~mask:                 ");
    uintAsBits(x & ~(shiftedMask));
    printf("  Y:                                 ");
    uintAsBits(y);
    printf("  Y & mask:                          ");
    uintAsBits(y & mask);
    printf("  Result of (Y & mask), but shifted: ");
    uintAsBits((y & mask) << position);
    printf("  Final result:                      ");
    uintAsBits(result);
    printf("\n\n");

    return (x >> p) | (y >> n);
}

int main () {
    int offset = 9;
    int length = 7;
    unsigned x = 0x87654321;
    unsigned y = 0Xabcdeffa;

    printf("offset: %u  length: %u\n", offset, length);
    uintAsBits(x);
    uintAsBits(y);

    unsigned setBits = setbits(x, offset, length, y);
    uintAsBits(setBits);

    printf("%08x %08x %08x\n", x, y, setBits);

    return 0;
}
