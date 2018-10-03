#include<stdio.h>


int count();
int main()
{
	printf ("#Laba 1.1.1 \n"
                "#(c) Yuri Tolstov\n\n");
	int result=count();
	return(result==0)? printf("result saved \n"): printf("Error count function\n");	
}
/*_______________________________________________________________________________________________________________________________*/
int count()	/*function count*/
{
	FILE* data = fopen("data.txt", "r");		/*Reading data from data.txt*/
	FILE* result = fopen("result.txt", "w");	/*Whriting results to result.txt*/
	double u=0, i=0, ro=0;				/*Input variables*/
	int counter=0;		
	const int length1=20, length2=30, length3=50;	/*Input const*/
	const float square=1.06;	
	while (!feof(data)) 
	{
		counter +=1;
		int nitems = fscanf(data, "%lf %lf",&u,&i);
		if (u<=0 || u>1000)
		{                                                    
			printf("Error U=%4.0f in line %d\n", u, counter);
			break;	
		}
		if (i<=0 || i>1000)	
		{			
			printf("Error I=%4.2f in line %d\n", i, counter);
			break;
		}
		if  (counter <= 12)
		{
			if(counter == 1) 
			{			
				fprintf(result, "  Length of wire:%d\n", length1);
			}
			ro = u*square / (i*length1);		/*Counting for length1*/
			fprintf(result, "%d. ro=%4.4f*10^-4 Om*cm\n", counter, ro);	
		}
		if  (counter > 12 & counter < 24)
		{
			if(counter == 13) 
			{			
				fprintf(result,"  Length of wire:%d\n", length2);
			}
			ro = u*square / (i*length2);		/*Counting for length2*/
			fprintf(result,"%d. ro=%4.4f*10^-4 Om*cm\n", counter, ro);
		}
		if  (counter > 24 & counter <= 36)
		{
			if(counter == 25) 
			{			
				fprintf(result, "  Length of wire:%d\n", length3);
			}
			ro = u*square / (i*length3);		/*Counting for length3*/
			fprintf(result, "%d. ro=%4.4f*10^-4 Om*cm\n", counter, ro);	
		}	
	}
	fclose (data);	
	fclose (result);
}
/*_______________________________________________________________________________________________________________________________*/









