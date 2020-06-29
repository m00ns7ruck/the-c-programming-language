#include <stdio.h>
#include <stdlib.h>

struct MyIntList {
    int length;
    int index;

    int *data;
};

typedef struct MyIntList MyIntList;

MyIntList createList() {
    struct MyIntList List = {};
    List.length = 1;

    List.data = (int *)malloc(List.length * sizeof(int));

    return List;
}

void push(MyIntList* List, int item) {
    if(List->index > List->length) {
	List->length = sizeof(List->data) * 2;
	int *tempData = (int *)realloc(List->data, List->length * sizeof(int));
	List->data = tempData;
    }

    List->data[List->index] = item;
    ++List->index;
}

void printHorizontalHistogram(MyIntList Words) {
    for(int i = 0; i < Words.length; ++i) {
        if(Words.data[i] == 0) { continue; }

        for(int j = 0; j < Words.data[i]; ++j) {
            printf("%c", '*');
        }
        printf("\n");
    }
}

int getMaxWordLength(MyIntList Words) {
    int max = Words.data[0];

    for(int i = 1; i < Words.length; ++i) {
	if(Words.data[i] == 0) { continue; }

	if(max < Words.data[i]) { max = Words.data[i]; }
    }

    return max;
}

void printVerticalHistogram(MyIntList Words) {
    int longestWord = getMaxWordLength(Words);

    for(int i = longestWord; i >= 1; --i) {
	for(int j = 0; j < Words.length; ++j) {
	    if(Words.data[j] < i) {
		printf(" ");
	    }
	    else {
		printf("*");
	    }
	}
	printf("\n");
    }
}

int main() {
    int c;
    int c_prev;

    MyIntList words = createList();

    int wordLength = 0;
    while((c = getchar()) != EOF) {
	if(
            (!((c_prev == ' ') || (c_prev == '\t') || (c_prev == '\n')))
            && (c == ' ') || (c == '\t') || (c == '\n')
	) {
	    push(&words, wordLength);
	    wordLength = 0;
	}
	else {
	    ++wordLength;
	}

	c_prev = c;
    }

    /* printHorizontalHistogram(words); */
    printVerticalHistogram(words);

    return 0;
}
