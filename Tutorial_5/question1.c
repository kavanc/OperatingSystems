#define _XOPEN_SOURCE 600 // required for barriers to work
#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <pthread.h> 
#include <time.h>
void* hello_world(){
    srand(time(0));
    sleep(rand()%5);
    printf("Hello World\n");
return 0;
}
void* goodbye(){
    srand(time(0));
    sleep(rand()%5);
    printf("Goodbye\n");
    return 0;
}

int main(void) { 
    pthread_t tid;
    pthread_t tid1;
    pthread_create(&tid, NULL, hello_world, NULL);
   
    pthread_create(&tid1, NULL, goodbye, NULL);
    pthread_exit(NULL);
   
} 

