#include "function.h"
//_______________________________________________________________________

int main()
{
	char DataFileName[] = "onegin.txt";
	char ResultFileName[] = "sorted.txt";
	char* buf = NULL;
	int Lnumber = 0, NLines = 0;
	if ((Lnumber = ReadText(&buf, DataFileName)) == ERROR)
		{
			printf("\x1b[31m@SortMashine: Reading error\x1B[0;0;0m\n");
			return ERROR;
		}
	printf("@SortMashine: ReadText function completed...\n");
	language = CheckLanguage(buf);
	if (language == ERROR)
		{
			printf("\x1b[31m@SortMashine: Can't understand language\x1B[0;0;0m\n");
			return ERROR;
		}
  printf("@SortMashine: CheckLanguage function completed...\n");
	NLines = CountAndChange(buf, Lnumber);
	printf("@SortMashine: CountAndChange function completed...\n");
	char** text = calloc(NLines, sizeof(char*));
	if (text == NULL)
		{
			printf("\x1b[31m@SortMashine: Can't create array text\x1B[0;0;0m\n");
			return ERROR;
		}
	FillText(text, buf, Lnumber, NLines);
	printf("@SortMashine: FillText function completed...\n");
	qsort(text, NLines, sizeof(char*), CompareStrings);
	printf("@SortMashine: Sorting function completed...\n");
	PrintText(text, ResultFileName, NLines);
	printf("@SortMashine: PrintText function completed...\n");
	printf ("\x1b[32m@SortMashine: Text sorting completed! %d lines sorted!\n", NLines);
	MyFree(&buf, &text);
	return 0;
}
//_______________________________________________________________________
