// Problem Statement: Write a program to demonstrate parent child relationship whose parent process computes sum of even number and child process computes sum of odd number.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  int n;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  int sum_even = 0;
  int sum_odd = 0;
  pid_t pid = fork(); 
  if(pid == -1)
  {
    perror("Fork failed");
    exit(EXIT_FAILURE);
  }
  if(pid == 0)
  {
    for(int i=0;i<n;i++)
    {
       if(arr[i]%2!=0) 
         sum_odd += arr[i];
    }
    printf("child process: Sum of odd numbers = %d\n",sum_odd);
  }
  else 
  {
     for(int i=0;i<n;i++)
     {
        if(arr[i]%2==0)
         sum_even += arr[i];
     }
     printf("Parent process: Sum of even numbers = %d\n",sum_even);
  }
  return 0;
}

