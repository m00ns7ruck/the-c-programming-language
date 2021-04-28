#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int Getline(char line[], unsigned length) {
    int c = 0;

    int i;
    for(i = 0; i < length && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        line[i] = c;
    }

    if(c == '\n') line[i++] = c;

    line[i] = '\0';

    return i;
}

int Lower(int c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }
void ToLowerPrint(char line[], int length) {
    for(int i = 0; line[i] != '\0'; ++i) {
        printf("%c", Lower(line[i]));
    }
}

int main() {
    char line[MAX_LINE_LENGTH];

    int len;
    while((len = Getline(line, MAX_LINE_LENGTH)) > 0) {
        ToLowerPrint(line, len);
    }

    return 0;
}
