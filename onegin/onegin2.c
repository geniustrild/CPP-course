#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

const int ERROR = -1;
const int RU_ALPH_SIZE=66;
const int EN_ALPH_SIZE=52;
const int checker = 20;
int language = 0;

int ReadText(char** buf_ptr, char read_file[]);
int CheckLanguage (char* buf);
int CalculateSize (FILE* read);
int CountAndChange(char* buf, int Lnumber);
void FillText (char** text, char* buf, int Lnumber, int NLines);
int CustomEncoding (char c, int language);
int CompareStrings (const void* ptr1, const void* ptr2);
int PrintText (char** text, char write_file[], int NLines);
void MyFree (char **buf, char ***text);

//-------------------------------------------------------------------------------------------------------------------------------------

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

int CalculateSize (FILE* read)
{
	fseek (read, 0, SEEK_END);
	int size = ftell(read);
	fseek (read, 0, SEEK_SET);
	return size;
}

//_______________________________________________________________________

int ReadText(char** buf_ptr, char DataFileName[])
{
	FILE* read = fopen(DataFileName, "r");
	if (!read) {printf("\x1b[31mCannot open %s.\n", DataFileName); return ERROR;}
	int size = CalculateSize(read);
	*buf_ptr = calloc(size+1, sizeof(char));
	if (*buf_ptr == NULL) {printf("\x1b[31mCan't create array.\x1B[0;0;0m\n"); return ERROR;}
	int Lnumber = fread (*buf_ptr, sizeof(char), size, read);
	*buf_ptr = realloc(*buf_ptr, (Lnumber+1)*sizeof(char));
	if (*buf_ptr == NULL) {printf("\x1b[31mCan't create array.\x1B[0;0;0m\n"); return ERROR;}
	(*buf_ptr)[Lnumber] = '\n';
	fclose(read);
	return Lnumber;
}

//_______________________________________________________________________

int CountAndChange(char* buf, int Lnumber)
{
	int NLines = 0;
	for (int i = 0; i <= Lnumber; ++i) {
		if (buf[i] == '\n') {
			++NLines;
			buf[i] = '\0';
			while (buf[i+1] <= Lnumber && buf[i+1] == '\n')
				++i;
		}
	}
	return NLines;
}

//_______________________________________________________________________

void FillText (char** text, char* buf, int Lnumber, int NLines)
{
	text[0] = &buf[0];
	int count = 1;
	for (int i = 0; i < Lnumber; ++i) {
		if (buf[i] == '\0') {
			while (buf[i+1] <= Lnumber && buf[i+1] == '\n')
				++i;
			text[count] = &buf[i+1];
			++count;
			if (count == NLines) break;
		}
	}
}

//_______________________________________________________________________

int CustomEncoding (char c ,int language)
{
	char ru_alph[] = {"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"};
	char en_alph[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	if (language == RU_ALPH_SIZE)
		{
			for (int i = 0; i <= RU_ALPH_SIZE; ++i)
				if (c == ru_alph[i])
					return i+1;
		}
	if (language == EN_ALPH_SIZE)
		{
			for (int i = 0; i <= EN_ALPH_SIZE; ++i)
				if (c == en_alph[i])
					return i+1;
		}

	return 0;
}

//_______________________________________________________________________

int CompareStrings (const void* ptr1,const void* ptr2)
{
	char* str1 = *((char**) ptr1);
	char* str2 = *((char**) ptr2);
	while ((*str1) != '\0' && (*str2) != '\0')
	{
		while (CustomEncoding(*str1,language) == 0) *str1++;
		while (CustomEncoding(*str2,language) == 0) *str2++;
		if (CustomEncoding(*str1,language) != CustomEncoding(*str2,language))
			return CustomEncoding(*str1,language) - CustomEncoding(*str2,language);
		*str1++;
		*str2++;
	}
	return ((*str1) == '\0') ? -1 : 1;
}

//_______________________________________________________________________

int PrintText (char** text, char ResultFileName[], int NLines)
{
	FILE* write = fopen(ResultFileName, "w");
	if (!write)
	 	{
			printf("Cannot open %s.\n", ResultFileName);
			return ERROR;
		}
	for (int i = 0; i < NLines; ++i)
		fprintf (write, "%s\n", text[i]);
	fclose(write);

	return 0;
}

///_______________________________________________________________________

void MyFree (char **buf, char ***text)
{
	free(*buf);
	*buf = NULL;
	free(*text);
	*text = NULL;
}

int CheckLanguage (char* buf)
	{
		srand(time(NULL));
		int ENcounter = 0;
		int RUcounter = 0;
		for (int i=0; i <= checker; i++)
			{
				if (CustomEncoding(buf[rand() % RU_ALPH_SIZE], RU_ALPH_SIZE) != 0)
						RUcounter++;

				if (CustomEncoding(buf[rand() % EN_ALPH_SIZE], EN_ALPH_SIZE) != 0)
						ENcounter++;
			}
		if (RUcounter == checker) return RU_ALPH_SIZE;
		if (ENcounter == checker) return EN_ALPH_SIZE;

		return EN_ALPH_SIZE;
	}
