#include <stdio.h>
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

#include "function.c"
