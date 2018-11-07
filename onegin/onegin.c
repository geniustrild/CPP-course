#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int const max_lenth=1024;
const int error=-1;
const int empty=-2;

char *buf=NULL;
int *StringNum=NULL;
struct kotak* text=NULL;


int ReadText(char DataFileName[]);
int CountAndChange(char* buf, int size);
int SortText(char* buf, struct kotak* text, int NStrings );
int CompareStrings(const void* , const void* );
int CustomEncoding(char c);
int PrintText(int NStrings);



//_______________________________________________________________________
struct kotak
  {
    char* string_ptr;
    int StringLen;
  } *text;

struct kotak poem;
//_______________________________________________________________________


int main()
{
  printf ("#Onegin sorting \n"
          "#(c) Yuri Tolstov\n\n");
  char DataFileName[]="onegin1.txt";
  int size=ReadText(DataFileName);
  if (size==error)
    {
      printf("ERROR in ReadText function\n");
      return error;
    }
  printf("Function ReadText completed!\n");
  int NStrings=CountAndChange(buf,size);
  if (NStrings==error)
    {
      printf("ERROR in CountAndChange function\n");
      return error;
    }

  PrintText(NStrings);printf("_______________________________________________________________________\n");

  printf("!!%d\n",CompareStrings(StringNum, StringNum + 1) );
  qsort(text, NStrings, sizeof(int), CompareStrings);
  PrintText(NStrings);
  free(buf);
  free(text);
}

  /*_______________________________________________________________________________________________________________________________*/

int ReadText(char DataFileName[])
	{
	FILE* text_old = fopen(DataFileName, "r");			/*Reading data from onegin.txt*/
	if (!text_old)
    {
      printf("@laba:Cannot open onegin.txt file\n");
      return error;
    }

  fseek(text_old,0,SEEK_END);
  int size=0;
  if((size=ftell(text_old))==-1L)
    printf("A file error has occurred.\n");

  fseek(text_old,0,SEEK_SET);
  if (!(buf = (char*) calloc(size+1,sizeof(char))))
  {
    printf("Unable to create array buf\n");
    return error;
  }
  //fread("êóäà","Ğàçìåğ ıëåìåíòà","ğàçìåğ","ôàéë");
  if (fread(buf,sizeof(char),size,text_old)==0)
    {
      printf("Reading error\n");
      return error;
    }
  buf[size + 1] = '\n';

	int line=0;
		fclose(text_old);
	return size;
	}
  /*_______________________________________________________________________________________________________________________________*/

int CountAndChange(char buf[], int  size)
  {
    int NStrings=0, pos = 0;
    for(pos = 0; pos <= size; pos++)
      {
        if (buf[pos]=='\n')
          {
            buf[pos]='\0';
            NStrings++;
          }
      }

    if (!(text = (struct kotak*) calloc(NStrings, sizeof(struct kotak))))
      {
        printf("Unable to create array text\n");
        return error;
      }
    int CountStrings = 0, StringLen=0;
    if (!(StringNum=(int*) calloc(NStrings+2,sizeof(int))))
   		{
  			printf("Unable to create array StringNum\n");
  			return error;
      }
    text[0].string_ptr=buf;
    for (pos=0; pos <= size; pos++)
      {
      if (buf[pos] == '\0')
        {
          text[CountStrings].StringLen=StringLen;
          text[CountStrings+1].string_ptr=buf + pos + 1;
          StringNum[CountStrings]=CountStrings;
          CountStrings++;
          StringLen=0;
          continue;
        }
      StringLen++;
      }
    for (int i = 0; i < NStrings; i++)
      {
        StringNum[i] = i;
      }
    return NStrings-1;
  }
/*_______________________________________________________________________*/
int PrintText(int NStrings)
  {
      printf("\n");
    for(int string = 0; string <= NStrings; string++)
      {
        printf("%d\t", string);
        printf("%s\t\t%d\n", text[string].string_ptr, StringNum[string]);
      }

  }

/*_______________________________________________________________________*/
int CompareStrings(const void* VoidStructNumber1, const void* VoidStructNumber2)
  {
  int StringNumber1 = *(int*)VoidStructNumber1;
  int StringNumber2 = *(int*)VoidStructNumber2;
  struct kotak* obj1_ptr = (struct kotak*)VoidStructNumber1;
  obj1_ptr->string_ptr;
  struct kotak* obj2_ptr = (struct kotak*)VoidStructNumber2;
  obj2_ptr->string_ptr;
  printf("%s\t%s\n",text[StringNumber1].string_ptr, text[StringNumber2].string_ptr);
  int count1 = 0;
  int count2 = 0;
  for(;;)
    {
      for (;;)
        {
          if (empty == CustomEncoding(text[StringNumber1].string_ptr[count1]))
            {
              text[StringNumber1].string_ptr[count1++];
            }
          else break;
        }
      for (;;)
        {
          if (empty == CustomEncoding(text[StringNumber2].string_ptr[count2]))
            {
              text[StringNumber2].string_ptr[count2++];
            }
          else break;
        }
        printf("%c ", text[StringNumber1].string_ptr[count1]);

      if (CustomEncoding(text[StringNumber1].string_ptr[count1]) != CustomEncoding(text[StringNumber2].string_ptr[count2]))
        return CustomEncoding(text[StringNumber2].string_ptr[count2]) - CustomEncoding(text[StringNumber2].string_ptr[count1]);
      text[StringNumber1].string_ptr[count1++];
      text[StringNumber2].string_ptr[count2++];
    }
    if (count1 == 0 && count2 == 0)
      {
        return (text[StringNumber2].StringLen - text[StringNumber1].StringLen);
      }
  }
/*_______________________________________________________________________*/
int CustomEncoding(char c)
  {
    int number = 0;
    //char alph[]="ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    char alph[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for ( number = 0; number<66; number++)
      {
        if (alph[number]==c)
        {
          return number+1;
        }
      }
    return empty;
  }
