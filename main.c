#include <stdio.h>
#include "main.h"
#include "lib/lib.h"
#include "lib/getline.c"
#include "lib/strcmp.c"
#include "lib/strlen.c"
#include "lib/strcpy.c"
#include "lib/strtok.c"
#include "lib/run_commands.c"

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char **clist = NULL;
	long csize = 0;
	char *line = NULL;
	int open = 1;
	char *quit = "q";

	while (open)
	{
		printf("\nType q to exit (This is a temporary exit approach)\n\n");
		printf("$ ");
		fflush(stdout);

		line = _getline();
		printf("\nYou entered %s", line); /** To be deleted **/

		if (*line == EOF || _strcmp(line, quit) == 0)
		{
			open = 0;
		}

		csize = _strtok(&clist, line, " ");
		if (clist == NULL)
		{
			printf("\nError: Unable to split command list");
		}
		else
		{
			run_commands(clist, csize);
		}		

		printf("\n");
	}

	return (0);
}
