// banker algo
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processor:-\n");
    scanf("%d", &n);
    int m;
    printf("Enter the number of resources:-\n");
    scanf("%d", &m);
    int allocation[n][m];
    printf("Enter the allocation matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    int max_need[n][m];
    int need[n][m];
    printf("Enter the max need matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max_need[i][j]);
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
    printf("Enter the number of available resources of each type: \n");
    int avail[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    int pro_done = 0;
    int seq[n];
    int k = 0;
    int ans[n];
    for (int i = 0; i < n; i++)
        seq[i] = -1;
    while (pro_done != n)
    {
        int prevDone = pro_done;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            if (seq[i] != -1)
                continue;
            for (int j = 0; j < m; j++)
            {
                if (need[i][j] > avail[j])
                {
                    f = 0;
                }
            }
            if (f)
            {
                seq[i] = pro_done;
                ans[k++] = i;
                for (int j = 0; j < m; j++)
                {
                    avail[j] += need[i][j];
                }
                pro_done++;
            }
        }
        if (prevDone == pro_done)
        {
            printf("DEADLOCK\n");

            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("P%d->", ans[i]);
    }
    printf("P%d", ans[n - 1]);
}
