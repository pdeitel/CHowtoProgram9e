// fig08_10.c
// Using function sscanf
#include <stdio.h>

int main(void) {
   char s[] = "31298 87.375"; 
   int x = 0; 
   double y = 0; 

   sscanf(s, "%d%lf", &x, &y); 
   puts("The values stored in character array s are:");
   printf("integer:%6d\ndouble:%8.3f\n", x, y);
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
