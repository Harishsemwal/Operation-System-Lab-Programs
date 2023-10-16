/*

*/
//fcfs in c
/*
#include <stdio.h>
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
    int ct[n],tat[n],wt[n];
    ct[0]=at[0]+bt[0];
    for(int i=1;i<n;i++){
        int idle=0;
        if(at[i]>ct[i-1]){
            idle+=(at[i]-ct[i-1]);
        }
        ct[i]=ct[i-1]+bt[i]+idle;
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
*/




// SJF non preemptive scheduling program in c
/*
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

*/



/*
//sjf preemptive
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
*/



// round robin
/*
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
int main()
{
    printf("enter the number of process\n");
    int n;
    scanf("%d",&n);

    int at[n],bt[n],pid[n],tat[n],ct[n],wt[n],requiredTime[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
        requiredTime[i]=bt[i];
    }
    int currTime=0;
    int proDone=0;
    int timeQuanta=2;
    while(proDone!=n)
    {
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=currTime && requiredTime[i]!=0){
                flag=0;
                int req=min(timeQuanta,requiredTime[i]);
                requiredTime[i]-=req;

                currTime+=req;
                if(requiredTime[i]==0){
                proDone++;
                ct[i]=currTime;
            }
        }
            
            
        }
        if(flag)currTime++;
    }
    float avgWt=0.0,avgTat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgTat+=tat[i];
        avgWt+=wt[i];
    }
    avgTat/=n;
    avgWt/=n;
    printf("\npid\t A.T\t B.T\t C.T\t TAT\t WT");
   for(int i=0;i<n;i++)
    {
       printf("\nP%d\t %d\t %d\t %d\t %d\t %d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    } 
    printf("\navgTat : %f\n",avgTat);
    printf("avgWt : %f",avgWt);
}

*/






/*
// priority non preemptive in c

#include<stdio.h>
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

    int at[n],bt[n],pid[n],tat[n],ct[n],wt[n],requiredTime[n],pri[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
        printf("enter the priority of %d procces:",i+1);
        scanf("%d",&pri[i]);
        requiredTime[i]=bt[i];
    }
    //sorting according to priority
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(pri[j]>pri[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&pri[j],&pri[j+1]);
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
                swap(&pri[j],&pri[j+1]);
            }
        }
    }
    ct[0]=at[0]+bt[0];
    requiredTime[0]=0;
    int done=1;
    int currTime=ct[0];
    while(done!=n)
    {
        int idx=-1,prevPri=INT_MAX;
        for(int i=1;i<n;i++){
            if(requiredTime[i]!=0 && at[i]<=currTime && pri[i]<prevPri)
            {
                idx=i;
                prevPri=pri[i];
            }
        }
        if(idx!=-1){
            ct[idx]=currTime+bt[idx];
            requiredTime[idx]=0;
            done++;
            currTime+=bt[idx];
        }else{
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
   printf("\npid\t A.T\t B.T\t PRI\t C.T\t TAT\t WT");
   for(int i=0;i<n;i++)
    {
          printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t %d",pid[i],at[i],bt[i],pri[i],ct[i],tat[i],wt[i]);
    }

   (avgTat)/=n;
    (avgWat)/=n;
    printf("\navgTat : %f\n",avgTat);
    printf("avgWt : %f",avgWat);


}
*/




// priority preemptive in c
/*
#include<stdio.h>
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

    int at[n],bt[n],pid[n],tat[n],ct[n],wt[n],requiredTime[n],pri[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
        printf("enter the priority of %d procces:",i+1);
        scanf("%d",&pri[i]);
        requiredTime[i]=bt[i];
    }
    //sorting according to priority
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(pri[j]>pri[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&pri[j],&pri[j+1]);
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
                swap(&pri[j],&pri[j+1]);
            }
        }
    }
    int done=0;
    int currTime=0;
    while(done!=n)
    {
        int idx=-1,prevPri=INT_MAX;
        for(int i=0;i<n;i++){
            if(requiredTime[i]!=0 && at[i]<=currTime && pri[i]<prevPri)
            {
                idx=i;
                prevPri=pri[i];
            }
        }
        if(idx!=-1){
            currTime++;
            requiredTime[idx]--;
            if(requiredTime[idx]==0){
                ct[idx]=currTime;
                done++;
            }
        }else {
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
   printf("\npid\t A.T\t B.T\t PRI\t C.T\t TAT\t WT");
   for(int i=0;i<n;i++)
    {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t %d",pid[i],at[i],bt[i],pri[i],ct[i],tat[i],wt[i]);
    }
   (avgTat)/=n;
    (avgWat)/=n;
    printf("\navgTat : %f\n",avgTat);
    printf("avgWt : %f",avgWat);
}
*/