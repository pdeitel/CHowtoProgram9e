// fig08_23.c
// Using function memcmp
#include <stdio.h>
#include <string.h>

int main(void) {
   char s1[] = "ABCDEFG"; 
   char s2[] = "ABCDXYZ";
        
   printf("s1 = %s\ns2 = %s\n\n%s%2d\n%s%2d\n%s%2d\n", s1, s2,
      "memcmp(s1, s2, 4) = ", memcmp(s1, s2, 4),
      "memcmp(s1, s2, 7) = ", memcmp(s1, s2, 7),
      "memcmp(s2, s1, 7) = ", memcmp(s2, s1, 7));
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
