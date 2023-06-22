#include <stdio.h>

void print_commands(char **clist, long csize);

/**
 * run_commands - function to run commands
 * @clist: the command list
 * @csize: the size of the command list
 *
 * Return: 1
 */
int run_commands(char **clist, long csize)
{
	print_commands(clist, csize); /** delete this */

	return (1);
}

/**
 * print_commands - function to print commands
 * @clist: the command list
 * @csize: the size of the command list
 */
void print_commands(char **clist, long csize)
{
	long i = 0;

	printf("\nArray list:");
	while (i < csize)
	{
		printf("\n%ld: %s", i, clist[i]);
		i++;
	}
}
