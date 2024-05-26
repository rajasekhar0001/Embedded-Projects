#include "main.h"

int execute_internal_command(char * input) {
    char * buf = malloc(100);
    if (strncmp("exit", input, 4) == 0) {
        exit(1);
    }
    else if (strncmp("pwd", input, 3) == 0) {
        printf("%s\n", getcwd(buf, 100));
    }
    else {
        system(input);
        perror("system");
    }
    return SUCCESS;
}