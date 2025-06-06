#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Vulnerable function called by the Python backend
void secret_shell() {
    // This will spawn a shell in the context of the webserver process
    system("/bin/sh");
}

// Classic buffer overflow vulnerability
void check_input(const char* input) {
    char buffer[32];
    strcpy(buffer, input); // No bounds checking
    printf("OK\n");
}
