#include <stdio.h>

int main() {
    if((getchar() != EOF) == 1) {
	printf("getchar() != EOF is evaluated to 1.\n");
    }
    else {
	printf("getchar() != EOF is evaluated to 0.\n");
    }

    return 0;
}
