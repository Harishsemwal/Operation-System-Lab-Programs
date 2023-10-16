// Problem Statement: : Write a program to demonstrate the Preemptive Priority Scheduling using C language.
#include <stdio.h>
#include <limits.h>
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

    int at[n], bt[n], pid[n], tat[n], ct[n], wt[n], requiredTime[n], pri[n];
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("enter the arrival time of %d procces:", i + 1);
        scanf("%d", &at[i]);
        printf("enter the burst time of %d procces:", i + 1);
        scanf("%d", &bt[i]);
        printf("enter the priority of %d procces:", i + 1);
        scanf("%d", &pri[i]);
        requiredTime[i] = bt[i];
    }
    // sorting according to priority
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pri[j] > pri[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&pid[j], &pid[j + 1]);
                swap(&pri[j], &pri[j + 1]);
            }
        }
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
                swap(&pri[j], &pri[j + 1]);
            }
        }
    }
    int done = 0;
    int currTime = 0;
    while (done != n)
    {
        int idx = -1, prevPri = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (requiredTime[i] != 0 && at[i] <= currTime && pri[i] < prevPri)
            {
                idx = i;
                prevPri = pri[i];
            }
        }
        if (idx != -1)
        {
            currTime++;
            requiredTime[idx]--;
            if (requiredTime[idx] == 0)
            {
                ct[idx] = currTime;
                done++;
            }
        }
        else
        {
            currTime++;
        }
    }
    float avgTat = 0, avgWat = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTat += tat[i];
        avgWat += wt[i];
    }
    printf("\npid\t A.T\t B.T\t PRI\t C.T\t TAT\t WT");
    for (int i = 0; i < n; i++) 
    {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t %d", pid[i], at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }
    (avgTat) /= n;
    (avgWat) /= n;
    printf("\navgTat : %f\n", avgTat);
    printf("avgWt : %f", avgWat);
}
