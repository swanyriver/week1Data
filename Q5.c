/* CS261- Assignment 1 - Q.5*/
/* Name:Brandon Swanson
 * Date:10/1/14
 * Solution description:I used the ctype.h toupper and tolower
 * functions because they work without error on numerics and need no
 * checking for the case of the character before conversion
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void sticky(char* word){
     /*Convert to sticky caps*/
    /*bool up = true;
    for(int i=0; word[i]!='\0';i++){
        if(up) word[i] = toupper(word[i]);
        else word[i] = tolower(word[i]);

        up=!up;
    }*/

    //brandons first bitwise

    int lower=0;
    for(int i=0; word[i]!='\0';i++){
       if(lower) word[i]|=32;
       else word[i]&=95;
       lower=!lower;
    }

    //printf("%b",!32);
}



int main(){
    /*Read word from the keyboard using scanf*/
    char str[31];
    printf("please enter a word (30chars Max): ");
    scanf("%30s",str);

    /*Call sticky*/
    sticky(str);
    
    /*Print the new word*/
    printf("\n%s\n\n",str);
    
    return 0;
}
