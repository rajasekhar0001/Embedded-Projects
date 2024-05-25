#include "main.h"

int execute_external_command(char *input) {

    int ret = fork();
    if (ret == 0) {
        // child process
        char *cmd[] = {0};
        get_cmd(input, cmd);

        int i=0;
        while (cmd[i] != NULL) {
            printf("%s ", cmd[i]);
            i++;
        }
        printf("\n");

        execvp(cmd[0], cmd);
        printf("invalid command\n");
        // exit()
    }
    else if (ret > 0) {
        // parent process
        int status;
        wait(&status);

    }

    return FAILURE;

}
