#include "main.h"

void signal_handler(int signum, siginfo_t *info, void * ucontext) {
    
    printf("REceived SIGINT   %d  \n", getpid());
}

int main() {

    char input[100];
    char prompt[50] = "minishell";
    int exit_status = 0; // exit status of previous command or process

    struct sigaction act, old;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = signal_handler;
    sigaction(SIGINT, &act, &old);

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
            // printf("Internal command\n");
            exit_status = execute_internal_command(input);
        }
        else if (check_command_type(input) == EXT_CMD) {
            // printf("External command\n");
            execute_external_command(input);
        }
        else {
            printf("Invalid command\n");
        }  
    }
}