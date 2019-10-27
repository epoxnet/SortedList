//Main.h
#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>

int compareInts(void *p1, void *p2);

int compareDoubles(void *p1, void *p2);

int compareStrings(void *p1, void *p2);

void destroyBasicTypeAlloc(void *P);

void printListFromIterator(SortedListIteratorPtr slip);

void printIntList(SortedListPtr list);

void printDoubleList(SortedListPtr list);

void printCharList(SortedListPtr list);

int main(int argc,char **argv);

#endif //MAIN_H


