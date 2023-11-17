#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
size_t strLen(char *str);
char *pathFinder(char *cmd);
char *_strcpy(char *newstr, const char *strPrime);
void strCat(char str1[], char str2[]);
#endif
