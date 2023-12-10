#include<stdio.h>
struct Process {
 int pid; 
 int burst_time; 
 int at;
 int tat;
 int waittime;
};
void fcfsScheduling(struct Process proc[], int n) {
 int i, j;
 struct Process temp;
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (proc[j].at > proc[j + 1].at) {
 temp = proc[j];
 proc[j] = proc[j + 1];
 proc[j + 1] = temp;
 } 
 }
 }
 int total_waiting_time = 0;
 int total_turnaround_time = 0;
 int time=0;
 i=0;
while (i<n) {
 if(proc[i].at<=time){
 time+=proc[i].burst_time;
 proc[i].tat=time-proc[i].at;
 proc[i].waittime=proc[i].tat-proc[i].burst_time;
 total_turnaround_time+=proc[i].tat;
 total_waiting_time+=proc[i].waittime;
 i++;
 } 
 Else{
 time++;
 } 
 }
 printf("Process\tBT\tAT\tWT \t TAT\n");
 for (i = 0; i < n; i++) {
 printf("%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].burst_time,
 proc[i].at,proc[i].waittime,proc[i].waittime+proc[i].burst_time);
 }
 printf("\nAverage Waiting Time: %.2f\n", (float) total_waiting_time / n);
 printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
}
void main() {
int n, i;
printf("Enter the number of processes: ");
scanf("%d", &n);
struct Process proc[n];
printf("Enter process details (Process ID, Burst Time, Arrival Time):\n");
for (i = 0; i < n; i++) {
printf("Process %d: ", i + 1);
scanf("%d %d %d", &proc[i].pid, &proc[i].burst_time, &proc[i].at);
}
fcfsScheduling(proc, n);
}
