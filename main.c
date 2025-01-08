#include "shell.h"
/**
* main - Entry point for the simple shell program
* Return: 0 on success, 1 on error.
*/

int main(void)
{
	char *line = NULL;    /* To store input from the user */

	size_t len = 0;       /* Buffer size for getline */
	ssize_t read;         /* Read status */
	pid_t pid;            /* Process ID */
	char *argv[2];  /*a local array if argv isn't part of your fnc signature*/

	extern char **environ;

	argv[0] = line;
	while (1)
	{
		printf("cisfun$");
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1) /* EOF (Ctrl+D) condition */
		{
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
			if (execve(line, argv, environ) == -1)
			{
				perror("./hsh");
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
