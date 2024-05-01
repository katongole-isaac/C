/**
 * This illustrate the use of `#define` to deal with magic
 * number (random value) in the program
*/

#include <stdio.h>

#define PI 3.14
#define GRAVITY 9.8

int main () {

    printf("PI: %.2f\n", PI);
    printf("Gravity: %.2f", GRAVITY);

    return 0;

}