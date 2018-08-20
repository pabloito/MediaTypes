#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TYPE_ARRAY_LENGTH 10
#define MAX_TYPE_SIZE 15
#define INITIAL_DICTIONARY_SIZE 5


int isType(char * type);
void toLowerString(char * lowerCaseCopy, char * original);
char ** divideMediaType(char * mediaType);


#endif
