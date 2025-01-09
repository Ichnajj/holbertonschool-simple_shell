#include "shell.h"

/**
 * fork_execute - Creates a child process to execute a command
 * @args: An array of command arguments (args[0] is the command)
 * @env: The environment variables to be passed to the command
 *
 * Return: None
 */
void fork_execute(char **args, char **env)
{
pid_t pid = fork(); /* creating new process */
int status;
if (pid == -1)
{
perror("fork failed");
return;
}
if (pid == 0) /* Child process */
{
execute_command(args, env); /* replacing code with the entry command to run*/
_exit(EXIT_FAILURE);
}
else
{
wait(&status); /* Parent process waits for the child pro to complete */
}
}
