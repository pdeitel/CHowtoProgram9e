#include <stdio.h>

int main(void) {
   int x = 0; 
   int y = 0; 

   // prompt user for input
   printf("%s", "Enter two integers in the range 1-20: ");
   scanf("%d%d", &x, &y); // read values for x and y

   for (int i = 1; i <= y; ++i) { // count from 1 to y

      for (int j = 1; j <= x; ++j) { // count from 1 to x
         printf("%s", "@"); 
      } 

      puts(""); // begin new line
   } 
} 



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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