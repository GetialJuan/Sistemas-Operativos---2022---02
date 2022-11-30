#include "main.h"

void execmd(char **argv){
    char *command = NULL, *comando = NULL;

    if (argv){
        /* get the command */
        command = argv[0];

        /* generate the path to this command before passing it to execve */
        comando = route(command);

        /* execute the actual command with execve */
        if (execve(comando, argv, NULL) == -1){
            perror("Error:");
        }
    }

}
