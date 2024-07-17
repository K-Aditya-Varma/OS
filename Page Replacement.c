#include <stdio.h>
#include <stdbool.h>

void fpr(int p, int is[], int f) { 
    int pf = 0; 
    int t[f];
    int fr = 0;
    for (int m = 0; m < f; m++) 
    {
        t[m] = -1;
    }
    printf("\nFIFO\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\n");

    for (int m = 0; m < p; m++) {
        bool pfault = true;

        for (int n = 0; n < f; n++) {
            if (t[n] == is[m]) {
                pfault = false;
                break;
            }
        }

        if (pfault) {
            t[fr] = is[m];
            fr = (fr + 1) % f;
            pf++;
        }

        printf("%d\t\t", is[m]);
        for (int n = 0; n < f; n++) {
            if (t[n] != -1)
                printf("%d\t\t", t[n]);
            else
                printf("-\t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults:\t%d\n", pf);
}

void lru(int p, int is[], int f) {
    int pf = 0;
    int t[f];
    int u[f];

    for (int m = 0; m < f; m++) {
        t[m] = -1;
        u[m] = 0;
    }

    printf("\nLRU\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\n");

    for (int m = 0; m < p; m++) {
        bool pfault = true;
        int l = 0;

        for (int n = 0; n < f; n++) {
            if (t[n] == is[m]) {
                pfault = false;
                u[n] = m + 1;
                break;
            }
            if (u[n] < u[l]) {
                l = n;
            }
        }

        if (pfault) {
            t[l] = is[m];
            u[l] = m + 1;
            pf++;
        }

        printf("%d\t\t", is[m]);
        for (int n = 0; n < f; n++) {
            if (t[n] != -1)
                printf("%d\t\t", t[n]);
            else
                printf("-\t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults:\t%d\n", pf);
}

void opr(int p, int is[], int f) {
    int pf = 0;
    int t[f];

    for (int m = 0; m < f; m++) {
        t[m] = -1;
    }

    printf("\nOptimal Page Replacement Algorithm\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\n");

    for (int m = 0; m < p; m++) {
        bool pfault = true;
        int r = -1;
        int far = m;

        for (int n = 0; n < f; n++) {
            if (t[n] == is[m]) {
                pfault = false;
                break;
            }
        }

        if (pfault) {
            for (int n = 0; n < f; n++) {
                int j;
                for (j = m + 1; j < p; j++) {
                    if (t[n] == is[j]) {
                        if (j > far) {
                            far = j;
                            r = n;
                        }
                        break;
                    }
                }

                if (j == p) {
                    r = n;
                    break;
                }
            }

            if (r == -1) {
                r = 0;
            }

            t[r] = is[m];
            pf++;
        }

        printf("%d\t\t", is[m]);
        for (int n = 0; n < f; n++) {
            if (t[n] != -1)
                printf("%d\t\t", t[n]);
            else
                printf("-\t\t");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults:\t%d\n", pf);
}

int main() {
    int p;
    printf("Enter number of pages in incoming stream: ");
    scanf("%d", &p);

    int is[p];
    printf("Enter the sequence of pages:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &is[i]);
    }

    int f;
    printf("Enter number of frames (max 3): ");
    scanf("%d", &f);

    fpr(p, is, f);
    lru(p, is, f);
    opr(p, is, f);

    return 0;
}
