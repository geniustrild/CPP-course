#include<stdio.h>
#include<string.h>

int main()
	{
	|char|=1;
	
	'я'=255;
	'A'=65;
	'0'=48;
	' '=32 //пробел
	'\n'=10||13
	'5'=48+5='0'+5;
	printf("%c\n",'a'); //вывод буквы а
	printf("%d"\n,'a'); //вывод кодировки буквы а

	type('a')=char;
	
	printf("%s\n","a");
	
	strlen(str); //возвращает длинну строки
	strcat(str1,str2);//склеивает строки
	
// %s ждет тип char*
        '\0'=0
	str[0];		
	}

void PrintReverse(const char*str)
	{
	int len=0;
	for(;;)
		{
		if(str[i]!='\0')
			len++;
		else break;	
		}
// аналогичный способ задания цикла
	for(len;str[len];len++);
	}


