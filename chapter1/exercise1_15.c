#include <stdio.h>

int fahr2celsius(int fahr) {
    int result = 5 * (fahr-32) / 9;
    return result;
}

void printTable(int lower, int upper, int step) {
    int fahr = lower;

    while(fahr <= upper) {
        int celsius = fahr2celsius(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr += step;
    }
}

int main() {
    int lower = 0;
    int upper = 300;
    int step = 20;

    printTable(lower, upper, step);

    return 0;
}
