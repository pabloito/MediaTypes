#include "mediaTypes.h"

char * types[TYPE_ARRAY_LENGTH]= {"application", "audio", "example", "font", "image", "message", "model", "multipart", "text", "video"};

void toLowerString(char * lowerCaseCopy, char * original)
{
  char c = *original;
  int i=0;
  while(c!=0)
  {
    *(lowerCaseCopy+i)=tolower(c);
    c=*(original+ ++i);
  }
  *(lowerCaseCopy+i)=0;
}

int isType(char * type)
{
  char * lowerCaseCopy = malloc(MAX_TYPE_SIZE);
  toLowerString(lowerCaseCopy, type);
  for(int i=0; i<TYPE_ARRAY_LENGTH;i++)
  {
      if(!strcmp(lowerCaseCopy,types[i]))
      {
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
  if(i>=size)
  {
    size+=1;
    dictionary=realloc(dictionary,size);
  }
  dictionary[i]=NULL;
  return dictionary;
}
