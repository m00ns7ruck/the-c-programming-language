#include <stdio.h>

#define TRUE 1
#define FALSE 0

void uintAsBits(unsigned x) {
    unsigned maskShiftPosition = 1;
    unsigned mask = ~(~0 << maskShiftPosition);

    for(int shiftSize = sizeof(unsigned) * 8 - 1; shiftSize >= 0; --shiftSize) {
        printf("%u", (x >> shiftSize) & mask);
    }

    printf("\n");
}

unsigned rightRotate(unsigned x, int n, int printStepByStep) {
    unsigned uintBits = sizeof(unsigned) * 8;
    int mask = ~(~0 << n);
    unsigned right = mask & x;
    unsigned rightShift = right << (uintBits - n);
    unsigned result = (x >> n) | rightShift;

    if(printStepByStep != 0) {
        printf("Mask:           ");
        uintAsBits(mask);
        printf("Number:         ");
        uintAsBits(x);
        printf("Right:          ");
        uintAsBits(right);
        printf("Right shift:    ");
        uintAsBits(rightShift);
        printf("Shifted Number: ");
        uintAsBits(x >> n);
        printf("Result:         ");
        uintAsBits(result);
    }

    return result;
}

int main() {
    int number = 0x86421357;
    int rotationSize = 5;
    int rightRotation = rightRotate(number, rotationSize, FALSE);

    printf("Before rotation: ");
    uintAsBits(number);
    printf("After rotation:  ");
    uintAsBits(rightRotation);

    return 0;
}
