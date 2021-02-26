#include <stdio.h>

#define MAXLINE 1000

int myGetline(char line[], int lim);
void reverse(char line[], int len);

int main() {
    char inputLine[MAXLINE];

    int len;
    while((len = myGetline(inputLine, MAXLINE)) > 0) {
        if(len > 1) {
            reverse(inputLine, len);
            printf("%s\n", inputLine);
        }
    }

    return 0;
}

int myGetline(char line[], int lim) {
    int i, c;
    for(i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void reverse(char line[], int len) {
    for(int i = 0; i < len / 2; ++i) {
        char tmp = line[i];
        line[i] = line[len - 1 - i];
        line[len - 1 - i] = tmp;
    }
}
