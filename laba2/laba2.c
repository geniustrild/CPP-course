#include <stdio.h>
#include <string.h>
#include <math.h>

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

int main()
{
	printf ("#Laba 1.1.1 \n"
          "#(c) Yuri Tolstov\n\n");
	double I[NPoints], U[NPoints],R[NPoints],r[NPoints];
	memset(I,'0', NPoints);	memset(U,'0', NPoints);
	memset(R,'0', NPoints);	memset(r,'0', NPoints);
	double sigma[3]={0,0,0};
	int line=ReadData(I,U);
	if (line<=0){printf("@laba:%s\n", "\x1b[31mRead data function error\x1B[0;0;0m");return error;} else printf("@laba:Data read...\n");
	if (0==CalculateData(I,U,R,r,line)) printf("@laba:Data calculated...\n"); else {printf("%s\n", "\x1b[31m@laba:Calculating data function error!\x1B[0;0;0m");return error;}
	if (0==CalculateError(I,U,R,r,line,sigma)) printf("@laba:Data errors calculated...\n"); else {printf("%s\n", "\x1b[31mCalculating errors function error!\x1B[0;0;0m");return error;}
	(0==WriteData(I,U,R,r,line,sigma))? printf("@laba:Results wrote...\n@laba:%s\n", "\x1b[32mLaba 1.1.1 successfully calculated!\x1B[0;0;0m") :printf("@laba:%s\n", "\x1b[31mLaba 1.1.1 calculating error!\x1B[0;0;0m");
}
/*_______________________________________________________________________________________________________________________________*/

int ReadData(double I[],double U[])
	{
	FILE* data = fopen("data1.txt", "r");			/*Reading data from data.txt*/
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

double CalculateError(double I[],double U[],double R[],double r[],int line, double sigma[])
	{
		int number=0;
		double Umax_1,Umax_2,Umax_3;	Umax_1=Umax_2=Umax_3=0;
		double Imax_1,Imax_2,Imax_3;	Imax_1=Imax_2=Imax_3=0;
		double sum_U_1,sum_U_2,sum_U_3;	sum_U_1=sum_U_2=sum_U_3=0;
		double sum_I_1,sum_I_2,sum_I_3;	sum_I_1=sum_I_2=sum_I_3=0;
		double sum_UI_1,sum_UI_2,sum_UI_3;	sum_UI_1=sum_UI_2=sum_UI_3=0;
		double sum_Isq_1,sum_Isq_2,sum_Isq_3;	sum_Isq_1=sum_Isq_2=sum_Isq_3=0;
		double sum_Usq_1,sum_Usq_2,sum_Usq_3;	sum_Usq_1=sum_Usq_2=sum_Usq_3=0;
		for (number=1;number<line;number++)
			{
				if (number<=12)
					{
						if (U[number]>=Umax_1) Umax_1=U[number];
						if (I[number]>=Imax_1) Imax_1=I[number];
						sum_Usq_1 = sum_Usq_1 + U[number]*U[number];
						sum_Isq_1 = sum_Isq_1 + I[number]*I[number];
						sum_UI_1 = sum_UI_1 + U[number]*I[number];
					}
				if (number>12 && number<=24)
					{
						if (U[number]>=Umax_2) Umax_2=U[number];
						if (I[number]>=Imax_2) Imax_2=I[number];
						sum_Usq_2 = sum_Usq_2 + U[number]*U[number];
						sum_Isq_2 = sum_Isq_2 + I[number]*I[number];
						sum_UI_2 = sum_UI_2 + U[number]*I[number];
					}
				if (number>24 && number<=36)
					{
						if (U[number]>=Umax_3) Umax_3=U[number];
						if (I[number]>=Imax_3) Imax_3=I[number];
						sum_Usq_3 = sum_Usq_3 + U[number]*U[number];
						sum_Isq_3 = sum_Isq_3 + I[number]*I[number];
						sum_UI_3 = sum_UI_3 + U[number]*I[number];
					}

			}
									//sq=square a*a
		double average_Isq_1 = sum_Isq_1 / (number/3);	double average_Usq_1 = sum_Usq_1 / (number/3);
		double average_UI_1 = sum_UI_1 / (number/3);		double average_R_1 = average_UI_1 / average_Isq_1;
		double average_Isq_2 = sum_Isq_2 / (number/3);	double average_Usq_2 = sum_Usq_2 / (number/3);
		double average_UI_2 = sum_UI_2 / (number/3);		double average_R_2 = average_UI_2 / average_Isq_2;
		double average_Isq_3 = sum_Isq_3 / (number/3);	double average_Usq_3 = sum_Usq_3 / (number/3);
		double average_UI_3 = sum_UI_3 / (number/3);		double average_R_3 = average_UI_3 / average_Isq_3;

		double sigma_rand_1 = sqrt(average_Usq_1 /average_Isq_1 - average_R_1*average_R_1)/sqrt(number/3);
		double sigma_rand_2 = sqrt(average_Usq_2 /average_Isq_2 - average_R_2*average_R_2)/sqrt(number/3);
		double sigma_rand_3 = sqrt(average_Usq_3 /average_Isq_3 - average_R_3*average_R_3)/sqrt(number/3);

		double sigma_system_1 = sqrt((delta_U/Umax_1)*(delta_U/Umax_1)+(delta_I/Imax_1)*(delta_I/Imax_1));
		double sigma_system_2 = sqrt((delta_U/Umax_2)*(delta_U/Umax_2)+(delta_I/Imax_2)*(delta_I/Imax_3));
		double sigma_system_3 = sqrt((delta_U/Umax_3)*(delta_U/Umax_3)+(delta_I/Imax_3)*(delta_I/Imax_3));

		sigma[0]=sqrt((sigma_rand_1*sigma_rand_1) + (sigma_system_1*sigma_system_1));
		sigma[1]=sqrt((sigma_rand_2*sigma_rand_2) + (sigma_system_2*sigma_system_2));
		sigma[2]=sqrt((sigma_rand_3*sigma_rand_3) + (sigma_system_3*sigma_system_3));

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
