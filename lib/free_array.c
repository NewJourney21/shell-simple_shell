#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * free_array - function to release array memory
 * @arr: array
 * @size: the array size
 */
void free_array(char ***arr, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		free((*arr)[i]);
	}
}