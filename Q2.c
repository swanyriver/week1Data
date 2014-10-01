/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    
    /*Set b to half its original value*/
    *b = *b/2;
    
    /*Assign a+b to c*/
    c = *a +*b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    int result;

    /*Print the values of x, y and z*/
    printf( "x=%d y=%d z=%d\n", x,y,z );
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    result = foo(&x,&y,z);
    
    /*Print the value returned by foo*/
    printf( "foo returned:%d\n", result );
    
    /*Print the values of x, y and z again*/
    printf( "x=%d y=%d z=%d\n", x,y,z );

 
    /*Is the return value different than the value of z?  Why?*/
    /*
     * Yes, they are different,  the value of Z has never been modified after
     * its assignment,  the passing of it to the foo function is done via pass
     * by value, not by reference or address,  so the variable c in the function
     * foo which is initially assigned to the same value as z, is a local
     * Variable and modifications on said variable don't affect the variable
     * z and also pass out of scope after the return of the function
     */
    return 0;
}
    
    
