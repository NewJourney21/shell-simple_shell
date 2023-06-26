#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_run - test run command
 */
void test_run(void)
{
	char **arr = NULL;
	char *s = "";
	int count = 0;
	char *delim = " ";

	size_t len = 0;
	int n = 0;

	printf("\nInput $: ");
	n = getline(&s, &len, stdin);
	if (n == -1)
	{
		printf("Error: Unable to read line");
		exit(EXIT_FAILURE);
	}
	fflush(stdout);

	count = _strtok(&arr, s, delim);

	if (arr == NULL)
	{
		printf("\nError: Nothing to return");
	}
	else
	{
		run(arr, count);
	}

	printf("\nvalue: %s\n", s);
}
