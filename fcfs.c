#include <stdio.h>
#include <stdlib.h>
typedef struct{
 int pid;
 int btime;
 int atime;
 int wtime;
 int tatime;
} sp;
int main(){
 int i, j, n,ctime=0;
 float total_waiting_time=0, total_turnaround_time=0;
 sp *p, t;
 printf("Enter the no. of processes: ");
 scanf("%d", &n);
 p = (sp *)malloc(n * sizeof(sp));
 printf("Enter the burst time and arrival time of");
 for (i = 0; i < n; i++){
 printf("\nProcess%d\t:", i + 1);
 scanf("%d", &p[i].btime);
 scanf("%d", &p[i].atime);
 p[i].pid = i + 1;
 p[i].wtime = 0;
 }
 for(i=0;i<n;i++){
 for(j=0;j<n-i-1;j++){
 if(p[j].atime>p[j+1].atime){
 t=p[j];
 p[j]=p[j+1];
 p[j+1]=t;
 }
 }
 }
 printf("\n|------------------------------Process Scheduling--------------------------------|");
 printf("\n|Process\t|Burst Time\t|Arrival Time\t|Waiting Time\t|Turn Around Time|");
 printf("\n|--------------------------------------------------------------------------------|");
 for (i = 0; i < n; i++){
 ctime += p[i].btime;
 p[i].tatime = ctime - p[i].atime;
 p[i].wtime = p[i].tatime - p[i].btime;
 total_waiting_time += p[i].wtime;
 total_turnaround_time += p[i].tatime;
 printf("\n|%d\t\t|%d\t\t|%d", p[i].pid, p[i].btime, p[i].atime);
 printf("\t\t|%d\t\t|%d \t\t |", p[i].wtime, p[i].tatime);
 }
 printf("\n|--------------------------------------------------------------------------------|");
 printf("\n Total Waiting Time: %.2f", total_waiting_time);
 printf("\n Average Waiting Time: %.2f", (float)total_waiting_time / n);
 printf("\n Total Turn Around Time: %.2f", total_turnaround_time);
 printf("\n Average Turn Around Time: %.2f", (float)total_turnaround_time / n);
}
