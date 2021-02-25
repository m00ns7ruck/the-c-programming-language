#include <stdio.h>

#define MAXLINE 1000

int getline_trunc(char line[], int maxLength);

int main() {
    char aLine[MAXLINE];

    int row = 0;
    int len;
    while((len = getline_trunc(aLine, MAXLINE)) > 0) {
        if(len > 1) {
            printf("%d: %s", row, aLine);
            ++row;
        }
    }

    return 0;
}

int getline_trunc(char line[], int maxLength) {
    int i, c;

    for(i = 0; (i < (maxLength - 1) && (c = getchar()) != EOF) && (c != '\n'); ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    int j;
    for(j = i - 1;
        ((line[j] == ' ') || (line[j] == '\t') || (line[j] == '\n')); --j
    );

    line[++j] = '\n';
    line[++j] = '\0';
    return j;
}
