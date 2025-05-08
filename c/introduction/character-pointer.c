/**
 * Discussion on character pointers
 * 
 */

#include <stdio.h>

int main() {

    printf("Hi there\n");

    char *msg;
    char _msg[] = "isabc";

    // not allowed *msg = "N";
    
    msg = "Isaac";

    *(_msg+1) = 'A';
    printf("V: %c\n",*(msg));
    printf("Value of _msg: %c\n",*(_msg+1));

    return 0;
}