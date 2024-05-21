#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct process {
    char name[5];
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int exe;
};
int sjf(struct process p[], int n, int current_time) {
    int sj_in = -1;
    int sj_bt = INT_MAX;
    for (int i = 0; i < n; i++) 
    {
        if (p[i].AT <= current_time && p[i].exe == 0 && p[i].BT < sj_bt) {
            sj_in = i;
            sj_bt = p[i].BT;
        }
    }
    return sj_in;
}
void main() 
{
    int n, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the arrival time and burst time for all the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("\n\nProcess %d:\n", i + 1);
        sprintf(p[i].name, "p%d", i + 1);
        printf("Arrival time: ");
        scanf("%d", &p[i].AT);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);
        p[i].exe = 0;
    }
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (p[j].AT > p[j + 1].AT) 
            {
                temp = p[j].AT;
                p[j].AT = p[j + 1].AT;
                p[j + 1].AT = temp;
                temp = p[j].BT;
                p[j].BT = p[j + 1].BT;
                p[j + 1].BT = temp;
                char temp_name[5];
                strcpy(temp_name, p[j].name);
                strcpy(p[j].name, p[j + 1].name);
                strcpy(p[j + 1].name, temp_name);
            }
        }
    }
    int current_time = 0;
    for (int i = 0; i < n; i++) 
    {
        int sj_in = sjf(p, n, current_time);
        if (sj_in == -1) {
            current_time = p[i].AT;
            sj_in = sjf(p, n, current_time);
        }
        p[sj_in].CT = current_time + p[sj_in].BT;
        p[sj_in].TAT = p[sj_in].CT - p[sj_in].AT;
        p[sj_in].WT = p[sj_in].TAT - p[sj_in].BT;
        p[sj_in].exe = 1;
        current_time = p[sj_in].CT;
    }
    double avgwt=0,avgtat=0;
        for(int i=0;i<n;i++)
    {
        printf("\nProcess name = %s \n",p[i].name);
        printf("completion time : %d \n",p[i].CT);
        printf("turn around time time : %d \n",p[i].TAT);
        printf("waiting time : %d \n\n",p[i].WT);
    }
    for(int i=0;i<n;i++)
    {
        avgwt =avgwt + p[i].WT;
        avgtat =avgtat +p[i].TAT;
    }
    avgwt = avgwt/n;
    avgtat = avgtat/n;
    printf("Average waiting time = %lf\n",avgwt);
    printf("Average turn around time = %lf\n",avgtat);
}
