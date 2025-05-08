/**
 * Implmentation of strcat using a pointer
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strcatt(const char *s, const char *t){

 int len_s = strlen(s);
 int len_t = strlen(t);

 int total_reserved_space = len_s + len_t + 1;

 char *res = malloc(total_reserved_space * sizeof(char));

 while( *s != '\0') {
    *res = *s;
    res++;
    s++;
 }

 while( *t != '\0') {
    *res = *t;
    res++;
    t++;
 }
 
 *res = '\0'; // end of result string

 for(int i = 0; i < total_reserved_space - 1; i++) --res;

 return res;
 
}

int main() {

    char *res = strcatt("hi", " isaac");

    printf("Value: %s\n", res);
  
    return 0;
}