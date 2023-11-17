#include "shell.h"

/**
 * _realloc - resize a dynamically allocated memory block
 * @ptr: pointer to the existing memory block.
 * @newSize: new size in bytes for the memory block.
 * Return: pointer to the resized memory block.
 */
void *_realloc(void *ptr, size_t newSize)
{
	void *newPtr;
	char *oldPtr;
	char *newPrChar;

	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(newSize));
	}
	else
	{
		newPtr = malloc(newSize);
		if (newPtr == NULL)
		{
			perror("Mamory allocation error");
			exit(EXIT_FAILURE);
		}

		oldPtr = (char *)ptr;
		newPrChar = (char *)newPtr;

		for (size_t i = 0; i < newSize; ++i){
			newPrChar[i] = oldPtr[i];
		}
		free (ptr);
		return (newPtr);
	}
}

