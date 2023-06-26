#include <stdio.h>
#include "main.h"
#include "lib/lib.h"
#include "lib/getline.c"
#include "lib/strcmp.c"
#include "lib/strncmp.c"
#include "lib/strlen.c"
#include "lib/strcpy.c"
#include "lib/strtok.c"
#include "lib/strcat.c"
#include "lib/run_commands.c"
#include "lib/append_path.c"
#include "lib/run.c"
#include "lib/free_array.c"
#include "lib/array_copy.c"
#include "lib/print_env.c"

int exec_run_commands(char ***, long, char ***);

/**
 * main - entry point
 * @ac: argument count
 * @av: argument list
 * @env: the environment variables
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char **clist = NULL;
	long csize = 0;
	char *line = NULL;
	int open = 1;

	if (ac == 1)
	{
		while (open)
		{
			printf("$ ");
			fflush(stdout);

			line = _getline();
			if (*line == EOF || line[0] == '\0')
			{
				open = 0;
				printf("\n");
				continue;
			}

			csize = _strtok(&clist, line, " ");
			if (exec_run_commands(&clist, csize, &env) == 0)
			{
				open = 0;
				continue;
			}
		}
	}
	else
	{
		csize = array_copy(&clist, &av, csize, 1, ac - 1);
		if (csize != -1)
		{
			exec_run_commands(&clist, csize, &env);
		}
		else
		{
			printf("\nError");
		}
	}

	return (0);
}

/**
 * exec_run_commands - function to execute run_commands
 * @clist: the command list
 * @csize: the array size
 * @env: the address of the environment variables
 *
 * Return: status
 */
int exec_run_commands(char ***clist, long csize, char ***env)
{
	if (clist == NULL)
	{
		printf("\nError: Unable to split command list ");
	}
	else
	{
		if (_strcmp("exit", (*clist)[0]) == 0)
		{
			return (0);
		}

		if (run_commands(clist, csize, env) == -1)
		{
			printf("\nError");
		}
	}

	return (1);
}
