#include  "shell.h"

/**
 * main - Entry point.
 * @ac: argument count
 * @args: Argument vector
 * @env: environment variable
 * Return: 0
 */

int main(int ac, char **args, char **env)
{
	char *command = NULL;
	char *cmdPath;
	size_t commandLen = 1;
	int charRead;
	int tokCount = 0;
	char *tok;
	int inputLen;
	int status;
	pid_t pid;

	(void)ac;
	(void)env;
	while (1)
	{
		write(1, "$ ", 2);
		fflush(stdout);

		charRead = getLine(&command, &commandLen, STDIN_FILENO);

		if(charRead == -1)
		{
			perror("Failed to read input");
			break;
		}

		inputLen = strLen(command);

		if(inputLen > 0 && command[inputLen - 1] == '\n')
		{
			command[inputLen - 1] = '\0';
		}

		args = malloc(sizeof(char *) * (tokCount + 2));

		tok = strtok(command, " ");
		while (tok != NULL)
		{
			args[tokCount] = malloc(sizeof(char) * (strlen(tok) + 1));
			_strcpy(args[tokCount],tok);
			tokCount++;
			tok = strtok(NULL, " ");
		}
		args[tokCount] = NULL;

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
			write(1, "No command\n", 11);
		}

		free(args);
	}

	free(command);
	
	return (0);
}
