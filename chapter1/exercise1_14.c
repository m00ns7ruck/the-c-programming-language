#include <stdio.h>

#define CHARACTERS_MAX 256

int  main() {
    int c;

    int characters[CHARACTERS_MAX];
    for(int i = 0; i < CHARACTERS_MAX; ++i) {
	characters[i] = 0;
    }

    while((c = getchar()) != EOF) { ++characters[c]; }

    for(int i = 0; i < CHARACTERS_MAX; ++i) {
	while((--characters[i]) >= 0) {
	    putchar('*');
	}
	putchar('\n');
    }
   return 0;
}
