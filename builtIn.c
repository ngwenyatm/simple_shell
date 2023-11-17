#include "shell.h"

/**
*builtIn - checks if input is env or exit and executes accordingly
*@args: tokenized string array from user
*@envp: environment info
*Return: 0
*/
int builtIn(char **args, char **envp)
{
	if (args[0] == "env")
	{
		int i = 0;

		for (i = 0 ; envp[i] != NULL; i++)
		{
			write(STDOUT_FILENO, (const void *)envp[i], strLen(envp[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	else if (args[0] == "exit")
	{
		exit(0);
		return (1);
	}

	return (0);
}
