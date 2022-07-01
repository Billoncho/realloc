/*
Author:     Billy Gene Ridgeway
Purpose:    Learn about using calloc in C. Realloc allows you to change the size of a block of memory.
Date:       July 1st. 2022 
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Look at free() and realloc().
int main() {
	char *s;
	int i;

	i = sizeof("Hello");						// Assign 'i' the size of the string "Hello".
	s = (char*)malloc(i);						// Allocates 6 bytes of memory to the pointer 's'. Malloc will return 0 if it fails, so we should check here, but we wont for brevity.
	strncpy(s, "Hello", i);						// Now copy the string into the newly allocated memory.
	printf("\ns is %s\n\n", s);

	// Now suppose we want to add 'world!' to 'Hello' - we can't just do this ...
	// strcat(s, " world!");					- disaster!!! 
	s = (char*)realloc(s, 13);					// But we can use 'realloc' which frees the original 6 bytes of memory and allocates an new 13 bytes.
	strncpy(s, "Hello", i);						// Now copy the string into the newly re-allocated memory.
	strcat(s, " world!");						// Now we can add on the 'world!'.
	printf("s is now %s\n", s);


	free(s);									// When we've finished we should always free up any memory by using 'free'.
												// NOTE: Make a habit of using 'free' whan you've finished with some memory otherwise there will be 'memory leaks'
												// where memory that you have allocated will be 'lost' to your program.
												// These are not as important as they used to be (a few bytes in several GB won't make much of a difference) but it is considered to be good programming practise to clean up.

	return 0;
}

