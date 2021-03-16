#define _XOPEN_SOURCE 700 // required for barriers to work 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#define THREADS 5
int total_sum = 0;
sem_t add_factorial;

void* factorial(void *number)
{
	int num = *(int *)number;
	int factnum = num;
	int factorial = 1;
	for (int i = 0; i < num; i++)
	{
		factorial *= factnum;
		factnum --;
	}
	sem_wait(&add_factorial);
	total_sum += factorial;
	sem_post(&add_factorial);
	return NULL;
}
void sum_to_file()
{
	FILE *fp;
	fp = fopen("sum.txt", "w");
	if(fp == NULL)
	{
      printf("Error!");   
      exit(1);             
   	}
   fprintf(fp,"%d", total_sum);
   fclose(fp);
}
int main(void)
{
	pid_t pid;
	FILE *fptr;
	fptr = fopen("numbers.txt", "w+");
	
	if(fptr == NULL)
	{
		printf("Error!");   
		exit(1);             
	}
	 if(sem_init(&add_factorial, 0, 1))
	{
		printf("Could not initialize a semaphore\n");
		return -1;
	}
	pid = fork();
	if(pid == 0)//child
	{
		pthread_t tid[THREADS];
		int numbers[5];
		for(int i = 0; i < 5; i++)
		{
			fscanf(fptr, "%d", numbers[i]);
		}
		for(int i = 0; i < THREADS; i++)
		{
			pthread_create(&tid[i], NULL, factorial, &numbers[i]);
		}
		for (int i = 0; i < THREADS; i++)
		{
			pthread_join(tid[i], NULL);
		}	
	}
	else
	{
		int number = 0;
	 	for(int i = 0; i < 5; i++)
		{
	 		printf("Enter a number");
	 		scanf("%d" , &number);
	 		fprintf(fptr, "%d", &number);
	 	}
	}
	 
	 
	 fclose(fptr);
	 sem_destroy(&add_factorial);
	 sum_to_file();
	 
} 