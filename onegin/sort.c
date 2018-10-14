#include <stdio.h>
#include <string.h>

int const max_lenth=1024;
int const max_lines=2048;
const int size=10;

int main()
{
srand(time(0));
int data[size];
  for (int n=0;n<size-1;n++)
  {
    for (int i=0;i<size-1;i++)
    {
      if (data[i]>data[i+1])
      {
        int temp=data[i];
                data[i]=data[i+1];
                        data[i+1]=temp;
      }
    }
  }
}
