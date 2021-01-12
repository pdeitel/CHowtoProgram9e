// fig07_03.c
// Cube a variable using pass-by-reference with a pointer argument.

#include <stdio.h>

void cubeByReference(int *nPtr); // function prototype

int main(void) {
   int number = 5; // initialize number

   printf("The original value of number is %d", number);
   cubeByReference(&number); // pass address of number to cubeByReference
   printf("\nThe new value of number is %d\n", number);
} 

// calculate cube of *nPtr; actually modifies number in main
void cubeByReference(int *nPtr) {                           
   *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr             
}



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

