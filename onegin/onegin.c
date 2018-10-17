#include <stdio.h>
#include <string.h>
#include <math.h>

int const max_lenth=1024;
const int error=-1;

int ReadText();
int SortText();
int PrintText();

int main()
{
  printf ("#Onegin sorting \n"
          "#(c) Yuri Tolstov\n\n");
  ReadText();
  SortText();
  PrintText();
}

  /*_______________________________________________________________________________________________________________________________*/

  int ReadText()
  	{
  	FILE* text_old = fopen("onegin.txt", "r");			/*Reading data from onegin.txt*/
  	if (!text_old) {printf("@laba:Cannot open onegin.txt");return error;}

  	int line=0;
  	for (;;)
  		{
  			line++;
      }
  			fclose(text_old);
  	return line;
  	}

  /*_______________________________________________________________________________________________________________________________*/

int sort_v1()
{
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
