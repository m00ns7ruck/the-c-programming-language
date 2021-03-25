#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i] != '\0'; ++i) {
        int j;
        for(j = 0; s2[j] != '\0'; ++j) {
            if(s1[i] != s2[j]) { continue; }

            int p;
            for(p = i; s1[p + 1] != '\0'; ++p) {
                s1[p] = s1[p + 1];
            }
            s1[p] = '\0';
            --i;

            break;
        }
    }
}

int main() {
    char line[] = "ayouei. Some words in a sentence, you know!";
    char squeezeIt[] = "ayouei";

    printf("Before: %s, ", line);
    squeeze(line, squeezeIt);
    printf("After: %s\n", line);

    return 0;
}
