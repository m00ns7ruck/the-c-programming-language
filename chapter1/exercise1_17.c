#include <stdio.h>

#define MAXLINE 1000
#define TRESHHOLD 80

int myGetline(char line[], int maxLine);

int main() {
    int len;

    char line [MAXLINE];
    while ((len = myGetline(line, MAXLINE)) > 0) {
        if(len >= TRESHHOLD) {
            printf("%s\n", line);
        }
    }

    return 0;
}

int myGetline(char s[], int lim) {
    int c, i;

    for(i = 0; i < (lim -1) && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        if(s[i] == '\n') {
            s[i] == '\n';
            ++i;
        }
    }

    s[i] = '\0';
    return i;
}
