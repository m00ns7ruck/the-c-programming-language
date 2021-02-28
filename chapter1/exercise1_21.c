#include <stdio.h>

#define TAB '*'
#define MAX_LINE_SIZE 1000

int TAB_SIZE = 8;

int getlineEntab(char line[], int lineMaxSize);

int main() {

    char inputLine[MAX_LINE_SIZE];
    int  lineSize;

    while((lineSize = getlineEntab(inputLine, MAX_LINE_SIZE)) > 0 ) {
        printf("%s", inputLine);
    }

    return 0;
}

int getlineEntab(char line[], int lineMaxSize) {
    int i, c;

    int seqSpaces = 0;
    for(i = 0; (i < MAX_LINE_SIZE) && ((c = getchar()) != EOF) && c!= '\n'; ++i) {
        line[i] = c;

        if(c == ' ') {
            ++seqSpaces;
            if(seqSpaces == TAB_SIZE) {
                i = i - (TAB_SIZE - 1);
                line[i] = TAB;
                seqSpaces = 0;
            }
        }
        else {
            seqSpaces = 0;
        }
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
