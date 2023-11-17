#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
size_t strLen(char *str);
char *pathFinder(char *cmd);
char *_strcpy(char *newstr, const char *strPrime);
void strCat(char str1[], char str2[]);
int builtIn(char **args, char **env);
void *_realloc(void *ptr, size_t newSize);
ssize_t getLine(char **line, size_t *lineSize, int fd);

#endif
