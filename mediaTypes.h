#ifndef MEDIA_TYPES_H
#define MEDIA_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mediaTypesTest.h"

#define TYPE_ARRAY_LENGTH 10
#define MAX_TYPE_SIZE 15
#define INITIAL_DICTIONARY_SIZE 5 * sizeof(char *)
#define INITIAL_INPUT_SIZE  100


int isType(char * type);
int toNLowerString(char * lowerCaseCopy, char * original, int n);

char ** divideStrByDelimeter(char * string, char * delimeter);
char ** divideMediaType(char * mediaType);
char ** divideUserInputByLine(char * userInput);
char ** divideMediaRangeList(char * mediaTypeList);

int mediaTypeBelongsToMediaRange(char ** mediaType, char ** mediaRange);
void finalizeMediaType(char ** splitMediaType);
int isValidMediaType(char ** mediaType);
int fetchInputFromStdin(char ** bufferPosition);


#endif
