/*
Write a program that accepts a string input from stdio and sends it to a function that transforms it according a transposition function passed in to it as an argument.  The function will print out the string, transform it, and then print out the result. The transposition function, you can assume, simply shuffles the existing characters in the string.  Build a transposition function that reverses the string and apply it.  Where appropriate and possible, use dynamic allocation and pointer arithmetic to get the job done.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*transform_func)(char*);

// transform function
void transform(const char* input, transform_func reverse) {
    printf("Original String: %s\n", input);

    // dynamic memory allocation necessary to not mess with input argument
    char * buffer = malloc((strlen(input) + 1) * sizeof(char)); // +1 for the null terminator
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // copy the input into buffer
    strcpy(buffer, input);

    // apply transposition function
    reverse(buffer);

    printf("Transformed String: %s\n", buffer);

    // free memory
    free(buffer);
}

// transposition function (reverse string)
void reverse(char* string) {
    char* start = string;
    size_t len = strlen(string);
    
    if (len == 0) {
        return;
    }

    char* end = string + len - 1; // -1 for the null terminator
    char temp;

    while (start  < end) {
        temp = *start; 
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main () {
    char buffer[256];

    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        transform(buffer, reverse);
    }

    return 0;
}