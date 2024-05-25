#include "main.h"

int main() {

    char input[100];
    char prompt[50] = "minishell";
    int exit_status = 0; // exit status of previous command or process

    while(1) {
        printf("%s$ ", prompt);
        fgets(input, 100, stdin); // fgets adds '\n' at the end 

        *(strchr(input, '\n')) ='\0';

        if (strncmp("PS1=", input, 4)== 0) {
            strcpy(prompt, input+4);
        }
        else if (strcmp("echo $$", input) == 0) {
            printf("%d\n", getpid());
        }
        else if (strcmp("echo $?", input) == 0) {
            printf("%d\n", exit_status);
        }
        else if(check_command_type(input) == INT_CMD) {
            printf("Internal command\n");
            execute_internal_command(input);
        }
        else if (check_command_type(input) == EXT_CMD) {
            printf("EXternal command\n");
            execute_external_command(input);
            printf("external cmd done\n");
        }
        else {
            printf("Invalid command\n");
        }  
    }
}