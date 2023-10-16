// Problem Statement: Write a program to implement FCFS (First Come First Serve.
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    printf("enter the number of process\n");
    int n;
    scanf("%d", &n);

    int at[n], bt[n], pid[n];
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("enter the arrival time of %d procces:", i + 1);
        scanf("%d", &at[i]);
        printf("enter the burst time of %d procces:", i + 1);
        scanf("%d", &bt[i]);
    }
    // sorting according to arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&pid[j], &pid[j + 1]);
            }
        }
    }
    int ct[n], tat[n], wt[n];
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++)
    {
        int idle = 0;
        if (at[i] > ct[i - 1])
        {
            idle += (at[i] - ct[i - 1]);
        }
        ct[i] = ct[i - 1] + bt[i] + idle;
    }
    float avgTat = 0, avgWat = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTat += tat[i];
        avgWat += wt[i];
    }
    printf("\npid\t A.T\t B.T\t C.T\t TAT\t WT");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t %d\t\t %d \t\t%d \t\t%d \t\t%d", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    (avgTat) /= n;
    (avgWat) /= n;
    printf("\navgTat : %f\n", avgTat);
    printf("avgWt : %f", avgWat);
}
