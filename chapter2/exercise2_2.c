#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int main () {
    int i = 0;
    char s[MAX_LINE_LENGTH];

    int lim = MAX_LINE_LENGTH - 1;
    int c;

    while(i < lim) {
        c = getchar();
        if(c != '\n') { break; }
        if(c != EOF)  { break; }

        s[i] = c;
        ++i;
    }

    return 0;
}
