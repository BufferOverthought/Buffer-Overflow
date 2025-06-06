#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* check_input(const char* input) {
    static char output[256];
    // Specific payload that triggers simulated shell
    if (strcmp(input, "thequickbrownfoxjumpsoverthelazydog") == 0) {
        FILE *flagfile = fopen("flag.txt", "r");
        char flag[128] = {0};
        if (flagfile) {
            fread(flag, 1, 120, flagfile);
            fclose(flagfile);
        } else {
            strcpy(flag, "Could not open flag.txt");
        }
        snprintf(output, sizeof(output), 
            "Simulated shell:\n$ whoami\nappuser\n$ cat flag.txt\n%s\n$ exit", flag);
        return output;
    }
    strcpy(output, "Login processed (no errors detected).");
    return output;
}
