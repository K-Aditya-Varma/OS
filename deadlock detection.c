#include <stdio.h>
int main() 
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], req[n][m], avail[m];
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Process %d: ", i);
        for (j = 0; j < m; j++) 
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the request matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < m; j++) {
            scanf("%d", &req[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (j = 0; j < m; j++) 
    {
        scanf("%d", &avail[j]);
    }
    int f[n], ss[n], w[m], flag;
    for (i = 0; i < n; i++) 
    {
        f[i] = 0; 
    }
    for (j = 0; j < m; j++) 
    {
        w[j] = avail[j];
    }
    int c = 0;
    while (c < n) 
    {
        flag = 0;
        for (i = 0; i < n; i++) 
        {
            if (f[i] == 0) 
            {
                int cp = 1;
                for (j = 0; j < m; j++) 
                {
                    if (req[i][j] > w[j])   
                    {
                        cp = 0;
                        break;
                    }
                }
                if (cp) 
                {
                    for (k = 0; k < m; k++) 
                    {
                        w[k] += alloc[i][k];
                    }
                    ss[c++] = i;
                    f[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0) 
        {
            break;
        }
    }
    int dl = 0;
    for (i = 0; i < n; i++) 
    {
        if (f[i] == 0) 
        {
            dl = 1;
            printf("System is in a deadlock state.\n");
            printf("The deadlocked processes are: ");
            for (j = 0; j < n; j++) 
            {
                if (f[j] == 0) 
                {
                    printf("P%d ", j);
                }
            }
            break;
        }
    }
    if (dl == 0) {
        printf("System is in safe state.\n");
        printf("Safe Sequence is: ");
        for (i = 0; i < n; i++) 
        {
            printf("P%d ", ss[i]);
        }
    }
    return 0;
}