/*Consider a scheduler which schedules the job by considering the arrival time of the processes where arrival time
if given as 0 is discarded or displayed as error. The scheduler implements the shortest job first scheduling policy,
but checks the queue of the processes after the every process terminates and time taken for checking and arranging
the process according to the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting time and
turnaround time of the processes. Also compute the total time taken by the processor to compute all the jobs.
*/

#include<stdio.h>
struct process
{
    int pno;
    int p_arrival;
    int p_burst;

};
struct outcome
{
    int final_pno;
    int waiting_time;
    int turnaround_time;
};
int main()
{
	struct process obj[30];
	struct outcome res[30];
	int i,n,j,pos,min,pro_exec,time=0,end,k,flag,ideal_time,sumwait=0,sumturn=0;
	printf("Enter the no. of processes-");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("\n\nPROCESS P%d\n",i);
		obj[i].pno=i;
		X:printf("Arrival Time-");
		scanf("%d",&obj[i].p_arrival);
		if(obj[i].p_arrival<0)
     		{
       		     printf("\noops! arrival time can't be 0\n");
         	     goto X;
        	}
		Y:printf("Burst Time-");
		scanf("%d",&obj[i].p_burst);
		if(obj[i].p_burst<=0)
        	{
            	     printf("\noops! burst time can't be 0\n");
                     goto Y;
		}
	}
	time!=0;
	for(i=1;i<=n;i++)
	{
		if(obj[i].p_arrival==0)
        {
            printf("Process- %d Discared Error!",i);
            for(j=i;j<n;j++)
            {
                obj[j]=obj[j+1];
            }
            time=obj[1].p_arrival;
            n--;
            i--;
        }
        if(obj[i].p_arrival<time )
        {
            time=obj[i].p_arrival;
        }
	}
	end = n;
	min=0;
	k=1;
	while(n>0)
	{
	    pro_exec=obj[1].p_burst;
	    ideal_time=time+1;
	    flag=0;
		for(j=1;j<=n;j++)
		{

			if(pro_exec>=obj[j].p_burst && obj[j].p_arrival<=time)
			{
				pro_exec = obj[j].p_burst;
				pos=j;
				flag=1;
			}
			if(ideal_time>time && ideal_time>obj[j].p_arrival && obj[j].p_arrival!=time)
            {
                ideal_time=obj[j].p_arrival;
            }
		}
		if(flag==1)
        {
            if(pos==1)
            {
                res[k].waiting_time=time-obj[pos].p_arrival;
                time = time + pro_exec;
                res[k].turnaround_time=time-obj[pos].p_arrival;
            }
            else
            {
                res[k].waiting_time=time-obj[pos].p_arrival+2;
                time = time + pro_exec;
                res[k].turnaround_time=time-obj[pos].p_arrival+2;
            }
            res[k].final_pno=obj[pos].pno;
            for(i=pos;i<n;i++)
            {
               obj[i]=obj[i+1];
            }
            n--;
            k++;

        }
        else //IDEAL TIME FOR CPU
        {
            time = ideal_time;
        }

        }
       // RESULT OF ALL PROCESSES
        printf("\n\n\nPROCESS     WAITING TIME      TURNAROUND TIME");
        for(i=1;i<=end;i++)
        {
            printf("\nP%d\t\t%d\t\t%d",res[i].final_pno,res[i].waiting_time,res[i].turnaround_time);
		sumwait=sumwait+res[i].waiting_time;
		sumturn=sumturn+res[i].turnaround_time;
        }
	 printf("\n\nTotal time taken to compute all the process is =   %d \n",time);
	 printf("Average waiting time = %d\nAverage turnaround time = %d",sumwait/end,sumturn/end);
    return 0;
}
