#include <stdio.h>

int main() {

    int guess = 5;

    int i;

    for( i =0; i < 10; i++) if( guess == i ) goto found;

    found:
        printf("We found the guess: %d",i);
        printf("\nBye");
    
    return 0;
}