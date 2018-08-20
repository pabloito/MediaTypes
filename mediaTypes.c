#include "mediaTypes.h"

char * types[TYPE_ARRAY_LENGTH]= {"application", "audio", "example", "font", "image", "message", "model", "multipart", "text", "video"};

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

char ** divideMediaType(char * mediaType)
{
  char * nextToken;
  char ** dictionary= malloc(INITIAL_DICTIONARY_SIZE);

  if(mediaType==NULL)
  {
      dictionary[0]=NULL;
      return dictionary;
  }

  char * copy=strdup(mediaType);
  char * tofree=copy;

  int i=0, size=INITIAL_DICTIONARY_SIZE;

  while((nextToken = strsep(&copy, "/")))
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
