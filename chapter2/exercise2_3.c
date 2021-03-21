#include <stdio.h>

long int htoi(const char* string);
int alphatoi(const char alpha);
int isHex(const char symb);
int isNumeric(const char symb);

int main () {
    char* tests[] = {
        "test",    "0xTest",   "A1B2",     "a1b2",
        "0XABCD",  "1234A",    "beep",     "DEAD",
        "0x13bfa", "12asdf",   "012345f",  "0123",
        "xra_g",   "F00",      "bar",      "0100",
        "0x1",     "0XA",      "0X0C0BE",  "abcdef",
        "123456",  "0x123456", "deadbeef", "zog_c"
    };
    int numberOfTests = sizeof(tests) / sizeof(tests[0]);
    int currentTest = 0;

    while(currentTest < numberOfTests) {
        long int converted = htoi(tests[currentTest]);
        printf("Hex: %-10s Dec: %-5ld\n", tests[currentTest], converted);
        ++currentTest;
    }

    return 0;
}

int isHex(const char symb) {
    int result = 0;

    result = (symb >= '0' && symb <= '9')
        || (symb >= 'a' && symb <= 'f')
        || (symb >= 'A' && symb <= 'F');

    return result;
}

int isNumeric(const char symb) {
    int result = 0;

    int symbInt = symb - '0';

    result = (symbInt >= 0 && symbInt <= 9);

    return result;
}

int alphatoi(const char alpha) {
    int result = 0;
    const int MAX_HEX_INT = 15;

    result = MAX_HEX_INT - ('f' - tolower(alpha));
    result *= (result >= 10 && result <= 15);

    return result;
}

long int htoi(const char* string) {
    long int result = 0;

    int i = 0;
    i += (string[i] == '0')
        + ((string[i+1] == 'x') || (string[i+1] == 'X'));

    while(string[i] != '\0') {
        if(! isHex(string[i])) {
            result = -1;
            break;
        }

        if(isNumeric(string[i])) {
            result += string[i] - '0';
        }
        else {
            result += alphatoi(string[i]);
        }

        if(string[i + 1] != '\0') result *= 16;
        ++i;
    }

    return result;
}
