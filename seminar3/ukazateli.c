#include<stdio.h>

int main()
	{
	int x=10;
//	sizeof(int)=4;
//	sizeof(int*)=4;
//	sizeof(любой указатель)=4;
//	sizeof(char)=1;
	x+=7;
// к названию переменной добавить _ptr (pointer)
	(int*) x_ptr=&x;
//* с типом = новый тип (указатель на старый тип)
//& -взятие адреса т е получает не число х а имя ячейки где она хранится	
	x_ptr-=5;//означает x_ptr=)xABC0-sizeof(int)*5	
	*x_ptr-=5;//означает x-5 т е обычное действие
//* с указателем= прохождение по указателю	
	int a=7,b=9;
	swap(&a,&b);
	printf("%d %d",a,b);	
	}

void swap(int *a_ptr, int *b_ptr)
	{
	int buf=*a_ptr;
	*a_ptr=*b_ptr;
	*b_ptr=buf;
	}

