// FIFO PAGE REPLACEMENT
#include <stdio.h>

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
    {
        temp[i] = -1;
    }

    int k = 0;
    int hit = 0, miss = 0;

    for (int i = 0; i < n; i++)
    {
        int f = 1;
        for (int j = 0; j < m; j++)
        {
            if (stream[i] == temp[j])
            {
                hit++;
                f = 0;
                break;
            }
        }
        if (f)
        {
            miss++;
            temp[k] = stream[i];
            k++;
            k %= m;
        }
        for (int j = 0; j < m; j++)
        {
            if (temp[j] == -1)
                printf("-\t");
            else
                printf("%d\t", temp[j]);
        }
        printf("\n");
    }

    printf("%d %d\n", hit, miss);

    return 0;
}