#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* check_input(const char* input) {
    static char output[256];
    // If the payload is the special one, crash the app
    if (strcmp(input, "thequickbrownfoxjumpsoverthelazydog") == 0) {
        abort(); // Simulate real buffer overflow exploit (crash)
    }
    strcpy(output, "Login processed (no errors detected).");
    return output;
}
