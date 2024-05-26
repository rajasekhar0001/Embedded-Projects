#include "main.h"

int execute_external_command(char *input) {

    int ret = fork();
    if (ret == 0) {
        // child process
        char *cmd[] = {0};
        get_cmd(input, cmd);

        execvp(cmd[0], cmd);
        printf("Command not found\n");
        
    }
    else if (ret > 0) {
        // parent process
        int status;
        wait(&status);
        // 
    }

    // return FAILURE;

}
