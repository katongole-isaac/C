#include  <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int htoi(const char s[]) {
    
    int res = 0;

    for(int i = strlen(s) - 1, exp = 0; i >= 0 ; i--, exp++){
       if( isdigit(s[i]) ) res += ((s[i] - '0') * pow(16,exp));
       if(s[i] >= 'A' && s[i] <= 'F') res += ((s[i] - 'A') + 10 ) * pow(16,exp); // adding means a --> 10 in hex 
       if(s[i] >= 'a' && s[i] <= 'f') res += ((s[i] - 'a') + 10 ) * pow(16,exp); // adding means a --> 10 in hex 

    }

    return res;
}

int main() {


    printf("Hex: %d\n",htoi("aa"));

    return 0;

}