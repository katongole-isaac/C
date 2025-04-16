/**
 * Simple program illustrating 'hello world'
 * 
 */

#include <stdio.h>

// external variables
int _PI;

#define GRAVITY 9.8

void console(int, int);

// getline();

int main() {

    printf("%d\n", EOF);
    printf("%c\n", putchar(97));
    printf("hello world \b");

    printf("\n");

    printf("%d %d %d\n", '\b' ,'\t','\n');

    int backspace = '\n';
    int tab = '\t';
    int newline = '\n';

    printf("%d", backspace);

    int a = 10, b = 11;

    console(a,b);

    printf("\n%d %d\n",a, b);
    
    // external variables
    extern int _PI;

    _PI = 0;

    printf("External: %d" , _PI);

    char str[2] = "";

    str[0] = 'A';
    str[1] = 'A';
    str[2] = 'A';
    // str[3] = 'A';

    printf("\nstr: %s ", str);
    
}

void console(int a, int b) {
    a = 11;
    printf("\n%d %d", a, b);
}
