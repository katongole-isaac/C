/**
 * This examle illustrates the use of
 * external variable with `extern` keyword
*/
#include <stdio.h>

float PI;  // declared global(external) variable

int main(){

    extern float PI ;

    PI = 3.14;

    printf("PI: %3.3f", PI);

    return 0;
}