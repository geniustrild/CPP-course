#include <stdio.h>

int const max_lenth=1024;
int const max_lines=2048;


int main()
{
char poem[max_lines][max_lenth]={""};
PrintText(char poem[max_lines][max_lenth]);
}

/*char read_poem()
{


}*/

void PrintText (char poem[max_lines][max_lenth]) //можно не писать max_lines
   {
     FILE* text = fopen(text,"text.txt", "r");
     for (int i=0;i< ;i++)
     {
       fgets(&poem[i],max_lenth-1,file); //или fgets(poem+i,max_lenth-1)
           printf("%s\n", poem[i]);
     }


     for (int i=0;i < ; i++)
     {
      puts(poem[i]);

      //for (int j=0;poem[i][j];j++)
      //  putchar(poem[i][j]);
     }
  }

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
