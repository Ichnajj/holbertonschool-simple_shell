#include "shell.h"

/**
 * read_line - Reads a line of input from the user
 *
 * Return: A string containing the input entered by the user
 */

char *read_line(void)
{
char *line = NULL; /* To store input from the user */
size_t len = 0;
ssize_t read;
read = getline(&line, &len, stdin);
if (read == -1) /* EOF (Ctrl+D) condition */
{
if (isatty(STDIN_FILENO))
printf("\n");
free(line);
exit(EXIT_SUCCESS);
}
if (line[read - 1] == '\n')
line[read - 1] = '\0';
return (line);
}
