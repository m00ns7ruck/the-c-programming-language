#include <stdio.h>
#define MAX_LINE_LENGTH 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int myGetLine(char line[], int length);

int main() {
    int length;
    char line[MAX_LINE_LENGTH];

    while((length = myGetLine(line, MAX_LINE_LENGTH)) > 0) {
        char escaped[MAX_LINE_LENGTH];
        char unescaped[MAX_LINE_LENGTH];

        escape(escaped, line);
        unescape(unescaped, escaped);

        printf("Original:\n%s\n", line);
        printf("Escaped:\n%s\n", escaped);
        printf("Unescaped:\n%s\n", unescaped);
    }

    return 0;
}

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;

    while(t[i] != '\0') {
        switch (t[i]) {
            case '\t': {
                s[j++] = '\\';
                s[j++] = 't';
            } break;
            case '\n': {
                s[j++] = '\\';
                s[j++] = 'n';
            } break;
            case ' ': {
                s[j++] = '\\';
                s[j++] = 's';
            } break;
            default: {
                s[j++] = t[i];
            } break;
        }

        ++i;
    }

    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i = 0;
    int j = 0;

    while(t[i] != '\0') {
        switch (t[i]) {
            case '\\': {
                switch (t[i+1]) {
                    case 't': {
                        s[j++] = '\t';
                        ++i;
                    } break;
                    case 'n': {
                        s[j++] = '\n';
                        ++i;
                    } break;
                    case 's': {
                        s[j++] = ' ';
                        ++i;
                    } break;
                    default: {
                        s[j++] = '\\';
                    } break;
                }
            } break;
            default: {
                s[j++] = t[i];
            } break;
        }

        ++i;
    }

    s[j] = '\0';
}

int myGetLine(char line[], int length) {
    int i, c;

    for(i = 0; (i < length - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        line[i] = c;
    }

    if(c == '\n') { line[i++] = c; }
    line[i] = '\0';

    return i;
}
