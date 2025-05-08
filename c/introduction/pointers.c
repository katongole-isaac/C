#include <stdio.h>

void display(int *);

int main() {

   char *ptr;
   char c = '8';

   ptr = &c;

   *ptr = 'B';

   printf("Chara: %c\n", *ptr);
   printf("C: %c\n", c);


   int *p;
   int x = 10;

   p = &x;

   p++;

   *p = 11;

   printf("Undefined: %d\n", *p);

   // --------------------------------------------------------
    
   int array[] = {28,12,41,2,4,1,2,4};

   int *pa;

   pa = array;

   display(pa+2);
   display(array);
   display(array+5);
   display(&pa[1]);

    return 0;
}

void display(int *p){
    printf("\nvalue: %d\n", *p);
}