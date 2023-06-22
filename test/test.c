#include <stdio.h>
#include <unistd.h>
#include "test.h"
#include "../lib/lib.h"

void print_intro(void);

/**
 * main - test file
 *
 * Return: 0
 */
int main(void)
{
	int i;

	print_intro();
	scanf("%d", &i);
	getchar();

	switch (i)
	{
		case 1:
			test_getline();
			break;
		case 2:
			test_strcmp();
			break;
		case 3:
			test_strlen();
			break;
		case 4:
			test_strcpy();
			break;
		case 5:
			test_strtok();
			break;
		default:
			printf("Unsupported value entered");
			break;
	}

	return (0);
}

/**
 * print_intro- print welcome
 */
void print_intro(void)
{
	printf("Testing Unix Shell Interpreter\n\n");
	printf("Press 1: to test _getline\n");
	printf("Press 2: to test _strcmp\n");
	printf("Press 3: to test _strlen\n");
	printf("Press 4: to test _strcpy\n");
	printf("Press 5: to test _strtok\n");
}
