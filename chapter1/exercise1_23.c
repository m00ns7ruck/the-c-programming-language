#include "stdio.h"
#include "stdlib.h"

#define MAX_LENGTH 1000
#define TRUE 1
#define FALSE 0

int MULTILINE_COMMENT = 0;

int Getline(char line[], int maxLength);
char* RemoveComments(char line[], int len);

int main() {
    char inputLine[MAX_LENGTH];

    int len = 0;

    while((len = Getline(inputLine, MAX_LENGTH)) > 0) {
        char* noCommentsLine = RemoveComments(inputLine, len);
        printf("%s", noCommentsLine);
    }

    return 0;
}

int Getline(char line[], int maxLength) {
    int i, c, prev;

    for(i = 0; (i < maxLength) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

char* RemoveComments(char line[], int len) {
    char* result = malloc(len);

    for(int i = 0, j = 0; i < len; ++i) {
        if(line[i] == '*' && line[i + 1] == '/') {
            MULTILINE_COMMENT = FALSE;
            if(j > 1) {
                j -= 2;
            }

            i += 2;
        }

        if(! MULTILINE_COMMENT) {
            if(line[i] == '/') {
                if(line[i + 1] == '/') {
                    result[j] = '\n';
                    result[j + 1] = '\0';
                    break;
                }
                else if (line[i + 1] == '*') {
                    result[j++] = '\n';
                    result[j++] = '\0';
                MULTILINE_COMMENT = TRUE;
            }
        }

            result[j++] = line[i];
        }
    }

    return result;
}
