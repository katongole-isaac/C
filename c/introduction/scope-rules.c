#include <stdio.h>
#include "header-file.h";
b(){
    static int x = 1;
    printf("X1: %d", x);
}

c(){
    int x = 0;
    printf("\nX2: %d", x);
}



int main() {

    // b();
    // c();
    extern char name[];
    extern int external;

    printf("%s", name);
    test();

    printf("\nPI: %f", PI);
    printf("\nExternal: %d", external);

    return 0;
}

char name[100] ="isaac";

void test(){
    printf("\nName: %s", name);
}