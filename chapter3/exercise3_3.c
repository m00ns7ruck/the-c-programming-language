#include <stdio.h>
#define MAX_LINE_LENGTH 1000

int MyGetline(char line[], int maxLength);
int IsAlphaNumeric(int c);
void expand(char s1[], char s2[]);

int main() {
    char line[MAX_LINE_LENGTH];
    int length;

    while((length = MyGetline(line, MAX_LINE_LENGTH)) > 0) {
        char expanded[MAX_LINE_LENGTH];
        expand(line, expanded);
        printf("Original: %s", line);
        printf("Expanded: %s", expanded);
    }

    return 0;
}

void expand(char s1[], char s2[]) {
    int k = 0;
    for(int i = 0; (s1[i] != '\0') && (k < MAX_LINE_LENGTH - 1); ++i) {
        if(s1[i] == '-') {
            if(s1[i - 1] >= s1[i + 1]) {
                s2[k++] = s1[i];
                continue;
            }

            if(((i - 1) >= 0) && (s1[i + 1] != '\0')) {
                int start = s1[i - 1];
                int end = s1[i + 1];
                int nonModifiedK = k;
                --k;

                for(int j = start; j <= end; ++j) {
                    if(! IsAlphaNumeric(j)) {
                        k = nonModifiedK;
                        s2[k++] = s1[i];
                        --i;
                        break;
                    }
                    s2[k++] = j;
                }

                ++i;
            }
            else {
                s2[k++] = s1[i];
            }
        }
        else {
            s2[k++] = s1[i];
        }
    }

    s2[k] = '\0';

    if(k >= MAX_LINE_LENGTH) {
        printf("\n\nWARNING: Expansion too long. Truncated at %d\n\n", MAX_LINE_LENGTH);
    }
}

int MyGetline(char line[], int maxLength) {
    int i, c;

    for(i = 0; (i < maxLength - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

int IsAlphaNumeric(int c) {
    int result = ((c >= 48 && c <= 57)
                  || (c >= 65 && c <= 90)
                  || (c >= 97 && c <= 122));

    return result;
}
