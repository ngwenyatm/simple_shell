#include  "shell.h"

/**
 * main - Entry point.
 * @ac: argument count
 * @args: Argument vector
 * @env: environment variable
 * Return: integer
 */
int main(int ac, char **args, char **env)
{
	char *command;
	char *cp_Ptr;
	char *cmdPath;
	size_t commandLen = 0;
	size_t charRead;
	int tokCount = 0;
	char *tok;
	int inputLen;
	int status;
	int i;
	pid_t pid;

	command = NULL;
	cp_Ptr = NULL;

	(void) ac;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		charRead = getline(&command, &commandLen, stdin);
		if (!charRead)
		{
			break;
		}
		inputLen = strLen(command);
		cp_Ptr = malloc(sizeof(char) * charRead);
		if (cp_Ptr == NULL)
		{
			perror("failed allocate memory");
			break;
		}

		_strcpy(cp_Ptr, command);

		tok = strtok(command, " ");
		while (tok != NULL)
		{
			tokCount++;
			tok = strtok(NULL, " ");
		}
		tokCount++;
		args = malloc(sizeof(char *) * tokCount);
		tok = strtok(cp_Ptr, " ");

		for (i = 0; tok != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * strLen(tok));

			_strcpy(args[i], tok);
			tok = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (inputLen > 0 && command[inputLen - 1] == '\n')
		{
			command[inputLen - 1] = '\0';
		}

		builtIn(args, env);

		cmdPath = pathFinder(command);

		if (cmdPath != NULL)
		{
			args[0] = cmdPath;
			pid = fork();
			if (pid == -1)
			{
				perror("Fork failed");
				exit(1);
			}
			if (pid == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror(args[0]);
					exit(1);
				}
			}
			else
			{
				wait(&status);
			}
			free(cmdPath);
		}
		else
		{
			write(STDOUT_FILENO, "No command\n", 11);
		}
	}


	for (i = 0; i < tokCount; i++)
	{
		free(args[i]);
	}
	free(args);
	free(cp_Ptr);
	free(command);
	return (0);
}
