#include<stdio.h>


int count();
int main()
	{
	printf ("#Laba 1.1.1 \n"
                "#(c) Yuri Tolstov\n\n");
	int result=count();
	return(result!=0)? printf("result saved %d\n",result):printf("Error count function\n");	
	}
/*_______________________________________________________________________________________________________________________________*/
int count()	/*Функция с рассчетами*/
	{
	FILE* data=fopen("data.txt","r");	/*Чтение данных из файла data.txt*/
	FILE* result=fopen("result.txt","w");	/*Запись данных в файл result.txt*/
	double u=0,i=0,ro=1,counter=0;		/*Ввод необходиных переменных*/
	const int l1=20,l2=30,l3=50,s=1.06;	/*Ввод необходиных констант*/
	while (!feof(data)) 
		{
		counter +=1;
		int nitems=fscanf(data,"%lf %lf",&u,&i);
		if (u<=0 || u>1000)	/*Если данные U из файла превышают заданные границы или меньше или равны 0*/
			{                                                    
			printf("Error U=%4.0f in line %2.0f\n",u,counter);	/*Возврат номера строчки с ошибкой*/
			break;	
			}
		if (i<=0 || i>1000)	/*Если данные I из файла превышают заданные границы или меньше или равны 0*/
			{
			printf("Error I=%4.2f in line %2.0f\n",i,counter);	/*Возврат номера строчки с ошибкой*/
			break;
			}
		if  (counter<=12)
			{
			ro=u*s/(i*l1);		/*Рассчет ro для длины l1*/
			printf("%f	%f	%f\n",u,i,ro);
			fprintf(result,"ro=%4.4f*10^-4 Om*sm\n",ro);	
			}
		if  (counter>12 & counter<24)
			{
			ro=u*s/(i*l2);		/*Рассчет ro для длины l2*/
			printf("%f	%f	%f\n",u,i,ro);
			fprintf(result,"ro=%4.4f*10^-4 Om*sm\n",ro);
			}
		if  (counter>24 & counter<=36)
			{
			ro=u*s/(i*l3);		/*Рассчет ro для длины l3*/
			printf("%f	%f	%f\n",u,i,ro);
			fprintf(result,"ro=%4.4f*10^-4 Om*sm\n",ro);	
			}
		
		}
	
	
	}
/*_______________________________________________________________________________________________________________________________*/









