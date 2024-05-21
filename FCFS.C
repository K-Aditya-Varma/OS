#include<stdio.h>
struct prc
{
    char pid[10];
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void main()
{
    int n,temp;
    double avgwt=0,avgtat=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct prc p[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the process name : ");
        scanf("%s",p[i].pid);
        printf("arrival time : ");
        scanf("%d",&p[i].at);
        printf("bust time : ");
        scanf("%d",&p[i].bt);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j].at;
                p[j].at = p[j+1].at;
                p[j+1].at = temp;
                temp = p[j].bt;
                p[j].bt = p[j+1].bt;
                p[j+1].bt = temp;
            }
        }
    }
    int curt=0;
    for(int i=0;i<n;i++)
    {
        if(curt < p[i].at)
            curt = p[i].at;
        p[i].ct = curt + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        curt = p[i].ct;
    }
    for(int i=0;i<n;i++)
    {
        printf("\nProcess name = %s \n",p[i].pid);
        printf("completion time : %d \n",p[i].ct);
        printf("turn around time time : %d \n",p[i].tat);
        printf("waiting time : %d \n\n",p[i].wt);
    }
    for(int i=0;i<n;i++)
    {
        avgwt =avgwt + p[i].wt;
        avgtat =avgtat +p[i].tat;
    }
    avgwt = avgwt/n;
    avgtat = avgtat/n;
    printf("Average waiting time = %lf\n",avgwt);
    printf("Average turn around time = %lf\n",avgtat);
}