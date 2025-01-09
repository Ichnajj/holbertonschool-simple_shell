#include "shell.h"
/**
* main - Entry point for the simple shell program
* @argc: The number of arguments passed to the program (not used)
* @argv: Array of argument strings - command line- passed(not used)
* @env: environment variables for shell program
*
* Return: 0 on success, exits on EOF (Ctrl+D)
*/

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **args;    /* To store input from the user */
	(void)argc;
	(void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		line = read_line();
		if (!line)
		break;
		args = parsetheinput(line);
		if (!args)
			{
				free(line);
				continue;
			}
		if (args && args[0])
			{
		if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(EXIT_SUCCESS);
			}
		if (strcmp(args[0], "cd") == 0)
			{
				handlecommand_cd(args);
				free(args);
				free(line);
				continue;
			}
		if (strcmp(args[0], "env") == 0)
			{
				handlecommand_env(env);
			}
		else
			fork_execute(args, env);
	}
		free(args);
		free(line);
	}
	return (0);
}
