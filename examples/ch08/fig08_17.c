// fig08_17.c
// Using function strrchr
#include <stdio.h>
#include <string.h>

int main(void) {
   const char *s1 = "A zoo has many animals including zebras";
   int c = 'z'; // character to search for
   
   printf("%s '%c' %s\n\"%s\"\n",
      "Remainder of s1 beginning with the last occurrence of character",
      c, "is:", strrchr(s1, c));
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
