#include <stdio.h>

int main() {
    int c, spaces = 0, tabs = 0, newLines = 0;

    while((c = getchar()) != EOF) {
	if(c == '\n')       ++newLines;
	else if (c == ' ')  ++spaces;
	else if (c == '\t') ++tabs;
    }

    printf("You have used %d spaces, %d tabs, %d new lines!\n", spaces, tabs, newLines);

    return 0;
}
