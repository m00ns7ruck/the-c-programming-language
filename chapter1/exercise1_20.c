#include <stdio.h>

#define SPACE '-'
#define MAX_LINE_SIZE 1000

int TAB_SIZE = 4;

int getlineDetab(char line[], int lineMaxSize);

int main() {

    char inputLine[MAX_LINE_SIZE];
    int  lineSize;

    while((lineSize = getlineDetab(inputLine, MAX_LINE_SIZE)) > 0 ) {
        printf("%s", inputLine);
    }

    return 0;
}

int getlineDetab(char line[], int lineMaxSize) {
    int i, c;

    for(i = 0; (i < MAX_LINE_SIZE) && ((c = getchar()) != EOF) && c!= '\n'; ++i) {
        if(c == '\t') {
            for(int j = 0; j < TAB_SIZE; ++j) {
                line[i] = SPACE;
                ++i;
            }
            --i;
        }
        else {
            line[i] = c;
        }
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
