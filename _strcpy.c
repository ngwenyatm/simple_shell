#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strcpy - copies a string
 * @newstr: new copy string
 * @strPrime: original string being copied
 * Return: pointer to new copy string
 */

char *_strcpy(char *newstr, const char *strPrime)
{
	int i = 0;

	if (newstr == NULL)
	{
		return (NULL);
	}

	char *ptr = newstr;

	for (i = 0; i < strlen(strPrime); i++)
	{
		if (strPrime[i] != '\0')
		{
			newstr[i] = strPrime[i];
		}
	}
	newstr[i] = '\0';
	return (ptr);
}
