#include "shell.h"

#define INIT_SIZE 64
/**
 * getLine - Read a line from a file descriptor.
 * @line: store the allocated line.
 * @lineSize: store the size of the allocated line.
 * @fd: where to read the line.
 * Return: number of characters read.
 */
ssize_t getLine(char **line, size_t *lineSize, int fd)
{
	ssize_t byteRead;
	char *buf = NULL;
	ssize_t readChar = 0;
	int bufSize = 0;
	int bufPos = 0;
	char charCurrent;

	*line = NULL;
	*lineSize = 0;

	while (1)
	{
		if (bufPos >= bufSize)
		{
			if (buf == NULL || bufPos == bufSize)
			{
				bufSize = INIT_SIZE;
				buf = _realloc(buf, bufSize);

				if (buf == NULL)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
			}
			byteRead = read(fd, buf, bufSize);
			bufPos = 0;

			if (byteRead == 0)
			{
				if (*lineSize > 0)
					return (readChar);
				else
					return (-1);
			}
		}
		charCurrent = buf[bufPos++];

		if (charCurrent == '\n')
		{
			*line = _realloc(*line, *lineSize + 1);
			(*line)[(*lineSize)++] = charCurrent;
			*line = _realloc(*line, *lineSize + 1);
			(*line)[*lineSize] = '\0';
			return (readChar);
		}
		*line = _realloc(*line, *lineSize + 1);
		(*line)[(*lineSize)++] = charCurrent;
		readChar++;
	}
}

