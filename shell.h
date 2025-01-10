#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define MAX_ARGS 100

int main(int argc, char **argv, char **env);
char **parsetheinput(char *input);
char *read_line(void);
void fork_execute(char **args, char **env);
void execute_command(char **args, char **env);
void handlecommand_cd(char **args);
void handlecommand_env(char **env);


#endif
