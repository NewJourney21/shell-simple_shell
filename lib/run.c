#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "lib.h"

int exec_process(char **cmd, long size);

/**
 * run - function to executes a command
 * @cmd: the command represented as an array
 * @size: the size of the command list
 *
 * Return: 1
 */
int run(char **cmd, long size)
{
	struct stat st;
	int status;
	pid_t cid;

	if (cmd[0] == NULL)
	{
		return (-1);
	}

	if (stat(cmd[0], &st) != 0)
	{
		printf("\nbash: %s: command not found\n", cmd[0]);
		return (-1);
	}
	else
	{
		cid = fork();
		if (cid == -1)
		{
			printf("\nError creating proces");
			return (-1);
		}
		else if (cid == 0)
		{
			return (exec_process(cmd, size));
		}
		else
		{
			wait(&status);
			free_array(&cmd, size);
		}
	}

	return (1);
}

/**
 * exec_process - function to execute a process
 * @cmd: command array
 * @size: command array size
 *
 * Return: an integer
 */
int exec_process(char **cmd, long size)
{
	cmd[size] = NULL;

	if (execve("/bin/ls", cmd, NULL) == -1)
	{
		printf("Error\n");
		return (-1);
	}

	return (1);
}
