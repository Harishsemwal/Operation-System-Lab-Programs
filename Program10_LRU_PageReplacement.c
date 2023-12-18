// LRU PAGE REPLACEMENT ALGO
#include <stdio.h>
void displayFrames(int frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == -1)
        {
            printf("| - ");
        }
        else
        {
            printf("| %d ", frames[i]);
        }
    }
    printf("|\n");
}
int main()
{
    int n;
    scanf("%d", &n);

    int stream[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stream[i]);
    }

    int m;
    scanf("%d", &m);
    printf("LRU Page Replacement Algorithm\n");
    int temp[m];
    int time[m];
    for (int i = 0; i < m; i++)
    {
        temp[i] = -1;
        time[i] = 0;
    }
    int hit = 0, miss = 0, currTime = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 1;
        currTime++;
        int replace = time[0];
        int replaceIdx = 0;
        for (int j = 0; j < m; j++)
        {
            if (stream[i] == temp[j])
            {
                f = 0;
                time[j] = currTime;
                hit++;
                break;
            }
            else
            {
                if (time[j] < replace)
                {
                    replace = time[j];
                    replaceIdx = j;
                }
            }
        }
        if (f == 0)
        {
            printf("Page %d -> ", stream[i]);
            displayFrames(temp, m);
            /* for(int k=0;k<m;k++){
                 printf("%d ",time[k]);
             }
             printf("\n");*/
            continue;
        }
        miss++;
        temp[replaceIdx] = stream[i];
        time[replaceIdx] = currTime;
        printf("Page %d -> ", stream[i]);
        displayFrames(temp, m);
        /* for(int k=0;k<m;k++){
                 printf("%d ",time[k]);
             }
             printf("\n");*/
    }
    printf("%d %d\n", hit, miss);
    printf("\nTotal Page Faults: %d\n", miss);
}
