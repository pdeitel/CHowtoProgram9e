// fig09_02.c
// Using the floating-point conversion specifiers
#include <stdio.h>

int main(void) {
   printf("%e\n", 1234567.89);
   printf("%e\n", +1234567.89); // plus does not print
   printf("%e\n", -1234567.89); // minus prints
   printf("%E\n", 1234567.89);
   printf("%f\n", 1234567.89); // six digits to right of decimal point
   printf("%g\n", 1234567.89); // prints with lowercase e
   printf("%G\n", 1234567.89); // prints with uppercase E
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
