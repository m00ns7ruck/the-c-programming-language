#include "stdio.h"

#define CELSIUS_UPPER_LIMIT 100

int main() {
    float celsius = 0;

    printf("+---------------+\n|  TEMPERATURE  |\n+---------------+\n");
    while(celsius++ < CELSIUS_UPPER_LIMIT)
	printf("| %6.2lf | %3.2f |\n", celsius, ((9.0 * celsius) / 5.0) + 32.0);

    return 0;
}
