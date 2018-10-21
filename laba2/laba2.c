#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int NPoints=100;
const int error=-1;
const int length1=20;
const int length2=30;
const int length3=50;
const int maxI=1000;
const int maxU=1000;
const float square=1.06;
const double delta_U=0.6;
const double delta_I=0.05;
const double MinValue=0.0;
const double MaxValue = 100.0;
const double Tolerance = 3e-8;
const char cherta[]="_____________________________________________________________________________________________________________________\n";
int CheckSum=666;
//Функции
int ReadData(double I[],double U[], char DataFileName[]); 	 //reading data from file
int CalculateData(double I[],double U[],double R[],double r[],int line);		//calculating values
int CalculateError(double I[],double U[],double R[],double r[],int line, double sigma[],int length);		//calculating error
int WriteData(double I[],double U[],double R[],double r[],int line, double sigma[],char ResultFileName[]);		//writing data in file
void myfunction_free(void **I,void **U,void **R,void **r);
int Check_array(double arr[]);
int CheckTolerance(double value);
/*____________________________________________________________________________*/
int main()
{
	printf ("#Laba 1.1.1 \n"
          "#(c) Yuri Tolstov\n\n");
	char DataFileName[]="data1.txt";
	char ResultFileName[]="result.txt";
	double* I=NULL; double* U=NULL;
	double* R=NULL; double* r=NULL;
	if (!(I=(double*) calloc(NPoints,sizeof(double))))
 		{
			printf("Unable to create array I\n");
			return error;
		}
	I[0]=CheckSum; I[NPoints]=CheckSum;//ставлю в первый и последний элементы массива число 666,
	if (!(U=(double*) calloc(NPoints,sizeof(double))))
 		{
	 		printf("Unable to create array U\n");
	 		return error;
 		}
	U[0]=CheckSum; U[NPoints]=CheckSum;//чтобы можно было проверить, не вышел ли массив
	if (!(R=(double*) calloc(NPoints,sizeof(double))))
 		{
	 		printf("Unable to create array R\n");
	 		return error;
 		}
	R[0]=CheckSum; R[NPoints]=CheckSum;//за свои пределы, т.е не изменилось ли число 666
	if (!(r=(double*) calloc(NPoints,sizeof(double))))
 		{
			printf("Unable to create array r\n");
			return error;
		}
	r[0]=CheckSum; r[NPoints]=CheckSum;
	double sigma[3]={0,0,0};

	int line=ReadData(U,I,DataFileName);
	if (line<=0)
		{
			printf("@laba:%s\n", "\x1b[31mRead data function error\x1B[0;0;0m");
			return error;
		}
 	else printf("@laba:Data read...\n");

	if (0==CalculateData(I,U,R,r,line))
	 printf("@laba:Data calculated...\n");
	else
		{
			printf("%s\n", "\x1b[31m@laba:Calculating data function error!\x1B[0;0;0m");
			return error;
		}

	if (0==CalculateError(I,U,R,r,line,sigma,length1))
	 	printf("@laba:Data error for length1 calculated...\n");
 	else
		{
			printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");
			return error;
		}
	if (0==CalculateError(I,U,R,r,line,sigma,length2))
		printf("@laba:Data error for length2 calculated...\n");
	else
		{
			printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");
			return error;
		}
	if (0==CalculateError(I,U,R,r,line,sigma,length3))
		printf("@laba:Data error for length3 calculated...\n");
 	else
		{
			printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");
			return error;
		}
	if(0==WriteData(I,U,R,r,line,sigma,ResultFileName))
		printf("@laba:Results wrote...\n@laba:%s\n", "\x1b[32mLaba 1.1.1 successfully calculated!\x1B[0;0;0m");
	else printf("@laba:%s\n", "\x1b[31mLaba 1.1.1 calculating error!\x1B[0;0;0m");

	myfunction_free(&I,&U,&R,&r);
}
/*_______________________________________________________________________________________________________________________________*/

int ReadData(double I[],double U[], char DataFileName[])
{
	FILE* data = fopen(DataFileName, "r");			/*Reading data from data.txt*/
	if (!data)
		{
			printf("@laba:Cannot open data1.txt\n");
			return error;
		}

	int line=0;
	for (;;)
		{
			line++;
			if (fscanf(data,"%lg %lg",&U[line],&I[line])==EOF) break;
			if (U[line]<=0 || U[line]>maxU)
				{
					printf("Error U=%lg in line %d\n", I[line], line);
					if (CheckTolerance(*U+line)!=0) return error;
					return error;
				}
			if (I[line]<=0 || I[line]>maxI)
			 	{
					printf("Error I=%lg in line %d\n", U[line], line);
					if (CheckTolerance(*U+line)!=0) return error;
					return error;
				}
		}
	if (Check_array(I)!=0)
		{
			printf("I array is damaged\n");
			return error;
		}
	if (Check_array(U)!=0)
		{
			printf("U array is damaged\n");
			return error;
		}
	fclose(data);
	return line;
}

