#include <stdio.h>

char* any(char s1[], char s2[]) {
    for(int i = 0; s1[i] != '\0'; ++i) {
        for(int j = 0; s2[j] != '\0'; ++j) {
            if(s1[i] == s2[j]) {
                return &s1[i];
            }
        }
    }

    return 0;
}

int anyPos(char s1[], char s2[]) {
    int result = 0;

    for(int i = 0; s1[i] != '\0'; ++i) {
        for(int j = 0; s2[j] != '\0'; ++j) {
            if(s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return result;
}

int main() {
    char line[] = "Some words in a sentence, you know!";
    char containsAny[] = "ayouei";

    printf("Searching for any of [%s] in '%s'.\n", containsAny, line);
    printf(
        "First symbol in [%s], found in '%s', is '%c'.\n",
        containsAny,
        line,
        *any(line, containsAny)
    );

    printf(
        "First symbol in [%s], found in '%s', is at position %d.\n",
        containsAny,
        line,
        anyPos(line, containsAny)
    );
}
