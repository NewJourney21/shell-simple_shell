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
		if (clist == NULL)
		{
			printf("\nError: Unable to split command list");
		}
		else
		{
			run_commands(&clist, csize);
		}
	}

	return (0);
}
