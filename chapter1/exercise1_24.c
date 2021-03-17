#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXLENGTH 1000

/*
  Which is what
  Braces - {}, aka. curly braces
  Brackets - [], aka. square brackets
  Parenthesis - ()
 */

int GetLine(char line[], int maxLenght);
int RemoveComments(char line[], int len, char output[]);

int MULTILINE_COMMENT;
int IN_DOUBLE_QUOTES;

int main() {
    MULTILINE_COMMENT = FALSE;
    IN_DOUBLE_QUOTES = FALSE;

    int braces = 0;
    int brackets = 0;
    int parenthesis = 0;

    char inputLine[MAXLENGTH];
    int length;
    int row = 0;
    while((length = GetLine(inputLine, MAXLENGTH)) > 0) {
        if(length <= 1) { continue; }

        char noCommentLine[length];
        int noCommentLineLength = RemoveComments(
            inputLine,
            length,
            noCommentLine
        );

        if(noCommentLineLength <= 1) { continue; }

        for(int i = 0;  i < noCommentLineLength; ++i) {
            // Handle quotes
            if(noCommentLine[i] == '"') {
                IN_DOUBLE_QUOTES = ! IN_DOUBLE_QUOTES;
            }

            if(IN_DOUBLE_QUOTES && noCommentLine[i + 1] == '\n') {
                if(noCommentLine[i] == '\\') {
                    continue;
                }
                else {
                    printf("%*s^\n", i, "");
                    printf("\nError:%d:%d: Expected closing '\"'\n", (row + 1), i);
                    break;
                }
            }
            if(IN_DOUBLE_QUOTES) { continue; }

            // Handle apostrophes
            if(noCommentLine[i] == '\'') {
                if(noCommentLine[i + 1] == '\'' || ((i + 1) >= MAXLENGTH)) {
                    printf("%*s^\n", i + 1, "");
                    printf(
                        "\nError:%d:%d: Empty character sequence!\n\n",
                        (row + 1),
                        i + 2
                    );
                    break;
                }

                if(noCommentLine[i + 1] == '\\' || ((i + 3) >= MAXLENGTH)) {
                    if(noCommentLine[i + 3] != '\'') {
                        printf("%*s^\n", i + 3, "");
                        printf(
                            "\nError:%d:%d: Expected '\''!\n\n",
                            (row + 1),
                            i + 4
                        );
                        break;
                    }

                    i += 3;
                    continue;
                }
                else if(noCommentLine[i + 2] != '\'' || ((i + 2) >= MAXLENGTH)) {
                    printf("%*s^\n", i + 2, "");
                    printf(
                        "\nError:%d:%d: Expected '\''!\n\n",
                        (row + 1),
                        i + 3
                    );
                    break;
                }

                i += 2;
                continue;
            }

            // Handle all kind of braces
            if(noCommentLine[i] == '(') { ++parenthesis; }
            else if(noCommentLine[i] == ')') { --parenthesis; }
            else if(noCommentLine[i] == '{') { ++braces; }
            else if(noCommentLine[i] == '}') { --braces; }
            else if(noCommentLine[i] == '[') { ++brackets; }
            else if(noCommentLine[i] == ']') { --brackets; }
        }

        ++row;
    }

    if(parenthesis) { printf("\nError: Missing parenthesis!\n"); }
    if(braces)      { printf("\nError: Missing braces!\n"); }
    if(brackets)    { printf("\nError: Missing brackets!\n"); }

    return 0;
}

int GetLine(char line[], int maxLenght) {
    int c, i;

    for(i = 0; (i < maxLenght) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

int RemoveComments(char line[], int len, char outputLine[]) {
    int i, j;
    for(i = 0, j = 0; i < len; ++i) {
        if(line[i] == '*' && line[i + 1] == '/') {
            MULTILINE_COMMENT = FALSE;
            if(j > 1) {
                j -= 2;
            }

            i += 2;
        }

        if(! MULTILINE_COMMENT) {
            if(line[i] == '/') {
                if(line[i + 1] == '/') {
                    outputLine[j] = '\n';
                    outputLine[j + 1] = '\0';
                    break;
                }
                else if (line[i + 1] == '*') {
                    outputLine[j++] = '\n';
                    outputLine[j++] = '\0';
                MULTILINE_COMMENT = TRUE;
            }
        }

            outputLine[j++] = line[i];
        }
    }

    return j;
}
