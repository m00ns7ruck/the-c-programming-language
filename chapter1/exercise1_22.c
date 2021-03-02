#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 1000
#define MAXCOL 10

int getline_(char line[], int lim, int maxCol);
char* fold(char line[], int length);

int main() {
    char currentLine[MAXLINE];

    int length = 0;
    while((length = getline_(currentLine, MAXLINE, MAXCOL)) > 0) {

        printf("%s", fold(currentLine, length));
    }

    return 0;
}

int getline_(char line[], int lim, int maxCol) {
    int c, i, j, lastWhitespace = -1;

    for(i = 0, j = 0; (i < lim) && ((c = getchar()) != EOF) && (c != '\n'); ++i, ++j) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

char* fold(char line[], int length) {
    char* result = malloc(length);

    int lastSeenWhitespace = -1;
    for(int i = 0, j = 0; i < length; ++i, ++j) {
        if(line[i] == ' ' || line[i] == '\t') {
            lastSeenWhitespace = i;
        }

        if(j >= MAXCOL && (line[i] == ' ' || line[i] == '\t')) {
            result[i] = '\n';
            lastSeenWhitespace = -1;
            j = 0;
            continue;
        }

        if(j >= MAXCOL && lastSeenWhitespace >= 0) {
            result[lastSeenWhitespace] = '\n';
            j = i - lastSeenWhitespace;
        }

        result[i] = line[i];
    }

    return result;
}
