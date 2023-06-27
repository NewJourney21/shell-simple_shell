#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

/**
 * _getline - Reads input from the user
 *
 * Return: the read input
 */
char *_getline()
{
	int max = 120;
	int ex = 1;
	char *b = NULL;
	char *temp = NULL;
	unsigned long int n, last;
	unsigned long int limit = sizeof(char) * max;
	int size = limit;

	b = calloc(size, sizeof(char));
	if (b == NULL)
	{
		return (NULL);
	}

	while ((n = read(0, (b + (size - limit)), limit)) > 0)
	{
		last = size - 1;
		if (n == limit && *(b + last) != '\n')
		{
			ex++;
			size = ex * limit;
			temp = calloc(size, sizeof(char));
			if (temp == NULL)
			{
				free(b);
				return (NULL);
			}
			_strcpy(temp, b);
			free(b);
			b = temp;
		}
		else if (n <= limit && *(b + (last - limit + n)) == '\n')
		{
			*(b + (last - limit + n)) = '\0';
			break;
		}
	}

	return (b);
}
