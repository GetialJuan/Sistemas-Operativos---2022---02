//Fila 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(void)
{
    char *full_command = NULL, *copy_command = NULL;
    size_t n = 0;
    ssize_t nchars_read; /* number of characters the user types */
    char *token;
    const char *delim = " \n";
    char **argv;
    int i = 0; 
    int num_tokens = 0;

    /*strcpy(command_copy, full_command);
     print a prompt for the user to type something */
    
    while(1){
        printf("$ ");

        /* get the string that the user types in and pass it to full_command */
        nchars_read = getline(&full_command, &n, stdin);

        /* let's allocate space to store the characters read by getline */
        copy_command = malloc(sizeof(char) * nchars_read);

        if (copy_command == NULL){
            perror("tsh: memory allocation error");
            return (-1);
        }

        /* make a copy of the command that was typed */
        strcpy(copy_command, full_command);
    
    
        /* check if the getline function failed or reached EOF or user use CTRL + D */
        if (nchars_read == -1){
            printf("Exiting shell....\n");
            return (-1);
        }
        else {

            /* split the string (full_command) into an array of words */
            token = strtok(full_command, delim);

            /* allocate space to store the variable arguments but before then determine how many tokens are there*/
            while (token != NULL){
                num_tokens++;
                token = strtok(NULL, delim);
            }
            num_tokens++;
            /* printf(">>>>> %d \n", num_tokens);

             use malloc to allocate enough space for the pointer to the argument variables */
            argv = malloc(sizeof(char *) * num_tokens);

            token = strtok(copy_command, delim);

            for (i = 0; token != NULL; i++){
                argv[i] = malloc(sizeof(char) * strlen(token));
                strcpy(argv[i], token);

                /* printf(">>>>> %s \n", argv[i]);*/
                token = strtok(NULL, delim);
            }
            argv[i] = NULL;

            
            /*Obtaining path and trying to execute the command*/
            char* path;
            path = getenv("PATH");

            char* copy_path;
            copy_path = strdup(path);

            char* current_path;

            current_path = strtok(copy_path,":");
            char* command;

            while(current_path != NULL){

                command = malloc(strlen(current_path) + strlen(argv[0]) + 2);

                strcpy(command,current_path);
                strcat(command,"/");
                strcat(command,argv[0]);
                strcat(command,"\0");

                execve(command,argv,NULL);

                free(command);

                current_path = strtok(NULL,":");
                if(current_path == NULL){
                    perror("Error: ");
                    free(copy_path);
                }
                /* execute the commands with execve */
                //execmd(command);    
            }

            
        }
    }

    free(full_command);
    free(copy_command);
    return (0);
}
