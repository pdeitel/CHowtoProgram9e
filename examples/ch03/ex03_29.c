#include <stdio.h>

int main(void) {
   int row = 10; // initialize row 

   while (row >= 1) { // loop until row < 1 
      int column = 1; // set column to 1 as iteration begins 

      while (column <= 10) { // loop 10 times 
         printf("%s", (row % 2) ? "<": ">"); // output 
         ++column; // increment column 
      } // end inner while 

      --row; // decrement row 
      puts(""); // begin new output line 
   } // end outer while 
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

