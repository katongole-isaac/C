/**
 * This example deals with pointers in c
 * Storage Allocator allocates free space in it's available 
 * 
 */

#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; // points to the beginning of the next free block

char *alloc(int n ) {

    if( allocbuf + ALLOCSIZE - allocp >= n ){
        allocp += n;
        return allocp - n; /* old allocp */
    }

    else return 0;

}

/**Cleaning the previous used space */
void afreep(char *p){
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE )
        allocp = p;
}

int main() {

    char *ptr = alloc(6);

    *ptr = 'A';
    printf("Pointer: %p\n", ptr);
    printf("Value: %c\n", *ptr);

    // ptr++;

    // *ptr = 'B';
    // printf("Pointer: %p\n", ptr);
    // printf("Value: %c\n", *ptr);

    printf("\nPointer Allocp: %p\n", allocp);

    afreep(ptr);

    printf("\nAfter afreep call: (Allocp): %p\n", allocp);


    return 0;
}