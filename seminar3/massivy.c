#include<stdio.h>

void swap_array(int data1[], int data2[],const int size);


int main()
	{
	const int size=3;
	int data[size]={0};
	data[0]=0;
	data[1]=0;
	data[2]=0;
//	...	
//или
	for(int i=0;i<size;i++)
		data[i]=0;
// можно функция memset	и bzero
	
	data[2]+=13;
	*(data+2)+=13;
//тип переменной data int* 

	swap(&data1[i],data2+i);
// &data[i] = data+i идентичный код

int *data[size]={};
type(data)=int** //^для этой строки
	
int a0=0;
data[0]=&0;

int a1=0;
data[1]=&0;

int a2=0;
data[2]=&0;
// ...






}

void swap_array(int data1[], int data2[],const int size)
{
	for (int i=0; i<size;i++)
		{
		int  buf=data[i];
		data1[i]=data2[i];
		data2[i]=buf;
		}

}
