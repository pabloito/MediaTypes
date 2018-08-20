#include <stdbool.h>
#include "mediaTypes.h"

char * types[TYPE_ARRAY_LENGTH]= {"application", "audio", "example", "font", "image", "message", "model", "multipart", "text", "video"};


int main(int argc, char ** args)
{
  if(argc!=2  && !stringIsDelimited(args[1]))
  {
    printf("Program must be executed as follows ./prog '[ListOfMediaRanges]'\n");
    exit(1);
  }
  char * listOfMediaRanges = removeStringDelimitations(args[1]);
  char ** mediaRangeCompleteList = divideMediaRangeList(listOfMediaRanges);
  char * mediaRangeComplete;
  int i=0;
  while((mediaRangeComplete=mediaRangeCompleteList[i])!=NULL)
  {
    char ** splitMediaRange = divideMediaType(mediaRangeComplete);
    if(!isValidMediaType(splitMediaRange))
    {
      printf("'%s' is not a valid mediaRange. Exiting program...",mediaRangeComplete);
      exit(1);
    }
  }
  char * input;
  fetchInputFromStdin(&input);
  char ** mediaTypeCompleteList = divideUserInputByLine(input);
  free(input);
  char * mediaTypeComplete;

  i=0;
  while((mediaTypeComplete=mediaTypeCompleteList[i])!=NULL)
  {
      char ** splitMediaType = divideMediaType(mediaTypeComplete);
      if(!isValidMediaType(splitMediaType))
      {
        printf("null\n");
      }
      int j=0;
      while((mediaRangeComplete=mediaRangeCompleteList[j]))
      {
        char ** splitMediaRange = divideMediaType(mediaRangeComplete);
        if(mediaTypeBelongsToMediaRange(splitMediaType,splitMediaRange))
        {
          printf("true\n");
        }
      }
      printf("false\n");
  }
  return 1;
}

char *removeStringDelimitations(char *string) {
  char * ret = string+1;
  char c;
  string++;
  while(*string!=0) string++;
  *(string-1)=0;
  return ret;
}

int stringIsDelimited(char *string) {
  if(string==NULL)
  {
    return 0;
  }
  if(*string!='\'')
  {
    return 0;
  }
  char c;
  char lastc=0;
  string++;
  while((c=*string)!=0)
  {
    string++;
    lastc=c;
  }
  if(lastc!='\'')
  {
    return 0;
  }
  return 1;
}

int fetchInputFromStdin(char ** bufferPosition)
{
  char c;
  int counter=0;
  char * buffer = malloc(INITIAL_INPUT_SIZE);
  int size=INITIAL_INPUT_SIZE;
  while((c=getchar())!=EOF){
    if(counter>=size){
      size+=INITIAL_INPUT_SIZE;
      buffer = realloc(buffer, size);
    }
    *(buffer+counter)=c;
    counter++;
  }
  *bufferPosition=buffer;
  return counter;
}

int toNLowerString(char * lowerCaseCopy, char * original, int n)
{
  char c = *original;
  int i=0;
  while(c!=0 && i<n)
  {
    *(lowerCaseCopy+i)=tolower(c);
    c=*(original+ ++i);
  }
  *(lowerCaseCopy+i)=0;
  if(i>=n)
  {
    return 1;
  }
  return 0;
}

int isType(char * type)
{
  char * lowerCaseCopy = malloc(MAX_TYPE_SIZE);
  if(toNLowerString(lowerCaseCopy, type, MAX_TYPE_SIZE)){
    free(lowerCaseCopy);
    return 0;
  }
  for(int i=0; i<TYPE_ARRAY_LENGTH;i++)
  {
      if(!strcmp(lowerCaseCopy,types[i]))
      {
        free(lowerCaseCopy);
        return 1;
      }
  }
  free(lowerCaseCopy);
  return 0;
}

char ** divideStrByDelimeter(char * string, char * delimeter)
{
  char * nextToken;
  char ** dictionary= malloc(INITIAL_DICTIONARY_SIZE);

  if(string==NULL)
  {
      dictionary[0]=NULL;
      return dictionary;
  }

  char * copy=strdup(string);
  char * tofree=copy;

  int i=0, size=INITIAL_DICTIONARY_SIZE;

  while((nextToken = strsep(&copy, delimeter)))
  {
    if(strcmp(nextToken,"")==0) break;
    if(i>=size)
    {
      size+=INITIAL_DICTIONARY_SIZE;
      dictionary=realloc(dictionary,size);
    }
    dictionary[i]=strdup(nextToken);
    i++;
  }

  free(tofree);

  if(i>=size)
  {
    size+=1;
    dictionary=realloc(dictionary,size);
  }
  dictionary[i]=NULL;
  return dictionary;
}

char ** divideMediaType(char * mediaType)
{
  return divideStrByDelimeter(mediaType, "/");
}

char ** divideUserInputByLine(char * userInput)
{
  return divideStrByDelimeter(userInput,"\n");
}

char ** divideMediaRangeList(char * mediaTypeList)
{
  return divideStrByDelimeter(mediaTypeList,",");
}

int mediaTypeBelongsToMediaRange(char ** mediaType, char ** mediaRange)
{
  if(mediaType==NULL || mediaRange==NULL)
  {
    return 0;
  }

  char * mediaTypeToken;
  char * mediaRangeToken;

  int i=0;
  while(1)
  {
    mediaTypeToken = mediaType[i];
    mediaRangeToken = mediaRange[i];
    if(mediaRangeToken==NULL)
    {
      return 1;
    }
    if(mediaTypeToken==NULL)
    {
      return 0;
    }
    if(strcmp(mediaRangeToken,"*")==0)
    {
      return 1;
    }
    if(strcmp(mediaRangeToken,mediaTypeToken)!=0)
    {
      return 0;
    }
    i++;
  }

}

void finalizeMediaType(char ** splitMediaType)
{
  if(splitMediaType==NULL){
    return;
  }
  int i=0;
  while((splitMediaType[i])!=NULL)
  {
    free(splitMediaType[i]);
    splitMediaType[i]=NULL;
    i++;
  }
  free(splitMediaType);
  splitMediaType=NULL;
}

int isValidMediaType(char ** mediaType)
{
  char ** dictionary=mediaType;
  if(dictionary[0]==NULL ||!isType(dictionary[0]))
  {
    return 0;
  }
  return 1;
}
