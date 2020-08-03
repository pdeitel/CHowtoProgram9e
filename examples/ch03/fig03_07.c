// fig03_07.c
// Preincrementing and postincrementing.
#include <stdio.h>

// function main begins program execution 
int main(void) {
   // demonstrate postincrement 
   int c = 5; // assign 5 to c 
   printf("%d\n", c); // print 5 
   printf("%d\n", c++); // print 5 then postincrement
   printf("%d\n\n", c); // print 6                                   
   
   // demonstrate preincrement 
   c = 5; // assign 5 to c 
   printf("%d\n", c); // print 5 
   printf("%d\n", ++c); // preincrement then print 6
   printf("%d\n", c); // print 6                                    
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
