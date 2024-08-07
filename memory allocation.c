#include <stdio.h>
#define MAX 25
void ff(int nb, int nf, int b[], int f[]) 
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, temp;
    for (i = 1; i <= nf; i++) 
    {
        for (j = 1; j <= nb; j++) 
        {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) 
                {
                    ff[i] = j;
                    frag[i] = temp;
                    bf[j] = 1;
                    break;
                }
            }
        }
    }
    printf("\nMemory Management Scheme - First Fit\n");
    printf("File_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t", i, f[i]);
        if (ff[i] != 0) {
            printf("%d\t\t%d\t\t%d\n", ff[i], b[ff[i]], frag[i]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }
}
void bf(int nb, int nf, int b[], int f[]) 
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, temp, l = 10000;

    for (i = 1; i <= nf; i++) 
    {
        for (j = 1; j <= nb; j++) 
        {
            if (bf[j] != 1) 
            {
                temp = b[j] - f[i];
                if (temp >= 0 && l > temp) 
                {
                    ff[i] = j;
                    l = temp;
                }
            }
        }
        frag[i] = l;
        bf[ff[i]] = 1;
        l = 10000;
    }

    printf("\nMemory Management Scheme - Best Fit\n");
    printf("File No\tFile Size \tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t", i, f[i]);
        if (ff[i] != 0) 
        {
            printf("%d\t\t%d\t\t%d\n", ff[i], b[ff[i]], frag[i]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }
}

void wf(int nb, int nf, int b[], int f[]) 
{
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, temp, h = 0;
    for (i = 1; i <= nf; i++) 
    {
        for (j = 1; j <= nb; j++) 
        {
            if (bf[j] != 1) 
            {
                temp = b[j] - f[i];
                if (temp >= 0 && h < temp) 
                {
                    ff[i] = j;
                    h = temp;
                }
            }
        }
        frag[i] = h;
        bf[ff[i]] = 1;
        h = 0;
    }
    printf("\nMemory Management Scheme - Worst Fit\n");
    printf("File_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) 
    {
        printf("%d\t\t%d\t\t", i, f[i]);
        if (ff[i] != 0) 
        {
            printf("%d\t\t%d\t\t%d\n", ff[i], b[ff[i]], frag[i]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }
}

int main() 
{
    int b[MAX], f[MAX], nb, nf;
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:-\n");
    for (int i = 1; i <= nb; i++) 
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (int i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    int b1[MAX], b2[MAX], b3[MAX];
    for (int i = 1; i <= nb; i++) 
    {
        b1[i] = b[i];
        b2[i] = b[i];
        b3[i] = b[i];
    }
    ff(nb, nf, b1, f);
    bf(nb, nf, b2, f);
    wf(nb, nf, b3, f);
    return 0;
}