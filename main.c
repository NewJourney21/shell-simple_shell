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

void exec_run_commands(char ***clist, long csize);

/**
 * main - entry point
 * @ac: argument count
 * @av: argument list
 * @env: environment vairable
 *
 * Return: 0
 */
int main(int ac, char **av)
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
			exec_run_commands(&clist, csize);
		}
	}
	else
	{
		if ((csize = array_copy(&clist, &av, csize, 1, ac - 1)) != -1)
		{
			exec_run_commands(&clist, csize);
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
 */
void exec_run_commands(char ***clist, long csize)
{
	if (clist == NULL)
	{
		printf("\nError: Unable to split command list ");
	}
	else
	{
		if (run_commands(clist, csize) == -1)
		{
			printf("\nError");
		}
	}
}
