#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define SUCCESS 1
#define FAILURE 0
#define INT_CMD 0
#define EXT_CMD 1
#define INVALID_CMD 2

#if 1
int check_command_type(char *cmd);
int execute_external_command(char *cmd);
int execute_internal_command(char * cmd);
int get_cmd(char *input, char *cmd[]);

// #endif

#endif
#endif

