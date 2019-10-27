//Main.c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.c"
#include "Main.h"


int compareInts(void *p1, void *p2)
{
   int i1 = *(int*)p1;
   int i2 = *(int*)p2;
   return i1 - i2 ;
}


int compareDoubles(void *p1, void *p2)
{
   double d1 = *(double*)p1;
   double d2 = *(double*)p2;
    return (d1<d2) ? -1 : ((d1>d2) ? 1 : 0); // "?:" Conditional -(Right to left) - If Condition is true ? then value X : otherwise value Y
}


int compareStrings(void *p1, void *p2)
{
   char *s1= p1;
   char *s2= p2;
   return strcmp(s1, s2);
}


//destructor functions

void destroyBasicTypeAlloc(void *p)
{
   //for pointers to basic data type
   //use for allocated memory
   free(p);
}


void destroyBasicTypeNoAlloc(void *p)
{
    //use for memory that has not been allocated
    return;
}

void printListFromIterator(SortedListIteratorPtr slip)
{
   int* iterData;
   for(iterData =(int*)SLGetItem(slip);
	     iterData != NULL;
	     iterData = (int*)SLNextItem(slip))
             {
             printf("%d -> ", *iterData);
             }
   printf("\n");
}

//Helper Functions to print out an int list without having to use iterators

void printIntList(SortedListPtr list)
{
  if(list==NULL)
    {
      return;
    }
  NodePtr ptr = NULL;

  for(ptr = list -> front; ptr != NULL; ptr = ptr->next)
    {
      printf("%d->", *(int*)ptr->data);
    }
  printf("\n");
}
//Helper Function to print out a double list without having to use iterators

void printDoubleList(SortedListPtr list)  
{
  if (list == NULL)
    {
      return;
    }
  NodePtr ptr = NULL;
  for(ptr = list-> front; ptr != NULL; ptr = ptr->next)
    {
      printf("%f->", *(double*)ptr->data);
    }
  printf("\n");
 }
 //Helper Functions to print out char list without a char list without having to use iterator

void printCharList(SortedListPtr list)
{
  if (list==NULL)
    {
      return;
    }
  NodePtr ptr = NULL;
  for(ptr = list->front; ptr != NULL; ptr = ptr->next)
    {
      printf("%c->", *(char*)ptr->data);
    }
  printf("\n");
}
		     
		     
//************ MAIN ****************

int main(int argc,char **argv)
{
  int choice, quit = 0;
  while (!quit)//not quit
    {
      printf("Please enter a test case number 1-3, or -1 to quit.\n");
      scanf("%d", &choice);


      switch(choice)
	{
	case 1:
	  printf("Comparing Ints.\n");
	  printf("Input is: 10,9,8,7,6\n");

	  int a = 10;
	  int b = 9;
	  int c = 8;
	  int d = 7;
	  int e = 6;


	  SortedListPtr slpInt = SLCreate(compareInts, destroyBasicTypeNoAlloc);
	  SLInsert(slpInt,(void*)&a);
	  SLInsert(slpInt,(void*)&b);
	  SLInsert(slpInt,(void*)&c);
	  SLInsert(slpInt,(void*)&d);
	  SLInsert(slpInt,(void*)&e);


	  printf("Expected output:10, 9, 8 , 7 , 6 \n");
	  printIntList(slpInt);
	  SLDestroy(slpInt);
	  break;

	case 2:
	  printf("comparing doubles.\n");
	  printf("Input is : 22.1, 25, 34.3455, 3.3, 3.14299\n");

	  double f = 22.1;
	  double g = 25;
	  double h = 34.3455;
	  double i = 3.3;
	  double j = 3.14299;


	  SortedListPtr slpDouble= SLCreate(compareDoubles, destroyBasicTypeNoAlloc);
	  SLInsert(slpDouble,(void*)&f);
	  SLInsert(slpDouble,(void*)&g);
	  SLInsert(slpDouble,(void*)&h);
	  SLInsert(slpDouble,(void*)&i);
	  SLInsert(slpDouble,(void*)&j);

	  printf("Expected output: 34.3455, 25, 22.1, 3.3, 3.14299\n");
	  printDoubleList(slpDouble);
	  SLDestroy(slpDouble);
	  break;

       case 3:
	  printf("Comparing Strings.\n");
	  printf("Input is: test, zero, hello, alpha, fun\n");

	  char *k = "test";
	  char *l = "zero";
	  char *m = "hello";
	  char *n = "alpha";
	  char *o = "fun";


	  SortedListPtr slp= SLCreate(compareStrings, destroyBasicTypeNoAlloc);

	  SLInsert(slp,(void*)&k);
	  SLInsert(slp,(void*)&l);
	  SLInsert(slp,(void*)&m);
	  SLInsert(slp,(void*)&n);
	  SLInsert(slp,(void*)&o);

	  printf("Expected output: zero, test, hello, fun, alpha");
	  printf("Result:zero, test, hello, fun, alpha");
	  SLDestroy(slp);
	  break;


      case -1:
	   quit = 1;
	   break;


       default:
	   printf("Error, Bad input.\n");

	}
    }
}
