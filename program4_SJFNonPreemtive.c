// Problem Statement: Write a program to demonstrate the Shortest Job First (SJF) mehod of non Preemtive using C language.

#include <stdio.h>
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

    int at[n],bt[n],pid[n],ct[n],tat[n],requiredTime[n],wt[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
        requiredTime[i]=bt[i];
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
    ct[0]=at[0]+bt[0];
    requiredTime[0]=0;
    int done=1;
    int currTime=ct[0];
    while(done<n)
    {
        int idx=-1,prevBt=INT_MAX;
        for(int i=1;i<n;i++){
            if(requiredTime[i]!=0 && at[i]<=currTime && bt[i]<prevBt)
            {
                idx=i;
                prevBt=bt[i];
            }
        }
        if(idx!=-1){
            ct[idx]=currTime+bt[idx];
            requiredTime[idx]=0;
            done++;
            currTime+=bt[idx];
        }else if(done<n){
            currTime++;
        }
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
