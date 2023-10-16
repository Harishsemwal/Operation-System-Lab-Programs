//Problem Statement: Implement Single Fork System Call using fork () function.
#include <stdio.h>
#include <unistd.h>
int main()
{
    fork();
    printf("Harish");
    fork();
    printf("Semwal");
    return 0;
}