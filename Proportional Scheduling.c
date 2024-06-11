#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    char name[5];
    int tckts;
} prc;

void main()
{
    int n, ttl_tckts = 0;
    float ttl_T = 0.0;
    printf("Enter the no of Processes: ");
    scanf("%d", &n);
    prc p[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        sprintf(p[i].name, "P%d", i + 1);
        printf("Tickets: ");
        scanf("%d", &p[i].tckts);
        ttl_tckts += p[i].tckts;
        ttl_T += p[i].tckts;
    }
    printf("Enter the time period for scheduling: ");
    int m;
    scanf("%d", &m);
    for (int i=0;i<m;i++)
    {
        int win_tckt = rand() % ttl_tckts + 1;
        int acc_tckts = 0;
        int winner_index;
        for (int j=0;j<n;j++)
        {
            acc_tckts += p[j].tckts;
            if (win_tckt <= acc_tckts)
            {
                winner_index = j;
                break;
            }
        }
        printf("Tickets picked: %d, Winner: %s\n", win_tckt, p[winner_index].name);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nThe Process: %s gets %0.2f%% of Processor Time.\n", p[i].name, ((p[i].tckts / ttl_T) * 100));
    }

}
