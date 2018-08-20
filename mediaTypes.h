#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TYPE_ARRAY_LENGTH 10
#define MAX_TYPE_SIZE 15
#define INITIAL_DICTIONARY_SIZE 5 * sizeof(char *)


int isType(char * type);
int toNLowerString(char * lowerCaseCopy, char * original, int n);
char ** divideMediaType(char * mediaType);


#endif
