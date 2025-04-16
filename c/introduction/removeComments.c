
#include <stdio.h>
#include <string.h>


int main() {

    int i,c, k = 0, j = 0;

    int in_comment = 0; // flag to check whether we are in comment
    int in_quotes = 0;

    char program[1000] = "";
    char comment[1000] = "";

    char *str = "#include <stido.h> \n int main { /* this is a block comment **/ \n  int i = 0;  \n char str = \"//yuh have no coment here\"; \n // single comment \n return 0; \n }";
               

    // for(i = 0; (c = getchar()) != EOF; i++ ){
    for(i = 0; i < strlen(str); i++ ){

        c = str[i];

        if(c == '"' ) {

            if(in_comment) {
                comment[j] = c;
                j++;
                continue;
            }

            if( !in_quotes && !in_comment) in_quotes = 1;
            else if(in_quotes && !in_comment) in_quotes = 0;
            
            program[k] = c;
            k++;
            continue;
        }

    
        if(in_comment) {
          // check in you're in block-level comment
          if(comment[0] == '/' &&  comment[1] == '*') {

            if( c =='/' && comment[j-1] == '*') {
                    comment[j] = c;
                    j = 0;
                    in_comment = 0;
                    printf("Comment: %s\n",comment);
                    comment[0] = '\0';
                    continue;
                    // closing or end of the block-level comment.
            }

            comment[j] = c;
            j++;
            continue;

          }

          if(c == '\n'){
            comment[j] = c;
            j=0;
            in_comment = 0;
            printf("Comment: %s\n",comment);
            comment[0] = '\0';
            continue; 
            // end of the single-line comment
          }else {
            comment[j] = c;
            j++;
            continue;
          }

            
        }


        if(c == '/' && !in_quotes ){

            if(strlen(comment) == 0){
                comment[j] = c;
                j++;
                continue;                
            } 
            
            else if (comment[0] == '/' && c == '/') {
                comment[j] = c;
                j++;
                in_comment = 1;
                continue;
            }
            

        }

    // check if j == 1 means if we only have one character (/) in the comment character string which is now followed by "*" the activated the block level comment 
        if(comment[0] == '/' && j == 1 && c == '*')  
        {
            comment[j] = c;
            j++;
            in_comment = 1; // block level comment activated
            continue;
        }

        program[k] = c;
        k++;

    }

    printf("\nProgram: \n \n%s\n\n ", program);

   

    return 0;
}
