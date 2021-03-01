#include <stdlib.h> 
#include <stdio.h> 

int main(void) {
    char arr[] ="hello world";
    int i = 0;
    while(1){
        if (arr[i] == '\0'){
            break;
        }
    printf("%c", arr[i]);
   i++; 
}

    
 } 