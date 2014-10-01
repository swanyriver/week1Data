/*
 ============================================================================
 Name        : Assignment 0
 Author      : Brandon Swanson
 Version     :
 Description : exponent function,  argv[1] to the power of argv[2]
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////
//////Linear time to execute recursive exponent algorithm//////////////////
////////////////////////////////////////////////////////////////////////////
long int exponent(int value, int pow){
   if(pow == 1) return value;
   else return exponent(value, --pow) * value;
}


int main(int argc, char **argv) {

   /////////////////TEST CASES///////////////
   //printf("%d to the %d is : %ld\n", 2,4, exponent(2,4) );
   //printf("%d to the %d is : %ld\n", 3,3, exponent(3,3) );

   int val = atoi(argv[1]);
   int pow = atoi(argv[2]);

   printf("%d to the %d is : %ld\n", val,pow, exponent(val,pow));


	return 0;
}
