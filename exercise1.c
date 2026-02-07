// 1. Print “Hello, <NAME>” where NAME is input from the keyboard.

#include <stdio.h>

int main(int argc, char * argv[]) {
    char *name;
    char buffer[256];
    
    // through command-line interface
    if (argc > 1) {
        name = argv[1];
        printf("Hello, %s\n", name);

    // from keyboard
    } else {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) { 
            printf("Hello, %s", buffer);
        }
    }

    return 0;
}