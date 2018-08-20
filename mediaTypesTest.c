#include "mediaTypesTest.h"


int main(int argc, char ** args)
{
  testAudioBelongsToTypes();
  testTrashDoesNotBelongToTypes();
  testCapitalizedTypeBelongsToTypes();
  testSplitOfNull();
  testSplitOfSplittingString();
  testSplitOfNonSplittingString();
  testSplitOfDelimeterString();
  return 0;
}

void testSplitOfDelimeterString()
{
  printf("Entering split of delimeter string test\n");
  givenADelimeterString();
  whenSplittingString();
  thenStringOneIsEqualToNull();
  freeSplitStrings();
}

void testSplitOfNonSplittingString()
{
  printf("Entering split of non splitting string test\n");
  givenANonSplittingString();
  whenSplittingString();
  thenStringOneIsEqualToNoSplit();
  thenStringTwoIsEqualToNull();
  freeSplitStrings();
}

void testSplitOfSplittingString()
{
  printf("Entering split of splitting string test\n");
  givenASplittingString();
  whenSplittingString();
  thenStringOneIsEqualToTest();
  thenStringTwoIsEqualToSplit();
  thenStringThreeIsEqualToNull();
  freeSplitStrings();
}

void givenADelimeterString()
{
  testString = "/////";
}

void givenANonSplittingString()
{
  testString = "nosplit";
}

void givenASplittingString()
{
  testString="test/split";
}

void thenStringOneIsEqualToTest()
{
  if(strcmp(testSplitStrings[0],"test")==0)
  {
    ok();
  }
  else
  {
    fail("Expected string equal to test, found different string");
  }
}

void thenStringOneIsEqualToNoSplit()
{
  if(strcmp(testSplitStrings[0],"nosplit")==0)
  {
    ok();
  }
  else
  {
    fail("Expected string equal to nosplit, found different string");
  }
}

void thenStringTwoIsEqualToSplit()
{
  if(strcmp(testSplitStrings[1],"split")==0)
  {
    ok();
  }
  else
  {
    fail("Expected string equal to split, found different string");
  }
}

void thenStringTwoIsEqualToNull()
{
  if(testSplitStrings[1]==NULL)
  {
    ok();
  }
  else
  {
    fail("Expected NULL string, found different string");
  }
}

void thenStringThreeIsEqualToNull()
{
  if(testSplitStrings[2]==NULL)
  {
    ok();
  }
  else
  {
    fail("Expected NULL string, found different string");
  }
}

void testSplitOfNull()
{
  printf("Entering split of null test\n");
  givenNullString();
  whenSplittingString();
  thenStringOneIsEqualToNull();
  freeSplitStrings();
}

void givenNullString()
{
  testString=NULL;
}

void whenSplittingString()
{
  testSplitStrings = divideMediaType(testString);
}

void thenStringOneIsEqualToNull()
{
  if(testSplitStrings[0]==NULL)
  {
    ok();
  }
  else
  {
    fail("Expected return value NULL, found different value");
  }
}

void freeSplitStrings()
{
  if(testSplitStrings==NULL){
    return;
  }
  int i=0;
  while((testSplitStrings[i])!=NULL)
  {
    free(testSplitStrings[i]);
    testSplitStrings[i]=NULL;
    i++;
  }
  free(testSplitStrings);
  testSplitStrings=NULL;
}


void testAudioBelongsToTypes()
{
  printf("Entering 'audio' belongs to types test\n");
  givenStringAudio();
  whenCheckingContainment();
  thenReturnedValueIsOne();
}

void testTrashDoesNotBelongToTypes()
{
  printf("Entering 'trash' does not belong to types test\n");
  givenStringTrash();
  whenCheckingContainment();
  thenReturnedValueIsZero();
}

void testCapitalizedTypeBelongsToTypes()
{
  printf("Entering 'AUDIO' belongs to types test\n");
  givenCapitalizedType();
  whenCheckingContainment();
  thenReturnedValueIsOne();
}

void givenStringTrash()
{
  testString="trash";
}

void givenStringAudio()
{
  testString="audio";
}

void givenCapitalizedType()
{
  testString="AUDIO";
}

void whenCheckingContainment()
{
  testReturnValue = isType(testString);
}

void thenReturnedValueIsZero()
{
  if(testReturnValue==0)
  {
    ok();
  }
  else
  {
    fail("Expected return value 0, found different value");
  }
}

void thenReturnedValueIsOne()
{
  if(testReturnValue==1)
  {
    ok();
  }
  else
  {
    fail("Expected return value 1, found different value");
  }
}
