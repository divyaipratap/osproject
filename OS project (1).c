#include<stdlib.h>
#include<stdio.h>
int main()
{
static int comp[40];
int no_of_process,j,At[40],Bt[40],time=456329,rem[40],Pr;

char p[40][30];
int qunant1=3,qunant2=6,waiting[40],trunaround[40],total_time,average_waiting,average_trunaround;
int i,min=346579;
int data;
float total_waiting=0,total_trunaround=0;
printf("\n=================  OS PROGRAM  ====================\n");
printf("Enter the No of processes:-");
scanf("%d",&no_of_process);



for (i = 0; i < no_of_process; ++i)
{

fflush(stdin);
printf("\nArrival time  of process p%d=",i+1);	scanf("%d",&At[i]);
fflush(stdin);
printf("\nBurst time of process p%d=",i+1);scanf("%d",&Bt[i]);


}
for (i = 0; i < no_of_process; ++i)
{
	if (At[i]<time)
	{
		time=At[i];
	}
}

for(Pr = 0; Pr < 3; ++Pr)
{
    	if (Pr==0){

		for ( i = 0; i < no_of_process; ++i)
		{

			
			if (time<At[i] && rem[i]!=0)
			{
				time=At[i];
			}
			if (Bt[i]>qunant1)
			{

				rem[i]=Bt[i]-qunant1;
				time=time+qunant1;
			}
			else if (Bt[i]<=qunant1 )
			{
			time=time+Bt[i];
             rem[i]=0;
             comp[i]=time;

			}
			}
		
                    }
		if (Pr==1)
		{
		for ( i = 0; i < no_of_process; ++i)
		{
			if (rem[i]>qunant2 && rem[i]!=0)
			{

				rem[i]=rem[i]-qunant2;
				time=time+qunant2;
				comp[i]=time;
			}
			else if (rem[i]<=qunant2 && rem[i]!=0)
			{
			time=time+rem[i];
            rem[i]=0;
            comp[i]=time;
			}

		}
	}
		if (Pr==2 )
		{
		for (i = 0; i < no_of_process; ++i)

		{
         if (rem[i]!=0)
         {

         	if (min>rem[i])
         	{
         		min=rem[i];

         	}
         }

		}

		for (i = 0; i < no_of_process; ++i)
		{

		if (rem[i]==min && rem[i]!=0)
		{

			time=time+rem[i];
			rem[i]=0;
			comp[i]=time;

		}
		}

}
}

   for (i = 0; i < no_of_process; ++i)
		{
		 if (rem[i]==0)
		{

			trunaround[i]=comp[i]-At[i];
			waiting[i]=trunaround[i]-Bt[i];
			if (waiting[i]<=0)
			{
				waiting[i]=0;
			}

		}


		}

	

printf("rem time of p4%d\n",rem[3] );


	printf("\n----------------------------(program)-----------------------------\n");
	printf("process    Bt     At  comp   trunaround       waiting\n");

		for (i = 0; i < no_of_process; ++i)
		{
		 if (rem[i]==0)
		{

			printf("P%d       %d          %d         %d           %d            %d\n",i+1, Bt[i],At[i],comp[i],trunaround[i],waiting[i]);
		}


		}


		for (i = 0; i < no_of_process; ++i)
		{
		 if (rem[i]==0)
		{

		     data++;
			total_trunaround=(float)total_trunaround+trunaround[i];
            total_waiting=(float)total_waiting+waiting[i];

		}
	}
	
		printf("\nAverage waiting=%.2f",total_waiting/data);
		printf("\nAverage trunaround=%.2f\n",total_trunaround/data);

	for (i = 0; i < no_of_process; ++i)
		{
		 if (rem[i]>0)

		{

		printf("\n Terminated process are  p%d\n",i+1);

		}
	}


	}
