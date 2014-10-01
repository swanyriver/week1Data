/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
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


struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* result = malloc(10*sizeof(struct student));
     
     /*return the pointer*/
    return result;
}

void generate(struct student* students){

    const int NUM_STUDENTS = 10;

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

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    for(int i=0;i<10;i++){
        printf( "ID%d score%d\n" , students[i].id, students[i].score );
    }

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = 100;
     int max = 0;
     int total =0;
     int average;

     for(int i=0;i<10;i++){
         if(students[i].score>max) max = students[i].score;
         if(students[i].score<min) min = students[i].score;
         total += students[i].score;
     }

     average = total/10;

     printf("max:%d min:%d average:%d\n",max,min,average);
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){

    srand(time(NULL));

    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);


    return 0;
}
