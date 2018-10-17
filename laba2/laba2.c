#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DATA_FILE_NAME "data1.txt"
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

int ReadData(); 	 //reading data from file
int CalculateData();		//calculating values
double CalculateError();		//calculating error
int WriteData();		//writing data in file
void myfunctions_free();

int main()
{
	printf ("#Laba 1.1.1 \n"
          "#(c) Yuri Tolstov\n\n");
	double sigma[3]={0,0,0};

double* I=(double*) calloc(NPoints,sizeof(double));
double* U=(double*) calloc(NPoints,sizeof(double));
double *R=(double*) calloc(NPoints,sizeof(double));
double *r=(double*) calloc(NPoints,sizeof(double));

	int line=ReadData(U,I);
	if (line<=0){printf("@laba:%s\n", "\x1b[31mRead data function error\x1B[0;0;0m");return error;} else printf("@laba:Data read...\n");
	if (0==CalculateData(I,U,R,r,line)) printf("@laba:Data calculated...\n"); else {printf("%s\n", "\x1b[31m@laba:Calculating data function error!\x1B[0;0;0m");return error;}
	if (0==CalculateError(I,U,R,r,line,sigma,length1)) printf("@laba:Data errors calculated...\n"); else {printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");return error;}
	if (0==CalculateError(I,U,R,r,line,sigma,length2)) printf("@laba:Data errors calculated...\n"); else {printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");return error;}
	if (0==CalculateError(I,U,R,r,line,sigma,length3)) printf("@laba:Data errors calculated...\n"); else {printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");return error;}
	(0==WriteData(I,U,R,r,line,sigma))? printf("@laba:Results wrote...\n@laba:%s\n", "\x1b[32mLaba 1.1.1 successfully calculated!\x1B[0;0;0m") :printf("@laba:%s\n", "\x1b[31mLaba 1.1.1 calculating error!\x1B[0;0;0m");
	myfunctions_free(I,U,R,r);
}
/*_______________________________________________________________________________________________________________________________*/

int ReadData(double I[],double U[])
	{
	FILE* data = fopen(DATA_FILE_NAME, "r");			/*Reading data from data.txt*/
	if (!data) {printf("@laba:Cannot open data1.txt");return error;}

	int line=0;
	for (;;)
		{
			line++;
			if (fscanf(data,"%lg %lg",&U[line],&I[line])==EOF) break;
			if (U[line]<=0 || U[line]>maxU) {printf("Error U=%lg in line %d\n", I[line], line); return error;}
			if (I[line]<=0 || I[line]>maxI) {printf("Error I=%lg in line %d\n", U[line], line); return error;}
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
			return 0;
	}
	/*_______________________________________________________________________________________________________________________________*/

	double CalculateError(double I[],double U[],double R[],double r[],int line, double sigma[],int length)
		{
			int number=0;
			int gap=0;
			int sigmanum=0;
			double Umax=0;	double Imax=0;
			double sum_U=0;	double sum_I=0;
			double sum_UI=0;double sum_Isq=0;
			double sum_Usq=0;
			if (length==20) {number=1;gap=12;sigmanum=0;}
			if (length==30) {number=13;gap=24;sigmanum=1;}
			if (length==50)	{number=25;gap=36;sigmanum=2;}
			for (number;number<gap;number++)
				{
							if (U[number]>=Umax) Umax=U[number];
							if (I[number]>=Imax) Imax=I[number];
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


int WriteData(double I[],double U[],double R[],double r[],int line, double sigma[])
	{
		FILE* result = fopen("result.txt", "w"); 			/*Whriting results to result.txt*/
		int Nsigma=0;
		for (int number=1;number<line;number++)
			{
				if (number==line) break;
				if (number==1) {fprintf(result,"_____________________________________________________________________________________________________________________\n\tLength of wire: %d cm\n_____________________________________________________________________________________________________________________\n",length1); Nsigma=0;}
				if (number==13) {fprintf(result,"_____________________________________________________________________________________________________________________\n\tLength of wire: %d cm\n_____________________________________________________________________________________________________________________\n",length2); Nsigma=1;}
				if (number==25) {fprintf(result,"_____________________________________________________________________________________________________________________\n\tLength of wire: %d cm\n_____________________________________________________________________________________________________________________\n",length3); Nsigma=2;}
				fprintf(result,"%d.\t I=%4.4lg\tA \t  U=%4.4lg\tV \t R=%4.4lg(+-)\t%4.4lg\tOm\t r=%4.4lg*10^-4\tOm*cm\n",number,U[number],I[number],R[number],sigma[Nsigma],r[number]);
			}
	return	0;

}

/*_______________________________________________________________________________________________________________________________*/
void myfunctions_free(double I[],double U[],double R[],double r[])
{
	free(I); I=NULL;
	free(U); U=NULL;
	free(R); R=NULL;
	free(r); r=NULL;
}
