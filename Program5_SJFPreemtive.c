// Problem Statement: : Write a program to demonstrate the Preemptive Priority Scheduling using C language.

#include <stdio.h>
#include<math.h>
#include<limits.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    printf("enter the number of process\n");
    int n;
    scanf("%d",&n);

    int at[n],bt[n],pid[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
    }
    //sorting according to burst time
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pid[j],&pid[j+1]);
            }
        }
    }
    //sorting according to arrival time
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pid[j],&pid[j+1]);
            }
        }
    }
    int remainingTime[n];
    for(int i=0;i<n;i++)remainingTime[i]=bt[i];
    int ct[n],tat[n],wt[n];
    int nProComp=0;
    int currentTime=0;
        while(nProComp!=n){

        // finding shortes job among all
        int shortestJob = -1;
        int shortestTime = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0) {
                shortestJob = i;
                shortestTime = remainingTime[i];
            }
        }
        int shortestJobIndex=shortestJob;
        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }
        remainingTime[shortestJobIndex]--;
        if (remainingTime[shortestJobIndex] == 0) {
            nProComp++;
            ct[shortestJobIndex] = currentTime + 1;
        }

        currentTime++;

    }
    
    float avgTat=0,avgWat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgTat+=tat[i];
        avgWat+=wt[i];
    }
   printf("\npid\t A.T\t B.T\t C.T\t TAT\t WT");
   for(int i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d\t %d\t %d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
   (avgTat)/=n;
    (avgWat)/=n;
    printf("\navgTat : %f\n",avgTat);
    printf("avgWt : %f",avgWat);
}
