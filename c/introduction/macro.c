#include <stdio.h>

#define dprint(exp) printf(#exp " = %lf\n", exp)

#define paste(f, b) f ## b

// conditional Inclusion
#if !defined(H)
#define HN
// code 
#endif

#if SYSTEM == SYSV
  #define H "float.h"
#elif SYSTEM == BSD
  #define H "bsd.h"
#else 
  #define H "default.h"
#endif 



int main() {

    dprint(12/3.3);

    int n1 = 23;

    printf("Token-Pasting Operator: %d\n", paste(n, 1));

    return 0;
}