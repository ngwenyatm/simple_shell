#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * strLen - gets the length of the input string.
 * @str: String to be counted.
 * Return: the count of characters in the string.
 */
size_t strLen(char *str)
{
	size_t num = 0;

	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}
