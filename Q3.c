/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
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


void InsertElement ( int val , int *sortArray ,  int numHolding ) {
  int i = 0;
  for ( ; i < numHolding ; i++ ) {
     if ( val < sortArray[i] ) {
        for ( int j = numHolding ; j > i ; j-- ) {
           sortArray[j] = sortArray[j - 1];
        }
        break;
     }
  }
  sortArray[i] = val;
}

void sort(int* number, int n){
     /*Sort the given array number , of length n*/

    ///////////an insertion sort implementation///////////////

    //copy contents to another array before mutating original
    int *vals = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        vals[i]=number[i];
    }

    //index in array vals, one time through, each element gets placed in sorted
    //position in array number;
    for(int i=0;i<n;i++){
        InsertElement(vals[i],number,i);
    }
}

void display(int* number, int n){
    for(int i=0;i<n;i++){
       printf("%d",number[i]);
       if(n-i>1) printf(",");
   }
   printf("\n");
}

int main(){

    //for random range
    const int MAX = 100;

    //seed random gen
    srand(time(NULL));

    /*Declare an integer n and assign it a value of 20.*/
    int n=20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *vals = malloc(20*sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    for(int i=0;i<n;i++){
        vals[i]=GetRandomInRange(0,MAX);
    }
    
    /*Print the contents of the array.*/
    display(vals,n);

    /*Pass this array along with n to the sort() function of part a.*/
    sort(vals,n);
    
    /*Print the contents of the array.*/
    display(vals,n);
    
    return 0;
}
