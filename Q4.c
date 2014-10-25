/* CS261- Assignment 1 - Q.4*/
/* Name:Brandon Swanson
 * Date:10/1/14
 * Solution description: For this problem i was able to re-use many of the functions
 * previously written in the earlier problems
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct student{
    int id;
    int score;
};

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


void InsertElement ( struct student val , struct student *sortArray ,
        int numHolding ) {
  int i = 0;
  for ( ; i < numHolding ; i++ ) {
     if ( val.score < sortArray[i].score ) {
        for ( int j = numHolding ; j > i ; j-- ) {
           sortArray[j] = sortArray[j - 1];
        }
        break;
     }
  }
  sortArray[i] = val;
}


void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    ///////////an insertion sort implementation///////////////

    //copy contents to another array before mutating original
    struct student *vals = malloc(n*sizeof(struct student));
    for(int i=0;i<n;i++){
        vals[i]=students[i];
    }

    //index in array vals, one time through, each element gets placed in sorted
    //position in array number;
    for(int i=0;i<n;i++){
        InsertElement(vals[i],students,i);
    }
}

void generate(struct student* students, int n){

    int NUM_STUDENTS = n;

     /*Generate random ID and scores for ten students, ID being between 1 and 10,
      * scores between 0 and 100*/
    //create a 1 to 10 array for ID
    int *ids = malloc(sizeof(int)*NUM_STUDENTS);
    for(int i=0; i<NUM_STUDENTS; i++){
        ids[i]=i+1;
    }

    //fill ID and Score randomly for all 10 students
    for(int i=0; i<NUM_STUDENTS; i++){
        //select a score
        students[i].score=GetRandomInRange(0,100);

        //select and ID from the remaining available
        int selectedIndex = GetRandomInRange(i,NUM_STUDENTS-1);
        students[i].id = ids[selectedIndex];

        //remove ID from list
        ids[selectedIndex] = ids[i];

    }

    free(ids);

}

void output(struct student* students, int n){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    for(int i=0;i<n;i++){
        printf( "ID%d score%d\n" , students[i].id, students[i].score );
    }

}


int main(){
    /*Declare an integer n and assign it a value.*/
    int n=15;
    
    /*Allocate memory for n students using malloc.*/
    struct student *stud = malloc(n*sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(stud,n);

    
    /*Print the contents of the array of n students.*/
    output(stud,n);
    printf("\n\n");

    /*Pass this array along with n to the sort() function*/
    sort(stud,n);
    
    /*Print the contents of the array of n students.*/
    output(stud,n);
    
    free(stud);

    return 0;
}
