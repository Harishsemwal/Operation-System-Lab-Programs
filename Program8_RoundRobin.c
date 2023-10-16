// Problem Statement: Write a program to demonstrate the Round Robin using c language.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main()
{
    printf("enter the number of process\n");
    int n;
    scanf("%d", &n);

    int at[n], bt[n], pid[n], tat[n], ct[n], wt[n], requiredTime[n];
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("enter the arrival time of %d procces:", i + 1);
        scanf("%d", &at[i]);
        printf("enter the burst time of %d procces:", i + 1);
        scanf("%d", &bt[i]);
        requiredTime[i] = bt[i];
    }
    int currTime = 0;
    int proDone = 0;
    int timeQuanta = 2;
    while (proDone != n)
    {
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currTime && requiredTime[i] != 0)
            {
                flag = 0;
                int req = min(timeQuanta, requiredTime[i]);
                requiredTime[i] -= req;

                currTime += req;
                if (requiredTime[i] == 0)
                {
                    proDone++;
                    ct[i] = currTime;
                }
            }
        }
        if (flag)
            currTime++;
    }
    float avgWt = 0.0, avgTat = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTat += tat[i];
        avgWt += wt[i];
    }
    avgTat /= n;
    avgWt /= n;
    printf("\npid\t A.T\t B.T\t C.T\t TAT\t WT");
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\navgTat : %f\n", avgTat);
    printf("avgWt : %f", avgWt);
}
