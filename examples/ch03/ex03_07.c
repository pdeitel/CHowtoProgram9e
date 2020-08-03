// raise x to the y power 
#include <stdio.h>

int main(void) {
   printf("%s", "Enter first integer: ");
   int x = 0; 
   scanf("%d", &x); // read value for x from user 
   printf("%s", "Enter second integer: ");
   int y = 0; 
   scanf("%d", &y); // read value for y from user 

   int i = 1; 
   int power = 1; // set power 

   while (i <= y) { // loop while i is less than or equal to y 
      power *= x; // multiply power by x 
      ++i; // increment i 
   } // end while                                        

   printf("%d\n", power); // display power 
} // end main function 


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