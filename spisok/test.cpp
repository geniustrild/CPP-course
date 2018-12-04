#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* letter1,const void* letter2);

int main ()
{
  char str[1000];
  scanf("%[^.]", str);
  qsort(str[1000], 1000, sizeof(char), compare);
  printf("%s\n", str);
}

int compare(const void* letter1,const void* letter2)
{
  return ((char) letter1) - ((char) letter2);
}
