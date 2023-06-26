#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "lib.h"

int exec_process(char **cmd, long size);
int exec_custom_commands(char **cmd, char ***env);

/**
 * run - function to executes a command
 * @cmd: the command represented as an array
 * @size: the size of the command list
 * @env: the address of the environment variables
 *
 * Return: 1
 */
int run(char **cmd, long size, char ***env)
{
	struct stat st;
	int status;
	pid_t cid;

	if (cmd[0] == NULL)
	{
		return (-1);
	}

	if (_strcmp(cmd[0], "/bin/env") == 0 ||
		_strcmp(cmd[0], "/bin/printenv") == 0)
	{
		_print_env(env);
	}
	else if (stat(cmd[0], &st) != 0)
	{
		return (exec_custom_commands(cmd, env));
	}
	else
	{
		cid = fork();
		if (cid == -1)
		{
			dprintf(2, "Error creating proces\n");
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
		dprintf(2, "Error\n");
		return (-1);
	}
	return (1);
}

/**
 * exec_custom_commands - function to exectue commands outside stat
 * @cmd: the command list
 * @env: the address of the environment variables
 *
 * Return: 1 if successful
 */
int exec_custom_commands(char **cmd, char ***env)
{
	if (_strcmp(cmd[0], "/bin/setenv") == 0)
	{
		char *var = NULL;

		if (cmd[1] == NULL || cmd[2] == NULL ||
		cmd[1][0] == '\0' || cmd[2][0] == '\0')
		{
			dprintf(2, "Error:Usage: setenv [name] [value]\n");
		}

		var = _strcat(cmd[1], "=");
		if (var == NULL)
		{
			return (-1);
		}

		var = _strcat(var, cmd[2]);
		if (var == NULL)
		{
			return (-1);
		}

		return (_set_env(var, env));
	}
	else if (_strcmp(cmd[0], "/bin/unsetenv") == 0)
	{
		if (cmd[1] == NULL || cmd[1][0] == '\0')
		{
			dprintf(2, "Error:Usage: unset [name]\n");
		}

		return (_unset_env(cmd[1], env));

	}
	else
	{
		dprintf(2, "bash: %s: command not found\n", cmd[0]);
		return (-1);
	}
}
