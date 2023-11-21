#include "shell.h"

/**
 * _strcpy - copies a string
 * @newstr: new copy string
 * @strPrime: original string being copied
 * Return: pointer to new copy string
 */

char *_strcpy(char *newStr, const char *strPrime)
{
	int i = 0;
while (strPrime[i] != '\0')
  {
	  newStr[i] = strPrime[i];
	  i++;
  }
  newStr = '\0';
  return newStr;
}
