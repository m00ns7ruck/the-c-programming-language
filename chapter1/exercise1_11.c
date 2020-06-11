#include <stdio.h>

#define IN  1
#define OUT 0

/*
  1. Empty file(created with touch, not modified)     - 0 lines,      0 characters,      0 words
  2. cat /dev/null | <Program executable>             - 0 lines,      0 characters,      0 words
  3. Long 69999 characters word                       - 1 lines,      70000 characters,  2 words
  4. 70000 newlines                                   - 70000 lines,  70000 characters,  0 words
  5. cat <Program executable> | <Program executable>  - 4 lines,      16664 characters,  56 words
  6. cat /usr/share/dict/words | <Program executable> - 102401 lines, 972398 characters, 102402 words
 */

int main () {
    int input, lines, words, allCharacters;
    int state = OUT;

    lines = words = allCharacters = 0;
    while((input = getchar()) != EOF) {
	++allCharacters;
	if(input == '\n') {
	    ++lines;
	    state = OUT;
	}
	if(input == '\t' || input == ' ') {
	    state = OUT;
	}
	else if(state == OUT) {
	    state = IN;
	    ++words;
	}
    }
    printf("%d lines, %d characters, %d words\n", lines, allCharacters, words);

    return 0;
}
