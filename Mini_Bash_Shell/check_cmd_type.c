#include "main.h"

char *int_cmds[] = {"cd", "pwd", "exit", "rmdir", "mkdir", NULL};


int check_command_type(char *input) {
    int i=0;
    while (int_cmds[i] != NULL) {
        if (strncmp(input, int_cmds[i], strlen(input)) == 0) {
            return INT_CMD;
        }
        i++;
    }

    return EXT_CMD;
}

int get_cmd(char *input, char *cmd[]) {
    int i=0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        // printf("-> %s -> ", token);
        cmd[i] = malloc(strlen(token)+1);
        strcpy(cmd[i++], token);
        token = strtok(NULL, " ");
    }
    cmd[i] = malloc(8);
    cmd[i] = NULL;
    return SUCCESS;
}