#include "shell.h"

/**
 * handlecommand_cd - Handles the `cd` built-in command
 * @args: The arguments for the command
 *
 * Return: None
 */
void handlecommand_cd(char **args)
{
if (args[1] == NULL || chdir(args[1]) == -1)
{
perror("cd");
}
}

/**
 * handlecommand_env - Handles the `env` built-in command
 * @env: The environment variables
 *
 * Return: None
 */
void handlecommand_env(char **env)
{
int i;
for (i = 0; env[i]; i++)
printf("%s\n", env[i]);
}
