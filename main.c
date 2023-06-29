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
#include "lib/puts.c"
#include "lib/print_commands.c"

void run_interactive_mode(char ***, long *, char ***);
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

	if (isatty(STDIN_FILENO))
	{
		run_interactive_mode(&clist, &csize, &env);
	}
	else
	{
		line = _getline();

		if (ac == 1 && (*line != '\0'))
		{
			csize = _strtok(&clist, line, " ");
			exec_run_commands(&clist, csize, &env);
		}
		else if (ac > 1)
		{
			csize = array_copy(&clist, &av, ac, 1, ac - 1);

			if (csize != -1)
			{
				exec_run_commands(&clist, csize, &env);
			}
			else
			{
				_puts(2, "Error(array_copy)\n");
			}
		}
		else
		{
			_puts(2, "Error: too few arguments supplied\n");
		}
	}

	free(line);
	free_array(&clist, csize + 1);
	return (0);
}

/**
 * run_interactive_mode - function to run in interactive mode
 * @clist: the command list
 * @csize: the command size
 * @env: the address of the environment variables
 */
void run_interactive_mode(char ***clist, long *csize, char ***env)
{
	char *line = NULL;
	int open = 1;

	while (open)
	{
		_puts(1, "$ ");
		line = _getline();
		fflush(stdout);

		if (*line == EOF)
		{
			open = 0;
			_puts(1, "\n");
			continue;
		}
		else if (*line == '\0')
		{
			free(line);
			_puts(1,  "\n");
			continue;
		}

		if (*clist != NULL)
		{
			free_array(clist, *csize + 1);
			*clist = NULL;
		}

		*csize = _strtok(clist, line, " ");
		free(line);

		if (exec_run_commands(clist, *csize, env) == 0)
		{
			open = 0;
			continue;
		}
	}
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
		_puts(2, "Error: Unable to split command list\n");
	}
	else
	{
		if (_strcmp("exit", (*clist)[0]) == 0)
		{
			free_array(clist, 2);
			exit(EXIT_SUCCESS);
			return (0);
		}

		run_commands(clist, csize, env);
	}

	return (1);
}
