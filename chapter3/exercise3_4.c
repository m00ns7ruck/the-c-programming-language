#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void _itoa(int n, char s[]);
void reverse(char s[]);
int stringLength(char s[]);

int main() {
    char string[20];

    printf("INT_MIN: %d\n", INT_MIN);
    _itoa(INT_MIN, string);
    printf("Result: %s\n", string);

    return 0;
}

int stringLength(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; ++i);

    return i;
}

void reverse(char s[]) {
    int c, i, j;

    for(i = 0, j = stringLength(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void _itoa(int n, char s[]) {
    int i;
    int sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while(n /= 10);

    if(sign < 0) s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
