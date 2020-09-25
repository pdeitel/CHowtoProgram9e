// fig08_09.c
// Using function sprintf
#include <stdio.h>
#define SIZE 80

int main(void) {
   int x = 0; 
   double y = 0.0; 

   puts("Enter an integer and a double:");
   scanf("%d%lf", &x, &y);

   char s[SIZE] = ""; // create char array
   sprintf(s, "integer:%6d\ndouble:%7.2f", x, y);
   
   printf("The formatted output stored in array s is:\n%s\n", s);
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