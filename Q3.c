/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<time.h>

/******************************************************************************
 *    purpose:produce a random number
 *
 *    entry: none
 *
 *    exit: random int in range [min,max]
 *
 *    Written during Summer Term 2014 @ Oregon State University
 ******************************************************************************/
int GetRandomInRange ( int min , int max ) {

   int random;
   int range = max - min + 1;
   if ( range == 1 )
      return min;
   random = (rand() % range) + min;
   return random;
}


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
}

int main(){

    //for random range
    const int MAX = 100;

    //seed random gen
    srand(time(NULL));

    /*Declare an integer n and assign it a value of 20.*/
    
    /*Allocate memory for an array of n integers using malloc.*/
    
    /*Fill this array with random numbers, using rand().*/
    
    /*Print the contents of the array.*/

    /*Pass this array along with n to the sort() function of part a.*/
    
    /*Print the contents of the array.*/    
    
    return 0;
}
