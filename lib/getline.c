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
	int max = 1024;
	int ex = 1;
	char *b, *temp;
	unsigned long int n, last;
	unsigned long int limit = sizeof(char) * max;
	int size = limit;

	b = malloc(size);
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
			temp = malloc(size);
			if (temp == NULL)
			{
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
