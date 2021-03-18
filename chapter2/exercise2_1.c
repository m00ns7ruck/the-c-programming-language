#include <stdio.h>
#include <limits.h>

#define UCHAR_MIN 0
#define USHRT_MIN 0
#define UINT_MIN 0
#define ULONG_MIN 0l
#define ULLONG_MIN 0ll

int main() {

    printf("Char bits: %d\n\n\n", CHAR_BIT);

    printf("Signed char range:    %-20d   %-20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range:  %-20u   %-20u\n", UCHAR_MIN, UCHAR_MAX);

    printf("Signed short range:   %-20d   %-20d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short range: %-20u   %-20u\n", USHRT_MIN, USHRT_MAX);

    printf("Signed int range:     %-20d   %-20d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range:   %-20u   %-20u\n", UINT_MIN, UINT_MAX);

    printf("Signed long range:    %-20ld   %-20ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long range:  %-20lu   %-20lu\n", ULONG_MIN, ULONG_MAX);

    printf("Signed long range:    %-20lld   %-20lld\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned long range:  %-20llu   %-20llu\n", ULLONG_MIN, ULLONG_MAX);

    return 0;
}