/*_______________________________________________________________________________________________________________________________*/

int CalculateData(double I[],double U[],double R[],double r[],int line)
{
	int number=0, length=0;
	for (number=1;number<line;number++)
		{
			if (number<=line/3) length=length1;
			if (number>line/3 && number<=24) length=length2;
			if (number>line*2/3 && number<=line) length=length3;
			R[number]=U[number]/I[number];
			r[number]=U[number]*square / (I[number]*length);
		}
	if (Check_array(R)!=0)
		{
			printf("R array is damaged\n");
			return error;
		}
	if (Check_array(r)!=0)
		{
			printf("r array is damaged\n");
			return error;
		}
			return 0;
}
/*_______________________________________________________________________________________________________________________________*/

int CalculateError(double I[],double U[],double R[],double r[],int line, double sigma[],int length)
{
	int number=0;
	int gap=0;
	int sigmanum=0;
	double Umax=0;	double Imax=0;
	double sum_U=0;	double sum_I=0;
	double sum_UI=0;double sum_Isq=0;
	double sum_Usq=0;
	if (length==20)
		{number=1;gap=12;sigmanum=0;}
	if (length==30)
		{number=13;gap=24;sigmanum=1;}
	if (length==50)
		{number=25;gap=36;sigmanum=2;}
	for (number;number<gap;number++)
		{
			if (U[number]>=Umax)
				Umax=U[number];
			if (I[number]>=Imax)
			 	Imax=I[number];
			sum_Usq = sum_Usq + U[number]*U[number];
			sum_Isq = sum_Isq + I[number]*I[number];
			sum_UI = sum_UI + U[number]*I[number];
		}
								//sq=square a*a
	double average_Isq = sum_Isq / (12);	double average_Usq = sum_Usq / (12);
	double average_UI = sum_UI / (12);		double average_R = average_UI / average_Isq;
	double sigma_rand = sqrt(average_Usq /average_Isq - average_R*average_R)/sqrt(12);
	double sigma_system = sqrt((delta_U/Umax)*(delta_U/Umax)+(delta_I/Imax)*(delta_I/Imax));
	sigma[sigmanum]=sqrt((sigma_rand*sigma_rand) + (sigma_system*sigma_system));
	return 0;
}
	/*_______________________________________________________________________________________________________________________________*/


int WriteData(double I[],double U[],double R[],double r[],int line, double sigma[],char ResultFileName[])
{
	FILE* result = fopen(ResultFileName, "w"); 			/*Whriting results to result.txt*/
	int Nsigma=0;
	for (int number=1;number<line;number++)
		{
			if (number==line) break;
			if (number==1)
				{
					fprintf(result,"%s\tLength of wire: %d cm\n%s",cherta,length1,cherta);
					Nsigma=0;
				}
			if (number==13)
				{
					fprintf(result,"%s\tLength of wire: %d cm\n%s",cherta,length2,cherta);
					Nsigma=1;
				}
			if (number==25)
				{
					fprintf(result,"%s\tLength of wire: %d cm\n%s",cherta,length3,cherta);
					Nsigma=2;
				}
			fprintf(result,"%d.\t I=%4.4lg\tA \t  U=%4.4lg\tV \t R=%4.4lg(+-)\t%4.4lg\tOm\t r=%4.4lg*10^-4\tOm*cm\n",number,U[number],I[number],R[number],sigma[Nsigma],r[number]);
		}
return	0;
	}
/*_______________________________________________________________________________________________________________________________*/
void myfunction_free(void **I,void **U,void **R,void **r)
{
	free(*I); *I=NULL;
	free(*U); *U=NULL;
	free(*R); *R=NULL;
	free(*r); *r=NULL;
}
/*_______________________________________________________________________________________________________________________________*/
int Check_array(double arr[])
{
	if ( arr[0]==CheckSum && arr[NPoints]==CheckSum) return 0;
	else return error;
}

int CheckTolerance(double value)
{
	if (value > MinValue - Tolerance && value < MaxValue - Tolerance)
		if (fabs(value) > Tolerance)
			return 0;
	return error;
}
