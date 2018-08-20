#ifndef MEDIA_TYPES_TEST_H
#define MEDIA_TYPES_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "testLib.h"
#include "mediaTypes.h"

char ** testSplitStrings;
char * testString;
int testReturnValue;

void testAudioBelongsToTypes();
void testTrashDoesNotBelongToTypes();
void testCapitalizedTypeBelongsToTypes();
void testSplitOfNull();
void testSplitOfSplittingString();
void testSplitOfNonSplittingString();
void givenStringAudio();
void givenStringTrash();
void givenCapitalizedType();
void whenCheckingContainment();
void thenReturnedValueIsOne();
void thenReturnedValueIsZero();

void givenASplittingString();
void whenSplittingString();
void thenStringOneIsEqualToTest();
void thenStringTwoIsEqualToSplit();
void thenStringThreeIsEqualToNull();

void givenANonSplittingString();
void thenStringOneIsEqualToNoSplit();
void thenStringTwoIsEqualToNull();

void givenNullString();
void thenStringOneIsEqualToNull();

void freeSplitStrings();

#endif
