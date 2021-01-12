// fig05_03.c
// Demonstrating the function-call stack 
// and stack frames using a function square.
#include <stdio.h>

int square(int x); // prototype for function square

int main() {
   int a = 10; // value to square (local variable in main)

   printf("%d squared: %d\n", a, square(a)); // display a squared
} 

// returns the square of an integer
int square(int x) { // x is a local variable
   return x * x; // calculate square and return result
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
 **************************************************************************/
