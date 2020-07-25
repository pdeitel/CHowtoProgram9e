// fig02_04.c
// Addition program.
#include <stdio.h>

// function main begins program execution 
int main(void) {
   int integer1 = 0; // will hold first number to be entered by user 
   int integer2 = 0; // will hold second number to be entered by user

   printf("Enter first integer: "); // prompt
   scanf("%d", &integer1); // read an integer

   printf("Enter second integer: "); // prompt
   scanf("%d", &integer2); // read an integer

   int sum = 0; // variable in which sum will be stored
   sum = integer1 + integer2; // assign total to sum

   printf("Sum is %d\n", sum); // print sum
} // end function main



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
