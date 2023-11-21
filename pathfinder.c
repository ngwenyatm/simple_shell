#include "shell.h"

/**
 * pathFinder - iterates through directories to find the path
 * @cmd: tokenized string from user
 * Return: full path of command
 */

char *pathFinder(char *cmd)
{
	char *pathMain, *pathCp, *pathTok, *cmdPath;
	int pathLen;
	struct stat buff;

	if (cmd[0] != '/')
	{
		pathMain = getenv("PATH");

		while (pathMain)
		{
			pathCp = strdup(pathMain);
			pathTok = strtok(pathCp, ":");

			while (pathTok != NULL)
			{
				pathLen = strLen(cmd) + strLen(pathTok);
				cmdPath = malloc(pathLen + 2);

				if (cmdPath != NULL)
				{
					_strcpy(cmdPath, pathTok);
					strCat(cmdPath, "/");
					strCat(cmdPath, cmd);

					if (stat(cmdPath, &buff) == 0)
					{
						free(pathCp);
						return (cmdPath);
					}
					else
					{
						free(cmdPath);
						pathTok = strtok(NULL, ":");
					}
				}
				else
				{
					perror("Memory allocation failed");
					exit(1);
				}
			}
			free(pathCp);
			return (NULL);
		}
	}
	else
	{
		return (cmd);
	}

	return (0);
}
