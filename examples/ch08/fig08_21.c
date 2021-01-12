// fig08_21.c
// Using function memcpy
#include <stdio.h>
#include <string.h>

int main(void) {
   char s1[17] = ""; 
   char s2[] = "Copy this string"; 

   memcpy(s1, s2, 17); // 17 so we copy s2's terminating \0 
   puts("After s2 is copied into s1 with memcpy, s1 contains:");
   puts(s1);
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
