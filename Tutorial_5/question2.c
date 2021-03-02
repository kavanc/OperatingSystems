#define _XOPEN_SOURCE 600 // required for barriers to work 
#include <stdlib.h> 
#include <stdio.h> 
#include <pthread.h> 
void* bellcurve(void *student){
    double bell = *(int *)student * 1.5;
    printf("%.2f\n", bell);
    return 0;
}
int main(void) {
    int students[5];
    for (int i = 0; i < 5; i++){
        printf("What is the student's grade?\n");
        scanf("%d\n", &students[i]);
    }

    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {   
        
        pthread_create(&tid[i], NULL, bellcurve, &students[i]);
       
    }
    pthread_exit(NULL);
    return 0;
} 