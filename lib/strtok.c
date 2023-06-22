#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int add_char(char c, char **word, int *wc);
int add_word(char ***arr, long *pos, char *word, int *wc);
void free_array(char ***arr, int size);

/**
 * _strtok - function to split string to an array
 * @arr: the address of the array to split string into
 * @line: string
 * @delim: delimeter
 *
 * Return: the size of the array
 */
long _strtok(char ***arr, char *line, char *delim)
{
	int i = 0;
	char c = '0';
	long pos = 0;
	int wc = 0;
	char *word = "";

	if (line == NULL)
		return (0);

	if (delim == NULL)
	{
		*arr = malloc(sizeof(line));
		if (*arr == NULL)
			return (0);

		*arr[0] = line;
		return (1);
	}

	while (!((*(line + i) == '\0') || (*(line + i) == '\n')))
	{
		c = *(line + i);
		if (c == *delim)
			add_word(arr, &pos, word, &wc);
		else
			add_char(c, &word, &wc);
		i++;
	}

	if (wc > 0)
		add_word(arr, &pos, word, &wc);

	return (pos);
}

/**
 * add_char - adds a character to a word
 * @c: the character to be added
 * @word: the word
 * @wc: the current word count
 *
 * Return: 1
 */
int add_char(char c, char **word, int *wc)
{
	if (*wc == 0)
	{
		*word = malloc(sizeof(char));
		if (word == NULL)
		{
			return (-1);
		}
	}

	*(*word + *wc) = c;
	*wc += 1;

	return (1);
}

/**
 * add_word - adds a word to an array
 * @arr: the array
 * @pos: the current position of the array to add on
 * @word: the word to be added
 * @wc: the current word count
 *
 * Return: an integer
 */
int add_word(char ***arr, long *pos, char *word, int *wc)
{
	if (*wc == 0)
	{
		return (0);
	}

	if (*arr == NULL)
	{
		*arr = calloc(1, sizeof(char *));
		if (*arr == NULL)
			return (-1);
	}
	else
	{
		*arr = reallocarray(*arr, (*pos + 1), sizeof(char *));
		if (*arr == NULL)
		{
			free_array(arr, *pos);
			return (-1);
		}
	}

	if (*pos < 0 || *wc < 0 || word == NULL)
		return (-1);

	*(*arr + *pos) = malloc(sizeof(char) * (*wc));
	if (*(*arr + *pos) == NULL)
	{
		free_array(arr, *pos);
	}

	if (_strcpy(*(*arr + *pos), word) == NULL)
	{
		free_array(arr, *pos);
		return (-1);
	}

	*wc = 0;
	*pos += 1;
	free(word);

	return (1);
}

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

