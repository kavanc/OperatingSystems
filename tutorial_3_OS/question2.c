#include <stdlib.h>
#include <stdio.h>
int main(void) {
    FILE *ptr;
    ptr = fopen("question2.txt", "r");
     if(ptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

    int a[10];

     for (int i = 0; i < 10; i++)
    {
        fscanf(ptr, "%2d", &a[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Number is: %d\n\n", a[i]);
    }
    fclose(ptr);
    return 0;
} 