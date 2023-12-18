#include <stdio.h>
#include <math.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

typedef struct process
{
    int id = 0, at = 0, bt = 0, st = 0, ct = 0, wt = 0, tat = 0, rt = 0, rbt = 0;
    bool completed = false;
    bool started = false;
    bool inqueue = false;
    int order = 0;
} process;

void swap(int *a, int *b)
{
    *a = (*a + *b) - (*b = *a);
}
void sort_arrival(int n, process p[], bool orig)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((!orig && p[j].at > p[j + 1].at) || (orig && p[j].id > p[j + 1].id))
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int ready_queue[1000] = {0};
int front = -1, rear = -1;
void push(int x)
{
    if (front == -1 && rear == -1)
    {
        front++;
    }
    rear++;
    ready_queue[rear] = x;
}
int pop()
{
    int temp = front++;
    if (front > rear)
        front = rear = -1;
    return ready_queue[temp];
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
        p[i].id = i + 1;

    printf("Enter arrival times: \n");
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].at, &p[i].bt);
    printf("Enter burst times: \n");
    // for(int i=0; i<n; i++) scanf("%d", &p[i].bt);
    printf("Enter time quanta: ");
    int tq;
    scanf("%d", &tq);

    bool orig = false;
    sort_arrival(n, p, orig = false);

    for (int i = 0; i < n; i++)
        p[i].rbt = p[i].bt;

    int time = 0;
    int done = 0;
    int i = 0;

    while (done != n)
    {
        if (front != -1)
        {
            int j = pop();

            if (p[j].started == false)
            {
                p[j].st = time;
                p[j].started = true;
            } // Process starting for the very first time

            time += min(tq, p[j].rbt);
            p[j].rbt -= min(tq, p[j].rbt);

            // If any of the process (not started yet) has arrival time less than the current times
            for (int k = 0; k < n; k++)
            {
                if (p[k].inqueue == false && p[k].at <= time)
                {
                    push(k);
                    p[k].inqueue = true;
                    i = k;
                }
            }
            // printf("Running...\n");

            if (p[j].rbt == 0)
            { // Process is completed
                p[j].ct = time;
                p[j].rt = p[j].st - p[j].at;
                p[j].tat = p[j].ct - p[j].at;
                p[j].wt = p[j].tat - p[j].bt;
                p[j].completed = true;
                done++;
            }
            else
                push(j); // If the process is not completed...pushing it back in the ready queue
        }
        else
        {
            for (int k = 0; k < n; k++)
            {
                if (p[k].inqueue == false && p[k].at <= time)
                {
                    push(k);
                    p[k].inqueue = true;
                    // i=k;
                }
            }
            if (front == -1)
                time++;
        }
    }

    sort_arrival(n, p, orig = true);

    printf("\n\nProcess Table:\n\n");
    printf("P.Id\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].wt, p[i].tat);
    }
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\n\nAverage waiting time: %0.2f", avg_wt);
    printf("\nAverage turnaround time: %0.2f", avg_tat);
    return 0;
}