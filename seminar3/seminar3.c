#include<stdio.h>

int GetInt()
	{
	int val=0;
	do {
	 	printf("Enter value:");
		if (scanf("%d",&val)==1 && 1<=val && val<=10)break;
		scanf("%*[^\n]");
		printf("Tyi toopoyi, bistrejj\n");
	   }	
	   while ("true");
	return val;
	}


int GetStr()
	{
//	char* str=(char*) calloc(100,sizeof(char));	
	
	//static int counter=0; 
	char str[100]="";
	do {
	 	printf("Enter value:");
		scanf("%.*s",sizeof(str)-1,str);
		fgets(str,sizeof(str)-1,stdin);

	//фильтр нехороших слов
		
	   }	
	   while ("true");
	return str;
	}



int main()
	{
	GetInt();
//	char* str=GetStr();
//	printf("%s",str);	
//	char str[]="";
//	strcpy(str,GetStr());

//	char* s=GetStr();
//	free(s);
		
	
	}
//написать все версии программы (даже с ошибками)






