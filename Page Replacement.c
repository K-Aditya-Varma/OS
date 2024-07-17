#include <stdio.h>
#include <stdbool.h>

void fpr(int p, int is[], int f) { // fifoPageReplacement -> fpr
    int pf = 0; // pageFaults -> pf
    int t[f];
    int fr = 0; // front -> fr

    for (int m = 0; m < f; m++) {
        t[m] = -1;
    }

    printf("\n--- FIFO Page Replacement Algorithm ---\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\tFrame 4\tFrame 5\n");

    for (int m = 0; m < p; m++) { // pages -> p, incomingStream -> is, frames -> f
        bool pfault = true; // pageFault -> pfault

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

void lru(int p, int is[], int f) { // lruPageReplacement -> lru
    int pf = 0; // pageFaults -> pf
    int t[f];
    int u[f];

    for (int m = 0; m < f; m++) {
        t[m] = -1;
        u[m] = 0;
    }

    printf("\n--- LRU Page Replacement Algorithm ---\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\tFrame 4\tFrame 5\n");

    for (int m = 0; m < p; m++) { // pages -> p, incomingStream -> is, frames -> f
        bool pfault = true; // pageFault -> pfault
        int l = 0; // leastUsedIdx -> l

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

void opr(int p, int is[], int f) { // optimalPageReplacement -> opr
    int pf = 0; // pageFaults -> pf
    int t[f];

    for (int m = 0; m < f; m++) {
        t[m] = -1;
    }

    printf("\n--- Optimal Page Replacement Algorithm ---\n");
    printf("\nIncoming\tFrame 1\tFrame 2\tFrame 3\tFrame 4\tFrame 5\n");

    for (int m = 0; m < p; m++) { // pages -> p, incomingStream -> is, frames -> f
        bool pfault = true; // pageFault -> pfault
        int r = -1; // replaceIdx -> r
        int far = m; // farthest -> far

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
    printf("Enter number of frames: ");
    scanf("%d", &f);

    fpr(p, is, f);
    lru(p, is, f);
    opr(p, is, f);

    return 0;
}