#include <stdio.h>
#define Max 100
struct process{
 int pid;
 int arrival_time;
 int burst_time;
 int remaining_time;
 int waiting_time;
 int turnaround_time;
};
int main(){
 int n;
 printf("Enter the number of processes:");
 scanf("%d", &n);
 struct process p[Max];
 for (int i = 0; i < n; i++){
 p[i].pid = i + 1;
 printf("Enter the arrival time and burst time for process %d:", i + 1);
 scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
 p[i].remaining_time = p[i].burst_time;
 }
 int t = 0;
 int completed = 0;
 while (completed < n){
 int shortest = -1;
 for (int i = 0; i < n; i++){
 if (p[i].arrival_time <= t && p[i].remaining_time > 0){
 if (shortest == -1 || p[i].remaining_time < p[shortest].remaining_time){
 shortest = i;
 }
 }
 }
 if (shortest == -1){
 t++;
 continue;
 }
 p[shortest].remaining_time--;
 if (p[shortest].remaining_time == 0){
 completed++;
 p[shortest].turnaround_time = t + 1 - p[shortest].arrival_time;
 p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
 }
 t++;
 }
 float total_waiting_time = 0;
 float total_turnaround_time = 0;
 printf("\n|------------------------------Process Scheduling--------------------------------|");
 printf("\n|Process\t|Arrival Time\t|Burst Time\t|Turnaround Time |Waiting Time |\n");
 printf("|--------------------------------------------------------------------------------|");
 for (int i = 0; i < n; i++){
 printf("\n %d\t\t %d\t\t %d\t\t %d\t\t %d", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].turnaround_time, 
p[i].waiting_time);
 total_waiting_time += p[i].waiting_time;
 total_turnaround_time += p[i].turnaround_time;
 }
 printf("\n|--------------------------------------------------------------------------------|");
 printf("\nTotal Waiting Time: %.2f\n", total_waiting_time);
 printf("Total Turn Around Time: %.2f\n", total_turnaround_time);
 printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
 printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}
