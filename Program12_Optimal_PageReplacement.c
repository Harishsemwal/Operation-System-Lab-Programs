// OPTIMAL PAGE REPLACEMENT
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
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = -1;
    int hit = 0, miss = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 1;
        for (int j = 0; j < m; j++)
        {
            if (temp[j] == stream[i])
            {
                f = 0;
                hit++;
                break;
            }
            if (temp[j] == -1)
            {
                f = 0;
                temp[j] = stream[i];
                miss++;
                break;
            }
        }
        if (f == 0)
        {
            printf("Page %d -> ", stream[i]);
            displayFrames(temp, m);
            continue;
        }
        miss++;
        int demand[m];
        for (int k = 0; k < m; k++)
        {
            demand[k] = 1e9;
        }
        for (int j = 0; j < m; j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if (stream[k] == temp[j])
                {
                    demand[j] = k;
                    break;
                }
            }
        }

        int lateDemand = demand[0];
        int lateDemandIdx = 0;
        for (int j = 1; j < m; j++)
        {
            if (demand[j] > lateDemand)
            {
                lateDemand = demand[j];
                lateDemandIdx = j;
            }
        }
        temp[lateDemandIdx] = stream[i];
        printf("Page %d -> ", stream[i]);
        displayFrames(temp, m);
    }
    printf("%d %d\n", hit, miss);
}
