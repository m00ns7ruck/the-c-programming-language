#include <stdio.h>
#define SPACE ' '

int main() {
    int c;

    int spaces = 0;
    while( (c = getchar()) != EOF ) {
	if(c == SPACE) ++spaces;
	else {
	    spaces = 0;
	}
	if(spaces > 1) continue;

	printf("%c", c);
    }

    return 0;
}
