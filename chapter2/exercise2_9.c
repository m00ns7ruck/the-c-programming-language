#include <stdio.h>

/*
  Example 1:
    Taking the hexadecimal number 0x12345678.
    In binary - 00010010001101000101011001111000

    Subtracting 1 from 0x12345678 results in:
                00010010001101000101011001110111

    When we AND 0x12345678 and (0x12345678 - 1):
    00010010001101000101011001111000
    &
    00010010001101000101011001110111
    --------------------------------
    00010010001101000101011001110000

    In other words ANDing a number with the same number - 1
    clears the rightmost 1 bit and sets everything else to 0.

  Example 2:
    Taking the hexadecimal number 0x12345679.
    In binary - 00010010001101000101011001111001

    0x12345679 - 1 is in binary:
                00010010001101000101011001111000

    ANDing the two numbers:
    00010010001101000101011001111001
    &
    00010010001101000101011001111000
    --------------------------------
    00010010001101000101011001111000

    The result is the same as in Example 1 - the rightmost bit 1
    is set to 0


  As conclusion we can say that we can repeat the operation
  x &=(x-1) as long as there are 1 bits in the result. Because of
  that we can omit the if check, therefor making a faster bitcout().
 */
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01) b++;

    return b;
}

int bitcountFaster(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x -1)) b++;

    return b;
}

void uintAsBits(unsigned x) {
    unsigned uintSize = sizeof(unsigned) * 8;
    int mask = 1;

    for(int i = uintSize-1; i >= 0; --i) {
        printf("%u", (x >> i) & mask);
    }

    printf("\n");
}

int main() {
    unsigned number = 0x12345678;
    printf("Counting the 1 bits in: ");
    uintAsBits(number);
    printf(
        "The count of the 1 bits, using the old bitcount() is %d.\n",
        bitcount(number)
    );
    printf(
        "The count of the 1 bits, using the new bitcount() is %d.\n",
        bitcountFaster(number)
    );

    return 0;
}
