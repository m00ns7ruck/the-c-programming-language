#include <stdio.h>

int main() {
    int c;

    while((c = getchar()) != EOF) {
	if((c == ' ') || (c == '\t')) {
	    printf("\n");
	    continue;
	}

	printf("%c", c);
    }

    return 0;
}
