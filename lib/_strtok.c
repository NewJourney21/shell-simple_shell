#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
int add_char(char c, char **word, int *wc);
int add_word(char ***arr, int *pos, char *word, int *wc);
void free_array(char ***arr, int size);
*/

/**
 * _strtok - function to split string to an array
 * @line: string
 * @delim: delimeter
 *
 * Return: an array of pointers
 */
/*
char **_strtok_old(char *line, char *delim)
{
	int i = 0;
	char c = '0';
	int pos = 0;
	int wc = 0;
	char *word = "";
	char **arr = NULL;

	if (line == NULL)
		return (arr);

	if (delim == NULL)
	{
		arr = malloc(sizeof(line));
		if (arr == NULL)
			return (arr);
		
		arr[0] = line;
		return (arr);
	}

	while(!((*(line + i) == '\0') || (*(line + i) == '\n')))
	{
		c = *(line + i);
		if (c == *delim)
			add_word(&arr, &pos, word, &wc);
		else
			add_char(c, &word, &wc);
		i++;
	}

	if (wc > 0)
		add_word(&arr, &pos, word, &wc);

	return (arr);
}
*/

/**
 * add_char - adds a character to a word
 * @c: the character to be added
 * @word: the word
 * @wc: the current word count
 */
/*
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
*/
/**
 * add_word - adds a word to an array
 * @arr: the array
 * @pos: the current position of the array to add on
 * @word: the word to be added
 * @wc: the current word count
 *
 * Return: an integer
 */
/*
int add_word(char ***arr, int *pos, char *word, int *wc)
{
	if (*wc == 0)
	{
		return (0);
	}

	if (*arr == NULL)
	{
		*arr = malloc(sizeof(char*));
		if (*arr == NULL)
		{
			return (-1);
		}
	}

	if (*pos < 0 || *wc < 0 || word == NULL)
	{
		return (-1);
	}

	*(*arr + *pos) = malloc(sizeof(char) * (*wc));
	if (*(*arr + *pos) == NULL)
	{
		free_array(arr, *pos);
	}

	_strcpy(*(*arr + *pos), word);

	*wc = 0;
	*pos += 1;

	return (1);
}
*/
/**
 * free_array - function to release array memory
 * @arr: array
 * @size: the array size
 */
/*
void free_array(char ***arr, int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
	{
		free((*arr)[i]);
	}
}
*/
