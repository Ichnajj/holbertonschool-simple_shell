#include "shell.h"
/**
* simple_shell - Entry point for the simple shell program
* @argc: The number of arguments passed to the program (not used)
* @argv: Array of argument str- command line-passed to the program(not used)
* @env: environment variables for shell program
* Return: 0 on success, 1 on error.
*/
int simple_shell(void)
{
	char *line = NULL;    /* To store input from the user */
	size_t len = 0;       /* Buffer size for getline */
	ssize_t read;         /* Read status */
	pid_t pid;            /* Process ID */
	char *argv[2];  /*a local array if argv isn't part of your fnc signature*/

	argv[0] = line;
	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1) /* EOF (Ctrl+D) condition */
		{
			printf("\n");
			free(line);
			exit(0);
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		argv[0] = line;
		argv[1] = NULL;  /* Null-terminate the argument array */
		pid = fork();
		if (pid == -1) /* Fork failed */
		{
			perror("fork failed");
			exit(1);
		}
		if (pid == 0) /* Child process */
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
		else /* Parent process */
		{
			wait(NULL);
		}
	}
	return (0);
}
