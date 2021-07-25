// figG_01.c
// Finding the maximum of three integers
#include <stdio.h>

int maximum(int x, int y, int z); // function prototype

// function main begins program execution
int main(void) {
   int number1 = 0; // first integer
   int number2 = 0; // second integer
   int number3 = 0; // third integer

   printf("%s", "Enter three integers: ");
   scanf("%d%d%d", &number1, &number2, &number3);
   
   // number1, number2 and number3 are arguments 
   // to the maximum function call
   printf("Maximum is: %d\n", maximum(number1, number2, number3));
} // end main

// Function maximum definition
// x, y and z are parameters
int maximum(int x, int y, int z) {
   int max = x; // assume x is largest

   if (y > max) { // if y is larger than max, assign y to max
      max = y;
   } // end if

   if (z > max) { // if z is larger than max, assign z to max
      max = z;
   } // end if

   return max; // max is largest value
} // end function maximum


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
 **************************************************************************/
