#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * execute_command - Executes a command by searching in
 * directories listed in PATH or using an absolute/relative path.
 * @args: An array of command arguments (args[0] is the command).
 * @env: The environment variables to be passed to the command.
 *
 * Return: None
 */
void execute_command(char **args, char **env)
{
char *path_env = getenv("PATH");
char *token = NULL;
    if (args[0] == NULL)  /* If no command is provided*/ 
    {
        return;
    }

    /*Check if the command is an absolute or relative paht*/
    if (args[0][0] == '/' || args[0][0] == '.')
    {
        if (access(args[0], X_OK) == 0)  /* If file is executable*/
        {
            execve(args[0], args, env);
        }
        else
        {
            perror(args[0]);  /* Print error if command not found*/
        }
        return;
    }

    /* If PATH is not set, return command not found*/
    if (!path_env || strlen(path_env) == 0)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    /*Tokenize the PATH and check each directory*/
    while (token != NULL)
    {
        char full_path[1024];
        
        if (strlen(token) + 1 + strlen(args[0]) < sizeof(full_path))
        {
            sprintf(full_path, "%s/%s", token, args[0]);
            
            if (access(full_path, X_OK) == 0)  /*If executable found*/
            {
                execve(full_path, args, env);
                return;
            }
        }

        token = strtok(NULL, ":");  /*Continue with the next token*/ 
    }

    /* If command is not found in any PATH directory*/
    fprintf(stderr, "%s: command not found\n", args[0]);
}
