// figD_01.c
// Initializing specific array elements with designated initializers. 
#include <stdio.h>

int main(void) {
   int values[5] = {
      [0] = 123, // initialize element 0
      [4] = 456 // initialize element 4
   }; // semicolon is required

   // output array contents
   printf("values: ");

   for (size_t i = 0; i < 5; ++i) {
      printf("%d  ", values[i]);
   } 

   puts("");
} 



 /*************************************************************************
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
